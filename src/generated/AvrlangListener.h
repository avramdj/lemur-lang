
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;


// Generated from Avrlang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AvrlangParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AvrlangParser.
 */
class  AvrlangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(AvrlangParser::FileContext *ctx) = 0;
  virtual void exitFile(AvrlangParser::FileContext *ctx) = 0;

  virtual void enterGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) = 0;
  virtual void exitGlobalstmt(AvrlangParser::GlobalstmtContext *ctx) = 0;

  virtual void enterFunctiondef(AvrlangParser::FunctiondefContext *ctx) = 0;
  virtual void exitFunctiondef(AvrlangParser::FunctiondefContext *ctx) = 0;


};

