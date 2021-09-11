
    #include <vector>
    #include <string>


// Generated from Avrlang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AvrlangListener.h"


/**
 * This class provides an empty implementation of AvrlangListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AvrlangBaseListener : public AvrlangListener {
public:

  virtual void enterFile(AvrlangParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(AvrlangParser::FileContext * /*ctx*/) override { }

  virtual void enterGlobalstmt(AvrlangParser::GlobalstmtContext * /*ctx*/) override { }
  virtual void exitGlobalstmt(AvrlangParser::GlobalstmtContext * /*ctx*/) override { }

  virtual void enterClassdef(AvrlangParser::ClassdefContext * /*ctx*/) override { }
  virtual void exitClassdef(AvrlangParser::ClassdefContext * /*ctx*/) override { }

  virtual void enterClassbody(AvrlangParser::ClassbodyContext * /*ctx*/) override { }
  virtual void exitClassbody(AvrlangParser::ClassbodyContext * /*ctx*/) override { }

  virtual void enterClassvardecl(AvrlangParser::ClassvardeclContext * /*ctx*/) override { }
  virtual void exitClassvardecl(AvrlangParser::ClassvardeclContext * /*ctx*/) override { }

  virtual void enterClassfunctiondef(AvrlangParser::ClassfunctiondefContext * /*ctx*/) override { }
  virtual void exitClassfunctiondef(AvrlangParser::ClassfunctiondefContext * /*ctx*/) override { }

  virtual void enterFunctiondef(AvrlangParser::FunctiondefContext * /*ctx*/) override { }
  virtual void exitFunctiondef(AvrlangParser::FunctiondefContext * /*ctx*/) override { }

  virtual void enterParamlist(AvrlangParser::ParamlistContext * /*ctx*/) override { }
  virtual void exitParamlist(AvrlangParser::ParamlistContext * /*ctx*/) override { }

  virtual void enterBlock(AvrlangParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(AvrlangParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt(AvrlangParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(AvrlangParser::StmtContext * /*ctx*/) override { }

  virtual void enterPrintstmt(AvrlangParser::PrintstmtContext * /*ctx*/) override { }
  virtual void exitPrintstmt(AvrlangParser::PrintstmtContext * /*ctx*/) override { }

  virtual void enterVardecl(AvrlangParser::VardeclContext * /*ctx*/) override { }
  virtual void exitVardecl(AvrlangParser::VardeclContext * /*ctx*/) override { }

  virtual void enterAssign(AvrlangParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(AvrlangParser::AssignContext * /*ctx*/) override { }

  virtual void enterDeclassign(AvrlangParser::DeclassignContext * /*ctx*/) override { }
  virtual void exitDeclassign(AvrlangParser::DeclassignContext * /*ctx*/) override { }

  virtual void enterRet(AvrlangParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(AvrlangParser::RetContext * /*ctx*/) override { }

  virtual void enterWhileloop(AvrlangParser::WhileloopContext * /*ctx*/) override { }
  virtual void exitWhileloop(AvrlangParser::WhileloopContext * /*ctx*/) override { }

  virtual void enterForloop(AvrlangParser::ForloopContext * /*ctx*/) override { }
  virtual void exitForloop(AvrlangParser::ForloopContext * /*ctx*/) override { }

  virtual void enterIfExpr(AvrlangParser::IfExprContext * /*ctx*/) override { }
  virtual void exitIfExpr(AvrlangParser::IfExprContext * /*ctx*/) override { }

  virtual void enterIfElseExpr(AvrlangParser::IfElseExprContext * /*ctx*/) override { }
  virtual void exitIfElseExpr(AvrlangParser::IfElseExprContext * /*ctx*/) override { }

  virtual void enterStringRule(AvrlangParser::StringRuleContext * /*ctx*/) override { }
  virtual void exitStringRule(AvrlangParser::StringRuleContext * /*ctx*/) override { }

  virtual void enterOpExprRule(AvrlangParser::OpExprRuleContext * /*ctx*/) override { }
  virtual void exitOpExprRule(AvrlangParser::OpExprRuleContext * /*ctx*/) override { }

  virtual void enterIndexRule(AvrlangParser::IndexRuleContext * /*ctx*/) override { }
  virtual void exitIndexRule(AvrlangParser::IndexRuleContext * /*ctx*/) override { }

  virtual void enterMethodRule(AvrlangParser::MethodRuleContext * /*ctx*/) override { }
  virtual void exitMethodRule(AvrlangParser::MethodRuleContext * /*ctx*/) override { }

  virtual void enterListRule(AvrlangParser::ListRuleContext * /*ctx*/) override { }
  virtual void exitListRule(AvrlangParser::ListRuleContext * /*ctx*/) override { }

  virtual void enterNumberRule(AvrlangParser::NumberRuleContext * /*ctx*/) override { }
  virtual void exitNumberRule(AvrlangParser::NumberRuleContext * /*ctx*/) override { }

  virtual void enterUminusRule(AvrlangParser::UminusRuleContext * /*ctx*/) override { }
  virtual void exitUminusRule(AvrlangParser::UminusRuleContext * /*ctx*/) override { }

  virtual void enterCallExprRule(AvrlangParser::CallExprRuleContext * /*ctx*/) override { }
  virtual void exitCallExprRule(AvrlangParser::CallExprRuleContext * /*ctx*/) override { }

  virtual void enterVarRule(AvrlangParser::VarRuleContext * /*ctx*/) override { }
  virtual void exitVarRule(AvrlangParser::VarRuleContext * /*ctx*/) override { }

  virtual void enterNegRule(AvrlangParser::NegRuleContext * /*ctx*/) override { }
  virtual void exitNegRule(AvrlangParser::NegRuleContext * /*ctx*/) override { }

  virtual void enterBraceExprRule(AvrlangParser::BraceExprRuleContext * /*ctx*/) override { }
  virtual void exitBraceExprRule(AvrlangParser::BraceExprRuleContext * /*ctx*/) override { }

  virtual void enterList(AvrlangParser::ListContext * /*ctx*/) override { }
  virtual void exitList(AvrlangParser::ListContext * /*ctx*/) override { }

  virtual void enterMethodCall(AvrlangParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(AvrlangParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterString(AvrlangParser::StringContext * /*ctx*/) override { }
  virtual void exitString(AvrlangParser::StringContext * /*ctx*/) override { }

  virtual void enterNumber(AvrlangParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(AvrlangParser::NumberContext * /*ctx*/) override { }

  virtual void enterVar(AvrlangParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(AvrlangParser::VarContext * /*ctx*/) override { }

  virtual void enterCallexpr(AvrlangParser::CallexprContext * /*ctx*/) override { }
  virtual void exitCallexpr(AvrlangParser::CallexprContext * /*ctx*/) override { }

  virtual void enterArglist(AvrlangParser::ArglistContext * /*ctx*/) override { }
  virtual void exitArglist(AvrlangParser::ArglistContext * /*ctx*/) override { }

  virtual void enterNeg(AvrlangParser::NegContext * /*ctx*/) override { }
  virtual void exitNeg(AvrlangParser::NegContext * /*ctx*/) override { }

  virtual void enterBinoperator(AvrlangParser::BinoperatorContext * /*ctx*/) override { }
  virtual void exitBinoperator(AvrlangParser::BinoperatorContext * /*ctx*/) override { }

  virtual void enterBracedexpr(AvrlangParser::BracedexprContext * /*ctx*/) override { }
  virtual void exitBracedexpr(AvrlangParser::BracedexprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

