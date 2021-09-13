#include <iostream>
#include <string>
#include <antlr4-runtime.h>
#include <LemurLexer.h>
#include <LemurParser.h>
#include <ASTBuilder.h>
#include <ParserErrorListener.h>
#include <context.h>

int main(int argc, char *argv[]) {

    bool printIR = true;
    backend::InitializeContext();
    std::basic_istream<char>* source;
    std::ifstream infile;
    if(argc > 1) {
        infile.open(argv[1]);
        source = &infile;
    } else {
        source = &std::cin;
    }
    std::string str((std::istreambuf_iterator<char>(*source)),
                    std::istreambuf_iterator<char>());

    antlr4::ANTLRInputStream input(str);
    LemurLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    ParserErrorListener errorListner;

    tokens.fill();

    LemurParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListner);
    try {
        antlr4::tree::ParseTree* tree = parser.file();
        ASTBuilder builder;
        builder.visit(tree);
        backend::printModule(printIR, "output.o");
        return 0;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 10;
    }
}