//
// Created by avram on 30.8.21..
//

#ifndef LEMUR_MODULE_H
#define LEMUR_MODULE_H

#include <map>
#include <utility>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "symbol_table.h"

namespace backend {
extern llvm::Module *TheModule;
extern llvm::LLVMContext TheContext;
extern llvm::IRBuilder<> Builder;
extern llvm::legacy::FunctionPassManager *TheFPM;
namespace libc {
extern llvm::Function *print;
extern llvm::Function *malloc;
extern llvm::Function *free;
}  // namespace libc

extern llvm::Value *str_int_format;
extern llvm::Value *str_float_format;
extern llvm::Value *str_format;

extern SymbolTable<llvm::Value*> named_values;
extern SymbolTable<types::LemurTypes> named_analysis_values;

void InitializeContext();
void InitializeStrings();
void InitializeModuleAndPassManager();
void printModule(const std::string &outPath, bool printIR = false);

std::string encodeFunctionName(const std::string &fnName,
                               const std::string &clsName = "");

class TargetErrorException : public std::exception {
 public:
  explicit TargetErrorException(std::string msgstr) : msg(std::move(msgstr)) {}
  const char *what() const noexcept override { return msg.c_str(); }

 private:
  std::string msg;
};

class FileException : public std::exception {
 public:
  explicit FileException(std::string msgstr) : msg(std::move(msgstr)) {}
  const char *what() const noexcept override { return msg.c_str(); }

 private:
  std::string msg;
};
}  // namespace backend

#endif  // LEMUR_MODULE_H