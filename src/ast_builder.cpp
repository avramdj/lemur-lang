//
// Created by avram on 30.8.21..
//

#include <ast.h>
#include <ast_builder.h>
#include <ast_util.h>
#include <context.h>

antlrcpp::Any ASTBuilder::visitFile(LemurParser::FileContext *ctx) {
  return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitGlobalstmt(LemurParser::GlobalstmtContext *ctx) {
  return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitFunctiondef(
    LemurParser::FunctiondefContext *ctx) {
  std::string functionName = ctx->fName->getText();
  std::pair<std::vector<std::string>, std::vector<std::string>> fparams =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->params);
  auto types = fparams.first;
  auto params = fparams.second;
  std::string ret = ctx->retType ? ctx->retType->getText() : "void";
  std::shared_ptr<backend::ExprAST> functionBody =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->body);
  auto *f = new backend::FunctionDefAST(functionName, types, params, ret,
                                        functionBody);
  f->codegen();
  return f;
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
  std::vector<std::shared_ptr<backend::ExprAST>> stmtVector;
  for (auto &stmt : ctx->stmt()) {
    std::shared_ptr<backend::ExprAST> stmtAST =
        antlr4::tree::AbstractParseTreeVisitor::visit(stmt);
    stmtVector.push_back(stmtAST);
  }
  return std::shared_ptr<backend::ExprAST>(new backend::SeqExprAST(stmtVector));
}
antlrcpp::Any ASTBuilder::visitStmt(LemurParser::StmtContext *ctx) {
  return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitAssign(LemurParser::AssignContext *ctx) {
  std::string varName = ctx->varName->getText();
  std::string subName =
      ctx->subName ? ctx->subName->getText() : std::string("");
  std::shared_ptr<backend::ExprAST> expr =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
  if (subName.empty()) {
    return std::shared_ptr<backend::ExprAST>(
        new backend::SetExprAST(expr, varName));
  }
  return std::shared_ptr<backend::ExprAST>(
      new backend::SetExprAST(expr, varName, subName));
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
  std::string Name = ctx->var()->varName->getText();
  std::string Sub =
      ctx->var()->subName ? ctx->var()->subName->getText() : std::string("");
  if (Sub.empty()) {
    return std::shared_ptr<backend::ExprAST>(
        new backend::VariableExprAST(Name));
  } else {
    return std::shared_ptr<backend::ExprAST>(
        new backend::VariableExprAST(Name, Sub));
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
  std::shared_ptr<backend::ExprAST> LHS =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->leftOp);
  std::shared_ptr<backend::ExprAST> RHS =
      antlr4::tree::AbstractParseTreeVisitor::visit(ctx->rightOp);
  backend::ExprAST *binop = nullptr;
  if (op == "and") {
    binop = new backend::AndExprAST(LHS, RHS);
  } else if (op == "or") {
    binop = new backend::OrExprAST(LHS, RHS);
  } else if (op == "xor") {
    binop = new backend::XorExprAST(LHS, RHS);
  } else if (op == "+") {
    binop = new backend::AddExprAST(LHS, RHS);
  } else if (op == "-") {
    binop = new backend::SubExprAST(LHS, RHS);
  } else if (op == "*") {
    binop = new backend::MulExprAST(LHS, RHS);
  } else if (op == "/") {
    binop = new backend::DivExprAST(LHS, RHS);
  } else if (op == "==") {
    binop = new backend::EqExprAST(LHS, RHS);
  } else if (op == "!=") {
    binop = new backend::NeqExprAST(LHS, RHS);
  } else if (op == "<") {
    binop = new backend::LtExprAST(LHS, RHS);
  } else if (op == "<=") {
    binop = new backend::LteExprAST(LHS, RHS);
  } else if (op == ">") {
    binop = new backend::GtExprAST(LHS, RHS);
  } else if (op == ">=") {
    binop = new backend::GteExprAST(LHS, RHS);
  } else if (op == "<<") {
    binop = new backend::ShlExprAST(LHS, RHS);
  } else if (op == ">>") {
    binop = new backend::ShrExprAST(LHS, RHS);
  }
  return std::shared_ptr<backend::ExprAST>(binop);
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
  std::vector<std::string> vartypes;
  std::vector<std::string> varnames;
  std::string Name = ctx->cName->getText();
  std::string BaseName =
      ctx->baseName ? ctx->baseName->getText() : std::string("");
  for (auto &t : ctx->classbody()->classvardecl()) {
    vartypes.push_back(t->typeName->getText());
    varnames.push_back(t->varName->getText());
  }

  std::vector<backend::FunctionDefAST *> functions;

  for (auto &fn : ctx->classbody()->classfunctiondef()) {
    std::string functionName = backend::encodeFunctionName(
        fn->fName->getText(), ctx->cName->getText());
    std::pair<std::vector<std::string>, std::vector<std::string>> fparams =
        antlr4::tree::AbstractParseTreeVisitor::visit(fn->params);
    auto types = fparams.first;
    types.insert(types.begin(), Name);
    auto params = fparams.second;
    params.insert(params.begin(), std::string("this"));
    std::string ret = fn->retType ? fn->retType->getText() : "void";
    std::shared_ptr<backend::ExprAST> functionBody =
        antlr4::tree::AbstractParseTreeVisitor::visit(fn->body);
    auto *f = new backend::FunctionDefAST(functionName, types, params, ret,
                                          functionBody, true);
    functions.push_back(f);
  }

  auto cls = new backend::ClassDefExprAST(Name, BaseName, vartypes, varnames,
                                          functions);
  cls->codegen();
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
    std::shared_ptr<backend::ExprAST> e =
        antlr4::tree::AbstractParseTreeVisitor::visit(p);
    args.push_back(e);
  }
  return std::shared_ptr<backend::ExprAST>(
      new backend::MethodCallExprAST(var, method, args));
}
