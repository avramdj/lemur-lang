//
// Created by avram on 25.9.21..
//

#ifndef LEMUR_INCLUDE_TYPES_H_
#define LEMUR_INCLUDE_TYPES_H_

#include <map>
#include <vector>
#include <string>

#include "llvm/IR/Value.h"

namespace backend {
namespace types {
enum LemurTypes {
  kInt,
  kFloat,
  kBool,
  kString,
  kClass,
  kVoid,
  kNone,
  kError,
};
inline namespace class_meta {
extern std::map<std::string, std::map<std::string, unsigned>> class_var_table;
extern std::map<std::string, std::map<std::string, llvm::Type *>> class_var_types;
extern std::map<std::string, std::vector<std::string>> class_functions;
}  // namespace class_meta
extern std::map<std::string, llvm::Type *> type_table;
extern std::map<llvm::Type *, std::string> type_names;
llvm::Value *getTypeConstant(llvm::Type *, float);
llvm::Value *getTypeConstant(std::string, float);
llvm::Type *getType(std::string name);
void InitializeTypeTable();
bool isClassType(llvm::Type *t);
llvm::Value *boolCast(llvm::Value *val);
llvm::Value *floatCast(llvm::Value *val);
llvm::Value *stringCast(llvm::Value *v);
llvm::Value *getStructSize(llvm::Type *t);
bool isVoid(const std::string &type_name);
bool isVoid(llvm::Type *type);
}  // namespace types
}  // namespace backend
#endif  // LEMUR_INCLUDE_TYPES_H_
