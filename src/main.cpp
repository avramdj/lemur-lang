#include <antlr4-runtime.h>

#include <iostream>
#include <string>

#include "LemurLexer.h"
#include "LemurParser.h"
#include "ast_builder.h"
#include "ast_core.h"
#include "context.h"
#include "logger.h"
#include "parser_error_listener.h"

int main(int argc, char* argv[]) {
  bool printIR = true;
  std::string outPath = "output.o";
  backend::InitializeContext();
  std::basic_istream<char>* source;
  std::ifstream infile;
  if (argc > 1) {
    infile.open(argv[argc - 1]);
    source = &infile;
  } else {
    source = &std::cin;
  }
  backend::log::logLevel = backend::log::lWarn;
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
    std::shared_ptr<backend::FileAST> root = builder.visit(tree);
    bool isSuccess = backend::compile(root);
    if (isSuccess) {
      backend::printModule(outPath, printIR);
    } else {
      exit(-1);
    }
    return 0;
  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
    return 10;
  }
}