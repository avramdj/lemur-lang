
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
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::CLASS)
      | (1ULL << AvrlangParser::DEF)
      | (1ULL << AvrlangParser::NEWLINE))) != 0)) {
      setState(60);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AvrlangParser::CLASS:
        case AvrlangParser::DEF: {
          setState(58);
          globalstmt();
          break;
        }

        case AvrlangParser::NEWLINE: {
          setState(59);
          match(AvrlangParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(65);
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

AvrlangParser::ClassdefContext* AvrlangParser::GlobalstmtContext::classdef() {
  return getRuleContext<AvrlangParser::ClassdefContext>(0);
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
    setState(69);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AvrlangParser::CLASS: {
        enterOuterAlt(_localctx, 1);
        setState(67);
        classdef();
        break;
      }

      case AvrlangParser::DEF: {
        enterOuterAlt(_localctx, 2);
        setState(68);
        functiondef();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassdefContext ------------------------------------------------------------------

AvrlangParser::ClassdefContext::ClassdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::ClassdefContext::CLASS() {
  return getToken(AvrlangParser::CLASS, 0);
}

tree::TerminalNode* AvrlangParser::ClassdefContext::LEFTBRACE() {
  return getToken(AvrlangParser::LEFTBRACE, 0);
}

tree::TerminalNode* AvrlangParser::ClassdefContext::RIGHTBRACE() {
  return getToken(AvrlangParser::RIGHTBRACE, 0);
}

std::vector<tree::TerminalNode *> AvrlangParser::ClassdefContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::ClassdefContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
}

AvrlangParser::ClassbodyContext* AvrlangParser::ClassdefContext::classbody() {
  return getRuleContext<AvrlangParser::ClassbodyContext>(0);
}

tree::TerminalNode* AvrlangParser::ClassdefContext::ARROW() {
  return getToken(AvrlangParser::ARROW, 0);
}


size_t AvrlangParser::ClassdefContext::getRuleIndex() const {
  return AvrlangParser::RuleClassdef;
}

void AvrlangParser::ClassdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassdef(this);
}

void AvrlangParser::ClassdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassdef(this);
}


antlrcpp::Any AvrlangParser::ClassdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitClassdef(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ClassdefContext* AvrlangParser::classdef() {
  ClassdefContext *_localctx = _tracker.createInstance<ClassdefContext>(_ctx, getState());
  enterRule(_localctx, 4, AvrlangParser::RuleClassdef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(AvrlangParser::CLASS);
    setState(72);
    dynamic_cast<ClassdefContext *>(_localctx)->cName = match(AvrlangParser::NAME);
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AvrlangParser::ARROW) {
      setState(73);
      match(AvrlangParser::ARROW);
      setState(74);
      dynamic_cast<ClassdefContext *>(_localctx)->derName = match(AvrlangParser::NAME);
    }
    setState(77);
    match(AvrlangParser::LEFTBRACE);
    setState(78);
    dynamic_cast<ClassdefContext *>(_localctx)->body = classbody();
    setState(79);
    match(AvrlangParser::RIGHTBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassbodyContext ------------------------------------------------------------------

AvrlangParser::ClassbodyContext::ClassbodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AvrlangParser::VardeclContext* AvrlangParser::ClassbodyContext::vardecl() {
  return getRuleContext<AvrlangParser::VardeclContext>(0);
}

AvrlangParser::FunctiondefContext* AvrlangParser::ClassbodyContext::functiondef() {
  return getRuleContext<AvrlangParser::FunctiondefContext>(0);
}


size_t AvrlangParser::ClassbodyContext::getRuleIndex() const {
  return AvrlangParser::RuleClassbody;
}

void AvrlangParser::ClassbodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassbody(this);
}

void AvrlangParser::ClassbodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassbody(this);
}


antlrcpp::Any AvrlangParser::ClassbodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitClassbody(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ClassbodyContext* AvrlangParser::classbody() {
  ClassbodyContext *_localctx = _tracker.createInstance<ClassbodyContext>(_ctx, getState());
  enterRule(_localctx, 6, AvrlangParser::RuleClassbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AvrlangParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(81);
        vardecl();
        break;
      }

      case AvrlangParser::DEF: {
        enterOuterAlt(_localctx, 2);
        setState(82);
        functiondef();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
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

std::vector<tree::TerminalNode *> AvrlangParser::FunctiondefContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::FunctiondefContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
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
  enterRule(_localctx, 8, AvrlangParser::RuleFunctiondef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(AvrlangParser::DEF);
    setState(86);
    dynamic_cast<FunctiondefContext *>(_localctx)->fName = match(AvrlangParser::NAME);
    setState(87);
    match(AvrlangParser::OPEN);
    setState(88);
    dynamic_cast<FunctiondefContext *>(_localctx)->params = paramlist();
    setState(89);
    match(AvrlangParser::CLOSED);
    setState(90);
    match(AvrlangParser::T__0);
    setState(91);
    dynamic_cast<FunctiondefContext *>(_localctx)->retType = match(AvrlangParser::NAME);
    setState(92);
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
  enterRule(_localctx, 10, AvrlangParser::RuleParamlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AvrlangParser::NAME) {
      setState(94);
      dynamic_cast<ParamlistContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
      setState(95);
      dynamic_cast<ParamlistContext *>(_localctx)->varName = match(AvrlangParser::NAME);
      _localctx->types.push_back((dynamic_cast<ParamlistContext *>(_localctx)->typeName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->typeName->getText() : ""));_localctx->vars.push_back((dynamic_cast<ParamlistContext *>(_localctx)->varName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->varName->getText() : ""));
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AvrlangParser::T__1) {
        setState(97);
        match(AvrlangParser::T__1);
        setState(98);
        dynamic_cast<ParamlistContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
        setState(99);
        dynamic_cast<ParamlistContext *>(_localctx)->varName = match(AvrlangParser::NAME);
        {_localctx->types.push_back((dynamic_cast<ParamlistContext *>(_localctx)->typeName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->typeName->getText() : ""));_localctx->vars.push_back((dynamic_cast<ParamlistContext *>(_localctx)->varName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->varName->getText() : ""));}
        setState(105);
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
  enterRule(_localctx, 12, AvrlangParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(AvrlangParser::LEFTBRACE);
    setState(113); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(113);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AvrlangParser::T__3:
        case AvrlangParser::UMINUS:
        case AvrlangParser::FOR:
        case AvrlangParser::PRINTF:
        case AvrlangParser::PRINT:
        case AvrlangParser::OPEN:
        case AvrlangParser::RET:
        case AvrlangParser::WHILE:
        case AvrlangParser::IF:
        case AvrlangParser::NEG:
        case AvrlangParser::NAME:
        case AvrlangParser::NUM:
        case AvrlangParser::STRING: {
          setState(109);
          stmt();
          setState(110);
          match(AvrlangParser::NEWLINE);
          break;
        }

        case AvrlangParser::NEWLINE: {
          setState(112);
          match(AvrlangParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(115); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__3)
      | (1ULL << AvrlangParser::UMINUS)
      | (1ULL << AvrlangParser::FOR)
      | (1ULL << AvrlangParser::PRINTF)
      | (1ULL << AvrlangParser::PRINT)
      | (1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::RET)
      | (1ULL << AvrlangParser::WHILE)
      | (1ULL << AvrlangParser::IF)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NEWLINE)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::NUM)
      | (1ULL << AvrlangParser::STRING))) != 0));
    setState(117);
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

AvrlangParser::VardeclContext* AvrlangParser::StmtContext::vardecl() {
  return getRuleContext<AvrlangParser::VardeclContext>(0);
}

AvrlangParser::AssignContext* AvrlangParser::StmtContext::assign() {
  return getRuleContext<AvrlangParser::AssignContext>(0);
}

AvrlangParser::DeclassignContext* AvrlangParser::StmtContext::declassign() {
  return getRuleContext<AvrlangParser::DeclassignContext>(0);
}

AvrlangParser::RetContext* AvrlangParser::StmtContext::ret() {
  return getRuleContext<AvrlangParser::RetContext>(0);
}

AvrlangParser::WhileloopContext* AvrlangParser::StmtContext::whileloop() {
  return getRuleContext<AvrlangParser::WhileloopContext>(0);
}

AvrlangParser::IfExprContext* AvrlangParser::StmtContext::ifExpr() {
  return getRuleContext<AvrlangParser::IfExprContext>(0);
}

AvrlangParser::IfElseExprContext* AvrlangParser::StmtContext::ifElseExpr() {
  return getRuleContext<AvrlangParser::IfElseExprContext>(0);
}

AvrlangParser::ForloopContext* AvrlangParser::StmtContext::forloop() {
  return getRuleContext<AvrlangParser::ForloopContext>(0);
}

AvrlangParser::ExprContext* AvrlangParser::StmtContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}

AvrlangParser::PrintstmtContext* AvrlangParser::StmtContext::printstmt() {
  return getRuleContext<AvrlangParser::PrintstmtContext>(0);
}

AvrlangParser::PrintfstmtContext* AvrlangParser::StmtContext::printfstmt() {
  return getRuleContext<AvrlangParser::PrintfstmtContext>(0);
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
  enterRule(_localctx, 14, AvrlangParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(119);
      vardecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(120);
      assign();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(121);
      declassign();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(122);
      ret();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(123);
      whileloop();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(124);
      ifExpr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(125);
      ifElseExpr();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(126);
      forloop();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(127);
      expr(0);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(128);
      printstmt();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(129);
      printfstmt();
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

//----------------- PrintstmtContext ------------------------------------------------------------------

AvrlangParser::PrintstmtContext::PrintstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::PrintstmtContext::PRINT() {
  return getToken(AvrlangParser::PRINT, 0);
}

tree::TerminalNode* AvrlangParser::PrintstmtContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

AvrlangParser::ExprContext* AvrlangParser::PrintstmtContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}

tree::TerminalNode* AvrlangParser::PrintstmtContext::CLOSED() {
  return getToken(AvrlangParser::CLOSED, 0);
}


size_t AvrlangParser::PrintstmtContext::getRuleIndex() const {
  return AvrlangParser::RulePrintstmt;
}

void AvrlangParser::PrintstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintstmt(this);
}

void AvrlangParser::PrintstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintstmt(this);
}


antlrcpp::Any AvrlangParser::PrintstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitPrintstmt(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::PrintstmtContext* AvrlangParser::printstmt() {
  PrintstmtContext *_localctx = _tracker.createInstance<PrintstmtContext>(_ctx, getState());
  enterRule(_localctx, 16, AvrlangParser::RulePrintstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(AvrlangParser::PRINT);
    setState(133);
    match(AvrlangParser::OPEN);
    setState(134);
    expr(0);
    setState(135);
    match(AvrlangParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintfstmtContext ------------------------------------------------------------------

AvrlangParser::PrintfstmtContext::PrintfstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::PrintfstmtContext::PRINTF() {
  return getToken(AvrlangParser::PRINTF, 0);
}

tree::TerminalNode* AvrlangParser::PrintfstmtContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

AvrlangParser::ExprContext* AvrlangParser::PrintfstmtContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}

tree::TerminalNode* AvrlangParser::PrintfstmtContext::CLOSED() {
  return getToken(AvrlangParser::CLOSED, 0);
}


size_t AvrlangParser::PrintfstmtContext::getRuleIndex() const {
  return AvrlangParser::RulePrintfstmt;
}

void AvrlangParser::PrintfstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintfstmt(this);
}

void AvrlangParser::PrintfstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintfstmt(this);
}


antlrcpp::Any AvrlangParser::PrintfstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitPrintfstmt(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::PrintfstmtContext* AvrlangParser::printfstmt() {
  PrintfstmtContext *_localctx = _tracker.createInstance<PrintfstmtContext>(_ctx, getState());
  enterRule(_localctx, 18, AvrlangParser::RulePrintfstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(AvrlangParser::PRINTF);
    setState(138);
    match(AvrlangParser::OPEN);
    setState(139);
    expr(0);
    setState(140);
    match(AvrlangParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

AvrlangParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AvrlangParser::VardeclContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::VardeclContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
}


size_t AvrlangParser::VardeclContext::getRuleIndex() const {
  return AvrlangParser::RuleVardecl;
}

void AvrlangParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void AvrlangParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


antlrcpp::Any AvrlangParser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::VardeclContext* AvrlangParser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 20, AvrlangParser::RuleVardecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    dynamic_cast<VardeclContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
    setState(143);
    dynamic_cast<VardeclContext *>(_localctx)->varName = match(AvrlangParser::NAME);
   
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

AvrlangParser::ExprContext* AvrlangParser::AssignContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}

tree::TerminalNode* AvrlangParser::AssignContext::NAME() {
  return getToken(AvrlangParser::NAME, 0);
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
  enterRule(_localctx, 22, AvrlangParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    dynamic_cast<AssignContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(146);
    match(AvrlangParser::T__2);
    setState(147);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclassignContext ------------------------------------------------------------------

AvrlangParser::DeclassignContext::DeclassignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AvrlangParser::ExprContext* AvrlangParser::DeclassignContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> AvrlangParser::DeclassignContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::DeclassignContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
}


size_t AvrlangParser::DeclassignContext::getRuleIndex() const {
  return AvrlangParser::RuleDeclassign;
}

void AvrlangParser::DeclassignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclassign(this);
}

void AvrlangParser::DeclassignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclassign(this);
}


antlrcpp::Any AvrlangParser::DeclassignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitDeclassign(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::DeclassignContext* AvrlangParser::declassign() {
  DeclassignContext *_localctx = _tracker.createInstance<DeclassignContext>(_ctx, getState());
  enterRule(_localctx, 24, AvrlangParser::RuleDeclassign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    dynamic_cast<DeclassignContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
    setState(150);
    dynamic_cast<DeclassignContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(151);
    match(AvrlangParser::T__2);
    setState(152);
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
  enterRule(_localctx, 26, AvrlangParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(AvrlangParser::RET);
    setState(155);
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
  enterRule(_localctx, 28, AvrlangParser::RuleWhileloop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(AvrlangParser::WHILE);
    setState(158);
    bracedexpr();
    setState(159);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForloopContext ------------------------------------------------------------------

AvrlangParser::ForloopContext::ForloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::ForloopContext::FOR() {
  return getToken(AvrlangParser::FOR, 0);
}

tree::TerminalNode* AvrlangParser::ForloopContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

tree::TerminalNode* AvrlangParser::ForloopContext::IN() {
  return getToken(AvrlangParser::IN, 0);
}

AvrlangParser::BlockContext* AvrlangParser::ForloopContext::block() {
  return getRuleContext<AvrlangParser::BlockContext>(0);
}

tree::TerminalNode* AvrlangParser::ForloopContext::NAME() {
  return getToken(AvrlangParser::NAME, 0);
}

AvrlangParser::ExprContext* AvrlangParser::ForloopContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}


size_t AvrlangParser::ForloopContext::getRuleIndex() const {
  return AvrlangParser::RuleForloop;
}

void AvrlangParser::ForloopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForloop(this);
}

void AvrlangParser::ForloopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForloop(this);
}


antlrcpp::Any AvrlangParser::ForloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitForloop(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ForloopContext* AvrlangParser::forloop() {
  ForloopContext *_localctx = _tracker.createInstance<ForloopContext>(_ctx, getState());
  enterRule(_localctx, 30, AvrlangParser::RuleForloop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(AvrlangParser::FOR);
    setState(162);
    match(AvrlangParser::OPEN);
    setState(163);
    dynamic_cast<ForloopContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(164);
    match(AvrlangParser::IN);
    setState(165);
    dynamic_cast<ForloopContext *>(_localctx)->listName = expr(0);
    setState(166);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfExprContext ------------------------------------------------------------------

AvrlangParser::IfExprContext::IfExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::IfExprContext::IF() {
  return getToken(AvrlangParser::IF, 0);
}

AvrlangParser::BracedexprContext* AvrlangParser::IfExprContext::bracedexpr() {
  return getRuleContext<AvrlangParser::BracedexprContext>(0);
}

AvrlangParser::BlockContext* AvrlangParser::IfExprContext::block() {
  return getRuleContext<AvrlangParser::BlockContext>(0);
}


size_t AvrlangParser::IfExprContext::getRuleIndex() const {
  return AvrlangParser::RuleIfExpr;
}

void AvrlangParser::IfExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfExpr(this);
}

void AvrlangParser::IfExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfExpr(this);
}


antlrcpp::Any AvrlangParser::IfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitIfExpr(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::IfExprContext* AvrlangParser::ifExpr() {
  IfExprContext *_localctx = _tracker.createInstance<IfExprContext>(_ctx, getState());
  enterRule(_localctx, 32, AvrlangParser::RuleIfExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(AvrlangParser::IF);
    setState(169);
    dynamic_cast<IfExprContext *>(_localctx)->cond = bracedexpr();
    setState(170);
    dynamic_cast<IfExprContext *>(_localctx)->then = block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfElseExprContext ------------------------------------------------------------------

AvrlangParser::IfElseExprContext::IfElseExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::IfElseExprContext::IF() {
  return getToken(AvrlangParser::IF, 0);
}

std::vector<AvrlangParser::BlockContext *> AvrlangParser::IfElseExprContext::block() {
  return getRuleContexts<AvrlangParser::BlockContext>();
}

AvrlangParser::BlockContext* AvrlangParser::IfElseExprContext::block(size_t i) {
  return getRuleContext<AvrlangParser::BlockContext>(i);
}

tree::TerminalNode* AvrlangParser::IfElseExprContext::ELSE() {
  return getToken(AvrlangParser::ELSE, 0);
}

AvrlangParser::BracedexprContext* AvrlangParser::IfElseExprContext::bracedexpr() {
  return getRuleContext<AvrlangParser::BracedexprContext>(0);
}


size_t AvrlangParser::IfElseExprContext::getRuleIndex() const {
  return AvrlangParser::RuleIfElseExpr;
}

void AvrlangParser::IfElseExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfElseExpr(this);
}

void AvrlangParser::IfElseExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfElseExpr(this);
}


antlrcpp::Any AvrlangParser::IfElseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitIfElseExpr(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::IfElseExprContext* AvrlangParser::ifElseExpr() {
  IfElseExprContext *_localctx = _tracker.createInstance<IfElseExprContext>(_ctx, getState());
  enterRule(_localctx, 34, AvrlangParser::RuleIfElseExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(AvrlangParser::IF);
    setState(173);
    dynamic_cast<IfElseExprContext *>(_localctx)->cond = bracedexpr();
    setState(174);
    block();
    setState(175);
    match(AvrlangParser::ELSE);
    setState(176);
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


size_t AvrlangParser::ExprContext::getRuleIndex() const {
  return AvrlangParser::RuleExpr;
}

void AvrlangParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringRuleContext ------------------------------------------------------------------

AvrlangParser::StringContext* AvrlangParser::StringRuleContext::string() {
  return getRuleContext<AvrlangParser::StringContext>(0);
}

AvrlangParser::StringRuleContext::StringRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::StringRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringRule(this);
}
void AvrlangParser::StringRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringRule(this);
}

antlrcpp::Any AvrlangParser::StringRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitStringRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OpExprRuleContext ------------------------------------------------------------------

AvrlangParser::BinoperatorContext* AvrlangParser::OpExprRuleContext::binoperator() {
  return getRuleContext<AvrlangParser::BinoperatorContext>(0);
}

std::vector<AvrlangParser::ExprContext *> AvrlangParser::OpExprRuleContext::expr() {
  return getRuleContexts<AvrlangParser::ExprContext>();
}

AvrlangParser::ExprContext* AvrlangParser::OpExprRuleContext::expr(size_t i) {
  return getRuleContext<AvrlangParser::ExprContext>(i);
}

AvrlangParser::OpExprRuleContext::OpExprRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::OpExprRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpExprRule(this);
}
void AvrlangParser::OpExprRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpExprRule(this);
}

antlrcpp::Any AvrlangParser::OpExprRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitOpExprRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexRuleContext ------------------------------------------------------------------

std::vector<AvrlangParser::ExprContext *> AvrlangParser::IndexRuleContext::expr() {
  return getRuleContexts<AvrlangParser::ExprContext>();
}

AvrlangParser::ExprContext* AvrlangParser::IndexRuleContext::expr(size_t i) {
  return getRuleContext<AvrlangParser::ExprContext>(i);
}

AvrlangParser::IndexRuleContext::IndexRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::IndexRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexRule(this);
}
void AvrlangParser::IndexRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexRule(this);
}

antlrcpp::Any AvrlangParser::IndexRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitIndexRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodRuleContext ------------------------------------------------------------------

AvrlangParser::MethodCallContext* AvrlangParser::MethodRuleContext::methodCall() {
  return getRuleContext<AvrlangParser::MethodCallContext>(0);
}

AvrlangParser::MethodRuleContext::MethodRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::MethodRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodRule(this);
}
void AvrlangParser::MethodRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodRule(this);
}

antlrcpp::Any AvrlangParser::MethodRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitMethodRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListRuleContext ------------------------------------------------------------------

AvrlangParser::ListContext* AvrlangParser::ListRuleContext::list() {
  return getRuleContext<AvrlangParser::ListContext>(0);
}

AvrlangParser::ListRuleContext::ListRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::ListRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListRule(this);
}
void AvrlangParser::ListRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListRule(this);
}

antlrcpp::Any AvrlangParser::ListRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitListRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRuleContext ------------------------------------------------------------------

AvrlangParser::NumberContext* AvrlangParser::NumberRuleContext::number() {
  return getRuleContext<AvrlangParser::NumberContext>(0);
}

AvrlangParser::NumberRuleContext::NumberRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::NumberRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRule(this);
}
void AvrlangParser::NumberRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRule(this);
}

antlrcpp::Any AvrlangParser::NumberRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitNumberRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UminusRuleContext ------------------------------------------------------------------

tree::TerminalNode* AvrlangParser::UminusRuleContext::UMINUS() {
  return getToken(AvrlangParser::UMINUS, 0);
}

AvrlangParser::ExprContext* AvrlangParser::UminusRuleContext::expr() {
  return getRuleContext<AvrlangParser::ExprContext>(0);
}

AvrlangParser::UminusRuleContext::UminusRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::UminusRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUminusRule(this);
}
void AvrlangParser::UminusRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUminusRule(this);
}

antlrcpp::Any AvrlangParser::UminusRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitUminusRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprRuleContext ------------------------------------------------------------------

AvrlangParser::CallexprContext* AvrlangParser::CallExprRuleContext::callexpr() {
  return getRuleContext<AvrlangParser::CallexprContext>(0);
}

AvrlangParser::CallExprRuleContext::CallExprRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::CallExprRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExprRule(this);
}
void AvrlangParser::CallExprRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExprRule(this);
}

antlrcpp::Any AvrlangParser::CallExprRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitCallExprRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarRuleContext ------------------------------------------------------------------

AvrlangParser::VarContext* AvrlangParser::VarRuleContext::var() {
  return getRuleContext<AvrlangParser::VarContext>(0);
}

AvrlangParser::VarRuleContext::VarRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::VarRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarRule(this);
}
void AvrlangParser::VarRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarRule(this);
}

antlrcpp::Any AvrlangParser::VarRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitVarRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegRuleContext ------------------------------------------------------------------

AvrlangParser::NegContext* AvrlangParser::NegRuleContext::neg() {
  return getRuleContext<AvrlangParser::NegContext>(0);
}

AvrlangParser::NegRuleContext::NegRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::NegRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegRule(this);
}
void AvrlangParser::NegRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegRule(this);
}

antlrcpp::Any AvrlangParser::NegRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitNegRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BraceExprRuleContext ------------------------------------------------------------------

AvrlangParser::BracedexprContext* AvrlangParser::BraceExprRuleContext::bracedexpr() {
  return getRuleContext<AvrlangParser::BracedexprContext>(0);
}

AvrlangParser::BraceExprRuleContext::BraceExprRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void AvrlangParser::BraceExprRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBraceExprRule(this);
}
void AvrlangParser::BraceExprRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBraceExprRule(this);
}

antlrcpp::Any AvrlangParser::BraceExprRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitBraceExprRule(this);
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
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, AvrlangParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NumberRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(179);
      number();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UminusRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(180);
      match(AvrlangParser::UMINUS);
      setState(181);
      expr(10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<VarRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(182);
      var();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<StringRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      string();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MethodRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(184);
      methodCall();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CallExprRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(185);
      callexpr();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<NegRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      neg();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ListRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      list();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BraceExprRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(188);
      bracedexpr();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(202);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(200);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<OpExprRuleContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->leftOp = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(191);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(192);
          binoperator();
          setState(193);
          dynamic_cast<OpExprRuleContext *>(_localctx)->rightOp = expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<IndexRuleContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(195);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(196);
          match(AvrlangParser::T__3);
          setState(197);
          expr(0);
          setState(198);
          match(AvrlangParser::T__4);
          break;
        }

        } 
      }
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ListContext ------------------------------------------------------------------

AvrlangParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AvrlangParser::ExprContext *> AvrlangParser::ListContext::expr() {
  return getRuleContexts<AvrlangParser::ExprContext>();
}

AvrlangParser::ExprContext* AvrlangParser::ListContext::expr(size_t i) {
  return getRuleContext<AvrlangParser::ExprContext>(i);
}


size_t AvrlangParser::ListContext::getRuleIndex() const {
  return AvrlangParser::RuleList;
}

void AvrlangParser::ListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList(this);
}

void AvrlangParser::ListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList(this);
}


antlrcpp::Any AvrlangParser::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ListContext* AvrlangParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 38, AvrlangParser::RuleList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(AvrlangParser::T__3);
    setState(211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__3)
      | (1ULL << AvrlangParser::UMINUS)
      | (1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::NUM)
      | (1ULL << AvrlangParser::STRING))) != 0)) {
      setState(206);
      expr(0);
      setState(209);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AvrlangParser::T__1) {
        setState(207);
        match(AvrlangParser::T__1);
        setState(208);
        expr(0);
      }
    }
    setState(213);
    match(AvrlangParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodCallContext ------------------------------------------------------------------

AvrlangParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::MethodCallContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

tree::TerminalNode* AvrlangParser::MethodCallContext::CLOSED() {
  return getToken(AvrlangParser::CLOSED, 0);
}

std::vector<tree::TerminalNode *> AvrlangParser::MethodCallContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::MethodCallContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
}

AvrlangParser::ArglistContext* AvrlangParser::MethodCallContext::arglist() {
  return getRuleContext<AvrlangParser::ArglistContext>(0);
}


size_t AvrlangParser::MethodCallContext::getRuleIndex() const {
  return AvrlangParser::RuleMethodCall;
}

void AvrlangParser::MethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCall(this);
}

void AvrlangParser::MethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCall(this);
}


antlrcpp::Any AvrlangParser::MethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitMethodCall(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::MethodCallContext* AvrlangParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 40, AvrlangParser::RuleMethodCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    dynamic_cast<MethodCallContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(216);
    match(AvrlangParser::T__5);
    setState(217);
    dynamic_cast<MethodCallContext *>(_localctx)->mathodName = match(AvrlangParser::NAME);
    setState(218);
    match(AvrlangParser::OPEN);
    setState(219);
    dynamic_cast<MethodCallContext *>(_localctx)->args = arglist();
    setState(220);
    match(AvrlangParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

AvrlangParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::StringContext::STRING() {
  return getToken(AvrlangParser::STRING, 0);
}


size_t AvrlangParser::StringContext::getRuleIndex() const {
  return AvrlangParser::RuleString;
}

void AvrlangParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void AvrlangParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


antlrcpp::Any AvrlangParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::StringContext* AvrlangParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 42, AvrlangParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(AvrlangParser::STRING);
   
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
  enterRule(_localctx, 44, AvrlangParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
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
  enterRule(_localctx, 46, AvrlangParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
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
  enterRule(_localctx, 48, AvrlangParser::RuleCallexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    dynamic_cast<CallexprContext *>(_localctx)->fName = match(AvrlangParser::NAME);
    setState(229);
    match(AvrlangParser::OPEN);
    setState(230);
    dynamic_cast<CallexprContext *>(_localctx)->args = arglist();
    setState(231);
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
  enterRule(_localctx, 50, AvrlangParser::RuleArglist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__3)
      | (1ULL << AvrlangParser::UMINUS)
      | (1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::NUM)
      | (1ULL << AvrlangParser::STRING))) != 0)) {
      setState(233);
      expr(0);
      setState(238);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AvrlangParser::T__1) {
        setState(234);
        match(AvrlangParser::T__1);
        setState(235);
        expr(0);
        setState(240);
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
  enterRule(_localctx, 52, AvrlangParser::RuleNeg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(AvrlangParser::NEG);
    setState(244);
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

tree::TerminalNode* AvrlangParser::BinoperatorContext::UMINUS() {
  return getToken(AvrlangParser::UMINUS, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::SHL() {
  return getToken(AvrlangParser::SHL, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::SHR() {
  return getToken(AvrlangParser::SHR, 0);
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

tree::TerminalNode* AvrlangParser::BinoperatorContext::GT() {
  return getToken(AvrlangParser::GT, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::LT() {
  return getToken(AvrlangParser::LT, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::GE() {
  return getToken(AvrlangParser::GE, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::LE() {
  return getToken(AvrlangParser::LE, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::EQ() {
  return getToken(AvrlangParser::EQ, 0);
}

tree::TerminalNode* AvrlangParser::BinoperatorContext::NE() {
  return getToken(AvrlangParser::NE, 0);
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
  enterRule(_localctx, 54, AvrlangParser::RuleBinoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__6)
      | (1ULL << AvrlangParser::T__7)
      | (1ULL << AvrlangParser::T__8)
      | (1ULL << AvrlangParser::UMINUS)
      | (1ULL << AvrlangParser::AND)
      | (1ULL << AvrlangParser::OR)
      | (1ULL << AvrlangParser::XOR)
      | (1ULL << AvrlangParser::SHL)
      | (1ULL << AvrlangParser::SHR)
      | (1ULL << AvrlangParser::GT)
      | (1ULL << AvrlangParser::GE)
      | (1ULL << AvrlangParser::LT)
      | (1ULL << AvrlangParser::LE)
      | (1ULL << AvrlangParser::EQ)
      | (1ULL << AvrlangParser::NE))) != 0))) {
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
  enterRule(_localctx, 56, AvrlangParser::RuleBracedexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(AvrlangParser::OPEN);
    setState(249);
    expr(0);
    setState(250);
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
    case 18: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AvrlangParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 6);

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
  "file", "globalstmt", "classdef", "classbody", "functiondef", "paramlist", 
  "block", "stmt", "printstmt", "printfstmt", "vardecl", "assign", "declassign", 
  "ret", "whileloop", "forloop", "ifExpr", "ifElseExpr", "expr", "list", 
  "methodCall", "string", "number", "var", "callexpr", "arglist", "neg", 
  "binoperator", "bracedexpr"
};

std::vector<std::string> AvrlangParser::_literalNames = {
  "", "':'", "','", "'='", "'['", "']'", "'.'", "'+'", "'*'", "'/'", "'-'", 
  "'for'", "'in'", "'class'", "'<-'", "'def'", "'printf'", "'print'", "'('", 
  "')'", "'{'", "'}'", "'return'", "'while'", "'if'", "'else'", "'and'", 
  "'or'", "'^'", "'<<'", "'>>'", "'not'", "'>'", "'>='", "'<'", "'<='", 
  "'=='", "'!='", "'\n'"
};

std::vector<std::string> AvrlangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "UMINUS", "FOR", "IN", "CLASS", 
  "ARROW", "DEF", "PRINTF", "PRINT", "OPEN", "CLOSED", "LEFTBRACE", "RIGHTBRACE", 
  "RET", "WHILE", "IF", "ELSE", "AND", "OR", "XOR", "SHL", "SHR", "NEG", 
  "GT", "GE", "LT", "LE", "EQ", "NE", "NEWLINE", "NAME", "NUM", "STRING", 
  "WHITESPACE", "COMMENT"
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
    0x3, 0x2d, 0xff, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 
    0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x3f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x42, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x48, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4e, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x56, 0xa, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x68, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0x6b, 0xb, 0x7, 0x5, 0x7, 0x6d, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x74, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x75, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x85, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xc0, 0xa, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xcb, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0xce, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0xd4, 0xa, 0x15, 0x5, 0x15, 0xd6, 0xa, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0xef, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 
    0xf2, 0xb, 0x1b, 0x5, 0x1b, 0xf4, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x2, 0x3, 0x26, 0x1f, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x2, 0x3, 
    0x5, 0x2, 0x9, 0xc, 0x1c, 0x20, 0x22, 0x27, 0x2, 0x102, 0x2, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x47, 0x3, 0x2, 0x2, 0x2, 0x6, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x55, 0x3, 0x2, 0x2, 0x2, 0xa, 0x57, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x86, 0x3, 0x2, 0x2, 0x2, 0x14, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x90, 0x3, 0x2, 0x2, 0x2, 0x18, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x97, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x24, 0xae, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0x28, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x32, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x36, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3f, 0x5, 0x4, 0x3, 0x2, 0x3d, 0x3f, 0x7, 0x28, 0x2, 0x2, 0x3e, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x43, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x43, 0x44, 0x7, 0x2, 0x2, 0x3, 0x44, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x45, 0x48, 0x5, 0x6, 0x4, 0x2, 0x46, 0x48, 0x5, 0xa, 0x6, 0x2, 
    0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0xf, 0x2, 0x2, 0x4a, 0x4d, 
    0x7, 0x29, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x10, 0x2, 0x2, 0x4c, 0x4e, 0x7, 
    0x29, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x16, 0x2, 
    0x2, 0x50, 0x51, 0x5, 0x8, 0x5, 0x2, 0x51, 0x52, 0x7, 0x17, 0x2, 0x2, 
    0x52, 0x7, 0x3, 0x2, 0x2, 0x2, 0x53, 0x56, 0x5, 0x16, 0xc, 0x2, 0x54, 
    0x56, 0x5, 0xa, 0x6, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x9, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 
    0x11, 0x2, 0x2, 0x58, 0x59, 0x7, 0x29, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x14, 
    0x2, 0x2, 0x5a, 0x5b, 0x5, 0xc, 0x7, 0x2, 0x5b, 0x5c, 0x7, 0x15, 0x2, 
    0x2, 0x5c, 0x5d, 0x7, 0x3, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x29, 0x2, 0x2, 
    0x5e, 0x5f, 0x5, 0xe, 0x8, 0x2, 0x5f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x61, 0x7, 0x29, 0x2, 0x2, 0x61, 0x62, 0x7, 0x29, 0x2, 0x2, 0x62, 0x69, 
    0x8, 0x7, 0x1, 0x2, 0x63, 0x64, 0x7, 0x4, 0x2, 0x2, 0x64, 0x65, 0x7, 
    0x29, 0x2, 0x2, 0x65, 0x66, 0x7, 0x29, 0x2, 0x2, 0x66, 0x68, 0x8, 0x7, 
    0x1, 0x2, 0x67, 0x63, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x73, 0x7, 0x16, 0x2, 0x2, 0x6f, 0x70, 0x5, 
    0x10, 0x9, 0x2, 0x70, 0x71, 0x7, 0x28, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x74, 0x7, 0x28, 0x2, 0x2, 0x73, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x17, 0x2, 0x2, 0x78, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x85, 0x5, 0x16, 0xc, 0x2, 0x7a, 0x85, 0x5, 
    0x18, 0xd, 0x2, 0x7b, 0x85, 0x5, 0x1a, 0xe, 0x2, 0x7c, 0x85, 0x5, 0x1c, 
    0xf, 0x2, 0x7d, 0x85, 0x5, 0x1e, 0x10, 0x2, 0x7e, 0x85, 0x5, 0x22, 0x12, 
    0x2, 0x7f, 0x85, 0x5, 0x24, 0x13, 0x2, 0x80, 0x85, 0x5, 0x20, 0x11, 
    0x2, 0x81, 0x85, 0x5, 0x26, 0x14, 0x2, 0x82, 0x85, 0x5, 0x12, 0xa, 0x2, 
    0x83, 0x85, 0x5, 0x14, 0xb, 0x2, 0x84, 0x79, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x84, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x87, 0x7, 0x13, 0x2, 0x2, 0x87, 0x88, 0x7, 0x14, 0x2, 0x2, 0x88, 
    0x89, 0x5, 0x26, 0x14, 0x2, 0x89, 0x8a, 0x7, 0x15, 0x2, 0x2, 0x8a, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x12, 0x2, 0x2, 0x8c, 0x8d, 0x7, 
    0x14, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x26, 0x14, 0x2, 0x8e, 0x8f, 0x7, 0x15, 
    0x2, 0x2, 0x8f, 0x15, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x7, 0x29, 0x2, 
    0x2, 0x91, 0x92, 0x7, 0x29, 0x2, 0x2, 0x92, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0x94, 0x7, 0x29, 0x2, 0x2, 0x94, 0x95, 0x7, 0x5, 0x2, 0x2, 0x95, 
    0x96, 0x5, 0x26, 0x14, 0x2, 0x96, 0x19, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 
    0x7, 0x29, 0x2, 0x2, 0x98, 0x99, 0x7, 0x29, 0x2, 0x2, 0x99, 0x9a, 0x7, 
    0x5, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x26, 0x14, 0x2, 0x9b, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x9d, 0x7, 0x18, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x26, 0x14, 
    0x2, 0x9e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x19, 0x2, 0x2, 
    0xa0, 0xa1, 0x5, 0x3a, 0x1e, 0x2, 0xa1, 0xa2, 0x5, 0xe, 0x8, 0x2, 0xa2, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0xd, 0x2, 0x2, 0xa4, 0xa5, 
    0x7, 0x14, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x29, 0x2, 0x2, 0xa6, 0xa7, 0x7, 
    0xe, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x26, 0x14, 0x2, 0xa8, 0xa9, 0x5, 0xe, 
    0x8, 0x2, 0xa9, 0x21, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x1a, 0x2, 
    0x2, 0xab, 0xac, 0x5, 0x3a, 0x1e, 0x2, 0xac, 0xad, 0x5, 0xe, 0x8, 0x2, 
    0xad, 0x23, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x1a, 0x2, 0x2, 0xaf, 
    0xb0, 0x5, 0x3a, 0x1e, 0x2, 0xb0, 0xb1, 0x5, 0xe, 0x8, 0x2, 0xb1, 0xb2, 
    0x7, 0x1b, 0x2, 0x2, 0xb2, 0xb3, 0x5, 0xe, 0x8, 0x2, 0xb3, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb5, 0x8, 0x14, 0x1, 0x2, 0xb5, 0xc0, 0x5, 0x2e, 
    0x18, 0x2, 0xb6, 0xb7, 0x7, 0xc, 0x2, 0x2, 0xb7, 0xc0, 0x5, 0x26, 0x14, 
    0xc, 0xb8, 0xc0, 0x5, 0x30, 0x19, 0x2, 0xb9, 0xc0, 0x5, 0x2c, 0x17, 
    0x2, 0xba, 0xc0, 0x5, 0x2a, 0x16, 0x2, 0xbb, 0xc0, 0x5, 0x32, 0x1a, 
    0x2, 0xbc, 0xc0, 0x5, 0x36, 0x1c, 0x2, 0xbd, 0xc0, 0x5, 0x28, 0x15, 
    0x2, 0xbe, 0xc0, 0x5, 0x3a, 0x1e, 0x2, 0xbf, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xcc, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xc2, 0xc, 0x6, 0x2, 0x2, 0xc2, 0xc3, 0x5, 0x38, 0x1d, 
    0x2, 0xc3, 0xc4, 0x5, 0x26, 0x14, 0x7, 0xc4, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xc6, 0xc, 0x8, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x6, 0x2, 0x2, 0xc7, 
    0xc8, 0x5, 0x26, 0x14, 0x2, 0xc8, 0xc9, 0x7, 0x7, 0x2, 0x2, 0xc9, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc5, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd5, 0x7, 0x6, 0x2, 0x2, 
    0xd0, 0xd3, 0x5, 0x26, 0x14, 0x2, 0xd1, 0xd2, 0x7, 0x4, 0x2, 0x2, 0xd2, 
    0xd4, 0x5, 0x26, 0x14, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd8, 0x7, 0x7, 0x2, 0x2, 0xd8, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xda, 0x7, 0x29, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x8, 0x2, 0x2, 
    0xdb, 0xdc, 0x7, 0x29, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x14, 0x2, 0x2, 0xdd, 
    0xde, 0x5, 0x34, 0x1b, 0x2, 0xde, 0xdf, 0x7, 0x15, 0x2, 0x2, 0xdf, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x2b, 0x2, 0x2, 0xe1, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x2a, 0x2, 0x2, 0xe3, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe5, 0x7, 0x29, 0x2, 0x2, 0xe5, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe7, 0x7, 0x29, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x14, 0x2, 0x2, 
    0xe8, 0xe9, 0x5, 0x34, 0x1b, 0x2, 0xe9, 0xea, 0x7, 0x15, 0x2, 0x2, 0xea, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xf0, 0x5, 0x26, 0x14, 0x2, 0xec, 0xed, 
    0x7, 0x4, 0x2, 0x2, 0xed, 0xef, 0x5, 0x26, 0x14, 0x2, 0xee, 0xec, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x35, 0x3, 0x2, 0x2, 0x2, 0xf5, 
    0xf6, 0x7, 0x21, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x26, 0x14, 0x2, 0xf7, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x9, 0x2, 0x2, 0x2, 0xf9, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x14, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x26, 
    0x14, 0x2, 0xfc, 0xfd, 0x7, 0x15, 0x2, 0x2, 0xfd, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x13, 0x3e, 0x40, 0x47, 0x4d, 0x55, 0x69, 0x6c, 0x73, 0x75, 0x84, 
    0xbf, 0xca, 0xcc, 0xd3, 0xd5, 0xf0, 0xf3, 
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
