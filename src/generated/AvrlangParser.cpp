
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;


// Generated from Avrlang.g4 by ANTLR 4.7.2


#include "AvrlangListener.h"
#include "AvrlangVisitor.h"

#include "AvrlangParser.h"


using namespace antlrcpp;
using namespace antlr4;

AvrlangParser::AvrlangParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AvrlangParser::~AvrlangParser() {
  delete _interpreter;
}

std::string AvrlangParser::getGrammarFileName() const {
  return "Avrlang.g4";
}

const std::vector<std::string>& AvrlangParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AvrlangParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

AvrlangParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::FileContext::EOF() {
  return getToken(AvrlangParser::EOF, 0);
}

std::vector<AvrlangParser::GlobalstmtContext *> AvrlangParser::FileContext::globalstmt() {
  return getRuleContexts<AvrlangParser::GlobalstmtContext>();
}

AvrlangParser::GlobalstmtContext* AvrlangParser::FileContext::globalstmt(size_t i) {
  return getRuleContext<AvrlangParser::GlobalstmtContext>(i);
}

std::vector<tree::TerminalNode *> AvrlangParser::FileContext::NEWLINE() {
  return getTokens(AvrlangParser::NEWLINE);
}

tree::TerminalNode* AvrlangParser::FileContext::NEWLINE(size_t i) {
  return getToken(AvrlangParser::NEWLINE, i);
}


size_t AvrlangParser::FileContext::getRuleIndex() const {
  return AvrlangParser::RuleFile;
}

void AvrlangParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void AvrlangParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any AvrlangParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::FileContext* AvrlangParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, AvrlangParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AvrlangParser::DEF

    || _la == AvrlangParser::NEWLINE) {
      setState(40);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AvrlangParser::DEF: {
          setState(38);
          globalstmt();
          break;
        }

        case AvrlangParser::NEWLINE: {
          setState(39);
          match(AvrlangParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(45);
    match(AvrlangParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalstmtContext ------------------------------------------------------------------

AvrlangParser::GlobalstmtContext::GlobalstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AvrlangParser::FunctiondefContext* AvrlangParser::GlobalstmtContext::functiondef() {
  return getRuleContext<AvrlangParser::FunctiondefContext>(0);
}


size_t AvrlangParser::GlobalstmtContext::getRuleIndex() const {
  return AvrlangParser::RuleGlobalstmt;
}

void AvrlangParser::GlobalstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalstmt(this);
}

void AvrlangParser::GlobalstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalstmt(this);
}


antlrcpp::Any AvrlangParser::GlobalstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitGlobalstmt(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::GlobalstmtContext* AvrlangParser::globalstmt() {
  GlobalstmtContext *_localctx = _tracker.createInstance<GlobalstmtContext>(_ctx, getState());
  enterRule(_localctx, 2, AvrlangParser::RuleGlobalstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    functiondef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctiondefContext ------------------------------------------------------------------

AvrlangParser::FunctiondefContext::FunctiondefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::FunctiondefContext::DEF() {
  return getToken(AvrlangParser::DEF, 0);
}

tree::TerminalNode* AvrlangParser::FunctiondefContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

tree::TerminalNode* AvrlangParser::FunctiondefContext::CLOSED() {
  return getToken(AvrlangParser::CLOSED, 0);
}

tree::TerminalNode* AvrlangParser::FunctiondefContext::NAME() {
  return getToken(AvrlangParser::NAME, 0);
}

AvrlangParser::ParamlistContext* AvrlangParser::FunctiondefContext::paramlist() {
  return getRuleContext<AvrlangParser::ParamlistContext>(0);
}

AvrlangParser::BlockContext* AvrlangParser::FunctiondefContext::block() {
  return getRuleContext<AvrlangParser::BlockContext>(0);
}


size_t AvrlangParser::FunctiondefContext::getRuleIndex() const {
  return AvrlangParser::RuleFunctiondef;
}

void AvrlangParser::FunctiondefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctiondef(this);
}

void AvrlangParser::FunctiondefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctiondef(this);
}


antlrcpp::Any AvrlangParser::FunctiondefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitFunctiondef(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::FunctiondefContext* AvrlangParser::functiondef() {
  FunctiondefContext *_localctx = _tracker.createInstance<FunctiondefContext>(_ctx, getState());
  enterRule(_localctx, 4, AvrlangParser::RuleFunctiondef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(AvrlangParser::DEF);
    setState(50);
    dynamic_cast<FunctiondefContext *>(_localctx)->fName = match(AvrlangParser::NAME);
    setState(51);
    match(AvrlangParser::OPEN);
    setState(52);
    dynamic_cast<FunctiondefContext *>(_localctx)->params = paramlist();
    setState(53);
    match(AvrlangParser::CLOSED);
    setState(54);
    dynamic_cast<FunctiondefContext *>(_localctx)->body = block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamlistContext ------------------------------------------------------------------

AvrlangParser::ParamlistContext::ParamlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AvrlangParser::ParamlistContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::ParamlistContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
}


size_t AvrlangParser::ParamlistContext::getRuleIndex() const {
  return AvrlangParser::RuleParamlist;
}

void AvrlangParser::ParamlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamlist(this);
}

void AvrlangParser::ParamlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamlist(this);
}


antlrcpp::Any AvrlangParser::ParamlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitParamlist(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ParamlistContext* AvrlangParser::paramlist() {
  ParamlistContext *_localctx = _tracker.createInstance<ParamlistContext>(_ctx, getState());
  enterRule(_localctx, 6, AvrlangParser::RuleParamlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AvrlangParser::NAME) {
      setState(56);
      match(AvrlangParser::NAME);
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AvrlangParser::T__0) {
        setState(57);
        match(AvrlangParser::T__0);
        setState(58);
        match(AvrlangParser::NAME);
        setState(63);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

AvrlangParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::BlockContext::LEFTBRACE() {
  return getToken(AvrlangParser::LEFTBRACE, 0);
}

tree::TerminalNode* AvrlangParser::BlockContext::RIGHTBRACE() {
  return getToken(AvrlangParser::RIGHTBRACE, 0);
}

std::vector<tree::TerminalNode *> AvrlangParser::BlockContext::NEWLINE() {
  return getTokens(AvrlangParser::NEWLINE);
}

tree::TerminalNode* AvrlangParser::BlockContext::NEWLINE(size_t i) {
  return getToken(AvrlangParser::NEWLINE, i);
}

std::vector<AvrlangParser::StmtContext *> AvrlangParser::BlockContext::stmt() {
  return getRuleContexts<AvrlangParser::StmtContext>();
}

AvrlangParser::StmtContext* AvrlangParser::BlockContext::stmt(size_t i) {
  return getRuleContext<AvrlangParser::StmtContext>(i);
}


size_t AvrlangParser::BlockContext::getRuleIndex() const {
  return AvrlangParser::RuleBlock;
}

void AvrlangParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void AvrlangParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any AvrlangParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::BlockContext* AvrlangParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, AvrlangParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(AvrlangParser::LEFTBRACE);
    setState(71); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(71);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AvrlangParser::OPEN:
        case AvrlangParser::RET:
        case AvrlangParser::WHILE:
        case AvrlangParser::IF:
        case AvrlangParser::NEG:
        case AvrlangParser::NAME:
        case AvrlangParser::NUM: {
          setState(67);
          stmt();
          setState(68);
          match(AvrlangParser::NEWLINE);
          break;
        }

        case AvrlangParser::NEWLINE: {
          setState(70);
          match(AvrlangParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(73); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::RET)
      | (1ULL << AvrlangParser::WHILE)
      | (1ULL << AvrlangParser::IF)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NEWLINE)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::NUM))) != 0));
    setState(75);
    match(AvrlangParser::RIGHTBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

AvrlangParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AvrlangParser::AssignContext* AvrlangParser::StmtContext::assign() {
  return getRuleContext<AvrlangParser::AssignContext>(0);
}

AvrlangParser::RetContext* AvrlangParser::StmtContext::ret() {
  return getRuleContext<AvrlangParser::RetContext>(0);
}

AvrlangParser::WhileloopContext* AvrlangParser::StmtContext::whileloop() {
  return getRuleContext<AvrlangParser::WhileloopContext>(0);
}

AvrlangParser::If_exprContext* AvrlangParser::StmtContext::if_expr() {
  return getRuleContext<AvrlangParser::If_exprContext>(0);
}

AvrlangParser::Ifelse_exprContext* AvrlangParser::StmtContext::ifelse_expr() {
  return getRuleContext<AvrlangParser::Ifelse_exprContext>(0);
}

AvrlangParser::ExprContext* AvrlangParser::StmtContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}


size_t AvrlangParser::StmtContext::getRuleIndex() const {
  return AvrlangParser::RuleStmt;
}

void AvrlangParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void AvrlangParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any AvrlangParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::StmtContext* AvrlangParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 10, AvrlangParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      assign();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(78);
      ret();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(79);
      whileloop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(80);
      if_expr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(81);
      ifelse_expr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(82);
      expr(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

AvrlangParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::AssignContext::NAME() {
  return getToken(AvrlangParser::NAME, 0);
}

AvrlangParser::ExprContext* AvrlangParser::AssignContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}


size_t AvrlangParser::AssignContext::getRuleIndex() const {
  return AvrlangParser::RuleAssign;
}

void AvrlangParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void AvrlangParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


antlrcpp::Any AvrlangParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::AssignContext* AvrlangParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 12, AvrlangParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(AvrlangParser::NAME);
    setState(86);
    match(AvrlangParser::T__1);
    setState(87);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

AvrlangParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::RetContext::RET() {
  return getToken(AvrlangParser::RET, 0);
}

AvrlangParser::ExprContext* AvrlangParser::RetContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}


size_t AvrlangParser::RetContext::getRuleIndex() const {
  return AvrlangParser::RuleRet;
}

void AvrlangParser::RetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet(this);
}

void AvrlangParser::RetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet(this);
}


antlrcpp::Any AvrlangParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::RetContext* AvrlangParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 14, AvrlangParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(AvrlangParser::RET);
    setState(90);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileloopContext ------------------------------------------------------------------

AvrlangParser::WhileloopContext::WhileloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::WhileloopContext::WHILE() {
  return getToken(AvrlangParser::WHILE, 0);
}

AvrlangParser::BracedexprContext* AvrlangParser::WhileloopContext::bracedexpr() {
  return getRuleContext<AvrlangParser::BracedexprContext>(0);
}

AvrlangParser::BlockContext* AvrlangParser::WhileloopContext::block() {
  return getRuleContext<AvrlangParser::BlockContext>(0);
}


size_t AvrlangParser::WhileloopContext::getRuleIndex() const {
  return AvrlangParser::RuleWhileloop;
}

void AvrlangParser::WhileloopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileloop(this);
}

void AvrlangParser::WhileloopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileloop(this);
}


antlrcpp::Any AvrlangParser::WhileloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitWhileloop(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::WhileloopContext* AvrlangParser::whileloop() {
  WhileloopContext *_localctx = _tracker.createInstance<WhileloopContext>(_ctx, getState());
  enterRule(_localctx, 16, AvrlangParser::RuleWhileloop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(AvrlangParser::WHILE);
    setState(93);
    bracedexpr();
    setState(94);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_exprContext ------------------------------------------------------------------

AvrlangParser::If_exprContext::If_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::If_exprContext::IF() {
  return getToken(AvrlangParser::IF, 0);
}

AvrlangParser::BracedexprContext* AvrlangParser::If_exprContext::bracedexpr() {
  return getRuleContext<AvrlangParser::BracedexprContext>(0);
}

AvrlangParser::BlockContext* AvrlangParser::If_exprContext::block() {
  return getRuleContext<AvrlangParser::BlockContext>(0);
}


size_t AvrlangParser::If_exprContext::getRuleIndex() const {
  return AvrlangParser::RuleIf_expr;
}

void AvrlangParser::If_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_expr(this);
}

void AvrlangParser::If_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_expr(this);
}


antlrcpp::Any AvrlangParser::If_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitIf_expr(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::If_exprContext* AvrlangParser::if_expr() {
  If_exprContext *_localctx = _tracker.createInstance<If_exprContext>(_ctx, getState());
  enterRule(_localctx, 18, AvrlangParser::RuleIf_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(AvrlangParser::IF);
    setState(97);
    bracedexpr();
    setState(98);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ifelse_exprContext ------------------------------------------------------------------

AvrlangParser::Ifelse_exprContext::Ifelse_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::Ifelse_exprContext::IF() {
  return getToken(AvrlangParser::IF, 0);
}

AvrlangParser::BracedexprContext* AvrlangParser::Ifelse_exprContext::bracedexpr() {
  return getRuleContext<AvrlangParser::BracedexprContext>(0);
}

std::vector<AvrlangParser::BlockContext *> AvrlangParser::Ifelse_exprContext::block() {
  return getRuleContexts<AvrlangParser::BlockContext>();
}

AvrlangParser::BlockContext* AvrlangParser::Ifelse_exprContext::block(size_t i) {
  return getRuleContext<AvrlangParser::BlockContext>(i);
}

tree::TerminalNode* AvrlangParser::Ifelse_exprContext::ELSE() {
  return getToken(AvrlangParser::ELSE, 0);
}


size_t AvrlangParser::Ifelse_exprContext::getRuleIndex() const {
  return AvrlangParser::RuleIfelse_expr;
}

void AvrlangParser::Ifelse_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfelse_expr(this);
}

void AvrlangParser::Ifelse_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfelse_expr(this);
}


antlrcpp::Any AvrlangParser::Ifelse_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitIfelse_expr(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::Ifelse_exprContext* AvrlangParser::ifelse_expr() {
  Ifelse_exprContext *_localctx = _tracker.createInstance<Ifelse_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, AvrlangParser::RuleIfelse_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(AvrlangParser::IF);
    setState(101);
    bracedexpr();
    setState(102);
    block();
    setState(103);
    match(AvrlangParser::ELSE);
    setState(104);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AvrlangParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AvrlangParser::NumberContext* AvrlangParser::ExprContext::number() {
  return getRuleContext<AvrlangParser::NumberContext>(0);
}

AvrlangParser::VarContext* AvrlangParser::ExprContext::var() {
  return getRuleContext<AvrlangParser::VarContext>(0);
}

AvrlangParser::CallexprContext* AvrlangParser::ExprContext::callexpr() {
  return getRuleContext<AvrlangParser::CallexprContext>(0);
}

AvrlangParser::NegContext* AvrlangParser::ExprContext::neg() {
  return getRuleContext<AvrlangParser::NegContext>(0);
}

AvrlangParser::BracedexprContext* AvrlangParser::ExprContext::bracedexpr() {
  return getRuleContext<AvrlangParser::BracedexprContext>(0);
}

AvrlangParser::BinoperatorContext* AvrlangParser::ExprContext::binoperator() {
  return getRuleContext<AvrlangParser::BinoperatorContext>(0);
}

std::vector<AvrlangParser::ExprContext *> AvrlangParser::ExprContext::expr() {
  return getRuleContexts<AvrlangParser::ExprContext>();
}

AvrlangParser::ExprContext* AvrlangParser::ExprContext::expr(size_t i) {
  return getRuleContext<AvrlangParser::ExprContext>(i);
}


size_t AvrlangParser::ExprContext::getRuleIndex() const {
  return AvrlangParser::RuleExpr;
}

void AvrlangParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void AvrlangParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any AvrlangParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


AvrlangParser::ExprContext* AvrlangParser::expr() {
   return expr(0);
}

AvrlangParser::ExprContext* AvrlangParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AvrlangParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AvrlangParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, AvrlangParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(107);
      number();
      break;
    }

    case 2: {
      setState(108);
      var();
      break;
    }

    case 3: {
      setState(109);
      callexpr();
      break;
    }

    case 4: {
      setState(110);
      neg();
      break;
    }

    case 5: {
      setState(111);
      bracedexpr();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(120);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        _localctx->leftOp = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(114);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(115);
        binoperator();
        setState(116);
        dynamic_cast<ExprContext *>(_localctx)->rightOp = expr(4); 
      }
      setState(122);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

AvrlangParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::NumberContext::NUM() {
  return getToken(AvrlangParser::NUM, 0);
}


size_t AvrlangParser::NumberContext::getRuleIndex() const {
  return AvrlangParser::RuleNumber;
}

void AvrlangParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void AvrlangParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any AvrlangParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::NumberContext* AvrlangParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 24, AvrlangParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(AvrlangParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

AvrlangParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::VarContext::NAME() {
  return getToken(AvrlangParser::NAME, 0);
}


size_t AvrlangParser::VarContext::getRuleIndex() const {
  return AvrlangParser::RuleVar;
}

void AvrlangParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void AvrlangParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


antlrcpp::Any AvrlangParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::VarContext* AvrlangParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 26, AvrlangParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(AvrlangParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallexprContext ------------------------------------------------------------------

AvrlangParser::CallexprContext::CallexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::CallexprContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

tree::TerminalNode* AvrlangParser::CallexprContext::CLOSED() {
  return getToken(AvrlangParser::CLOSED, 0);
}

tree::TerminalNode* AvrlangParser::CallexprContext::NAME() {
  return getToken(AvrlangParser::NAME, 0);
}

AvrlangParser::ArglistContext* AvrlangParser::CallexprContext::arglist() {
  return getRuleContext<AvrlangParser::ArglistContext>(0);
}


size_t AvrlangParser::CallexprContext::getRuleIndex() const {
  return AvrlangParser::RuleCallexpr;
}

void AvrlangParser::CallexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallexpr(this);
}

void AvrlangParser::CallexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallexpr(this);
}


antlrcpp::Any AvrlangParser::CallexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitCallexpr(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::CallexprContext* AvrlangParser::callexpr() {
  CallexprContext *_localctx = _tracker.createInstance<CallexprContext>(_ctx, getState());
  enterRule(_localctx, 28, AvrlangParser::RuleCallexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    dynamic_cast<CallexprContext *>(_localctx)->fName = match(AvrlangParser::NAME);
    setState(128);
    match(AvrlangParser::OPEN);
    setState(129);
    dynamic_cast<CallexprContext *>(_localctx)->args = arglist();
    setState(130);
    match(AvrlangParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

AvrlangParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AvrlangParser::ExprContext *> AvrlangParser::ArglistContext::expr() {
  return getRuleContexts<AvrlangParser::ExprContext>();
}

AvrlangParser::ExprContext* AvrlangParser::ArglistContext::expr(size_t i) {
  return getRuleContext<AvrlangParser::ExprContext>(i);
}


size_t AvrlangParser::ArglistContext::getRuleIndex() const {
  return AvrlangParser::RuleArglist;
}

void AvrlangParser::ArglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArglist(this);
}

void AvrlangParser::ArglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArglist(this);
}


antlrcpp::Any AvrlangParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ArglistContext* AvrlangParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 30, AvrlangParser::RuleArglist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::NUM))) != 0)) {
      setState(132);
      expr(0);
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AvrlangParser::T__0) {
        setState(133);
        match(AvrlangParser::T__0);
        setState(134);
        expr(0);
        setState(139);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NegContext ------------------------------------------------------------------

AvrlangParser::NegContext::NegContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::NegContext::NEG() {
  return getToken(AvrlangParser::NEG, 0);
}

AvrlangParser::ExprContext* AvrlangParser::NegContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}


size_t AvrlangParser::NegContext::getRuleIndex() const {
  return AvrlangParser::RuleNeg;
}

void AvrlangParser::NegContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeg(this);
}

void AvrlangParser::NegContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeg(this);
}


antlrcpp::Any AvrlangParser::NegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitNeg(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::NegContext* AvrlangParser::neg() {
  NegContext *_localctx = _tracker.createInstance<NegContext>(_ctx, getState());
  enterRule(_localctx, 32, AvrlangParser::RuleNeg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(AvrlangParser::NEG);
    setState(143);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinoperatorContext ------------------------------------------------------------------

AvrlangParser::BinoperatorContext::BinoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::AND() {
  return getToken(AvrlangParser::AND, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::OR() {
  return getToken(AvrlangParser::OR, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::XOR() {
  return getToken(AvrlangParser::XOR, 0);
}


size_t AvrlangParser::BinoperatorContext::getRuleIndex() const {
  return AvrlangParser::RuleBinoperator;
}

void AvrlangParser::BinoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinoperator(this);
}

void AvrlangParser::BinoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinoperator(this);
}


antlrcpp::Any AvrlangParser::BinoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitBinoperator(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::BinoperatorContext* AvrlangParser::binoperator() {
  BinoperatorContext *_localctx = _tracker.createInstance<BinoperatorContext>(_ctx, getState());
  enterRule(_localctx, 34, AvrlangParser::RuleBinoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__2)
      | (1ULL << AvrlangParser::T__3)
      | (1ULL << AvrlangParser::T__4)
      | (1ULL << AvrlangParser::T__5)
      | (1ULL << AvrlangParser::T__6)
      | (1ULL << AvrlangParser::T__7)
      | (1ULL << AvrlangParser::T__8)
      | (1ULL << AvrlangParser::T__9)
      | (1ULL << AvrlangParser::T__10)
      | (1ULL << AvrlangParser::T__11)
      | (1ULL << AvrlangParser::AND)
      | (1ULL << AvrlangParser::OR)
      | (1ULL << AvrlangParser::XOR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BracedexprContext ------------------------------------------------------------------

AvrlangParser::BracedexprContext::BracedexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::BracedexprContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

AvrlangParser::ExprContext* AvrlangParser::BracedexprContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}

tree::TerminalNode* AvrlangParser::BracedexprContext::CLOSED() {
  return getToken(AvrlangParser::CLOSED, 0);
}


size_t AvrlangParser::BracedexprContext::getRuleIndex() const {
  return AvrlangParser::RuleBracedexpr;
}

void AvrlangParser::BracedexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBracedexpr(this);
}

void AvrlangParser::BracedexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBracedexpr(this);
}


antlrcpp::Any AvrlangParser::BracedexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitBracedexpr(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::BracedexprContext* AvrlangParser::bracedexpr() {
  BracedexprContext *_localctx = _tracker.createInstance<BracedexprContext>(_ctx, getState());
  enterRule(_localctx, 36, AvrlangParser::RuleBracedexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(AvrlangParser::OPEN);
    setState(148);
    expr(0);
    setState(149);
    match(AvrlangParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AvrlangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AvrlangParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AvrlangParser::_decisionToDFA;
atn::PredictionContextCache AvrlangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AvrlangParser::_atn;
std::vector<uint16_t> AvrlangParser::_serializedATN;

std::vector<std::string> AvrlangParser::_ruleNames = {
  "file", "globalstmt", "functiondef", "paramlist", "block", "stmt", "assign", 
  "ret", "whileloop", "if_expr", "ifelse_expr", "expr", "number", "var", 
  "callexpr", "arglist", "neg", "binoperator", "bracedexpr"
};

std::vector<std::string> AvrlangParser::_literalNames = {
  "", "','", "'='", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'", "'>='", "'<='", 
  "'=='", "'!='", "'('", "')'", "'{'", "'}'", "'return'", "'while'", "'if'", 
  "'else'", "'and'", "'or'", "'^'", "'not'", "'def'", "", "'\n'"
};

std::vector<std::string> AvrlangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "OPEN", "CLOSED", 
  "LEFTBRACE", "RIGHTBRACE", "RET", "WHILE", "IF", "ELSE", "AND", "OR", 
  "XOR", "NEG", "DEF", "WHITESPACE", "NEWLINE", "NAME", "NUM"
};

dfa::Vocabulary AvrlangParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AvrlangParser::_tokenNames;

AvrlangParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1f, 0x9a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x3, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x2b, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2e, 0xb, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x3e, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x41, 0xb, 0x5, 0x5, 0x5, 0x43, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 
    0x4a, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x4b, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x56, 0xa, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x73, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x79, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x7c, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x8a, 0xa, 0x11, 0xc, 
    0x11, 0xe, 0x11, 0x8d, 0xb, 0x11, 0x5, 0x11, 0x8f, 0xa, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x2, 0x3, 0x18, 0x15, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x2, 0x3, 0x4, 0x2, 0x5, 0xe, 0x17, 0x19, 0x2, 0x98, 
    0x2, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x31, 0x3, 0x2, 0x2, 0x2, 0x6, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x42, 0x3, 0x2, 0x2, 0x2, 0xa, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x55, 0x3, 0x2, 0x2, 0x2, 0xe, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x16, 0x66, 0x3, 0x2, 0x2, 0x2, 0x18, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x20, 0x8e, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x90, 0x3, 0x2, 0x2, 0x2, 0x24, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x95, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 0x5, 0x4, 0x3, 0x2, 
    0x29, 0x2b, 0x7, 0x1d, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x2, 
    0x2, 0x3, 0x30, 0x3, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x5, 0x6, 0x4, 
    0x2, 0x32, 0x5, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x1b, 0x2, 0x2, 
    0x34, 0x35, 0x7, 0x1e, 0x2, 0x2, 0x35, 0x36, 0x7, 0xf, 0x2, 0x2, 0x36, 
    0x37, 0x5, 0x8, 0x5, 0x2, 0x37, 0x38, 0x7, 0x10, 0x2, 0x2, 0x38, 0x39, 
    0x5, 0xa, 0x6, 0x2, 0x39, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3f, 0x7, 
    0x1e, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x3c, 0x3e, 0x7, 0x1e, 
    0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x49, 0x7, 0x11, 0x2, 0x2, 0x45, 0x46, 0x5, 
    0xc, 0x7, 0x2, 0x46, 0x47, 0x7, 0x1d, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x4a, 0x7, 0x1d, 0x2, 0x2, 0x49, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x12, 0x2, 0x2, 0x4e, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x56, 0x5, 0xe, 0x8, 0x2, 0x50, 0x56, 0x5, 
    0x10, 0x9, 0x2, 0x51, 0x56, 0x5, 0x12, 0xa, 0x2, 0x52, 0x56, 0x5, 0x14, 
    0xb, 0x2, 0x53, 0x56, 0x5, 0x16, 0xc, 0x2, 0x54, 0x56, 0x5, 0x18, 0xd, 
    0x2, 0x55, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x55, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x51, 0x3, 0x2, 0x2, 0x2, 0x55, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0x1e, 0x2, 0x2, 0x58, 0x59, 0x7, 
    0x4, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x18, 0xd, 0x2, 0x5a, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5c, 0x7, 0x13, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0x18, 0xd, 
    0x2, 0x5d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x14, 0x2, 0x2, 
    0x5f, 0x60, 0x5, 0x26, 0x14, 0x2, 0x60, 0x61, 0x5, 0xa, 0x6, 0x2, 0x61, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x15, 0x2, 0x2, 0x63, 0x64, 
    0x5, 0x26, 0x14, 0x2, 0x64, 0x65, 0x5, 0xa, 0x6, 0x2, 0x65, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x15, 0x2, 0x2, 0x67, 0x68, 0x5, 0x26, 
    0x14, 0x2, 0x68, 0x69, 0x5, 0xa, 0x6, 0x2, 0x69, 0x6a, 0x7, 0x16, 0x2, 
    0x2, 0x6a, 0x6b, 0x5, 0xa, 0x6, 0x2, 0x6b, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x6d, 0x8, 0xd, 0x1, 0x2, 0x6d, 0x73, 0x5, 0x1a, 0xe, 0x2, 0x6e, 
    0x73, 0x5, 0x1c, 0xf, 0x2, 0x6f, 0x73, 0x5, 0x1e, 0x10, 0x2, 0x70, 0x73, 
    0x5, 0x22, 0x12, 0x2, 0x71, 0x73, 0x5, 0x26, 0x14, 0x2, 0x72, 0x6c, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x73, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0xc, 0x5, 0x2, 
    0x2, 0x75, 0x76, 0x5, 0x24, 0x13, 0x2, 0x76, 0x77, 0x5, 0x18, 0xd, 0x6, 
    0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x74, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x1f, 0x2, 0x2, 0x7e, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x80, 0x7, 0x1e, 0x2, 0x2, 0x80, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x82, 0x7, 0x1e, 0x2, 0x2, 0x82, 0x83, 0x7, 0xf, 0x2, 0x2, 
    0x83, 0x84, 0x5, 0x20, 0x11, 0x2, 0x84, 0x85, 0x7, 0x10, 0x2, 0x2, 0x85, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x86, 0x8b, 0x5, 0x18, 0xd, 0x2, 0x87, 0x88, 
    0x7, 0x3, 0x2, 0x2, 0x88, 0x8a, 0x5, 0x18, 0xd, 0x2, 0x89, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x91, 0x7, 0x1a, 0x2, 0x2, 0x91, 0x92, 0x5, 0x18, 0xd, 0x2, 0x92, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x9, 0x2, 0x2, 0x2, 0x94, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0xf, 0x2, 0x2, 0x96, 0x97, 0x5, 0x18, 
    0xd, 0x2, 0x97, 0x98, 0x7, 0x10, 0x2, 0x2, 0x98, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xd, 0x2a, 0x2c, 0x3f, 0x42, 0x49, 0x4b, 0x55, 0x72, 0x7a, 0x8b, 
    0x8e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AvrlangParser::Initializer AvrlangParser::_init;
