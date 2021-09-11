
    #include <vector>
    #include <string>


// Generated from Avrlang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AvrlangVisitor.h"


/**
 * This class provides an empty implementation of AvrlangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AvrlangBaseVisitor : public AvrlangVisitor {
public:

  virtual antlrcpp::Any visitFile(AvrlangParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassdef(AvrlangParser::ClassdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassbody(AvrlangParser::ClassbodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassvardecl(AvrlangParser::ClassvardeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassfunctiondef(AvrlangParser::ClassfunctiondefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctiondef(AvrlangParser::FunctiondefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamlist(AvrlangParser::ParamlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(AvrlangParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(AvrlangParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintstmt(AvrlangParser::PrintstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVardecl(AvrlangParser::VardeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(AvrlangParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclassign(AvrlangParser::DeclassignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(AvrlangParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileloop(AvrlangParser::WhileloopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForloop(AvrlangParser::ForloopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr(AvrlangParser::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElseExpr(AvrlangParser::IfElseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringRule(AvrlangParser::StringRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpExprRule(AvrlangParser::OpExprRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexRule(AvrlangParser::IndexRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodRule(AvrlangParser::MethodRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListRule(AvrlangParser::ListRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRule(AvrlangParser::NumberRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUminusRule(AvrlangParser::UminusRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallExprRule(AvrlangParser::CallExprRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarRule(AvrlangParser::VarRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNegRule(AvrlangParser::NegRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBraceExprRule(AvrlangParser::BraceExprRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList(AvrlangParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodCall(AvrlangParser::MethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(AvrlangParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(AvrlangParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(AvrlangParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallexpr(AvrlangParser::CallexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArglist(AvrlangParser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNeg(AvrlangParser::NegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinoperator(AvrlangParser::BinoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBracedexpr(AvrlangParser::BracedexprContext *ctx) override {
    return visitChildren(ctx);
  }


};

