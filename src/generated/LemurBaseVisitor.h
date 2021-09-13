
    #include <vector>
    #include <string>


// Generated from Lemur.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LemurVisitor.h"


/**
 * This class provides an empty implementation of LemurVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LemurBaseVisitor : public LemurVisitor {
public:

  virtual antlrcpp::Any visitFile(LemurParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobalstmt(LemurParser::GlobalstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassdef(LemurParser::ClassdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassbody(LemurParser::ClassbodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassvardecl(LemurParser::ClassvardeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassfunctiondef(LemurParser::ClassfunctiondefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctiondef(LemurParser::FunctiondefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamlist(LemurParser::ParamlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(LemurParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(LemurParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintstmt(LemurParser::PrintstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVardecl(LemurParser::VardeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(LemurParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclassign(LemurParser::DeclassignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(LemurParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileloop(LemurParser::WhileloopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForloop(LemurParser::ForloopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr(LemurParser::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElseExpr(LemurParser::IfElseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringRule(LemurParser::StringRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpExprRule(LemurParser::OpExprRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexRule(LemurParser::IndexRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodRule(LemurParser::MethodRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListRule(LemurParser::ListRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRule(LemurParser::NumberRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUminusRule(LemurParser::UminusRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallExprRule(LemurParser::CallExprRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarRule(LemurParser::VarRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNegRule(LemurParser::NegRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBraceExprRule(LemurParser::BraceExprRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList(LemurParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodCall(LemurParser::MethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(LemurParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(LemurParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(LemurParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallexpr(LemurParser::CallexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArglist(LemurParser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNeg(LemurParser::NegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinoperator(LemurParser::BinoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBracedexpr(LemurParser::BracedexprContext *ctx) override {
    return visitChildren(ctx);
  }


};

