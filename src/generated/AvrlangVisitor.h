
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;


// Generated from Avrlang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AvrlangParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AvrlangParser.
 */
class  AvrlangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AvrlangParser.
   */
    virtual antlrcpp::Any visitFile(AvrlangParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitGlobalstmt(AvrlangParser::GlobalstmtContext *context) = 0;

    virtual antlrcpp::Any visitFunctiondef(AvrlangParser::FunctiondefContext *context) = 0;

    virtual antlrcpp::Any visitParamlist(AvrlangParser::ParamlistContext *context) = 0;

    virtual antlrcpp::Any visitBlock(AvrlangParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStmt(AvrlangParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitPrintstmt(AvrlangParser::PrintstmtContext *context) = 0;

    virtual antlrcpp::Any visitAssign(AvrlangParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitRet(AvrlangParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitWhileloop(AvrlangParser::WhileloopContext *context) = 0;

    virtual antlrcpp::Any visitIf_expr(AvrlangParser::If_exprContext *context) = 0;

    virtual antlrcpp::Any visitIfelse_expr(AvrlangParser::Ifelse_exprContext *context) = 0;

    virtual antlrcpp::Any visitOpExprRule(AvrlangParser::OpExprRuleContext *context) = 0;

    virtual antlrcpp::Any visitNumberRule(AvrlangParser::NumberRuleContext *context) = 0;

    virtual antlrcpp::Any visitCallExprRule(AvrlangParser::CallExprRuleContext *context) = 0;

    virtual antlrcpp::Any visitVarRule(AvrlangParser::VarRuleContext *context) = 0;

    virtual antlrcpp::Any visitNegRule(AvrlangParser::NegRuleContext *context) = 0;

    virtual antlrcpp::Any visitBraceExprRule(AvrlangParser::BraceExprRuleContext *context) = 0;

    virtual antlrcpp::Any visitNumber(AvrlangParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitVar(AvrlangParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitCallexpr(AvrlangParser::CallexprContext *context) = 0;

    virtual antlrcpp::Any visitArglist(AvrlangParser::ArglistContext *context) = 0;

    virtual antlrcpp::Any visitNeg(AvrlangParser::NegContext *context) = 0;

    virtual antlrcpp::Any visitBinoperator(AvrlangParser::BinoperatorContext *context) = 0;

    virtual antlrcpp::Any visitBracedexpr(AvrlangParser::BracedexprContext *context) = 0;


};

