#include <iostream>
#include <memory>
#include <strstream>
#include <string>
#include <antlr4-runtime.h>
#include <AvrlangLexer.h>
#include <AvrlangParser.h>
#include <AvrlangBaseVisitor.h>
#include <ast.hpp>

class MyParserErrorListener: public antlr4::BaseErrorListener {
    void syntaxError(
            antlr4::Recognizer *recognizer,
            antlr4::Token *offendingSymbol,
            size_t line,
            size_t charPositionInLine,
            const std::string &msg,
            std::exception_ptr e) override {
        std::ostrstream s;
        s << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")";
        throw std::invalid_argument(s.str());
    }
};

class AvrlangASTBuilder: public AvrlangBaseVisitor {
    antlrcpp::Any visitFile(AvrlangParser::FileContext *ctx) override {
        return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
    }
    antlrcpp::Any visitGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) override {
        return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
    }
    antlrcpp::Any visitFunctiondef(AvrlangParser::FunctiondefContext *ctx) override {
        std::string functionName = ctx->fName->getText();
        std::vector<string> paramList = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->params);
        shared_ptr<backend::ExprAST> functionBody = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->body);
        auto *f = new backend::FunctionDefintionAST(functionName, paramList, functionBody);
        f->codegen();
        return f;
    }
    antlrcpp::Any visitParamlist(AvrlangParser::ParamlistContext *ctx) override {
        std::vector<string> params;
        for(auto& param : ctx->NAME()) {
            params.push_back(param->getText());
        }
        return params;
    }
    antlrcpp::Any visitBlock(AvrlangParser::BlockContext *ctx) override {
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
    antlrcpp::Any visitStmt(AvrlangParser::StmtContext *ctx) override {
        return antlr4::tree::AbstractParseTreeVisitor::visitChildren(ctx);
    }
    antlrcpp::Any visitAssign(AvrlangParser::AssignContext *ctx) override {
        std::string varName = ctx->NAME()->getText();
        shared_ptr<backend::ExprAST> expr =
                antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
        return std::shared_ptr<backend::ExprAST>(
                new backend::SetExprAST(expr, varName)
        );
    }
    antlrcpp::Any visitRet(AvrlangParser::RetContext *ctx) override {
        shared_ptr<backend::ExprAST> ret =
                antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
        return std::shared_ptr<backend::ExprAST>(
                new backend::RetExprAST(ret)
        );
    }
    antlrcpp::Any visitWhileloop(AvrlangParser::WhileloopContext *ctx) override {
        shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->bracedexpr());
        shared_ptr<backend::ExprAST> block = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
        return new backend::WhileExprAST(cond, block);
    }
    antlrcpp::Any visitNumber(AvrlangParser::NumberContext *ctx) override {
        return std::shared_ptr<backend::ExprAST>(
                new backend::NumberExprAST(std::stoi(ctx->NUM()->getText()))
        );
    }

    antlrcpp::Any visitVar(AvrlangParser::VarContext *ctx) override {
        return std::make_shared<backend::VariableExprAST>(
                ctx->NAME()->getText()
        );
    }

    antlrcpp::Any visitIf_expr(AvrlangParser::If_exprContext *ctx) override {
        std::shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->IF());
        std::shared_ptr<backend::ExprAST> block = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
        return std::shared_ptr<backend::ExprAST>(new backend::IfExprAST(cond, block));
    }
    antlrcpp::Any visitIfelse_expr(AvrlangParser::Ifelse_exprContext *ctx) override {
        shared_ptr<backend::ExprAST> cond = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->IF());
        shared_ptr<backend::ExprAST> thenBlock = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(0));
        shared_ptr<backend::ExprAST> elseBlock = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block().at(1));
        return shared_ptr<backend::ExprAST>(
                new backend::IfElseExprAST(cond, thenBlock, elseBlock)
        );
    }

    antlrcpp::Any visitCallexpr(AvrlangParser::CallexprContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitArglist(AvrlangParser::ArglistContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitNeg(AvrlangParser::NegContext *ctx) override {
        shared_ptr<backend::ExprAST> expr = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
        return std::shared_ptr<backend::ExprAST>(new backend::NotExprAST(expr));
    }

//    antlrcpp::Any visitBinoperator(AvrlangParser::BinoperatorContext *ctx) override {
//        return visitChildren(ctx);
//    }

    antlrcpp::Any visitBracedexpr(AvrlangParser::BracedexprContext *ctx) override {
        return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    }
};

int main(int argc, char *argv[]) {

    backend::InitializeModuleAndPassManager();
    std::basic_istream<char>* source;
    std::ifstream infile;
    if(argc > 1) {
        infile.open(argv[1]);
        source = &infile;
    } else {
        source = &cin;
    }
    std::string str((std::istreambuf_iterator<char>(*source)),
                    std::istreambuf_iterator<char>());

    antlr4::ANTLRInputStream input(str);
    AvrlangLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    MyParserErrorListener errorListner;

    tokens.fill();

    AvrlangParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListner);
    try {
        antlr4::tree::ParseTree* tree = parser.file();
        AvrlangASTBuilder ASTBuilder;
        ASTBuilder.visit(tree);
        backend::printModule();
        return 0;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 10;
    }
}