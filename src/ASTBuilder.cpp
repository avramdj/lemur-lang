//
// Created by avram on 30.8.21..
//

#include <ASTBuilder.hpp>
#include <ast.hpp>

antlrcpp::Any ASTBuilder::visitFile(AvrlangParser::FileContext *ctx) {
    return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) {
    return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitFunctiondef(AvrlangParser::FunctiondefContext *ctx) {
    std::string functionName = ctx->fName->getText();
    std::vector<string> paramList = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->params);
    shared_ptr<backend::ExprAST> functionBody = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->body);
    auto *f = new backend::FunctionDefintionAST(functionName, paramList, functionBody);
    f->codegen();
    return f;
}
antlrcpp::Any ASTBuilder::visitParamlist(AvrlangParser::ParamlistContext *ctx) {
    std::vector<string> params;
    for(auto& param : ctx->NAME()) {
        params.push_back(param->getText());
    }
    return params;
}
antlrcpp::Any ASTBuilder::visitBlock(AvrlangParser::BlockContext *ctx) {
    std::vector<shared_ptr<backend::ExprAST>> stmtVector;
    for(auto& stmt : ctx->stmt()) {
        shared_ptr<backend::ExprAST> stmtAST =
                antlr4::tree::AbstractParseTreeVisitor::visit(stmt);
        stmtVector.push_back(stmtAST);
    }
    return std::shared_ptr<backend::ExprAST>(
            new backend::SeqExprAST(stmtVector)
    );
}
antlrcpp::Any ASTBuilder::visitStmt(AvrlangParser::StmtContext *ctx) {
    return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitAssign(AvrlangParser::AssignContext *ctx) {
    std::string varName = ctx->NAME()->getText();
    shared_ptr<backend::ExprAST> expr =
            antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(
            new backend::SetExprAST(expr, varName)
    );
}
antlrcpp::Any ASTBuilder::visitRet(AvrlangParser::RetContext *ctx) {
    shared_ptr<backend::ExprAST> ret =
            antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(
            new backend::RetExprAST(ret)
    );
}
antlrcpp::Any ASTBuilder::visitWhileloop(AvrlangParser::WhileloopContext *ctx) {
    shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->bracedexpr()->expr());
    shared_ptr<backend::ExprAST> block = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
    return shared_ptr<backend::ExprAST>(new backend::WhileExprAST(cond, block));
}
antlrcpp::Any ASTBuilder::visitNumberRule(AvrlangParser::NumberRuleContext *ctx) {
    return std::shared_ptr<backend::ExprAST>(
            new backend::NumberExprAST(std::stoi(ctx->number()->NUM()->getText()))
    );
}

antlrcpp::Any ASTBuilder::visitVarRule(AvrlangParser::VarRuleContext *ctx) {
    return std::shared_ptr<backend::ExprAST>(
            new backend::VariableExprAST(ctx->var()->NAME()->getText())
    );
}

antlrcpp::Any ASTBuilder::visitIf_expr(AvrlangParser::If_exprContext *ctx) {
    std::shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond->expr());
    std::shared_ptr<backend::ExprAST> block = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
    return std::shared_ptr<backend::ExprAST>(new backend::IfExprAST(cond, block));
}
antlrcpp::Any ASTBuilder::visitIfelse_expr(AvrlangParser::Ifelse_exprContext *ctx) {
    shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond->expr());
    shared_ptr<backend::ExprAST> thenBlock = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(0));
    shared_ptr<backend::ExprAST> elseBlock = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(1));
    return shared_ptr<backend::ExprAST>(
            new backend::IfElseExprAST(cond, thenBlock, elseBlock)
    );
}

antlrcpp::Any ASTBuilder::visitCallExprRule(AvrlangParser::CallExprRuleContext *ctx) {
    std::string name = ctx->callexpr()->fName->getText();
    std::vector<std::shared_ptr<backend::ExprAST>> args;
    for(auto p : ctx->callexpr()->arglist()->expr()){
        shared_ptr<backend::ExprAST> e = antlr4::tree::AbstractParseTreeVisitor::visit(p);
        args.push_back(e);
    }
    return shared_ptr<backend::ExprAST>(
            new backend::CallExprAST(name, args)
    );
}

antlrcpp::Any ASTBuilder::visitArglist(AvrlangParser::ArglistContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitNegRule(AvrlangParser::NegRuleContext *ctx) {
    shared_ptr<backend::ExprAST> expr = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->neg()->expr());
    return std::shared_ptr<backend::ExprAST>(new backend::NotExprAST(expr));
}
antlrcpp::Any ASTBuilder::visitOpExprRule(AvrlangParser::OpExprRuleContext *ctx) {
    std::string op = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->binoperator());
    shared_ptr<backend::ExprAST> LHS = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->leftOp);
    shared_ptr<backend::ExprAST> RHS = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->rightOp);
    backend::ExprAST* binop = nullptr;
    if(op == "and") {
        binop = new backend::AndExprAST(LHS, RHS);
    } else if (op == "or") {
        binop = new backend::OrExprAST(LHS, RHS);
    } else if (op == "xor") {
        binop = new backend::XorExprAST(LHS, RHS);
    } else if (op == "+") {
        binop = new backend::AddExprAST(LHS, RHS);
    } else if (op == "-") {
        binop = new backend::SubExprAST(LHS, RHS);
    } else if (op == "*") {
        binop = new backend::MulExprAST(LHS, RHS);
    } else if (op == "/") {
        binop = new backend::DivExprAST(LHS, RHS);
    } else if (op == "==") {
        binop = new backend::EqExprAST(LHS, RHS);
    } else if (op == "!=") {
        binop = new backend::NeqExprAST(LHS, RHS);
    } else if (op == "<") {
        binop = new backend::LtExprAST(LHS, RHS);
    } else if (op == "<=") {
        binop = new backend::LteExprAST(LHS, RHS);
    } else if (op == ">") {
        binop = new backend::GtExprAST(LHS, RHS);
    } else if (op == ">=") {
        binop = new backend::GteExprAST(LHS, RHS);
    } else if (op == "<<") {
        binop = new backend::ShlExprAST(LHS, RHS);
    } else if (op == ">>") {
        binop = new backend::ShrExprAST(LHS, RHS);
    }
    return shared_ptr<backend::ExprAST>(binop);
}

antlrcpp::Any ASTBuilder::visitPrintstmt(AvrlangParser::PrintstmtContext *ctx) {
    shared_ptr<backend::ExprAST> expr = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(new backend::PrintExprAST(expr));
}

antlrcpp::Any ASTBuilder::visitBinoperator(AvrlangParser::BinoperatorContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any ASTBuilder::visitBraceExprRule(AvrlangParser::BraceExprRuleContext *ctx) {
    return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->bracedexpr()->expr());
}