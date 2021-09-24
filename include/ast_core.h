//
// Created by avram on 24.9.21..
//

#ifndef LEMUR_INCLUDE_AST_CORE_H_
#define LEMUR_INCLUDE_AST_CORE_H_

#include "ast.h"

namespace backend{
bool compile(std::shared_ptr<backend::ExprAST>);
bool codegen(const std::shared_ptr<backend::ExprAST>&);
bool isWellFormed(const std::shared_ptr<backend::ExprAST>&);
}

#endif  // LEMUR_INCLUDE_AST_CORE_H_
