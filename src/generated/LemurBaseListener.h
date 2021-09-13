
    #include <vector>
    #include <string>


// Generated from Lemur.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LemurListener.h"


/**
 * This class provides an empty implementation of LemurListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LemurBaseListener : public LemurListener {
public:

  virtual void enterFile(LemurParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(LemurParser::FileContext * /*ctx*/) override { }

  virtual void enterGlobalstmt(LemurParser::GlobalstmtContext * /*ctx*/) override { }
  virtual void exitGlobalstmt(LemurParser::GlobalstmtContext * /*ctx*/) override { }

  virtual void enterClassdef(LemurParser::ClassdefContext * /*ctx*/) override { }
  virtual void exitClassdef(LemurParser::ClassdefContext * /*ctx*/) override { }

  virtual void enterClassbody(LemurParser::ClassbodyContext * /*ctx*/) override { }
  virtual void exitClassbody(LemurParser::ClassbodyContext * /*ctx*/) override { }

  virtual void enterClassvardecl(LemurParser::ClassvardeclContext * /*ctx*/) override { }
  virtual void exitClassvardecl(LemurParser::ClassvardeclContext * /*ctx*/) override { }

  virtual void enterClassfunctiondef(LemurParser::ClassfunctiondefContext * /*ctx*/) override { }
  virtual void exitClassfunctiondef(LemurParser::ClassfunctiondefContext * /*ctx*/) override { }

  virtual void enterFunctiondef(LemurParser::FunctiondefContext * /*ctx*/) override { }
  virtual void exitFunctiondef(LemurParser::FunctiondefContext * /*ctx*/) override { }

  virtual void enterParamlist(LemurParser::ParamlistContext * /*ctx*/) override { }
  virtual void exitParamlist(LemurParser::ParamlistContext * /*ctx*/) override { }

  virtual void enterBlock(LemurParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(LemurParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt(LemurParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(LemurParser::StmtContext * /*ctx*/) override { }

  virtual void enterPrintstmt(LemurParser::PrintstmtContext * /*ctx*/) override { }
  virtual void exitPrintstmt(LemurParser::PrintstmtContext * /*ctx*/) override { }

  virtual void enterVardecl(LemurParser::VardeclContext * /*ctx*/) override { }
  virtual void exitVardecl(LemurParser::VardeclContext * /*ctx*/) override { }

  virtual void enterAssign(LemurParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(LemurParser::AssignContext * /*ctx*/) override { }

  virtual void enterDeclassign(LemurParser::DeclassignContext * /*ctx*/) override { }
  virtual void exitDeclassign(LemurParser::DeclassignContext * /*ctx*/) override { }

  virtual void enterRet(LemurParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(LemurParser::RetContext * /*ctx*/) override { }

  virtual void enterWhileloop(LemurParser::WhileloopContext * /*ctx*/) override { }
  virtual void exitWhileloop(LemurParser::WhileloopContext * /*ctx*/) override { }

  virtual void enterForloop(LemurParser::ForloopContext * /*ctx*/) override { }
  virtual void exitForloop(LemurParser::ForloopContext * /*ctx*/) override { }

  virtual void enterIfExpr(LemurParser::IfExprContext * /*ctx*/) override { }
  virtual void exitIfExpr(LemurParser::IfExprContext * /*ctx*/) override { }

  virtual void enterIfElseExpr(LemurParser::IfElseExprContext * /*ctx*/) override { }
  virtual void exitIfElseExpr(LemurParser::IfElseExprContext * /*ctx*/) override { }

  virtual void enterStringRule(LemurParser::StringRuleContext * /*ctx*/) override { }
  virtual void exitStringRule(LemurParser::StringRuleContext * /*ctx*/) override { }

  virtual void enterOpExprRule(LemurParser::OpExprRuleContext * /*ctx*/) override { }
  virtual void exitOpExprRule(LemurParser::OpExprRuleContext * /*ctx*/) override { }

  virtual void enterIndexRule(LemurParser::IndexRuleContext * /*ctx*/) override { }
  virtual void exitIndexRule(LemurParser::IndexRuleContext * /*ctx*/) override { }

  virtual void enterMethodRule(LemurParser::MethodRuleContext * /*ctx*/) override { }
  virtual void exitMethodRule(LemurParser::MethodRuleContext * /*ctx*/) override { }

  virtual void enterListRule(LemurParser::ListRuleContext * /*ctx*/) override { }
  virtual void exitListRule(LemurParser::ListRuleContext * /*ctx*/) override { }

  virtual void enterNumberRule(LemurParser::NumberRuleContext * /*ctx*/) override { }
  virtual void exitNumberRule(LemurParser::NumberRuleContext * /*ctx*/) override { }

  virtual void enterUminusRule(LemurParser::UminusRuleContext * /*ctx*/) override { }
  virtual void exitUminusRule(LemurParser::UminusRuleContext * /*ctx*/) override { }

  virtual void enterCallExprRule(LemurParser::CallExprRuleContext * /*ctx*/) override { }
  virtual void exitCallExprRule(LemurParser::CallExprRuleContext * /*ctx*/) override { }

  virtual void enterVarRule(LemurParser::VarRuleContext * /*ctx*/) override { }
  virtual void exitVarRule(LemurParser::VarRuleContext * /*ctx*/) override { }

  virtual void enterNegRule(LemurParser::NegRuleContext * /*ctx*/) override { }
  virtual void exitNegRule(LemurParser::NegRuleContext * /*ctx*/) override { }

  virtual void enterBraceExprRule(LemurParser::BraceExprRuleContext * /*ctx*/) override { }
  virtual void exitBraceExprRule(LemurParser::BraceExprRuleContext * /*ctx*/) override { }

  virtual void enterList(LemurParser::ListContext * /*ctx*/) override { }
  virtual void exitList(LemurParser::ListContext * /*ctx*/) override { }

  virtual void enterMethodCall(LemurParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(LemurParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterString(LemurParser::StringContext * /*ctx*/) override { }
  virtual void exitString(LemurParser::StringContext * /*ctx*/) override { }

  virtual void enterNumber(LemurParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(LemurParser::NumberContext * /*ctx*/) override { }

  virtual void enterVar(LemurParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(LemurParser::VarContext * /*ctx*/) override { }

  virtual void enterCallexpr(LemurParser::CallexprContext * /*ctx*/) override { }
  virtual void exitCallexpr(LemurParser::CallexprContext * /*ctx*/) override { }

  virtual void enterArglist(LemurParser::ArglistContext * /*ctx*/) override { }
  virtual void exitArglist(LemurParser::ArglistContext * /*ctx*/) override { }

  virtual void enterNeg(LemurParser::NegContext * /*ctx*/) override { }
  virtual void exitNeg(LemurParser::NegContext * /*ctx*/) override { }

  virtual void enterBinoperator(LemurParser::BinoperatorContext * /*ctx*/) override { }
  virtual void exitBinoperator(LemurParser::BinoperatorContext * /*ctx*/) override { }

  virtual void enterBracedexpr(LemurParser::BracedexprContext * /*ctx*/) override { }
  virtual void exitBracedexpr(LemurParser::BracedexprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

