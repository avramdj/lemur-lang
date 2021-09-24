//
// Created by avram on 30.8.21..
//
#include "context.h"

#include <exception>
#include <iostream>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils.h"
#include "ast.h"
#include "symbol_table.h"
#include "types.h"

//#define _DISABLE_OPTS_ 1

using namespace llvm;

namespace backend {
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
SymbolTable<Value*> named_values;
SymbolTable<types::LemurTypes> named_analysis_values;

void InitializeContext() {
  InitializeModuleAndPassManager();
  types::InitializeTypeTable();
}

void InitializeStrings() {
  str_int_format = Builder.CreateGlobalStringPtr("%d\n");
  str_float_format = Builder.CreateGlobalStringPtr("%g\n");
  str_format = Builder.CreateGlobalStringPtr("%s\n");
}

void InitializeModuleAndPassManager() {
  TheModule = new Module("my_module", TheContext);

  /* print function */
  FunctionType *print_fun_type =
      FunctionType::get(IntegerType::getInt32Ty(TheContext),
                        PointerType::get(Type::getInt8Ty(TheContext), 0), true);
  libc::print = Function::Create(print_fun_type, Function::ExternalLinkage,
                                 "printf", TheModule);

  /* malloc function */
  FunctionType *malloc_fun_type =
      FunctionType::get(IntegerType::getInt8PtrTy(TheContext),
                        IntegerType::getInt32Ty(TheContext), false);
  libc::malloc = Function::Create(malloc_fun_type, Function::ExternalLinkage,
                                  "malloc", TheModule);

  /* malloc function */
  FunctionType *free_fun_type =
      FunctionType::get(Type::getVoidTy(TheContext),
                        IntegerType::getInt8PtrTy(TheContext), false);
  libc::free = Function::Create(free_fun_type, Function::ExternalLinkage,
                                "free", TheModule);

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
  auto target_triple = sys::getDefaultTargetTriple();

  InitializeAllTargetInfos();
  InitializeAllTargets();
  InitializeAllTargetMCs();
  InitializeAllAsmParsers();
  InitializeAllAsmPrinters();

  std::string error_msg;
  auto target = TargetRegistry::lookupTarget(target_triple, error_msg);

  if (!target) {
    throw TargetErrorException(error_msg);
  }

  auto cpu = "generic";
  auto features = "";

  TargetOptions opt;
  auto reloc_model = Optional<Reloc::Model>();
  auto target_machine = target->createTargetMachine(target_triple, cpu,
                                                    features, opt, reloc_model);

  TheModule->setDataLayout(target_machine->createDataLayout());
  TheModule->setTargetTriple(target_triple);

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
    throw TargetErrorException("target machine can't emit a file of this type");
  }

  pass.run(*TheModule);
  dest.flush();
  dest.close();

  delete TheModule;
}

std::string encodeFunctionName(const std::string &fnName,
                               const std::string &clsName) {
  return std::string(".FUNC.") + clsName + std::string(".") + fnName;
}
}  // namespace backend
