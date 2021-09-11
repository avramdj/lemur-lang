//
// Created by avram on 30.8.21..
//

#include <ASTBuilder.hpp>
#include <ast.hpp>
#include <context.h>
#include <ASTUtil.h>

antlrcpp::Any ASTBuilder::visitFile(AvrlangParser::FileContext *ctx) {
    return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) {
    return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
}
antlrcpp::Any ASTBuilder::visitFunctiondef(AvrlangParser::FunctiondefContext *ctx) {
    std::string functionName = ctx->fName->getText();
    std::pair<std::vector<std::string>, std::vector<std::string>> fparams = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->params);
    auto types = fparams.first;
    auto params = fparams.second;
    std::string ret = ctx->retType->getText();
    std::shared_ptr<backend::ExprAST> functionBody = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->body);
    auto *f = new backend::FunctionDefintionAST(functionName, types, params, ret, functionBody);
    f->codegen();
    return f;
}
antlrcpp::Any ASTBuilder::visitParamlist(AvrlangParser::ParamlistContext *ctx) {
    std::vector<std::string> types;
    std::vector<std::string> params;
    for(auto& type : ctx->types) {
        types.push_back(type);
    }
    for(auto& param : ctx->vars) {
        params.push_back(param);
    }
    return std::make_pair(types, params);
}
antlrcpp::Any ASTBuilder::visitBlock(AvrlangParser::BlockContext *ctx) {
    std::vector<std::shared_ptr<backend::ExprAST>> stmtVector;
    for(auto& stmt : ctx->stmt()) {
        std::shared_ptr<backend::ExprAST> stmtAST =
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
    std::shared_ptr<backend::ExprAST> expr =
            antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(
            new backend::SetExprAST(expr, varName)
    );
}
antlrcpp::Any ASTBuilder::visitRet(AvrlangParser::RetContext *ctx) {
    std::shared_ptr<backend::ExprAST> ret =
            antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(
            new backend::RetExprAST(ret)
    );
}
antlrcpp::Any ASTBuilder::visitWhileloop(AvrlangParser::WhileloopContext *ctx) {
    std::shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->bracedexpr()->expr());
    std::shared_ptr<backend::ExprAST> block = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
    return std::shared_ptr<backend::ExprAST>(new backend::WhileExprAST(cond, block));
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

antlrcpp::Any ASTBuilder::visitIfExpr(AvrlangParser::IfExprContext *ctx) {
    std::shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond->expr());
    std::shared_ptr<backend::ExprAST> block = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
    return std::shared_ptr<backend::ExprAST>(new backend::IfExprAST(cond, block));
}
antlrcpp::Any ASTBuilder::visitIfElseExpr(AvrlangParser::IfElseExprContext *ctx) {
    std::shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond->expr());
    std::shared_ptr<backend::ExprAST> thenBlock = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(0));
    std::shared_ptr<backend::ExprAST> elseBlock = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(1));
    return std::shared_ptr<backend::ExprAST>(
            new backend::IfElseExprAST(cond, thenBlock, elseBlock)
    );
}

antlrcpp::Any ASTBuilder::visitCallExprRule(AvrlangParser::CallExprRuleContext *ctx) {
    std::string name = ctx->callexpr()->fName->getText();
    std::vector<std::shared_ptr<backend::ExprAST>> args;
    for(auto p : ctx->callexpr()->arglist()->expr()){
        std::shared_ptr<backend::ExprAST> e = antlr4::tree::AbstractParseTreeVisitor::visit(p);
        args.push_back(e);
    }
    return std::shared_ptr<backend::ExprAST>(
            new backend::CallExprAST(name, args)
    );
}

antlrcpp::Any ASTBuilder::visitArglist(AvrlangParser::ArglistContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitNegRule(AvrlangParser::NegRuleContext *ctx) {
    std::shared_ptr<backend::ExprAST> expr = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->neg()->expr());
    return std::shared_ptr<backend::ExprAST>(new backend::NotExprAST(expr));
}
antlrcpp::Any ASTBuilder::visitOpExprRule(AvrlangParser::OpExprRuleContext *ctx) {
    std::string op = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->binoperator());
    std::shared_ptr<backend::ExprAST> LHS = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->leftOp);
    std::shared_ptr<backend::ExprAST> RHS = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->rightOp);
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
    return std::shared_ptr<backend::ExprAST>(binop);
}

antlrcpp::Any ASTBuilder::visitPrintstmt(AvrlangParser::PrintstmtContext *ctx) {
    std::shared_ptr<backend::ExprAST> expr = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(new backend::PrintExprAST(expr));
}

antlrcpp::Any ASTBuilder::visitBinoperator(AvrlangParser::BinoperatorContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any ASTBuilder::visitBraceExprRule(AvrlangParser::BraceExprRuleContext *ctx) {
    return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->bracedexpr()->expr());
}

antlrcpp::Any ASTBuilder::visitVardecl(AvrlangParser::VardeclContext *ctx) {
    std::string type = ctx->typeName->getText();
    std::string name = ctx->varName->getText();
    return std::shared_ptr<backend::ExprAST>(new backend::VarDeclExprAST(type, name));
}

antlrcpp::Any ASTBuilder::visitDeclassign(AvrlangParser::DeclassignContext *ctx) {
    std::string type = ctx->typeName->getText();
    std::string name = ctx->varName->getText();
    std::shared_ptr<backend::ExprAST> expr = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    return std::shared_ptr<backend::ExprAST>(new backend::DeclAssignExprAST(type, name, expr));
}

antlrcpp::Any ASTBuilder::visitStringRule(AvrlangParser::StringRuleContext *ctx) {
    std::string str = ctx->getText();
    str = formatRawStr(str);
    return std::shared_ptr<backend::ExprAST>(new backend::StringExprAST(str));
}

antlrcpp::Any ASTBuilder::visitClassdef(AvrlangParser::ClassdefContext *ctx) {
    std::vector<std::string> vartypes;
    std::vector<std::string> varnames;
    std::string Name = ctx->cName->getText();
    std::string BaseName = ctx->baseName ? ctx->baseName->getText() : std::string("");
    for(auto& t : ctx->classbody()->classvardecl()) {
        vartypes.push_back(t->typeName->getText());
        varnames.push_back(t->varName->getText());
    }

    std::vector<backend::FunctionDefintionAST*> functions;

    for(auto& fn : ctx->classbody()->classfunctiondef()){
        std::string functionName = backend::encodeFunctionName(fn->fName->getText(), ctx->cName->getText());
        std::pair<std::vector<std::string>, std::vector<std::string>> fparams = antlr4::tree::AbstractParseTreeVisitor::visit(fn->params);
        auto types = fparams.first;
//        types.insert(types.begin(), 0, ctx->cName->getText());
        std::vector<std::string> typesext;
        typesext.push_back(ctx->cName->getText());
        for(auto& t : types) {
            typesext.push_back(t);
        }
        auto params = fparams.second;
        std::vector<std::string> paramsext;
        paramsext.emplace_back("this");
        for(auto& p : params) {
            paramsext.push_back(p);
        }
//        params.insert(params.begin(), 0, std::string("this"));

        std::string ret = fn->retType->getText();
        std::shared_ptr<backend::ExprAST> functionBody = antlr4::tree::AbstractParseTreeVisitor::visit(fn->body);
        auto *f = new backend::FunctionDefintionAST(functionName, typesext, paramsext, ret, functionBody);
        functions.push_back(f);
    }

    auto cls = new backend::ClassDefExprAST(Name, BaseName, vartypes, varnames, functions);
    cls->codegen();
    return std::shared_ptr<backend::ExprAST>(cls);
}

antlrcpp::Any ASTBuilder::visitClassbody(AvrlangParser::ClassbodyContext *ctx) {
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitMethodCall(AvrlangParser::MethodCallContext *ctx) {
    std::string var = ctx->varName->getText();
    std::string method = ctx->methodName->getText();
    std::vector<std::shared_ptr<backend::ExprAST>> args;
    for(auto p : ctx->arglist()->expr()){
        std::shared_ptr<backend::ExprAST> e = antlr4::tree::AbstractParseTreeVisitor::visit(p);
        args.push_back(e);
    }
    return std::shared_ptr<backend::ExprAST>(
            new backend::MethodCallExprAST(var, method, args)
    );
}

antlrcpp::Any ASTBuilder::visitObjVar(AvrlangParser::ObjVarContext *ctx) {
    std::string var = ctx->varName->getText();
    std::string subvar = ctx->varName->getText();
    return std::shared_ptr<backend::ExprAST>(
            new backend::ClassAccessExprAST(var, subvar)
    );
}
