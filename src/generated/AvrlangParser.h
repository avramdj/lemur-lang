
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;


// Generated from Avrlang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AvrlangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, PRINT = 7, 
    OPEN = 8, CLOSED = 9, LEFTBRACE = 10, RIGHTBRACE = 11, RET = 12, WHILE = 13, 
    IF = 14, ELSE = 15, AND = 16, OR = 17, XOR = 18, SHL = 19, SHR = 20, 
    NEG = 21, DEF = 22, GT = 23, GE = 24, LT = 25, LE = 26, EQ = 27, NE = 28, 
    NEWLINE = 29, NAME = 30, NUM = 31, WHITESPACE = 32, COMMENT = 33
  };

  enum {
    RuleFile = 0, RuleGlobalstmt = 1, RuleFunctiondef = 2, RuleParamlist = 3, 
    RuleBlock = 4, RuleStmt = 5, RulePrintstmt = 6, RuleAssign = 7, RuleRet = 8, 
    RuleWhileloop = 9, RuleIf_expr = 10, RuleIfelse_expr = 11, RuleExpr = 12, 
    RuleNumber = 13, RuleVar = 14, RuleCallexpr = 15, RuleArglist = 16, 
    RuleNeg = 17, RuleBinoperator = 18, RuleBracedexpr = 19
  };

  AvrlangParser(antlr4::TokenStream *input);
  ~AvrlangParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class GlobalstmtContext;
  class FunctiondefContext;
  class ParamlistContext;
  class BlockContext;
  class StmtContext;
  class PrintstmtContext;
  class AssignContext;
  class RetContext;
  class WhileloopContext;
  class If_exprContext;
  class Ifelse_exprContext;
  class ExprContext;
  class NumberContext;
  class VarContext;
  class CallexprContext;
  class ArglistContext;
  class NegContext;
  class BinoperatorContext;
  class BracedexprContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<GlobalstmtContext *> globalstmt();
    GlobalstmtContext* globalstmt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  GlobalstmtContext : public antlr4::ParserRuleContext {
  public:
    GlobalstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctiondefContext *functiondef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalstmtContext* globalstmt();

  class  FunctiondefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *fName = nullptr;;
    AvrlangParser::ParamlistContext *params = nullptr;;
    AvrlangParser::BlockContext *body = nullptr;;
    FunctiondefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *OPEN();
    antlr4::tree::TerminalNode *CLOSED();
    antlr4::tree::TerminalNode *NAME();
    ParamlistContext *paramlist();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctiondefContext* functiondef();

  class  ParamlistContext : public antlr4::ParserRuleContext {
  public:
    ParamlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamlistContext* paramlist();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFTBRACE();
    antlr4::tree::TerminalNode *RIGHTBRACE();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignContext *assign();
    RetContext *ret();
    WhileloopContext *whileloop();
    If_exprContext *if_expr();
    Ifelse_exprContext *ifelse_expr();
    ExprContext *expr();
    PrintstmtContext *printstmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  PrintstmtContext : public antlr4::ParserRuleContext {
  public:
    PrintstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    antlr4::tree::TerminalNode *OPEN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrintstmtContext* printstmt();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RET();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetContext* ret();

  class  WhileloopContext : public antlr4::ParserRuleContext {
  public:
    WhileloopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    BracedexprContext *bracedexpr();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileloopContext* whileloop();

  class  If_exprContext : public antlr4::ParserRuleContext {
  public:
    AvrlangParser::BracedexprContext *cond = nullptr;;
    AvrlangParser::BlockContext *then = nullptr;;
    If_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    BracedexprContext *bracedexpr();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_exprContext* if_expr();

  class  Ifelse_exprContext : public antlr4::ParserRuleContext {
  public:
    AvrlangParser::BracedexprContext *cond = nullptr;;
    Ifelse_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    BracedexprContext *bracedexpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ifelse_exprContext* ifelse_expr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OpExprRuleContext : public ExprContext {
  public:
    OpExprRuleContext(ExprContext *ctx);

    AvrlangParser::ExprContext *leftOp = nullptr;
    AvrlangParser::ExprContext *rightOp = nullptr;
    BinoperatorContext *binoperator();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberRuleContext : public ExprContext {
  public:
    NumberRuleContext(ExprContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallExprRuleContext : public ExprContext {
  public:
    CallExprRuleContext(ExprContext *ctx);

    CallexprContext *callexpr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarRuleContext : public ExprContext {
  public:
    VarRuleContext(ExprContext *ctx);

    VarContext *var();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegRuleContext : public ExprContext {
  public:
    NegRuleContext(ExprContext *ctx);

    NegContext *neg();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BraceExprRuleContext : public ExprContext {
  public:
    BraceExprRuleContext(ExprContext *ctx);

    BracedexprContext *bracedexpr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarContext* var();

  class  CallexprContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *fName = nullptr;;
    AvrlangParser::ArglistContext *args = nullptr;;
    CallexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN();
    antlr4::tree::TerminalNode *CLOSED();
    antlr4::tree::TerminalNode *NAME();
    ArglistContext *arglist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallexprContext* callexpr();

  class  ArglistContext : public antlr4::ParserRuleContext {
  public:
    ArglistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArglistContext* arglist();

  class  NegContext : public antlr4::ParserRuleContext {
  public:
    NegContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEG();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NegContext* neg();

  class  BinoperatorContext : public antlr4::ParserRuleContext {
  public:
    BinoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHL();
    antlr4::tree::TerminalNode *SHR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinoperatorContext* binoperator();

  class  BracedexprContext : public antlr4::ParserRuleContext {
  public:
    BracedexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BracedexprContext* bracedexpr();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};
