#include <LemurLexer.h>
#include <LemurParser.h>
#include <antlr4-runtime.h>
#include <ast_builder.h>
#include <context.h>
#include <parser_error_listener.h>

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  bool printIR = true;
  std::string outPath = "output.o";
  backend::InitializeContext();
  std::basic_istream<char>* source;
  std::ifstream infile;
  if (argc > 1) {
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
  tokens.fill();

  LemurParser parser(&tokens);
  parser.removeErrorListeners();
  ParserErrorListener errorListener;
  parser.addErrorListener(&errorListener);
  try {
    antlr4::tree::ParseTree* tree = parser.file();
    ASTBuilder builder;
    builder.visit(tree);
    backend::printModule(outPath, printIR);
    return 0;
  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
    return 10;
  }
}