//
// Created by avram on 30.8.21..
//

#ifndef LEMUR_MODULE_H
#define LEMUR_MODULE_H

#include <symbol_table.h>

#include <map>
#include <utility>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;
using namespace legacy;

namespace backend {
namespace types {
inline namespace class_meta {
extern std::map<std::string, std::map<std::string, unsigned>> class_var_table;
extern std::map<std::string, std::map<std::string, Type *>> class_var_types;
extern std::map<std::string, std::vector<std::string>> class_functions;
}  // namespace class_meta
extern std::map<std::string, Type *> type_table;
extern std::map<Type *, std::string> type_names;
Value *getTypeConstant(Type *, float);
Value *getTypeConstant(std::string, float);
Type *getType(std::string name);
bool isClassType(Type *t);
Value *boolCast(Value *v);
Value *floatCast(Value *v);
Value *stringCast(Value *v);
Value *getStructSize(Type *t);
bool isVoid(const std::string &typeName);
bool isVoid(Type *type);
}  // namespace types
typedef AllocaInst *AllocaPtr;
extern Module *TheModule;
extern LLVMContext TheContext;
extern IRBuilder<> Builder;
extern llvm::legacy::FunctionPassManager *TheFPM;
namespace libc {
extern Function *print;
extern Function *malloc;
extern Function *free;
}  // namespace libc

extern Value *str_int_format;
extern Value *str_float_format;
extern Value *str_format;

extern SymbolTable NamedValues;

void InitializeContext();
void InitializeStrings();
void InitializeTypeTable();
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