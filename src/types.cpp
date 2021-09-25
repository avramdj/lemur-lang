//
// Created by avram on 25.9.21..
//

#include "types.h"

#include <iostream>

#include "ast.h"
#include "context.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"

#define VOID_BITS 11

using namespace llvm;

namespace backend {
namespace types {
inline namespace class_meta {
std::map<std::string, std::map<std::string, unsigned>> class_var_table;
std::map<std::string, std::map<std::string, Type *>> class_var_types;
std::map<std::string, std::map<std::string, LemurTypes>> class_var_analysis;
std::map<std::string, std::vector<std::string>> class_functions;
}  // namespace class_meta
std::map<std::string, Type *> type_table;
std::map<Type *, std::string> type_names;

Value *getTypeConstant(Type *t, float val) {
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
Value *getTypeConstant(std::string type, float val) {
  return getTypeConstant(type_table[type], val);
}
Type *getType(std::string name) {
  auto type_it = type_table.find(name);
  if (type_it == type_table.end()) {
    std::cerr << "Invalid type  " << name << std::endl;
    return nullptr;
  }
  return type_it->second;
}
Value *boolCast(Value *val) {
  Type *bool_type = getType("bool");
  Type *val_type = val->getType();
  if (val_type == bool_type) {
    return val;
  } else if (val_type == getType("float")) {
    return Builder.CreateFPToUI(val, bool_type, "boolcast");
  } else if (val_type == getType("int")) {
    return Builder.CreateIntCast(val, bool_type, false, "boolcast");
  } else {
    return nullptr;
  }
}
Value *floatCast(Value *val) {
  Type *float_type = getType("float");
  Type *val_type = val->getType();
  if (val_type == float_type) {
    return val;
  } else if (val_type == getType("int")) {
    return Builder.CreateSIToFP(val, float_type, "boolcast");
  } else {
    return nullptr;
  }
}

bool isClassType(Type *t) {
  std::string ts = type_names[t];
  return class_var_table.find(ts) != class_var_table.end();
}

Value *getStructSize(Type *t) {
  Value *null_type_ptr =
      ConstantPointerNull::get(t->getPointerElementType()->getPointerTo());
  Value *gep_size = Builder.CreateGEP(t->getPointerElementType(), null_type_ptr,
                                      getTypeConstant("int", 1), "gep_size");
  return Builder.CreatePtrToInt(gep_size, getType("int"));
}

bool isVoid(const std::string &type_name) { return type_name == "void"; }
bool isVoid(Type *type) { return isVoid(type_names[type]); }

void InitializeTypeTable() {
  type_table["int"] = Type::getInt32Ty(TheContext);
  type_names[type_table["int"]] = "int";
  type_table["bool"] = Type::getInt1Ty(TheContext);
  type_names[type_table["bool"]] = "bool";
  type_table["float"] = Type::getDoubleTy(TheContext);
  type_names[type_table["float"]] = "float";
  type_table["string"] = Type::getInt8PtrTy(TheContext);
  type_names[type_table["string"]] = "string";
  type_table["void"] = Type::getIntNTy(TheContext, VOID_BITS);
  type_names[type_table["void"]] = "void";
}
LemurTypes getLemurType(std::string name) {
  if(name == "int") {
    return kInt;
  }
  if(name == "float") {
    return kFloat;
  }
  if(name == "bool") {
    return kBool;
  }
  if(name == "string") {
    return kString;
  }
  return kClass;
}
}  // namespace types
}  // namespace backend