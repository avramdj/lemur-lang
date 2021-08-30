//
// Created by avram on 30.8.21..
//

#include <AvrlangBaseVisitor.h>

class ASTBuilder: public AvrlangBaseVisitor {
    antlrcpp::Any visitFile(AvrlangParser::FileContext *ctx) override;

    antlrcpp::Any visitGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) override;

    antlrcpp::Any visitFunctiondef(AvrlangParser::FunctiondefContext *ctx) override;

    antlrcpp::Any visitParamlist(AvrlangParser::ParamlistContext *ctx) override;

    antlrcpp::Any visitBlock(AvrlangParser::BlockContext *ctx) override;

    antlrcpp::Any visitStmt(AvrlangParser::StmtContext *ctx) override;

    antlrcpp::Any visitAssign(AvrlangParser::AssignContext *ctx) override;

    antlrcpp::Any visitRet(AvrlangParser::RetContext *ctx) override;

    antlrcpp::Any visitWhileloop(AvrlangParser::WhileloopContext *ctx) override;

    antlrcpp::Any visitNumberRule(AvrlangParser::NumberRuleContext *ctx) override;

    antlrcpp::Any visitVarRule(AvrlangParser::VarRuleContext *ctx) override;

    antlrcpp::Any visitIf_expr(AvrlangParser::If_exprContext *ctx) override;

    antlrcpp::Any visitIfelse_expr(AvrlangParser::Ifelse_exprContext *ctx) override;

    antlrcpp::Any visitCallExprRule(AvrlangParser::CallExprRuleContext *ctx) override;

    antlrcpp::Any visitArglist(AvrlangParser::ArglistContext *ctx) override;

    antlrcpp::Any visitNegRule(AvrlangParser::NegRuleContext *ctx) override;

    antlrcpp::Any visitOpExprRule(AvrlangParser::OpExprRuleContext *ctx) override;

    antlrcpp::Any visitPrintstmt(AvrlangParser::PrintstmtContext *ctx) override;

    antlrcpp::Any visitBinoperator(AvrlangParser::BinoperatorContext *ctx) override;

    antlrcpp::Any visitBraceExprRule(AvrlangParser::BraceExprRuleContext *ctx) override;

};