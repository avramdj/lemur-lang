
    #include <vector>
    #include <string>


// Generated from Lemur.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LemurParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LemurParser.
 */
class  LemurVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LemurParser.
   */
    virtual antlrcpp::Any visitFile(LemurParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitGlobalstmt(LemurParser::GlobalstmtContext *context) = 0;

    virtual antlrcpp::Any visitClassdef(LemurParser::ClassdefContext *context) = 0;

    virtual antlrcpp::Any visitClassbody(LemurParser::ClassbodyContext *context) = 0;

    virtual antlrcpp::Any visitClassvardecl(LemurParser::ClassvardeclContext *context) = 0;

    virtual antlrcpp::Any visitClassfunctiondef(LemurParser::ClassfunctiondefContext *context) = 0;

    virtual antlrcpp::Any visitFunctiondef(LemurParser::FunctiondefContext *context) = 0;

    virtual antlrcpp::Any visitParamlist(LemurParser::ParamlistContext *context) = 0;

    virtual antlrcpp::Any visitBlock(LemurParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStmt(LemurParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitPrintstmt(LemurParser::PrintstmtContext *context) = 0;

    virtual antlrcpp::Any visitVardecl(LemurParser::VardeclContext *context) = 0;

    virtual antlrcpp::Any visitAssign(LemurParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitDeclassign(LemurParser::DeclassignContext *context) = 0;

    virtual antlrcpp::Any visitRet(LemurParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitWhileloop(LemurParser::WhileloopContext *context) = 0;

    virtual antlrcpp::Any visitForloop(LemurParser::ForloopContext *context) = 0;

    virtual antlrcpp::Any visitIfExpr(LemurParser::IfExprContext *context) = 0;

    virtual antlrcpp::Any visitIfElseExpr(LemurParser::IfElseExprContext *context) = 0;

    virtual antlrcpp::Any visitStringRule(LemurParser::StringRuleContext *context) = 0;

    virtual antlrcpp::Any visitOpExprRule(LemurParser::OpExprRuleContext *context) = 0;

    virtual antlrcpp::Any visitIndexRule(LemurParser::IndexRuleContext *context) = 0;

    virtual antlrcpp::Any visitMethodRule(LemurParser::MethodRuleContext *context) = 0;

    virtual antlrcpp::Any visitListRule(LemurParser::ListRuleContext *context) = 0;

    virtual antlrcpp::Any visitNumberRule(LemurParser::NumberRuleContext *context) = 0;

    virtual antlrcpp::Any visitUminusRule(LemurParser::UminusRuleContext *context) = 0;

    virtual antlrcpp::Any visitCallExprRule(LemurParser::CallExprRuleContext *context) = 0;

    virtual antlrcpp::Any visitVarRule(LemurParser::VarRuleContext *context) = 0;

    virtual antlrcpp::Any visitNegRule(LemurParser::NegRuleContext *context) = 0;

    virtual antlrcpp::Any visitBraceExprRule(LemurParser::BraceExprRuleContext *context) = 0;

    virtual antlrcpp::Any visitList(LemurParser::ListContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall(LemurParser::MethodCallContext *context) = 0;

    virtual antlrcpp::Any visitString(LemurParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitNumber(LemurParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitVar(LemurParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitCallexpr(LemurParser::CallexprContext *context) = 0;

    virtual antlrcpp::Any visitArglist(LemurParser::ArglistContext *context) = 0;

    virtual antlrcpp::Any visitNeg(LemurParser::NegContext *context) = 0;

    virtual antlrcpp::Any visitBinoperator(LemurParser::BinoperatorContext *context) = 0;

    virtual antlrcpp::Any visitBracedexpr(LemurParser::BracedexprContext *context) = 0;


};

