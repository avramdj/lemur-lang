//
// Created by avram on 24.9.21..
//

#ifndef LEMUR_INCLUDE_SYMBOL_TABLE_H_
#define LEMUR_INCLUDE_SYMBOL_TABLE_H_

#include <memory>
#include <map>
#include <utility>
#include "llvm/IR/Value.h"

namespace backend {
class SymbolTable {
 public:
  void pushScope();
  void popScope();
  void set(const std::string& name, llvm::Value* alloca);
  llvm::Value* get(const std::string& name);
  llvm::Value* operator[](const std::string& name);
  bool isInCurrentScope(const std::string& name);

  void swapLastTwo();

 private:
  struct Scope {
    std::shared_ptr<Scope> parent;
    std::map<std::string, llvm::Value*> symbols;
    static std::shared_ptr<Scope> get() { return std::make_shared<Scope>(); };
    explicit Scope() = default;
    explicit Scope(Scope* parent_) : parent(std::make_shared<Scope>(parent_)) {}
    explicit Scope(std::shared_ptr<Scope> parent_) : parent(std::move(parent_)) {}
  };

  std::shared_ptr<Scope> currentScope = nullptr;
};
};  // namespace backend

#endif  // LEMUR_INCLUDE_SYMBOL_TABLE_H_
