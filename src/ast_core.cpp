//
// Created by avram on 24.9.21..
//
#include "ast_core.h"
#include "context.h"

bool backend::compile(std::shared_ptr<backend::ExprAST> root){
//  if(!isWellFormed(root)){
//    return false;
//  }
  return codegen(root);
}
bool backend::codegen(const std::shared_ptr<backend::ExprAST>& root){
  bool ret = root->codegen() != nullptr;
  named_values.clear();
  return ret;
}
bool backend::isWellFormed(const std::shared_ptr<backend::ExprAST>& root){
  types::LemurTypes ret = root->wellFormed();
  named_values.clear();
  return ret != types::kError;
}
