//
// Created by avram on 30.8.21..
//
#include <iostream>
#include <ast.hpp>
#include <module.h>
#include <exception>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/IR/LegacyPassManager.h>

using namespace llvm;
using namespace llvm::legacy;

namespace backend {
    Module *TheModule;
    LLVMContext TheContext;
    llvm::legacy::FunctionPassManager *TheFPM;
    Function *PrintfFja;

    void InitializeModuleAndPassManager(void) {
        TheModule = new Module("my_module", TheContext);

        /* printf fja */
        FunctionType *FT1 = FunctionType::get(IntegerType::getInt32Ty(TheContext),
                                              PointerType::get(Type::getInt8Ty(TheContext), 0), true);
        PrintfFja = Function::Create(FT1, Function::ExternalLinkage, "printf", TheModule);

        // Create a new pass manager attached to it.
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

        string Error;
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
            cerr << "Could not open file: " << EC.message() << endl;
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
}

