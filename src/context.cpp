//
// Created by avram on 30.8.21..
//
#include <iostream>
#include <exception>

#include <ast.hpp>
#include <context.h>

#include "llvm/IR/IRBuilder.h"
#include <llvm/IR/LegacyPassManager.h>

#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils.h"

#include "llvm/Target/TargetOptions.h"
#include "llvm/Target/TargetMachine.h"
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include "llvm/Support/FileSystem.h"

#define _DISABLE_OPTS_ 1
#define VOID_BITS 11

using namespace llvm;

namespace backend {
    namespace Types {
        std::map<std::string, Type *> typeTable;
        std::map<Type *, std::string> typeNames;
        std::map<std::string, std::map<std::string, unsigned>> classVarTable;
        std::map<std::string, std::map<std::string, Type *>> classVarTypeTable;
        std::map<std::string, std::vector<std::string>> classFnTable;
    }
    Module *TheModule;
    LLVMContext TheContext;
    IRBuilder<> Builder(TheContext);
    llvm::legacy::FunctionPassManager *TheFPM;
    Function *PrintFun;
    Function *MallocFun;
    Function *FreeFun;
    Value *strIntFormat = nullptr;
    Value *strFloatFormat = nullptr;
    Value *strFormat = nullptr;
    std::map<std::string, std::pair<AllocaInst *, Type *>> NamedValues;

    void InitializeContext(void) {
        InitializeModuleAndPassManager();
        InitializeTypeTable();
    }

    void InitializeStrings(void) {
        strIntFormat = Builder.CreateGlobalStringPtr("%d\n");
        strFloatFormat = Builder.CreateGlobalStringPtr("%g\n");
        strFormat = Builder.CreateGlobalStringPtr("%s\n");
    }

    void InitializeTypeTable(void) {
        Types::typeTable["int"] = Type::getInt32Ty(TheContext);
        Types::typeNames[Types::typeTable["int"]] = "int";
        Types::typeTable["bool"] = Type::getInt1Ty(TheContext);
        Types::typeNames[Types::typeTable["bool"]] = "bool";
        Types::typeTable["float"] = Type::getDoubleTy(TheContext);
        Types::typeNames[Types::typeTable["float"]] = "float";
        Types::typeTable["string"] = Type::getInt8PtrTy(TheContext);
        Types::typeNames[Types::typeTable["string"]] = "string";
        Types::typeTable["void"] = Type::getIntNTy(TheContext, VOID_BITS);
        Types::typeNames[Types::typeTable["void"]] = "void";
    }

    void InitializeModuleAndPassManager(void) {
        TheModule = new Module("my_module", TheContext);

        /* print function */
        FunctionType *printFunType = FunctionType::get(IntegerType::getInt32Ty(TheContext),
                                              PointerType::get(Type::getInt8Ty(TheContext), 0), true);
        PrintFun = Function::Create(printFunType, Function::ExternalLinkage, "printf", TheModule);

        /* malloc function */
        FunctionType *mallocFunType = FunctionType::get(IntegerType::getInt8PtrTy(TheContext),
                                                        IntegerType::getInt32Ty(TheContext), false);
        MallocFun = Function::Create(mallocFunType, Function::ExternalLinkage, "malloc", TheModule);

        /* malloc function */
        FunctionType *freeFunType = FunctionType::get(Type::getVoidTy(TheContext),
                                                      IntegerType::getInt8PtrTy(TheContext), false);
        FreeFun = Function::Create(freeFunType, Function::ExternalLinkage, "free", TheModule);

        TheFPM = new llvm::legacy::FunctionPassManager(TheModule);

#ifndef _DISABLE_OPTS_
        // Do simple "peephole" optimizations and bit-twiddling optzns.
        TheFPM->add(createInstructionCombiningPass());
        // Reassociate expressions.
        TheFPM->add(createReassociatePass());
        // Eliminate Common SubExpressions.
        TheFPM->add(createNewGVNPass());
        // Simplify the control flow graph (deleting unreachable blocks, etc).
        TheFPM->add(createCFGSimplificationPass());
        TheFPM->add(createPromoteMemoryToRegisterPass());
#endif
        TheFPM->doInitialization();

    }

    void printModule(bool printIR, std::string outPath) {
        if(printIR) {
            TheModule->print(outs(), nullptr);
        }
        auto TargetTriple = sys::getDefaultTargetTriple();

        InitializeAllTargetInfos();
        InitializeAllTargets();
        InitializeAllTargetMCs();
        InitializeAllAsmParsers();
        InitializeAllAsmPrinters();

        std::string Error;
        auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

        if (!Target) {
            throw TargetErrorException(Error);
        }

        auto CPU = "generic";
        auto Features = "";

        TargetOptions opt;
        auto RM = Optional<Reloc::Model>();
        auto TargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

        TheModule->setDataLayout(TargetMachine->createDataLayout());
        TheModule->setTargetTriple(TargetTriple);

        const auto& Filename = outPath;
        std::error_code EC;
        raw_fd_ostream dest(Filename, EC, sys::fs::OF_None);

        if (EC) {
            std::cerr << "Could not open file: " << EC.message() << std::endl;
            throw FileException(EC.message());
        }

        legacy::PassManager pass;
        auto FileType = CGFT_ObjectFile;

        if (TargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
            throw TargetErrorException("TargetMachine can't emit a file of this type");
        }

        pass.run(*TheModule);
        dest.flush();
        dest.close();

        delete TheModule;
    }

    std::string encodeFunctionName(std::string fnName, std::string clsName = "") {
        return std::string("_FUNC_") + clsName + std::string("_") + fnName;
    }

    Value *Types::getTypeConstant(Type * t, float val) {
        if(t == typeTable["int"]) {
            return ConstantInt::get(Type::getInt32Ty(TheContext), APInt(32, val));
        }
        if(t == typeTable["float"]) {
            return ConstantFP::get(Type::getDoubleTy(TheContext), val);
        }
        if(t == typeTable["void"]) {
            return ConstantInt::get(Type::getInt32Ty(TheContext), APInt(VOID_BITS, val));
        }
        return nullptr;
    }
    Value *Types::getTypeConstant(std::string type, float val) {
        return getTypeConstant(typeTable[type], val);
    }
    Type *Types::getType(std::string name) {
        auto typeIt = Types::typeTable.find(name);
        if(typeIt == Types::typeTable.end()) {
            std::cerr << "Invalid type  " << name << std::endl;
            return nullptr;
        }
        return typeIt->second;
    }
    Value *Types::boolCast(Value *v) {
        Type *boolType = Types::getType("bool");
        Type *vT = v->getType();
        if (vT == boolType) {
            return v;
        } else if(vT == Types::getType("float")) {
            return Builder.CreateFPToUI(v, boolType, "boolcast");
        } else if(vT == Types::getType("int")) {
            return Builder.CreateIntCast(v, boolType, false, "boolcast");
        } else {
            return nullptr;
        }
    }
    Value *Types::floatCast(Value *v) {
        Type *floatType = Types::getType("float");
        Type *vT = v->getType();
        if(vT == floatType) {
            return v;
        } else if(vT == Types::getType("int")) {
            return Builder.CreateSIToFP(v, floatType, "boolcast");
        } else {
            return nullptr;
        }
    }

    bool Types::isClassType(Type *t) {
        std::string ts = Types::typeNames[t];
        return Types::classVarTable.find(ts) != Types::classVarTable.end();
    }

    Value *Types::getStructSize(Type *t) {
        Value *nullTypePtr = ConstantPointerNull::get(t->getPointerElementType()->getPointerTo());
        Value *gepSize = Builder.CreateGEP(t->getPointerElementType(), nullTypePtr, Types::getTypeConstant("int", 1), "gepSize");
        return Builder.CreatePtrToInt(gepSize, Types::getType("int"));
    }
//    Value *Types::stringCast(Value *v) {
//        Type *strType = Types::getType("string");
//        Type *vT = v->getType();
//        std::vector<Value *> Args;
//        if(vT == strType) {
//            return v;
//        } else if(vT == Types::getType("int")) {
//            Args.push_back(strIntFormat);
//        } else if(vT == Types::getType("float")){
//            Args.push_back(strFloatFormat);
//        } else {
//            return nullptr;
//        }
//        Args.push_back(v);
//        return Builder.CreateCall(Sprintf, Args, "sprintfCall");
//    }
    bool Types::isVoid(const std::string &typeName) {
        return typeName == "void";
    }
    bool Types::isVoid(Type *type) {
        return isVoid(typeNames[type]);
    }
}

