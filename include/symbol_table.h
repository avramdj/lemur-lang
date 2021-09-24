//
// Created by avram on 24.9.21..
//

#ifndef LEMUR_INCLUDE_SYMBOL_TABLE_H_
#define LEMUR_INCLUDE_SYMBOL_TABLE_H_

#include <map>
#include <memory>
#include <utility>

#include "context.h"
#include "types.h"

namespace backend {
template <class T>
class SymbolTable {
 public:
  void pushScope() {
    auto tmpScope = currentScope;
    currentScope = Scope::get();
    currentScope->parent = tmpScope;
  }
  void popScope() {
    currentScope = currentScope ? currentScope->parent : nullptr;
  }
  T operator[](const std::string& name) {
    auto searchScope = currentScope;
    while (searchScope) {
      auto it = searchScope->symbols.find(name);
      if (it != searchScope->symbols.end()) {
        return it->second;
      }
      searchScope = searchScope->parent;
    }
    return T();
  }
  void set(const std::string& name, T val) {
    currentScope->symbols[name] = val;
  }
  T get(const std::string& name) { return operator[](name); }
  bool isInCurrentScope(const std::string& name) {
    return currentScope->symbols.find(name) != currentScope->symbols.end();
  }
  void clear() { currentScope = nullptr; }
  void swapLastTwo() {
    auto curr = currentScope;
    auto prev = currentScope->parent;
    curr->parent = prev->parent;
    prev->parent = curr;
    currentScope = prev;
  }

 private:
  struct Scope {
    std::shared_ptr<Scope> parent;
    std::map<std::string, T> symbols;
    static std::shared_ptr<Scope> get() { return std::make_shared<Scope>(); };
    explicit Scope() = default;
    explicit Scope(Scope* parent_) : parent(std::make_shared<Scope>(parent_)) {}
    explicit Scope(std::shared_ptr<Scope> parent_)
        : parent(std::move(parent_)) {}
  };

  std::shared_ptr<Scope> currentScope = nullptr;
};
};  // namespace backend

#endif  // LEMUR_INCLUDE_SYMBOL_TABLE_H_
