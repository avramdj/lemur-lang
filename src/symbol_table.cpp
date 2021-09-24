//
// Created by avram on 24.9.21..
//
#include <symbol_table.h>

#include "llvm/IR/Value.h"

using namespace llvm;

void backend::SymbolTable::pushScope() {
  auto tmpScope = currentScope;
  currentScope = Scope::get();
  currentScope->parent = tmpScope;
}
void backend::SymbolTable::popScope() {
  currentScope = currentScope ? currentScope->parent : nullptr;
}
Value* backend::SymbolTable::operator[](const std::string& name) {
  auto searchScope = currentScope;
  while (searchScope) {
    auto it = searchScope->symbols.find(name);
    if (it != searchScope->symbols.end()) {
      return it->second;
    }
    searchScope = searchScope->parent;
  }
  return nullptr;
}
bool backend::SymbolTable::isInCurrentScope(const std::string& name) {
  return currentScope->symbols.find(name) != currentScope->symbols.end();
}
void backend::SymbolTable::set(const std::string& name, llvm::Value* alloca) {
  currentScope->symbols[name] = alloca;
}
Value* backend::SymbolTable::get(const std::string& name) {
  return operator[](name);
}
void backend::SymbolTable::swapLastTwo() {
  auto curr = currentScope;
  auto prev = currentScope->parent;
  curr->parent = prev->parent;
  prev->parent = curr;
  currentScope = prev;
};
