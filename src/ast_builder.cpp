//
// Created by avram on 30.8.21..
//

#include "ast_builder.h"

#include "ast.h"
#include "ast_util.h"
#include "context.h"

antlrcpp::Any ASTBuilder::visitFile(LemurParser::FileContext *ctx) {
  std::vector<std::shared_ptr<backend::ExprAST>> v_tmp;
  for (const auto &stmt : ctx->globalstmt()) {
    std::shared_ptr<backend::ExprAST> tmp =
        antlr4::tree::AbstractParseTreeVisitor::visit(stmt);
    v_tmp.push_back(tmp);
  }
  auto global_statements = std::make_shared<backend::FileAST>(v_tmp);
  return global_statements;
}
antlrcpp::Any ASTBuilder::visitGlobalstmt(LemurParser::GlobalstmtContext *ctx) {
  return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitFunctiondef(
    LemurParser::FunctiondefContext *ctx) {
  std::string function_name = ctx->fName->getText();
  std::pair<std::vector<std::string>, std::vector<std::string>> f_params =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->params);
  auto types = f_params.first;
  auto params = f_params.second;
  std::string ret = ctx->retType ? ctx->retType->getText() : "void";
  std::shared_ptr<backend::ExprAST> function_body =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->body);
  return std::shared_ptr<backend::ExprAST>(new backend::FunctionDefAST(
      function_name, types, params, ret, function_body));
}
antlrcpp::Any ASTBuilder::visitParamlist(LemurParser::ParamlistContext *ctx) {
  std::vector<std::string> types;
  std::vector<std::string> params;
  for (auto &type : ctx->types) {
    types.push_back(type);
  }
  for (auto &param : ctx->vars) {
    params.push_back(param);
  }
  return std::make_pair(types, params);
}
antlrcpp::Any ASTBuilder::visitBlock(LemurParser::BlockContext *ctx) {
  std::vector<std::shared_ptr<backend::ExprAST>> stmt_vector;
  for (auto &stmt : ctx->stmt()) {
    std::shared_ptr<backend::ExprAST> stmt_ast =
        antlr4::tree::AbstractParseTreeVisitor::visit(stmt);
    stmt_vector.push_back(stmt_ast);
  }
  return std::shared_ptr<backend::ExprAST>(
      new backend::SeqExprAST(stmt_vector));
}
antlrcpp::Any ASTBuilder::visitStmt(LemurParser::StmtContext *ctx) {
  return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitAssign(LemurParser::AssignContext *ctx) {
  std::string var_name = ctx->varName->getText();
  std::string sub_name =
      ctx->subName ? ctx->subName->getText() : std::string("");
  std::shared_ptr<backend::ExprAST> expr =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
  if (sub_name.empty()) {
    return std::shared_ptr<backend::ExprAST>(
        new backend::SetExprAST(expr, var_name));
  }
  return std::shared_ptr<backend::ExprAST>(
      new backend::SetExprAST(expr, var_name, sub_name));
}
antlrcpp::Any ASTBuilder::visitRet(LemurParser::RetContext *ctx) {
  if (ctx->expr()) {
    std::shared_ptr<backend::ExprAST> ret =
        antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(new backend::RetExprAST(ret));
  }
  return std::shared_ptr<backend::ExprAST>(new backend::RetExprAST());
}
antlrcpp::Any ASTBuilder::visitWhileloop(LemurParser::WhileloopContext *ctx) {
  std::shared_ptr<backend::ExprAST> cond =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->bracedexpr()->expr());
  std::shared_ptr<backend::ExprAST> block =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
  return std::shared_ptr<backend::ExprAST>(
      new backend::WhileExprAST(cond, block));
}
antlrcpp::Any ASTBuilder::visitNumberRule(LemurParser::NumberRuleContext *ctx) {
  if (ctx->number()->FLOAT()) {
    return std::shared_ptr<backend::ExprAST>(new backend::FloatExprAST(
        std::stof(ctx->number()->FLOAT()->getText())));
  }
  return std::shared_ptr<backend::ExprAST>(
      new backend::IntExprAST(std::stoi(ctx->number()->INT()->getText())));
}
antlrcpp::Any ASTBuilder::visitVarRule(LemurParser::VarRuleContext *ctx) {
  std::string name = ctx->var()->varName->getText();
  std::string sub =
      ctx->var()->subName ? ctx->var()->subName->getText() : std::string("");
  if (sub.empty()) {
    return std::shared_ptr<backend::ExprAST>(
        new backend::VariableExprAST(name));
  } else {
    return std::shared_ptr<backend::ExprAST>(
        new backend::VariableExprAST(name, sub));
  }
}

antlrcpp::Any ASTBuilder::visitIfExpr(LemurParser::IfExprContext *ctx) {
  std::shared_ptr<backend::ExprAST> cond =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond->expr());
  std::shared_ptr<backend::ExprAST> block =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
  return std::shared_ptr<backend::ExprAST>(new backend::IfExprAST(cond, block));
}
antlrcpp::Any ASTBuilder::visitIfElseExpr(LemurParser::IfElseExprContext *ctx) {
  std::shared_ptr<backend::ExprAST> cond =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond->expr());
  std::shared_ptr<backend::ExprAST> thenBlock =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(0));
  std::shared_ptr<backend::ExprAST> elseBlock =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(1));
  return std::shared_ptr<backend::ExprAST>(
      new backend::IfElseExprAST(cond, thenBlock, elseBlock));
}

antlrcpp::Any ASTBuilder::visitCallExprRule(
    LemurParser::CallExprRuleContext *ctx) {
  std::string name = ctx->callexpr()->fName->getText();
  std::vector<std::shared_ptr<backend::ExprAST>> args;
  for (auto p : ctx->callexpr()->arglist()->expr()) {
    std::shared_ptr<backend::ExprAST> e =
        antlr4::tree::AbstractParseTreeVisitor::visit(p);
    args.push_back(e);
  }
  return std::shared_ptr<backend::ExprAST>(
      new backend::CallExprAST(name, args));
}

antlrcpp::Any ASTBuilder::visitArglist(LemurParser::ArglistContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitNegRule(LemurParser::NegRuleContext *ctx) {
  std::shared_ptr<backend::ExprAST> expr =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->neg()->expr());
  return std::shared_ptr<backend::ExprAST>(new backend::NotExprAST(expr));
}
antlrcpp::Any ASTBuilder::visitOpExprRule(LemurParser::OpExprRuleContext *ctx) {
  std::string op =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->binoperator());
  std::shared_ptr<backend::ExprAST> lhs =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->leftOp);
  std::shared_ptr<backend::ExprAST> rhs =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->rightOp);
  backend::ExprAST *bin_op = nullptr;
  if (op == "and") {
    bin_op = new backend::AndExprAST(lhs, rhs);
  } else if (op == "or") {
    bin_op = new backend::OrExprAST(lhs, rhs);
  } else if (op == "xor") {
    bin_op = new backend::XorExprAST(lhs, rhs);
  } else if (op == "+") {
    bin_op = new backend::AddExprAST(lhs, rhs);
  } else if (op == "-") {
    bin_op = new backend::SubExprAST(lhs, rhs);
  } else if (op == "*") {
    bin_op = new backend::MulExprAST(lhs, rhs);
  } else if (op == "/") {
    bin_op = new backend::DivExprAST(lhs, rhs);
  } else if (op == "==") {
    bin_op = new backend::EqExprAST(lhs, rhs);
  } else if (op == "!=") {
    bin_op = new backend::NeqExprAST(lhs, rhs);
  } else if (op == "<") {
    bin_op = new backend::LtExprAST(lhs, rhs);
  } else if (op == "<=") {
    bin_op = new backend::LteExprAST(lhs, rhs);
  } else if (op == ">") {
    bin_op = new backend::GtExprAST(lhs, rhs);
  } else if (op == ">=") {
    bin_op = new backend::GteExprAST(lhs, rhs);
  } else if (op == "<<") {
    bin_op = new backend::ShlExprAST(lhs, rhs);
  } else if (op == ">>") {
    bin_op = new backend::ShrExprAST(lhs, rhs);
  }
  return std::shared_ptr<backend::ExprAST>(bin_op);
}

antlrcpp::Any ASTBuilder::visitPrintstmt(LemurParser::PrintstmtContext *ctx) {
  std::shared_ptr<backend::ExprAST> expr =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
  return std::shared_ptr<backend::ExprAST>(new backend::PrintExprAST(expr));
}

antlrcpp::Any ASTBuilder::visitBinoperator(
    LemurParser::BinoperatorContext *ctx) {
  return ctx->getText();
}

antlrcpp::Any ASTBuilder::visitBraceExprRule(
    LemurParser::BraceExprRuleContext *ctx) {
  return antlr4::tree::AbstractParseTreeVisitor::visit(
      ctx->bracedexpr()->expr());
}

antlrcpp::Any ASTBuilder::visitVardecl(LemurParser::VardeclContext *ctx) {
  std::string type = ctx->typeName->getText();
  std::string name = ctx->varName->getText();
  return std::shared_ptr<backend::ExprAST>(
      new backend::VarDeclExprAST(type, name));
}

antlrcpp::Any ASTBuilder::visitDeclassign(LemurParser::DeclassignContext *ctx) {
  std::string type = ctx->typeName->getText();
  std::string name = ctx->varName->getText();
  std::shared_ptr<backend::ExprAST> expr =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
  return std::shared_ptr<backend::ExprAST>(
      new backend::DeclAssignExprAST(type, name, expr));
}

antlrcpp::Any ASTBuilder::visitStringRule(LemurParser::StringRuleContext *ctx) {
  std::string str = ctx->getText();
  str = backend::formatRawStr(str);
  return std::shared_ptr<backend::ExprAST>(new backend::StringExprAST(str));
}

antlrcpp::Any ASTBuilder::visitClassdef(LemurParser::ClassdefContext *ctx) {
  std::vector<std::string> var_types;
  std::vector<std::string> var_names;
  std::string name = ctx->cName->getText();
  std::string base_name =
      ctx->baseName ? ctx->baseName->getText() : std::string("");
  for (auto &t : ctx->classbody()->classvardecl()) {
    var_types.push_back(t->typeName->getText());
    var_names.push_back(t->varName->getText());
  }

  std::vector<backend::FunctionDefAST *> functions;

  for (auto &fn : ctx->classbody()->classfunctiondef()) {
    std::string function_name = backend::encodeFunctionName(
        fn->fName->getText(), ctx->cName->getText());
    std::pair<std::vector<std::string>, std::vector<std::string>> f_params =
        antlr4::tree::AbstractParseTreeVisitor::visit(fn->params);
    auto types = f_params.first;
    types.insert(types.begin(), name);
    auto params = f_params.second;
    params.insert(params.begin(), std::string("this"));
    std::string ret = fn->retType ? fn->retType->getText() : "void";
    std::shared_ptr<backend::ExprAST> function_body =
        antlr4::tree::AbstractParseTreeVisitor::visit(fn->body);
    auto *f = new backend::FunctionDefAST(function_name, types, params, ret,
                                          function_body, true);
    functions.push_back(f);
  }

  auto cls = new backend::ClassDefExprAST(name, base_name, var_types, var_names,
                                          functions);
  return std::shared_ptr<backend::ExprAST>(cls);
}

antlrcpp::Any ASTBuilder::visitClassbody(LemurParser::ClassbodyContext *ctx) {
  return nullptr;
}

antlrcpp::Any ASTBuilder::visitMethodCall(LemurParser::MethodCallContext *ctx) {
  std::string var = ctx->varName->getText();
  std::string method = ctx->methodName->getText();
  std::vector<std::shared_ptr<backend::ExprAST>> args;
  for (auto p : ctx->arglist()->expr()) {
    std::shared_ptr<backend::ExprAST> expr =
        antlr4::tree::AbstractParseTreeVisitor::visit(p);
    args.push_back(expr);
  }
  return std::shared_ptr<backend::ExprAST>(
      new backend::MethodCallExprAST(var, method, args));
}
