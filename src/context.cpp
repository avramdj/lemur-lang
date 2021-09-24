//
// Created by avram on 30.8.21..
//
#include <ast.h>
#include <context.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <symbol_table.h>

#include <exception>
#include <iostream>

#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils.h"

//#define _DISABLE_OPTS_ 1
#define VOID_BITS 11

using namespace llvm;

namespace backend {
namespace types {
inline namespace class_meta {
std::map<std::string, std::map<std::string, unsigned>> class_var_table;
std::map<std::string, std::map<std::string, Type *>> class_var_types;
std::map<std::string, std::vector<std::string>> class_functions;
}  // namespace class_meta
std::map<std::string, Type *> type_table;
std::map<Type *, std::string> type_names;
}  // namespace types
Module *TheModule;
LLVMContext TheContext;
IRBuilder<> Builder(TheContext);
llvm::legacy::FunctionPassManager *TheFPM;
namespace libc {
Function *print;
Function *malloc;
Function *free;
}  // namespace libc
Value *str_int_format = nullptr;
Value *str_float_format = nullptr;
Value *str_format = nullptr;
SymbolTable NamedValues;

void InitializeContext() {
  InitializeModuleAndPassManager();
  InitializeTypeTable();
}

void InitializeStrings() {
  str_int_format = Builder.CreateGlobalStringPtr("%d\n");
  str_float_format = Builder.CreateGlobalStringPtr("%g\n");
  str_format = Builder.CreateGlobalStringPtr("%s\n");
}

void InitializeTypeTable() {
  types::type_table["int"] = Type::getInt32Ty(TheContext);
  types::type_names[types::type_table["int"]] = "int";
  types::type_table["bool"] = Type::getInt1Ty(TheContext);
  types::type_names[types::type_table["bool"]] = "bool";
  types::type_table["float"] = Type::getDoubleTy(TheContext);
  types::type_names[types::type_table["float"]] = "float";
  types::type_table["string"] = Type::getInt8PtrTy(TheContext);
  types::type_names[types::type_table["string"]] = "string";
  types::type_table["void"] = Type::getIntNTy(TheContext, VOID_BITS);
  types::type_names[types::type_table["void"]] = "void";
}

void InitializeModuleAndPassManager() {
  TheModule = new Module("my_module", TheContext);

  /* print function */
  FunctionType *printFunType =
      FunctionType::get(IntegerType::getInt32Ty(TheContext),
                        PointerType::get(Type::getInt8Ty(TheContext), 0), true);
  libc::print = Function::Create(printFunType, Function::ExternalLinkage, "printf",
                              TheModule);

  /* malloc function */
  FunctionType *mallocFunType =
      FunctionType::get(IntegerType::getInt8PtrTy(TheContext),
                        IntegerType::getInt32Ty(TheContext), false);
  libc::malloc = Function::Create(mallocFunType, Function::ExternalLinkage,
                               "malloc", TheModule);

  /* malloc function */
  FunctionType *freeFunType =
      FunctionType::get(Type::getVoidTy(TheContext),
                        IntegerType::getInt8PtrTy(TheContext), false);
  libc::free = Function::Create(freeFunType, Function::ExternalLinkage, "free",
                             TheModule);

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

void printModule(const std::string &outPath, bool printIR) {
  if (printIR) {
    TheModule->print(outs(), nullptr);
  }
  auto TargetTriple = sys::getDefaultTargetTriple();

  InitializeAllTargetInfos();
  InitializeAllTargets();
  InitializeAllTargetMCs();
  InitializeAllAsmParsers();
  InitializeAllAsmPrinters();

  std::string Error;
  auto target = TargetRegistry::lookupTarget(TargetTriple, Error);

  if (!target) {
    throw TargetErrorException(Error);
  }

  auto cpu = "generic";
  auto features = "";

  TargetOptions opt;
  auto realoc_model = Optional<Reloc::Model>();
  auto target_machine = target->createTargetMachine(TargetTriple, cpu, features, opt, realoc_model);

  TheModule->setDataLayout(target_machine->createDataLayout());
  TheModule->setTargetTriple(TargetTriple);

  const auto &filename = outPath;
  std::error_code EC;
  raw_fd_ostream dest(filename, EC, sys::fs::OF_None);

  if (EC) {
    std::cerr << "Could not open file: " << EC.message() << std::endl;
    throw FileException(EC.message());
  }

  legacy::PassManager pass;
  auto file_type = CGFT_ObjectFile;

  if (target_machine->addPassesToEmitFile(pass, dest, nullptr, file_type)) {
    throw TargetErrorException("target_machine can't emit a file of this type");
  }

  pass.run(*TheModule);
  dest.flush();
  dest.close();

  delete TheModule;
}

std::string encodeFunctionName(const std::string &fnName,
                               const std::string &clsName) {
  return std::string("_FUNC_") + clsName + std::string("_") + fnName;
}

Value *types::getTypeConstant(Type *t, float val) {
  if (t == type_table["int"]) {
    return ConstantInt::get(Type::getInt32Ty(TheContext), APInt(32, val));
  }
  if (t == type_table["float"]) {
    return ConstantFP::get(Type::getDoubleTy(TheContext), val);
  }
  if (t == type_table["void"]) {
    return ConstantInt::get(Type::getInt32Ty(TheContext),
                            APInt(VOID_BITS, val));
  }
  return nullptr;
}
Value *types::getTypeConstant(std::string type, float val) {
  return getTypeConstant(type_table[type], val);
}
Type *types::getType(std::string name) {
  auto typeIt = types::type_table.find(name);
  if (typeIt == types::type_table.end()) {
    std::cerr << "Invalid type  " << name << std::endl;
    return nullptr;
  }
  return typeIt->second;
}
Value *types::boolCast(Value *v) {
  Type *boolType = types::getType("bool");
  Type *vT = v->getType();
  if (vT == boolType) {
    return v;
  } else if (vT == types::getType("float")) {
    return Builder.CreateFPToUI(v, boolType, "boolcast");
  } else if (vT == types::getType("int")) {
    return Builder.CreateIntCast(v, boolType, false, "boolcast");
  } else {
    return nullptr;
  }
}
Value *types::floatCast(Value *v) {
  Type *floatType = types::getType("float");
  Type *vT = v->getType();
  if (vT == floatType) {
    return v;
  } else if (vT == types::getType("int")) {
    return Builder.CreateSIToFP(v, floatType, "boolcast");
  } else {
    return nullptr;
  }
}

bool types::isClassType(Type *t) {
  std::string ts = types::type_names[t];
  return types::class_var_table.find(ts) != types::class_var_table.end();
}

Value *types::getStructSize(Type *t) {
  Value *nullTypePtr =
      ConstantPointerNull::get(t->getPointerElementType()->getPointerTo());
  Value *gepSize =
      Builder.CreateGEP(t->getPointerElementType(), nullTypePtr,
                        types::getTypeConstant("int", 1), "gepSize");
  return Builder.CreatePtrToInt(gepSize, types::getType("int"));
}
//    Value *types::stringCast(Value *v) {
//        Type *strType = types::getType("string");
//        Type *vT = v->getType();
//        std::vector<Value *> Args;
//        if(vT == strType) {
//            return v;
//        } else if(vT == types::getType("int")) {
//            Args.push_back(str_int_format);
//        } else if(vT == types::getType("float")){
//            Args.push_back(str_float_format);
//        } else {
//            return nullptr;
//        }
//        Args.push_back(v);
//        return Builder.CreateCall(Sprintf, Args, "sprintfCall");
//    }
bool types::isVoid(const std::string &typeName) { return typeName == "void"; }
bool types::isVoid(Type *type) { return isVoid(type_names[type]); }
}  // namespace backend
