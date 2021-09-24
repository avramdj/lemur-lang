//
// Created by avram on 11.9.21..
//

#include <ASTUtil.h>
#include <context.h>

#include <iostream>
#include <string>

#include "llvm/IR/Instructions.h"

using namespace llvm;
using namespace backend;

bool backend::replaceFormat(std::string &str, const std::string &from,
                            const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos) return false;
  str.replace(start_pos, from.length(), to);
  return true;
}
std::string backend::formatRawStr(std::string s) {
  while (replaceFormat(s, "\\\\", "\\")) {
  }
  while (replaceFormat(s, "\\n", "\n")) {
  }
  s = s.substr(1, s.size() - 2);
  return s;
}
Value *backend::getPtrToValue(const std::string &Name, const std::string &Sub) {
  if (Sub.empty()) {
    return getPtrToPrim(Name);
  }
  return getPtrToMember(Name, Sub);
}
Value *backend::getPtrToPrim(const std::string &Name) {
  Value *Alloca = NamedValues[Name];
  if (!Alloca) {
    std::cerr << "Variable " << Name << " undefined" << std::endl;
    return nullptr;
  }
  return Alloca;
}
Value *backend::getPtrToMember(const std::string &Name,
                               const std::string &Sub) {
  Value* tmp = NamedValues[Name];
  if (tmp == nullptr) {
    std::cerr << "Variable " + Name + " is undefined" << std::endl;
    return nullptr;
  }
  Type *t = tmp->getType()->getPointerElementType();

  auto cit = types::typeNames.find(t);
  if (cit == types::typeNames.end()) {
    std::cerr << "Variable " << Name << " is not of class type" << std::endl;
    return nullptr;
  }
  std::string clsName = cit->second;
  auto it = types::classVarTable[clsName].find(Sub);
  if (it == types::classVarTable[clsName].end()) {
    std::cerr << "Class " << clsName << " doesn't have member " << Sub
              << std::endl;
    return nullptr;
  }
  unsigned memberIdx = it->second;
  Value *tmp2 = Builder.CreateLoad(t, tmp, "derefptrptr");  // pointer to struct
  Value *gep = Builder.CreateStructGEP(tmp2, memberIdx);
  return gep;
}
Value *backend::GetMemberPointer(const std::string &Name,
                                 const std::string &Var) {
  Value *tmp = NamedValues[Name];
  if (tmp == nullptr) {
    std::cerr << "Variable " + Name + " is undefined" << std::endl;
    return nullptr;
  }
  Type *t = tmp->getType()->getPointerElementType();

  auto cit = types::typeNames.find(t);
  if (cit == types::typeNames.end()) {
    std::cerr << "Variable " << Name << " is not of class type" << std::endl;
    return nullptr;
  }
  std::string clsName = cit->second;
  auto it = types::classVarTable[clsName].find(Var);
  if (it == types::classVarTable[clsName].end()) {
    std::cerr << "Class " << clsName << " doesn't have member " << Var
              << std::endl;
    return nullptr;
  }
  unsigned memberIdx = it->second;
  Value *tmp2 = Builder.CreateLoad(t, tmp, "derefptrptr");  // pointer to struct
  Value *gep = Builder.CreateStructGEP(
      types::classVarTypeTable[Name][Var]->getPointerTo(), tmp2, memberIdx);
  assert(gep);
  return gep;
}