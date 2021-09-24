//
// Created by avram on 30.8.21..
//

#include <LemurBaseVisitor.h>

class ASTBuilder : public LemurBaseVisitor {
  antlrcpp::Any visitFile(LemurParser::FileContext *ctx) override;
  antlrcpp::Any visitGlobalstmt(LemurParser::GlobalstmtContext *ctx) override;
  antlrcpp::Any visitFunctiondef(LemurParser::FunctiondefContext *ctx) override;
  antlrcpp::Any visitParamlist(LemurParser::ParamlistContext *ctx) override;
  antlrcpp::Any visitBlock(LemurParser::BlockContext *ctx) override;
  antlrcpp::Any visitStmt(LemurParser::StmtContext *ctx) override;
  antlrcpp::Any visitAssign(LemurParser::AssignContext *ctx) override;
  antlrcpp::Any visitVardecl(LemurParser::VardeclContext *ctx) override;
  antlrcpp::Any visitDeclassign(LemurParser::DeclassignContext *ctx) override;
  antlrcpp::Any visitStringRule(LemurParser::StringRuleContext *ctx) override;
  antlrcpp::Any visitRet(LemurParser::RetContext *ctx) override;
  antlrcpp::Any visitClassdef(LemurParser::ClassdefContext *ctx) override;
  antlrcpp::Any visitClassbody(LemurParser::ClassbodyContext *ctx) override;
  antlrcpp::Any visitWhileloop(LemurParser::WhileloopContext *ctx) override;
  antlrcpp::Any visitNumberRule(LemurParser::NumberRuleContext *ctx) override;
  antlrcpp::Any visitVarRule(LemurParser::VarRuleContext *ctx) override;
  antlrcpp::Any visitMethodCall(LemurParser::MethodCallContext *ctx) override;
  antlrcpp::Any visitIfExpr(LemurParser::IfExprContext *ctx) override;
  antlrcpp::Any visitIfElseExpr(LemurParser::IfElseExprContext *ctx) override;
  antlrcpp::Any visitCallExprRule(
      LemurParser::CallExprRuleContext *ctx) override;
  antlrcpp::Any visitArglist(LemurParser::ArglistContext *ctx) override;
  antlrcpp::Any visitNegRule(LemurParser::NegRuleContext *ctx) override;
  antlrcpp::Any visitOpExprRule(LemurParser::OpExprRuleContext *ctx) override;
  antlrcpp::Any visitPrintstmt(LemurParser::PrintstmtContext *ctx) override;
  antlrcpp::Any visitBinoperator(LemurParser::BinoperatorContext *ctx) override;
  antlrcpp::Any visitBraceExprRule(
      LemurParser::BraceExprRuleContext *ctx) override;
};