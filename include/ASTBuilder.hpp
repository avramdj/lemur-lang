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

    antlrcpp::Any visitVardecl(AvrlangParser::VardeclContext *ctx) override;

    antlrcpp::Any visitDeclassign(AvrlangParser::DeclassignContext *ctx) override;

    antlrcpp::Any visitStringRule(AvrlangParser::StringRuleContext *ctx) override;

    antlrcpp::Any visitRet(AvrlangParser::RetContext *ctx) override;

    antlrcpp::Any visitClassdef(AvrlangParser::ClassdefContext *ctx) override;

    antlrcpp::Any visitClassbody(AvrlangParser::ClassbodyContext *ctx) override;

    antlrcpp::Any visitWhileloop(AvrlangParser::WhileloopContext *ctx) override;

    antlrcpp::Any visitNumberRule(AvrlangParser::NumberRuleContext *ctx) override;

    antlrcpp::Any visitVarRule(AvrlangParser::VarRuleContext *ctx) override;

    antlrcpp::Any visitIfExpr(AvrlangParser::IfExprContext *ctx) override;

    antlrcpp::Any visitIfElseExpr(AvrlangParser::IfElseExprContext *ctx) override;

    antlrcpp::Any visitCallExprRule(AvrlangParser::CallExprRuleContext *ctx) override;

    antlrcpp::Any visitArglist(AvrlangParser::ArglistContext *ctx) override;

    antlrcpp::Any visitNegRule(AvrlangParser::NegRuleContext *ctx) override;

    antlrcpp::Any visitOpExprRule(AvrlangParser::OpExprRuleContext *ctx) override;

    antlrcpp::Any visitPrintstmt(AvrlangParser::PrintstmtContext *ctx) override;

    antlrcpp::Any visitBinoperator(AvrlangParser::BinoperatorContext *ctx) override;

    antlrcpp::Any visitBraceExprRule(AvrlangParser::BraceExprRuleContext *ctx) override;

};