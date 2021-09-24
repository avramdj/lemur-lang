
#include <string>
#include <vector>

// Generated from Lemur.g4 by ANTLR 4.7.2

#pragma once

#include "LemurParser.h"
#include "antlr4-runtime.h"

/**
 * This interface defines an abstract listener for a parse tree produced by
 * LemurParser.
 */
class LemurListener : public antlr4::tree::ParseTreeListener {
 public:
  virtual void enterFile(LemurParser::FileContext *ctx) = 0;
  virtual void exitFile(LemurParser::FileContext *ctx) = 0;

  virtual void enterGlobalstmt(LemurParser::GlobalstmtContext *ctx) = 0;
  virtual void exitGlobalstmt(LemurParser::GlobalstmtContext *ctx) = 0;

  virtual void enterClassdef(LemurParser::ClassdefContext *ctx) = 0;
  virtual void exitClassdef(LemurParser::ClassdefContext *ctx) = 0;

  virtual void enterClassbody(LemurParser::ClassbodyContext *ctx) = 0;
  virtual void exitClassbody(LemurParser::ClassbodyContext *ctx) = 0;

  virtual void enterClassvardecl(LemurParser::ClassvardeclContext *ctx) = 0;
  virtual void exitClassvardecl(LemurParser::ClassvardeclContext *ctx) = 0;

  virtual void enterClassfunctiondef(
      LemurParser::ClassfunctiondefContext *ctx) = 0;
  virtual void exitClassfunctiondef(
      LemurParser::ClassfunctiondefContext *ctx) = 0;

  virtual void enterFunctiondef(LemurParser::FunctiondefContext *ctx) = 0;
  virtual void exitFunctiondef(LemurParser::FunctiondefContext *ctx) = 0;

  virtual void enterParamlist(LemurParser::ParamlistContext *ctx) = 0;
  virtual void exitParamlist(LemurParser::ParamlistContext *ctx) = 0;

  virtual void enterBlock(LemurParser::BlockContext *ctx) = 0;
  virtual void exitBlock(LemurParser::BlockContext *ctx) = 0;

  virtual void enterStmt(LemurParser::StmtContext *ctx) = 0;
  virtual void exitStmt(LemurParser::StmtContext *ctx) = 0;

  virtual void enterPrintstmt(LemurParser::PrintstmtContext *ctx) = 0;
  virtual void exitPrintstmt(LemurParser::PrintstmtContext *ctx) = 0;

  virtual void enterVardecl(LemurParser::VardeclContext *ctx) = 0;
  virtual void exitVardecl(LemurParser::VardeclContext *ctx) = 0;

  virtual void enterAssign(LemurParser::AssignContext *ctx) = 0;
  virtual void exitAssign(LemurParser::AssignContext *ctx) = 0;

  virtual void enterDeclassign(LemurParser::DeclassignContext *ctx) = 0;
  virtual void exitDeclassign(LemurParser::DeclassignContext *ctx) = 0;

  virtual void enterRet(LemurParser::RetContext *ctx) = 0;
  virtual void exitRet(LemurParser::RetContext *ctx) = 0;

  virtual void enterWhileloop(LemurParser::WhileloopContext *ctx) = 0;
  virtual void exitWhileloop(LemurParser::WhileloopContext *ctx) = 0;

  virtual void enterForloop(LemurParser::ForloopContext *ctx) = 0;
  virtual void exitForloop(LemurParser::ForloopContext *ctx) = 0;

  virtual void enterIfExpr(LemurParser::IfExprContext *ctx) = 0;
  virtual void exitIfExpr(LemurParser::IfExprContext *ctx) = 0;

  virtual void enterIfElseExpr(LemurParser::IfElseExprContext *ctx) = 0;
  virtual void exitIfElseExpr(LemurParser::IfElseExprContext *ctx) = 0;

  virtual void enterStringRule(LemurParser::StringRuleContext *ctx) = 0;
  virtual void exitStringRule(LemurParser::StringRuleContext *ctx) = 0;

  virtual void enterOpExprRule(LemurParser::OpExprRuleContext *ctx) = 0;
  virtual void exitOpExprRule(LemurParser::OpExprRuleContext *ctx) = 0;

  virtual void enterIndexRule(LemurParser::IndexRuleContext *ctx) = 0;
  virtual void exitIndexRule(LemurParser::IndexRuleContext *ctx) = 0;

  virtual void enterMethodRule(LemurParser::MethodRuleContext *ctx) = 0;
  virtual void exitMethodRule(LemurParser::MethodRuleContext *ctx) = 0;

  virtual void enterListRule(LemurParser::ListRuleContext *ctx) = 0;
  virtual void exitListRule(LemurParser::ListRuleContext *ctx) = 0;

  virtual void enterNumberRule(LemurParser::NumberRuleContext *ctx) = 0;
  virtual void exitNumberRule(LemurParser::NumberRuleContext *ctx) = 0;

  virtual void enterUminusRule(LemurParser::UminusRuleContext *ctx) = 0;
  virtual void exitUminusRule(LemurParser::UminusRuleContext *ctx) = 0;

  virtual void enterCallExprRule(LemurParser::CallExprRuleContext *ctx) = 0;
  virtual void exitCallExprRule(LemurParser::CallExprRuleContext *ctx) = 0;

  virtual void enterVarRule(LemurParser::VarRuleContext *ctx) = 0;
  virtual void exitVarRule(LemurParser::VarRuleContext *ctx) = 0;

  virtual void enterNegRule(LemurParser::NegRuleContext *ctx) = 0;
  virtual void exitNegRule(LemurParser::NegRuleContext *ctx) = 0;

  virtual void enterBraceExprRule(LemurParser::BraceExprRuleContext *ctx) = 0;
  virtual void exitBraceExprRule(LemurParser::BraceExprRuleContext *ctx) = 0;

  virtual void enterList(LemurParser::ListContext *ctx) = 0;
  virtual void exitList(LemurParser::ListContext *ctx) = 0;

  virtual void enterMethodCall(LemurParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(LemurParser::MethodCallContext *ctx) = 0;

  virtual void enterString(LemurParser::StringContext *ctx) = 0;
  virtual void exitString(LemurParser::StringContext *ctx) = 0;

  virtual void enterNumber(LemurParser::NumberContext *ctx) = 0;
  virtual void exitNumber(LemurParser::NumberContext *ctx) = 0;

  virtual void enterVar(LemurParser::VarContext *ctx) = 0;
  virtual void exitVar(LemurParser::VarContext *ctx) = 0;

  virtual void enterCallexpr(LemurParser::CallexprContext *ctx) = 0;
  virtual void exitCallexpr(LemurParser::CallexprContext *ctx) = 0;

  virtual void enterArglist(LemurParser::ArglistContext *ctx) = 0;
  virtual void exitArglist(LemurParser::ArglistContext *ctx) = 0;

  virtual void enterNeg(LemurParser::NegContext *ctx) = 0;
  virtual void exitNeg(LemurParser::NegContext *ctx) = 0;

  virtual void enterBinoperator(LemurParser::BinoperatorContext *ctx) = 0;
  virtual void exitBinoperator(LemurParser::BinoperatorContext *ctx) = 0;

  virtual void enterBracedexpr(LemurParser::BracedexprContext *ctx) = 0;
  virtual void exitBracedexpr(LemurParser::BracedexprContext *ctx) = 0;
};
