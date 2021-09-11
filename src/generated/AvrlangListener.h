
    #include <vector>
    #include <string>


// Generated from Avrlang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AvrlangParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AvrlangParser.
 */
class  AvrlangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(AvrlangParser::FileContext *ctx) = 0;
  virtual void exitFile(AvrlangParser::FileContext *ctx) = 0;

  virtual void enterGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) = 0;
  virtual void exitGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) = 0;

  virtual void enterClassdef(AvrlangParser::ClassdefContext *ctx) = 0;
  virtual void exitClassdef(AvrlangParser::ClassdefContext *ctx) = 0;

  virtual void enterClassbody(AvrlangParser::ClassbodyContext *ctx) = 0;
  virtual void exitClassbody(AvrlangParser::ClassbodyContext *ctx) = 0;

  virtual void enterClassvardecl(AvrlangParser::ClassvardeclContext *ctx) = 0;
  virtual void exitClassvardecl(AvrlangParser::ClassvardeclContext *ctx) = 0;

  virtual void enterClassfunctiondef(AvrlangParser::ClassfunctiondefContext *ctx) = 0;
  virtual void exitClassfunctiondef(AvrlangParser::ClassfunctiondefContext *ctx) = 0;

  virtual void enterFunctiondef(AvrlangParser::FunctiondefContext *ctx) = 0;
  virtual void exitFunctiondef(AvrlangParser::FunctiondefContext *ctx) = 0;

  virtual void enterParamlist(AvrlangParser::ParamlistContext *ctx) = 0;
  virtual void exitParamlist(AvrlangParser::ParamlistContext *ctx) = 0;

  virtual void enterBlock(AvrlangParser::BlockContext *ctx) = 0;
  virtual void exitBlock(AvrlangParser::BlockContext *ctx) = 0;

  virtual void enterStmt(AvrlangParser::StmtContext *ctx) = 0;
  virtual void exitStmt(AvrlangParser::StmtContext *ctx) = 0;

  virtual void enterPrintstmt(AvrlangParser::PrintstmtContext *ctx) = 0;
  virtual void exitPrintstmt(AvrlangParser::PrintstmtContext *ctx) = 0;

  virtual void enterVardecl(AvrlangParser::VardeclContext *ctx) = 0;
  virtual void exitVardecl(AvrlangParser::VardeclContext *ctx) = 0;

  virtual void enterAssign(AvrlangParser::AssignContext *ctx) = 0;
  virtual void exitAssign(AvrlangParser::AssignContext *ctx) = 0;

  virtual void enterDeclassign(AvrlangParser::DeclassignContext *ctx) = 0;
  virtual void exitDeclassign(AvrlangParser::DeclassignContext *ctx) = 0;

  virtual void enterRet(AvrlangParser::RetContext *ctx) = 0;
  virtual void exitRet(AvrlangParser::RetContext *ctx) = 0;

  virtual void enterWhileloop(AvrlangParser::WhileloopContext *ctx) = 0;
  virtual void exitWhileloop(AvrlangParser::WhileloopContext *ctx) = 0;

  virtual void enterForloop(AvrlangParser::ForloopContext *ctx) = 0;
  virtual void exitForloop(AvrlangParser::ForloopContext *ctx) = 0;

  virtual void enterIfExpr(AvrlangParser::IfExprContext *ctx) = 0;
  virtual void exitIfExpr(AvrlangParser::IfExprContext *ctx) = 0;

  virtual void enterIfElseExpr(AvrlangParser::IfElseExprContext *ctx) = 0;
  virtual void exitIfElseExpr(AvrlangParser::IfElseExprContext *ctx) = 0;

  virtual void enterStringRule(AvrlangParser::StringRuleContext *ctx) = 0;
  virtual void exitStringRule(AvrlangParser::StringRuleContext *ctx) = 0;

  virtual void enterOpExprRule(AvrlangParser::OpExprRuleContext *ctx) = 0;
  virtual void exitOpExprRule(AvrlangParser::OpExprRuleContext *ctx) = 0;

  virtual void enterIndexRule(AvrlangParser::IndexRuleContext *ctx) = 0;
  virtual void exitIndexRule(AvrlangParser::IndexRuleContext *ctx) = 0;

  virtual void enterMethodRule(AvrlangParser::MethodRuleContext *ctx) = 0;
  virtual void exitMethodRule(AvrlangParser::MethodRuleContext *ctx) = 0;

  virtual void enterListRule(AvrlangParser::ListRuleContext *ctx) = 0;
  virtual void exitListRule(AvrlangParser::ListRuleContext *ctx) = 0;

  virtual void enterNumberRule(AvrlangParser::NumberRuleContext *ctx) = 0;
  virtual void exitNumberRule(AvrlangParser::NumberRuleContext *ctx) = 0;

  virtual void enterUminusRule(AvrlangParser::UminusRuleContext *ctx) = 0;
  virtual void exitUminusRule(AvrlangParser::UminusRuleContext *ctx) = 0;

  virtual void enterCallExprRule(AvrlangParser::CallExprRuleContext *ctx) = 0;
  virtual void exitCallExprRule(AvrlangParser::CallExprRuleContext *ctx) = 0;

  virtual void enterVarRule(AvrlangParser::VarRuleContext *ctx) = 0;
  virtual void exitVarRule(AvrlangParser::VarRuleContext *ctx) = 0;

  virtual void enterNegRule(AvrlangParser::NegRuleContext *ctx) = 0;
  virtual void exitNegRule(AvrlangParser::NegRuleContext *ctx) = 0;

  virtual void enterBraceExprRule(AvrlangParser::BraceExprRuleContext *ctx) = 0;
  virtual void exitBraceExprRule(AvrlangParser::BraceExprRuleContext *ctx) = 0;

  virtual void enterList(AvrlangParser::ListContext *ctx) = 0;
  virtual void exitList(AvrlangParser::ListContext *ctx) = 0;

  virtual void enterMethodCall(AvrlangParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(AvrlangParser::MethodCallContext *ctx) = 0;

  virtual void enterString(AvrlangParser::StringContext *ctx) = 0;
  virtual void exitString(AvrlangParser::StringContext *ctx) = 0;

  virtual void enterNumber(AvrlangParser::NumberContext *ctx) = 0;
  virtual void exitNumber(AvrlangParser::NumberContext *ctx) = 0;

  virtual void enterVar(AvrlangParser::VarContext *ctx) = 0;
  virtual void exitVar(AvrlangParser::VarContext *ctx) = 0;

  virtual void enterCallexpr(AvrlangParser::CallexprContext *ctx) = 0;
  virtual void exitCallexpr(AvrlangParser::CallexprContext *ctx) = 0;

  virtual void enterArglist(AvrlangParser::ArglistContext *ctx) = 0;
  virtual void exitArglist(AvrlangParser::ArglistContext *ctx) = 0;

  virtual void enterNeg(AvrlangParser::NegContext *ctx) = 0;
  virtual void exitNeg(AvrlangParser::NegContext *ctx) = 0;

  virtual void enterBinoperator(AvrlangParser::BinoperatorContext *ctx) = 0;
  virtual void exitBinoperator(AvrlangParser::BinoperatorContext *ctx) = 0;

  virtual void enterBracedexpr(AvrlangParser::BracedexprContext *ctx) = 0;
  virtual void exitBracedexpr(AvrlangParser::BracedexprContext *ctx) = 0;


};

