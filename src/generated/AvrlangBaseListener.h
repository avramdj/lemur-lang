
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;


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

  virtual void enterFunctiondef(AvrlangParser::FunctiondefContext * /*ctx*/) override { }
  virtual void exitFunctiondef(AvrlangParser::FunctiondefContext * /*ctx*/) override { }

  virtual void enterParamlist(AvrlangParser::ParamlistContext * /*ctx*/) override { }
  virtual void exitParamlist(AvrlangParser::ParamlistContext * /*ctx*/) override { }

  virtual void enterBlock(AvrlangParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(AvrlangParser::BlockContext * /*ctx*/) override { }

  virtual void enterStmt(AvrlangParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(AvrlangParser::StmtContext * /*ctx*/) override { }

  virtual void enterAssign(AvrlangParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(AvrlangParser::AssignContext * /*ctx*/) override { }

  virtual void enterRet(AvrlangParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(AvrlangParser::RetContext * /*ctx*/) override { }

  virtual void enterWhileloop(AvrlangParser::WhileloopContext * /*ctx*/) override { }
  virtual void exitWhileloop(AvrlangParser::WhileloopContext * /*ctx*/) override { }

  virtual void enterIf_expr(AvrlangParser::If_exprContext * /*ctx*/) override { }
  virtual void exitIf_expr(AvrlangParser::If_exprContext * /*ctx*/) override { }

  virtual void enterIfelse_expr(AvrlangParser::Ifelse_exprContext * /*ctx*/) override { }
  virtual void exitIfelse_expr(AvrlangParser::Ifelse_exprContext * /*ctx*/) override { }

  virtual void enterExpr(AvrlangParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(AvrlangParser::ExprContext * /*ctx*/) override { }

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

