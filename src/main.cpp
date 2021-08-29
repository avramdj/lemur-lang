#include <iostream>
#include <strstream>
#include <string>
#include <antlr4-runtime.h>
#include <AvrlangLexer.h>
#include <AvrlangParser.h>
#include <ast.hpp>

class MyParserErrorListener: public antlr4::BaseErrorListener {
    virtual void syntaxError(
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

int main(int argc, char *argv[]) {
    InitializeModuleAndPassManager();
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
    // Only if you want to list the tokens
    // for (auto token : tokens.getTokens()) {
    //  std::cout << token->toString() << std::endl;
    // }

    AvrlangParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListner);
    try {
        antlr4::tree::ParseTree* tree = parser.file();
        return 0;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 10;
    }
}