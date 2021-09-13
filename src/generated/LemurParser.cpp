
    #include <vector>
    #include <string>


// Generated from Lemur.g4 by ANTLR 4.7.2


#include "LemurListener.h"
#include "LemurVisitor.h"

#include "LemurParser.h"


using namespace antlrcpp;
using namespace antlr4;

LemurParser::LemurParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LemurParser::~LemurParser() {
  delete _interpreter;
}

std::string LemurParser::getGrammarFileName() const {
  return "Lemur.g4";
}

const std::vector<std::string>& LemurParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LemurParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

LemurParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::FileContext::EOF() {
  return getToken(LemurParser::EOF, 0);
}

std::vector<LemurParser::GlobalstmtContext *> LemurParser::FileContext::globalstmt() {
  return getRuleContexts<LemurParser::GlobalstmtContext>();
}

LemurParser::GlobalstmtContext* LemurParser::FileContext::globalstmt(size_t i) {
  return getRuleContext<LemurParser::GlobalstmtContext>(i);
}

std::vector<tree::TerminalNode *> LemurParser::FileContext::NEWLINE() {
  return getTokens(LemurParser::NEWLINE);
}

tree::TerminalNode* LemurParser::FileContext::NEWLINE(size_t i) {
  return getToken(LemurParser::NEWLINE, i);
}


size_t LemurParser::FileContext::getRuleIndex() const {
  return LemurParser::RuleFile;
}

void LemurParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void LemurParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any LemurParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::FileContext* LemurParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, LemurParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LemurParser::CLASS)
      | (1ULL << LemurParser::DEF)
      | (1ULL << LemurParser::NEWLINE))) != 0)) {
      setState(62);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LemurParser::CLASS:
        case LemurParser::DEF: {
          setState(60);
          globalstmt();
          break;
        }

        case LemurParser::NEWLINE: {
          setState(61);
          match(LemurParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(66);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(67);
    match(LemurParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalstmtContext ------------------------------------------------------------------

LemurParser::GlobalstmtContext::GlobalstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LemurParser::ClassdefContext* LemurParser::GlobalstmtContext::classdef() {
  return getRuleContext<LemurParser::ClassdefContext>(0);
}

LemurParser::FunctiondefContext* LemurParser::GlobalstmtContext::functiondef() {
  return getRuleContext<LemurParser::FunctiondefContext>(0);
}


size_t LemurParser::GlobalstmtContext::getRuleIndex() const {
  return LemurParser::RuleGlobalstmt;
}

void LemurParser::GlobalstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalstmt(this);
}

void LemurParser::GlobalstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalstmt(this);
}


antlrcpp::Any LemurParser::GlobalstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitGlobalstmt(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::GlobalstmtContext* LemurParser::globalstmt() {
  GlobalstmtContext *_localctx = _tracker.createInstance<GlobalstmtContext>(_ctx, getState());
  enterRule(_localctx, 2, LemurParser::RuleGlobalstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LemurParser::CLASS: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        classdef();
        break;
      }

      case LemurParser::DEF: {
        enterOuterAlt(_localctx, 2);
        setState(70);
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

LemurParser::ClassdefContext::ClassdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::ClassdefContext::CLASS() {
  return getToken(LemurParser::CLASS, 0);
}

tree::TerminalNode* LemurParser::ClassdefContext::LEFTBRACE() {
  return getToken(LemurParser::LEFTBRACE, 0);
}

tree::TerminalNode* LemurParser::ClassdefContext::RIGHTBRACE() {
  return getToken(LemurParser::RIGHTBRACE, 0);
}

std::vector<tree::TerminalNode *> LemurParser::ClassdefContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::ClassdefContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}

LemurParser::ClassbodyContext* LemurParser::ClassdefContext::classbody() {
  return getRuleContext<LemurParser::ClassbodyContext>(0);
}

tree::TerminalNode* LemurParser::ClassdefContext::ARROW() {
  return getToken(LemurParser::ARROW, 0);
}


size_t LemurParser::ClassdefContext::getRuleIndex() const {
  return LemurParser::RuleClassdef;
}

void LemurParser::ClassdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassdef(this);
}

void LemurParser::ClassdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassdef(this);
}


antlrcpp::Any LemurParser::ClassdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitClassdef(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ClassdefContext* LemurParser::classdef() {
  ClassdefContext *_localctx = _tracker.createInstance<ClassdefContext>(_ctx, getState());
  enterRule(_localctx, 4, LemurParser::RuleClassdef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    match(LemurParser::CLASS);
    setState(74);
    dynamic_cast<ClassdefContext *>(_localctx)->cName = match(LemurParser::NAME);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LemurParser::ARROW) {
      setState(75);
      match(LemurParser::ARROW);
      setState(76);
      dynamic_cast<ClassdefContext *>(_localctx)->baseName = match(LemurParser::NAME);
    }
    setState(79);
    match(LemurParser::LEFTBRACE);
    setState(80);
    dynamic_cast<ClassdefContext *>(_localctx)->body = classbody();
    setState(81);
    match(LemurParser::RIGHTBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassbodyContext ------------------------------------------------------------------

LemurParser::ClassbodyContext::ClassbodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LemurParser::ClassvardeclContext *> LemurParser::ClassbodyContext::classvardecl() {
  return getRuleContexts<LemurParser::ClassvardeclContext>();
}

LemurParser::ClassvardeclContext* LemurParser::ClassbodyContext::classvardecl(size_t i) {
  return getRuleContext<LemurParser::ClassvardeclContext>(i);
}

std::vector<LemurParser::ClassfunctiondefContext *> LemurParser::ClassbodyContext::classfunctiondef() {
  return getRuleContexts<LemurParser::ClassfunctiondefContext>();
}

LemurParser::ClassfunctiondefContext* LemurParser::ClassbodyContext::classfunctiondef(size_t i) {
  return getRuleContext<LemurParser::ClassfunctiondefContext>(i);
}

std::vector<tree::TerminalNode *> LemurParser::ClassbodyContext::NEWLINE() {
  return getTokens(LemurParser::NEWLINE);
}

tree::TerminalNode* LemurParser::ClassbodyContext::NEWLINE(size_t i) {
  return getToken(LemurParser::NEWLINE, i);
}


size_t LemurParser::ClassbodyContext::getRuleIndex() const {
  return LemurParser::RuleClassbody;
}

void LemurParser::ClassbodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassbody(this);
}

void LemurParser::ClassbodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassbody(this);
}


antlrcpp::Any LemurParser::ClassbodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitClassbody(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ClassbodyContext* LemurParser::classbody() {
  ClassbodyContext *_localctx = _tracker.createInstance<ClassbodyContext>(_ctx, getState());
  enterRule(_localctx, 6, LemurParser::RuleClassbody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LemurParser::DEF)
      | (1ULL << LemurParser::NEWLINE)
      | (1ULL << LemurParser::NAME))) != 0)) {
      setState(86);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LemurParser::NAME: {
          setState(83);
          classvardecl();
          break;
        }

        case LemurParser::DEF: {
          setState(84);
          classfunctiondef();
          break;
        }

        case LemurParser::NEWLINE: {
          setState(85);
          match(LemurParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassvardeclContext ------------------------------------------------------------------

LemurParser::ClassvardeclContext::ClassvardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LemurParser::ClassvardeclContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::ClassvardeclContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}


size_t LemurParser::ClassvardeclContext::getRuleIndex() const {
  return LemurParser::RuleClassvardecl;
}

void LemurParser::ClassvardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassvardecl(this);
}

void LemurParser::ClassvardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassvardecl(this);
}


antlrcpp::Any LemurParser::ClassvardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitClassvardecl(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ClassvardeclContext* LemurParser::classvardecl() {
  ClassvardeclContext *_localctx = _tracker.createInstance<ClassvardeclContext>(_ctx, getState());
  enterRule(_localctx, 8, LemurParser::RuleClassvardecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    dynamic_cast<ClassvardeclContext *>(_localctx)->typeName = match(LemurParser::NAME);
    setState(92);
    dynamic_cast<ClassvardeclContext *>(_localctx)->varName = match(LemurParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassfunctiondefContext ------------------------------------------------------------------

LemurParser::ClassfunctiondefContext::ClassfunctiondefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::ClassfunctiondefContext::DEF() {
  return getToken(LemurParser::DEF, 0);
}

tree::TerminalNode* LemurParser::ClassfunctiondefContext::OPEN() {
  return getToken(LemurParser::OPEN, 0);
}

tree::TerminalNode* LemurParser::ClassfunctiondefContext::CLOSED() {
  return getToken(LemurParser::CLOSED, 0);
}

std::vector<tree::TerminalNode *> LemurParser::ClassfunctiondefContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::ClassfunctiondefContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}

LemurParser::ParamlistContext* LemurParser::ClassfunctiondefContext::paramlist() {
  return getRuleContext<LemurParser::ParamlistContext>(0);
}

LemurParser::BlockContext* LemurParser::ClassfunctiondefContext::block() {
  return getRuleContext<LemurParser::BlockContext>(0);
}


size_t LemurParser::ClassfunctiondefContext::getRuleIndex() const {
  return LemurParser::RuleClassfunctiondef;
}

void LemurParser::ClassfunctiondefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassfunctiondef(this);
}

void LemurParser::ClassfunctiondefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassfunctiondef(this);
}


antlrcpp::Any LemurParser::ClassfunctiondefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitClassfunctiondef(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ClassfunctiondefContext* LemurParser::classfunctiondef() {
  ClassfunctiondefContext *_localctx = _tracker.createInstance<ClassfunctiondefContext>(_ctx, getState());
  enterRule(_localctx, 10, LemurParser::RuleClassfunctiondef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(LemurParser::DEF);
    setState(95);
    dynamic_cast<ClassfunctiondefContext *>(_localctx)->fName = match(LemurParser::NAME);
    setState(96);
    match(LemurParser::OPEN);
    setState(97);
    dynamic_cast<ClassfunctiondefContext *>(_localctx)->params = paramlist();
    setState(98);
    match(LemurParser::CLOSED);
    setState(101);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LemurParser::T__0) {
      setState(99);
      match(LemurParser::T__0);
      setState(100);
      dynamic_cast<ClassfunctiondefContext *>(_localctx)->retType = match(LemurParser::NAME);
    }
    setState(103);
    dynamic_cast<ClassfunctiondefContext *>(_localctx)->body = block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctiondefContext ------------------------------------------------------------------

LemurParser::FunctiondefContext::FunctiondefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::FunctiondefContext::DEF() {
  return getToken(LemurParser::DEF, 0);
}

tree::TerminalNode* LemurParser::FunctiondefContext::OPEN() {
  return getToken(LemurParser::OPEN, 0);
}

tree::TerminalNode* LemurParser::FunctiondefContext::CLOSED() {
  return getToken(LemurParser::CLOSED, 0);
}

std::vector<tree::TerminalNode *> LemurParser::FunctiondefContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::FunctiondefContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}

LemurParser::ParamlistContext* LemurParser::FunctiondefContext::paramlist() {
  return getRuleContext<LemurParser::ParamlistContext>(0);
}

LemurParser::BlockContext* LemurParser::FunctiondefContext::block() {
  return getRuleContext<LemurParser::BlockContext>(0);
}


size_t LemurParser::FunctiondefContext::getRuleIndex() const {
  return LemurParser::RuleFunctiondef;
}

void LemurParser::FunctiondefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctiondef(this);
}

void LemurParser::FunctiondefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctiondef(this);
}


antlrcpp::Any LemurParser::FunctiondefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitFunctiondef(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::FunctiondefContext* LemurParser::functiondef() {
  FunctiondefContext *_localctx = _tracker.createInstance<FunctiondefContext>(_ctx, getState());
  enterRule(_localctx, 12, LemurParser::RuleFunctiondef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(LemurParser::DEF);
    setState(106);
    dynamic_cast<FunctiondefContext *>(_localctx)->fName = match(LemurParser::NAME);
    setState(107);
    match(LemurParser::OPEN);
    setState(108);
    dynamic_cast<FunctiondefContext *>(_localctx)->params = paramlist();
    setState(109);
    match(LemurParser::CLOSED);
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LemurParser::T__0) {
      setState(110);
      match(LemurParser::T__0);
      setState(111);
      dynamic_cast<FunctiondefContext *>(_localctx)->retType = match(LemurParser::NAME);
    }
    setState(114);
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

LemurParser::ParamlistContext::ParamlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LemurParser::ParamlistContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::ParamlistContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}


size_t LemurParser::ParamlistContext::getRuleIndex() const {
  return LemurParser::RuleParamlist;
}

void LemurParser::ParamlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamlist(this);
}

void LemurParser::ParamlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamlist(this);
}


antlrcpp::Any LemurParser::ParamlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitParamlist(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ParamlistContext* LemurParser::paramlist() {
  ParamlistContext *_localctx = _tracker.createInstance<ParamlistContext>(_ctx, getState());
  enterRule(_localctx, 14, LemurParser::RuleParamlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LemurParser::NAME) {
      setState(116);
      dynamic_cast<ParamlistContext *>(_localctx)->typeName = match(LemurParser::NAME);
      setState(117);
      dynamic_cast<ParamlistContext *>(_localctx)->varName = match(LemurParser::NAME);
      _localctx->types.push_back((dynamic_cast<ParamlistContext *>(_localctx)->typeName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->typeName->getText() : ""));_localctx->vars.push_back((dynamic_cast<ParamlistContext *>(_localctx)->varName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->varName->getText() : ""));
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LemurParser::T__1) {
        setState(119);
        match(LemurParser::T__1);
        setState(120);
        dynamic_cast<ParamlistContext *>(_localctx)->typeName = match(LemurParser::NAME);
        setState(121);
        dynamic_cast<ParamlistContext *>(_localctx)->varName = match(LemurParser::NAME);
        {_localctx->types.push_back((dynamic_cast<ParamlistContext *>(_localctx)->typeName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->typeName->getText() : ""));_localctx->vars.push_back((dynamic_cast<ParamlistContext *>(_localctx)->varName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->varName->getText() : ""));}
        setState(127);
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

LemurParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::BlockContext::LEFTBRACE() {
  return getToken(LemurParser::LEFTBRACE, 0);
}

tree::TerminalNode* LemurParser::BlockContext::RIGHTBRACE() {
  return getToken(LemurParser::RIGHTBRACE, 0);
}

std::vector<tree::TerminalNode *> LemurParser::BlockContext::NEWLINE() {
  return getTokens(LemurParser::NEWLINE);
}

tree::TerminalNode* LemurParser::BlockContext::NEWLINE(size_t i) {
  return getToken(LemurParser::NEWLINE, i);
}

std::vector<LemurParser::StmtContext *> LemurParser::BlockContext::stmt() {
  return getRuleContexts<LemurParser::StmtContext>();
}

LemurParser::StmtContext* LemurParser::BlockContext::stmt(size_t i) {
  return getRuleContext<LemurParser::StmtContext>(i);
}


size_t LemurParser::BlockContext::getRuleIndex() const {
  return LemurParser::RuleBlock;
}

void LemurParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void LemurParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any LemurParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::BlockContext* LemurParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, LemurParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(LemurParser::LEFTBRACE);
    setState(135); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(135);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LemurParser::T__4:
        case LemurParser::UMINUS:
        case LemurParser::FOR:
        case LemurParser::PRINT:
        case LemurParser::OPEN:
        case LemurParser::RET:
        case LemurParser::WHILE:
        case LemurParser::IF:
        case LemurParser::NEG:
        case LemurParser::NAME:
        case LemurParser::INT:
        case LemurParser::FLOAT:
        case LemurParser::STRING: {
          setState(131);
          stmt();
          setState(132);
          match(LemurParser::NEWLINE);
          break;
        }

        case LemurParser::NEWLINE: {
          setState(134);
          match(LemurParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(137); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LemurParser::T__4)
      | (1ULL << LemurParser::UMINUS)
      | (1ULL << LemurParser::FOR)
      | (1ULL << LemurParser::PRINT)
      | (1ULL << LemurParser::OPEN)
      | (1ULL << LemurParser::RET)
      | (1ULL << LemurParser::WHILE)
      | (1ULL << LemurParser::IF)
      | (1ULL << LemurParser::NEG)
      | (1ULL << LemurParser::NEWLINE)
      | (1ULL << LemurParser::NAME)
      | (1ULL << LemurParser::INT)
      | (1ULL << LemurParser::FLOAT)
      | (1ULL << LemurParser::STRING))) != 0));
    setState(139);
    match(LemurParser::RIGHTBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

LemurParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LemurParser::VardeclContext* LemurParser::StmtContext::vardecl() {
  return getRuleContext<LemurParser::VardeclContext>(0);
}

LemurParser::AssignContext* LemurParser::StmtContext::assign() {
  return getRuleContext<LemurParser::AssignContext>(0);
}

LemurParser::DeclassignContext* LemurParser::StmtContext::declassign() {
  return getRuleContext<LemurParser::DeclassignContext>(0);
}

LemurParser::RetContext* LemurParser::StmtContext::ret() {
  return getRuleContext<LemurParser::RetContext>(0);
}

LemurParser::WhileloopContext* LemurParser::StmtContext::whileloop() {
  return getRuleContext<LemurParser::WhileloopContext>(0);
}

LemurParser::IfExprContext* LemurParser::StmtContext::ifExpr() {
  return getRuleContext<LemurParser::IfExprContext>(0);
}

LemurParser::IfElseExprContext* LemurParser::StmtContext::ifElseExpr() {
  return getRuleContext<LemurParser::IfElseExprContext>(0);
}

LemurParser::ForloopContext* LemurParser::StmtContext::forloop() {
  return getRuleContext<LemurParser::ForloopContext>(0);
}

LemurParser::ExprContext* LemurParser::StmtContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}

LemurParser::PrintstmtContext* LemurParser::StmtContext::printstmt() {
  return getRuleContext<LemurParser::PrintstmtContext>(0);
}


size_t LemurParser::StmtContext::getRuleIndex() const {
  return LemurParser::RuleStmt;
}

void LemurParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void LemurParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any LemurParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::StmtContext* LemurParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 18, LemurParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(141);
      vardecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(142);
      assign();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(143);
      declassign();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(144);
      ret();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(145);
      whileloop();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(146);
      ifExpr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(147);
      ifElseExpr();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(148);
      forloop();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(149);
      expr(0);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(150);
      printstmt();
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

LemurParser::PrintstmtContext::PrintstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::PrintstmtContext::PRINT() {
  return getToken(LemurParser::PRINT, 0);
}

tree::TerminalNode* LemurParser::PrintstmtContext::OPEN() {
  return getToken(LemurParser::OPEN, 0);
}

LemurParser::ExprContext* LemurParser::PrintstmtContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}

tree::TerminalNode* LemurParser::PrintstmtContext::CLOSED() {
  return getToken(LemurParser::CLOSED, 0);
}


size_t LemurParser::PrintstmtContext::getRuleIndex() const {
  return LemurParser::RulePrintstmt;
}

void LemurParser::PrintstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintstmt(this);
}

void LemurParser::PrintstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintstmt(this);
}


antlrcpp::Any LemurParser::PrintstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitPrintstmt(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::PrintstmtContext* LemurParser::printstmt() {
  PrintstmtContext *_localctx = _tracker.createInstance<PrintstmtContext>(_ctx, getState());
  enterRule(_localctx, 20, LemurParser::RulePrintstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(LemurParser::PRINT);
    setState(154);
    match(LemurParser::OPEN);
    setState(155);
    expr(0);
    setState(156);
    match(LemurParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

LemurParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LemurParser::VardeclContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::VardeclContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}


size_t LemurParser::VardeclContext::getRuleIndex() const {
  return LemurParser::RuleVardecl;
}

void LemurParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void LemurParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


antlrcpp::Any LemurParser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::VardeclContext* LemurParser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 22, LemurParser::RuleVardecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    dynamic_cast<VardeclContext *>(_localctx)->typeName = match(LemurParser::NAME);
    setState(159);
    dynamic_cast<VardeclContext *>(_localctx)->varName = match(LemurParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

LemurParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LemurParser::ExprContext* LemurParser::AssignContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> LemurParser::AssignContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::AssignContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}


size_t LemurParser::AssignContext::getRuleIndex() const {
  return LemurParser::RuleAssign;
}

void LemurParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void LemurParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


antlrcpp::Any LemurParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::AssignContext* LemurParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 24, LemurParser::RuleAssign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    dynamic_cast<AssignContext *>(_localctx)->varName = match(LemurParser::NAME);
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LemurParser::T__2) {
      setState(162);
      match(LemurParser::T__2);
      setState(163);
      dynamic_cast<AssignContext *>(_localctx)->subName = match(LemurParser::NAME);
    }
    setState(166);
    match(LemurParser::T__3);
    setState(167);
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

LemurParser::DeclassignContext::DeclassignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LemurParser::ExprContext* LemurParser::DeclassignContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> LemurParser::DeclassignContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::DeclassignContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}


size_t LemurParser::DeclassignContext::getRuleIndex() const {
  return LemurParser::RuleDeclassign;
}

void LemurParser::DeclassignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclassign(this);
}

void LemurParser::DeclassignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclassign(this);
}


antlrcpp::Any LemurParser::DeclassignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitDeclassign(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::DeclassignContext* LemurParser::declassign() {
  DeclassignContext *_localctx = _tracker.createInstance<DeclassignContext>(_ctx, getState());
  enterRule(_localctx, 26, LemurParser::RuleDeclassign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    dynamic_cast<DeclassignContext *>(_localctx)->typeName = match(LemurParser::NAME);
    setState(170);
    dynamic_cast<DeclassignContext *>(_localctx)->varName = match(LemurParser::NAME);
    setState(171);
    match(LemurParser::T__3);
    setState(172);
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

LemurParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::RetContext::RET() {
  return getToken(LemurParser::RET, 0);
}

LemurParser::ExprContext* LemurParser::RetContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}


size_t LemurParser::RetContext::getRuleIndex() const {
  return LemurParser::RuleRet;
}

void LemurParser::RetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet(this);
}

void LemurParser::RetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet(this);
}


antlrcpp::Any LemurParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::RetContext* LemurParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 28, LemurParser::RuleRet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(LemurParser::RET);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LemurParser::T__4)
      | (1ULL << LemurParser::UMINUS)
      | (1ULL << LemurParser::OPEN)
      | (1ULL << LemurParser::NEG)
      | (1ULL << LemurParser::NAME)
      | (1ULL << LemurParser::INT)
      | (1ULL << LemurParser::FLOAT)
      | (1ULL << LemurParser::STRING))) != 0)) {
      setState(175);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileloopContext ------------------------------------------------------------------

LemurParser::WhileloopContext::WhileloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::WhileloopContext::WHILE() {
  return getToken(LemurParser::WHILE, 0);
}

LemurParser::BracedexprContext* LemurParser::WhileloopContext::bracedexpr() {
  return getRuleContext<LemurParser::BracedexprContext>(0);
}

LemurParser::BlockContext* LemurParser::WhileloopContext::block() {
  return getRuleContext<LemurParser::BlockContext>(0);
}


size_t LemurParser::WhileloopContext::getRuleIndex() const {
  return LemurParser::RuleWhileloop;
}

void LemurParser::WhileloopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileloop(this);
}

void LemurParser::WhileloopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileloop(this);
}


antlrcpp::Any LemurParser::WhileloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitWhileloop(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::WhileloopContext* LemurParser::whileloop() {
  WhileloopContext *_localctx = _tracker.createInstance<WhileloopContext>(_ctx, getState());
  enterRule(_localctx, 30, LemurParser::RuleWhileloop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(LemurParser::WHILE);
    setState(179);
    bracedexpr();
    setState(180);
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

LemurParser::ForloopContext::ForloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::ForloopContext::FOR() {
  return getToken(LemurParser::FOR, 0);
}

tree::TerminalNode* LemurParser::ForloopContext::OPEN() {
  return getToken(LemurParser::OPEN, 0);
}

tree::TerminalNode* LemurParser::ForloopContext::IN() {
  return getToken(LemurParser::IN, 0);
}

LemurParser::BlockContext* LemurParser::ForloopContext::block() {
  return getRuleContext<LemurParser::BlockContext>(0);
}

tree::TerminalNode* LemurParser::ForloopContext::NAME() {
  return getToken(LemurParser::NAME, 0);
}

LemurParser::ExprContext* LemurParser::ForloopContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}


size_t LemurParser::ForloopContext::getRuleIndex() const {
  return LemurParser::RuleForloop;
}

void LemurParser::ForloopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForloop(this);
}

void LemurParser::ForloopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForloop(this);
}


antlrcpp::Any LemurParser::ForloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitForloop(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ForloopContext* LemurParser::forloop() {
  ForloopContext *_localctx = _tracker.createInstance<ForloopContext>(_ctx, getState());
  enterRule(_localctx, 32, LemurParser::RuleForloop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(LemurParser::FOR);
    setState(183);
    match(LemurParser::OPEN);
    setState(184);
    dynamic_cast<ForloopContext *>(_localctx)->varName = match(LemurParser::NAME);
    setState(185);
    match(LemurParser::IN);
    setState(186);
    dynamic_cast<ForloopContext *>(_localctx)->listName = expr(0);
    setState(187);
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

LemurParser::IfExprContext::IfExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::IfExprContext::IF() {
  return getToken(LemurParser::IF, 0);
}

LemurParser::BracedexprContext* LemurParser::IfExprContext::bracedexpr() {
  return getRuleContext<LemurParser::BracedexprContext>(0);
}

LemurParser::BlockContext* LemurParser::IfExprContext::block() {
  return getRuleContext<LemurParser::BlockContext>(0);
}


size_t LemurParser::IfExprContext::getRuleIndex() const {
  return LemurParser::RuleIfExpr;
}

void LemurParser::IfExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfExpr(this);
}

void LemurParser::IfExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfExpr(this);
}


antlrcpp::Any LemurParser::IfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitIfExpr(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::IfExprContext* LemurParser::ifExpr() {
  IfExprContext *_localctx = _tracker.createInstance<IfExprContext>(_ctx, getState());
  enterRule(_localctx, 34, LemurParser::RuleIfExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(LemurParser::IF);
    setState(190);
    dynamic_cast<IfExprContext *>(_localctx)->cond = bracedexpr();
    setState(191);
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

LemurParser::IfElseExprContext::IfElseExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::IfElseExprContext::IF() {
  return getToken(LemurParser::IF, 0);
}

std::vector<LemurParser::BlockContext *> LemurParser::IfElseExprContext::block() {
  return getRuleContexts<LemurParser::BlockContext>();
}

LemurParser::BlockContext* LemurParser::IfElseExprContext::block(size_t i) {
  return getRuleContext<LemurParser::BlockContext>(i);
}

tree::TerminalNode* LemurParser::IfElseExprContext::ELSE() {
  return getToken(LemurParser::ELSE, 0);
}

LemurParser::BracedexprContext* LemurParser::IfElseExprContext::bracedexpr() {
  return getRuleContext<LemurParser::BracedexprContext>(0);
}

std::vector<tree::TerminalNode *> LemurParser::IfElseExprContext::NEWLINE() {
  return getTokens(LemurParser::NEWLINE);
}

tree::TerminalNode* LemurParser::IfElseExprContext::NEWLINE(size_t i) {
  return getToken(LemurParser::NEWLINE, i);
}


size_t LemurParser::IfElseExprContext::getRuleIndex() const {
  return LemurParser::RuleIfElseExpr;
}

void LemurParser::IfElseExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfElseExpr(this);
}

void LemurParser::IfElseExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfElseExpr(this);
}


antlrcpp::Any LemurParser::IfElseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitIfElseExpr(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::IfElseExprContext* LemurParser::ifElseExpr() {
  IfElseExprContext *_localctx = _tracker.createInstance<IfElseExprContext>(_ctx, getState());
  enterRule(_localctx, 36, LemurParser::RuleIfElseExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(LemurParser::IF);
    setState(194);
    dynamic_cast<IfElseExprContext *>(_localctx)->cond = bracedexpr();
    setState(195);
    block();
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LemurParser::NEWLINE) {
      setState(196);
      match(LemurParser::NEWLINE);
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(202);
    match(LemurParser::ELSE);
    setState(203);
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

LemurParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LemurParser::ExprContext::getRuleIndex() const {
  return LemurParser::RuleExpr;
}

void LemurParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringRuleContext ------------------------------------------------------------------

LemurParser::StringContext* LemurParser::StringRuleContext::string() {
  return getRuleContext<LemurParser::StringContext>(0);
}

LemurParser::StringRuleContext::StringRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::StringRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringRule(this);
}
void LemurParser::StringRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringRule(this);
}

antlrcpp::Any LemurParser::StringRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitStringRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OpExprRuleContext ------------------------------------------------------------------

LemurParser::BinoperatorContext* LemurParser::OpExprRuleContext::binoperator() {
  return getRuleContext<LemurParser::BinoperatorContext>(0);
}

std::vector<LemurParser::ExprContext *> LemurParser::OpExprRuleContext::expr() {
  return getRuleContexts<LemurParser::ExprContext>();
}

LemurParser::ExprContext* LemurParser::OpExprRuleContext::expr(size_t i) {
  return getRuleContext<LemurParser::ExprContext>(i);
}

LemurParser::OpExprRuleContext::OpExprRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::OpExprRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpExprRule(this);
}
void LemurParser::OpExprRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpExprRule(this);
}

antlrcpp::Any LemurParser::OpExprRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitOpExprRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexRuleContext ------------------------------------------------------------------

std::vector<LemurParser::ExprContext *> LemurParser::IndexRuleContext::expr() {
  return getRuleContexts<LemurParser::ExprContext>();
}

LemurParser::ExprContext* LemurParser::IndexRuleContext::expr(size_t i) {
  return getRuleContext<LemurParser::ExprContext>(i);
}

LemurParser::IndexRuleContext::IndexRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::IndexRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexRule(this);
}
void LemurParser::IndexRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexRule(this);
}

antlrcpp::Any LemurParser::IndexRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitIndexRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodRuleContext ------------------------------------------------------------------

LemurParser::MethodCallContext* LemurParser::MethodRuleContext::methodCall() {
  return getRuleContext<LemurParser::MethodCallContext>(0);
}

LemurParser::MethodRuleContext::MethodRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::MethodRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodRule(this);
}
void LemurParser::MethodRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodRule(this);
}

antlrcpp::Any LemurParser::MethodRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitMethodRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListRuleContext ------------------------------------------------------------------

LemurParser::ListContext* LemurParser::ListRuleContext::list() {
  return getRuleContext<LemurParser::ListContext>(0);
}

LemurParser::ListRuleContext::ListRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::ListRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListRule(this);
}
void LemurParser::ListRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListRule(this);
}

antlrcpp::Any LemurParser::ListRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitListRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRuleContext ------------------------------------------------------------------

LemurParser::NumberContext* LemurParser::NumberRuleContext::number() {
  return getRuleContext<LemurParser::NumberContext>(0);
}

LemurParser::NumberRuleContext::NumberRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::NumberRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRule(this);
}
void LemurParser::NumberRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRule(this);
}

antlrcpp::Any LemurParser::NumberRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitNumberRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UminusRuleContext ------------------------------------------------------------------

tree::TerminalNode* LemurParser::UminusRuleContext::UMINUS() {
  return getToken(LemurParser::UMINUS, 0);
}

LemurParser::ExprContext* LemurParser::UminusRuleContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}

LemurParser::UminusRuleContext::UminusRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::UminusRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUminusRule(this);
}
void LemurParser::UminusRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUminusRule(this);
}

antlrcpp::Any LemurParser::UminusRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitUminusRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprRuleContext ------------------------------------------------------------------

LemurParser::CallexprContext* LemurParser::CallExprRuleContext::callexpr() {
  return getRuleContext<LemurParser::CallexprContext>(0);
}

LemurParser::CallExprRuleContext::CallExprRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::CallExprRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExprRule(this);
}
void LemurParser::CallExprRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExprRule(this);
}

antlrcpp::Any LemurParser::CallExprRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitCallExprRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarRuleContext ------------------------------------------------------------------

LemurParser::VarContext* LemurParser::VarRuleContext::var() {
  return getRuleContext<LemurParser::VarContext>(0);
}

LemurParser::VarRuleContext::VarRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::VarRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarRule(this);
}
void LemurParser::VarRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarRule(this);
}

antlrcpp::Any LemurParser::VarRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitVarRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegRuleContext ------------------------------------------------------------------

LemurParser::NegContext* LemurParser::NegRuleContext::neg() {
  return getRuleContext<LemurParser::NegContext>(0);
}

LemurParser::NegRuleContext::NegRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::NegRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegRule(this);
}
void LemurParser::NegRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegRule(this);
}

antlrcpp::Any LemurParser::NegRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitNegRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BraceExprRuleContext ------------------------------------------------------------------

LemurParser::BracedexprContext* LemurParser::BraceExprRuleContext::bracedexpr() {
  return getRuleContext<LemurParser::BracedexprContext>(0);
}

LemurParser::BraceExprRuleContext::BraceExprRuleContext(ExprContext *ctx) { copyFrom(ctx); }

void LemurParser::BraceExprRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBraceExprRule(this);
}
void LemurParser::BraceExprRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBraceExprRule(this);
}

antlrcpp::Any LemurParser::BraceExprRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitBraceExprRule(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ExprContext* LemurParser::expr() {
   return expr(0);
}

LemurParser::ExprContext* LemurParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LemurParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  LemurParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, LemurParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NumberRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(206);
      number();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UminusRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(207);
      match(LemurParser::UMINUS);
      setState(208);
      expr(10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<VarRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(209);
      var();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<StringRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(210);
      string();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MethodRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(211);
      methodCall();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CallExprRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(212);
      callexpr();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<NegRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(213);
      neg();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ListRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(214);
      list();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BraceExprRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(215);
      bracedexpr();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(229);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(227);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<OpExprRuleContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->leftOp = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(218);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(219);
          binoperator();
          setState(220);
          dynamic_cast<OpExprRuleContext *>(_localctx)->rightOp = expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<IndexRuleContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(222);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(223);
          match(LemurParser::T__4);
          setState(224);
          expr(0);
          setState(225);
          match(LemurParser::T__5);
          break;
        }

        } 
      }
      setState(231);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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

LemurParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LemurParser::ExprContext *> LemurParser::ListContext::expr() {
  return getRuleContexts<LemurParser::ExprContext>();
}

LemurParser::ExprContext* LemurParser::ListContext::expr(size_t i) {
  return getRuleContext<LemurParser::ExprContext>(i);
}


size_t LemurParser::ListContext::getRuleIndex() const {
  return LemurParser::RuleList;
}

void LemurParser::ListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList(this);
}

void LemurParser::ListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList(this);
}


antlrcpp::Any LemurParser::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ListContext* LemurParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 40, LemurParser::RuleList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(LemurParser::T__4);
    setState(238);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LemurParser::T__4)
      | (1ULL << LemurParser::UMINUS)
      | (1ULL << LemurParser::OPEN)
      | (1ULL << LemurParser::NEG)
      | (1ULL << LemurParser::NAME)
      | (1ULL << LemurParser::INT)
      | (1ULL << LemurParser::FLOAT)
      | (1ULL << LemurParser::STRING))) != 0)) {
      setState(233);
      expr(0);
      setState(236);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LemurParser::T__1) {
        setState(234);
        match(LemurParser::T__1);
        setState(235);
        expr(0);
      }
    }
    setState(240);
    match(LemurParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodCallContext ------------------------------------------------------------------

LemurParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::MethodCallContext::OPEN() {
  return getToken(LemurParser::OPEN, 0);
}

tree::TerminalNode* LemurParser::MethodCallContext::CLOSED() {
  return getToken(LemurParser::CLOSED, 0);
}

std::vector<tree::TerminalNode *> LemurParser::MethodCallContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::MethodCallContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}

LemurParser::ArglistContext* LemurParser::MethodCallContext::arglist() {
  return getRuleContext<LemurParser::ArglistContext>(0);
}


size_t LemurParser::MethodCallContext::getRuleIndex() const {
  return LemurParser::RuleMethodCall;
}

void LemurParser::MethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCall(this);
}

void LemurParser::MethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCall(this);
}


antlrcpp::Any LemurParser::MethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitMethodCall(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::MethodCallContext* LemurParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 42, LemurParser::RuleMethodCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    dynamic_cast<MethodCallContext *>(_localctx)->varName = match(LemurParser::NAME);
    setState(243);
    match(LemurParser::T__2);
    setState(244);
    dynamic_cast<MethodCallContext *>(_localctx)->methodName = match(LemurParser::NAME);
    setState(245);
    match(LemurParser::OPEN);
    setState(246);
    dynamic_cast<MethodCallContext *>(_localctx)->args = arglist();
    setState(247);
    match(LemurParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

LemurParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::StringContext::STRING() {
  return getToken(LemurParser::STRING, 0);
}


size_t LemurParser::StringContext::getRuleIndex() const {
  return LemurParser::RuleString;
}

void LemurParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void LemurParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


antlrcpp::Any LemurParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::StringContext* LemurParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 44, LemurParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(LemurParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

LemurParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::NumberContext::INT() {
  return getToken(LemurParser::INT, 0);
}

tree::TerminalNode* LemurParser::NumberContext::FLOAT() {
  return getToken(LemurParser::FLOAT, 0);
}


size_t LemurParser::NumberContext::getRuleIndex() const {
  return LemurParser::RuleNumber;
}

void LemurParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void LemurParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any LemurParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::NumberContext* LemurParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 46, LemurParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _la = _input->LA(1);
    if (!(_la == LemurParser::INT

    || _la == LemurParser::FLOAT)) {
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

//----------------- VarContext ------------------------------------------------------------------

LemurParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LemurParser::VarContext::NAME() {
  return getTokens(LemurParser::NAME);
}

tree::TerminalNode* LemurParser::VarContext::NAME(size_t i) {
  return getToken(LemurParser::NAME, i);
}


size_t LemurParser::VarContext::getRuleIndex() const {
  return LemurParser::RuleVar;
}

void LemurParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void LemurParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


antlrcpp::Any LemurParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::VarContext* LemurParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 48, LemurParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    dynamic_cast<VarContext *>(_localctx)->varName = match(LemurParser::NAME);
    setState(256);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(254);
      match(LemurParser::T__2);
      setState(255);
      dynamic_cast<VarContext *>(_localctx)->subName = match(LemurParser::NAME);
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

//----------------- CallexprContext ------------------------------------------------------------------

LemurParser::CallexprContext::CallexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::CallexprContext::OPEN() {
  return getToken(LemurParser::OPEN, 0);
}

tree::TerminalNode* LemurParser::CallexprContext::CLOSED() {
  return getToken(LemurParser::CLOSED, 0);
}

tree::TerminalNode* LemurParser::CallexprContext::NAME() {
  return getToken(LemurParser::NAME, 0);
}

LemurParser::ArglistContext* LemurParser::CallexprContext::arglist() {
  return getRuleContext<LemurParser::ArglistContext>(0);
}


size_t LemurParser::CallexprContext::getRuleIndex() const {
  return LemurParser::RuleCallexpr;
}

void LemurParser::CallexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallexpr(this);
}

void LemurParser::CallexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallexpr(this);
}


antlrcpp::Any LemurParser::CallexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitCallexpr(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::CallexprContext* LemurParser::callexpr() {
  CallexprContext *_localctx = _tracker.createInstance<CallexprContext>(_ctx, getState());
  enterRule(_localctx, 50, LemurParser::RuleCallexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    dynamic_cast<CallexprContext *>(_localctx)->fName = match(LemurParser::NAME);
    setState(259);
    match(LemurParser::OPEN);
    setState(260);
    dynamic_cast<CallexprContext *>(_localctx)->args = arglist();
    setState(261);
    match(LemurParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

LemurParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LemurParser::ExprContext *> LemurParser::ArglistContext::expr() {
  return getRuleContexts<LemurParser::ExprContext>();
}

LemurParser::ExprContext* LemurParser::ArglistContext::expr(size_t i) {
  return getRuleContext<LemurParser::ExprContext>(i);
}


size_t LemurParser::ArglistContext::getRuleIndex() const {
  return LemurParser::RuleArglist;
}

void LemurParser::ArglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArglist(this);
}

void LemurParser::ArglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArglist(this);
}


antlrcpp::Any LemurParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::ArglistContext* LemurParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 52, LemurParser::RuleArglist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LemurParser::T__4)
      | (1ULL << LemurParser::UMINUS)
      | (1ULL << LemurParser::OPEN)
      | (1ULL << LemurParser::NEG)
      | (1ULL << LemurParser::NAME)
      | (1ULL << LemurParser::INT)
      | (1ULL << LemurParser::FLOAT)
      | (1ULL << LemurParser::STRING))) != 0)) {
      setState(263);
      expr(0);
      setState(268);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LemurParser::T__1) {
        setState(264);
        match(LemurParser::T__1);
        setState(265);
        expr(0);
        setState(270);
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

LemurParser::NegContext::NegContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::NegContext::NEG() {
  return getToken(LemurParser::NEG, 0);
}

LemurParser::ExprContext* LemurParser::NegContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}


size_t LemurParser::NegContext::getRuleIndex() const {
  return LemurParser::RuleNeg;
}

void LemurParser::NegContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeg(this);
}

void LemurParser::NegContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeg(this);
}


antlrcpp::Any LemurParser::NegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitNeg(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::NegContext* LemurParser::neg() {
  NegContext *_localctx = _tracker.createInstance<NegContext>(_ctx, getState());
  enterRule(_localctx, 54, LemurParser::RuleNeg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(LemurParser::NEG);
    setState(274);
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

LemurParser::BinoperatorContext::BinoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::BinoperatorContext::UMINUS() {
  return getToken(LemurParser::UMINUS, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::SHL() {
  return getToken(LemurParser::SHL, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::SHR() {
  return getToken(LemurParser::SHR, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::AND() {
  return getToken(LemurParser::AND, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::OR() {
  return getToken(LemurParser::OR, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::XOR() {
  return getToken(LemurParser::XOR, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::GT() {
  return getToken(LemurParser::GT, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::LT() {
  return getToken(LemurParser::LT, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::GE() {
  return getToken(LemurParser::GE, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::LE() {
  return getToken(LemurParser::LE, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::EQ() {
  return getToken(LemurParser::EQ, 0);
}

tree::TerminalNode* LemurParser::BinoperatorContext::NE() {
  return getToken(LemurParser::NE, 0);
}


size_t LemurParser::BinoperatorContext::getRuleIndex() const {
  return LemurParser::RuleBinoperator;
}

void LemurParser::BinoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinoperator(this);
}

void LemurParser::BinoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinoperator(this);
}


antlrcpp::Any LemurParser::BinoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitBinoperator(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::BinoperatorContext* LemurParser::binoperator() {
  BinoperatorContext *_localctx = _tracker.createInstance<BinoperatorContext>(_ctx, getState());
  enterRule(_localctx, 56, LemurParser::RuleBinoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LemurParser::T__6)
      | (1ULL << LemurParser::T__7)
      | (1ULL << LemurParser::T__8)
      | (1ULL << LemurParser::UMINUS)
      | (1ULL << LemurParser::AND)
      | (1ULL << LemurParser::OR)
      | (1ULL << LemurParser::XOR)
      | (1ULL << LemurParser::SHL)
      | (1ULL << LemurParser::SHR)
      | (1ULL << LemurParser::GT)
      | (1ULL << LemurParser::GE)
      | (1ULL << LemurParser::LT)
      | (1ULL << LemurParser::LE)
      | (1ULL << LemurParser::EQ)
      | (1ULL << LemurParser::NE))) != 0))) {
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

LemurParser::BracedexprContext::BracedexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LemurParser::BracedexprContext::OPEN() {
  return getToken(LemurParser::OPEN, 0);
}

LemurParser::ExprContext* LemurParser::BracedexprContext::expr() {
  return getRuleContext<LemurParser::ExprContext>(0);
}

tree::TerminalNode* LemurParser::BracedexprContext::CLOSED() {
  return getToken(LemurParser::CLOSED, 0);
}


size_t LemurParser::BracedexprContext::getRuleIndex() const {
  return LemurParser::RuleBracedexpr;
}

void LemurParser::BracedexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBracedexpr(this);
}

void LemurParser::BracedexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LemurListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBracedexpr(this);
}


antlrcpp::Any LemurParser::BracedexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LemurVisitor*>(visitor))
    return parserVisitor->visitBracedexpr(this);
  else
    return visitor->visitChildren(this);
}

LemurParser::BracedexprContext* LemurParser::bracedexpr() {
  BracedexprContext *_localctx = _tracker.createInstance<BracedexprContext>(_ctx, getState());
  enterRule(_localctx, 58, LemurParser::RuleBracedexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(LemurParser::OPEN);
    setState(279);
    expr(0);
    setState(280);
    match(LemurParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool LemurParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LemurParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> LemurParser::_decisionToDFA;
atn::PredictionContextCache LemurParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LemurParser::_atn;
std::vector<uint16_t> LemurParser::_serializedATN;

std::vector<std::string> LemurParser::_ruleNames = {
  "file", "globalstmt", "classdef", "classbody", "classvardecl", "classfunctiondef", 
  "functiondef", "paramlist", "block", "stmt", "printstmt", "vardecl", "assign", 
  "declassign", "ret", "whileloop", "forloop", "ifExpr", "ifElseExpr", "expr", 
  "list", "methodCall", "string", "number", "var", "callexpr", "arglist", 
  "neg", "binoperator", "bracedexpr"
};

std::vector<std::string> LemurParser::_literalNames = {
  "", "':'", "','", "'.'", "'='", "'['", "']'", "'+'", "'*'", "'/'", "'-'", 
  "'for'", "'in'", "'class'", "'<-'", "'def'", "'print'", "'('", "')'", 
  "'{'", "'}'", "'return'", "'while'", "'if'", "'else'", "'and'", "'or'", 
  "'^'", "'<<'", "'>>'", "'not'", "'>'", "'>='", "'<'", "'<='", "'=='", 
  "'!='", "'\n'"
};

std::vector<std::string> LemurParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "UMINUS", "FOR", "IN", "CLASS", 
  "ARROW", "DEF", "PRINT", "OPEN", "CLOSED", "LEFTBRACE", "RIGHTBRACE", 
  "RET", "WHILE", "IF", "ELSE", "AND", "OR", "XOR", "SHL", "SHR", "NEG", 
  "GT", "GE", "LT", "LE", "EQ", "NE", "NEWLINE", "NAME", "INT", "FLOAT", 
  "STRING", "WHITESPACE", "COMMENT"
};

dfa::Vocabulary LemurParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LemurParser::_tokenNames;

LemurParser::Initializer::Initializer() {
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
    0x3, 0x2d, 0x11d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x41, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x44, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x4a, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x50, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x59, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5c, 
    0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x68, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x73, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 
    0x7e, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x81, 0xb, 0x9, 0x5, 0x9, 0x83, 
    0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x6, 0xa, 
    0x8a, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x8b, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x9a, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0xa7, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0xb3, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xc8, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0xcb, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xdb, 0xa, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x7, 0x15, 0xe6, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xe9, 0xb, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xef, 0xa, 
    0x16, 0x5, 0x16, 0xf1, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 
    0x1a, 0x103, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x10d, 0xa, 0x1c, 
    0xc, 0x1c, 0xe, 0x1c, 0x110, 0xb, 0x1c, 0x5, 0x1c, 0x112, 0xa, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x2, 0x3, 0x28, 0x20, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x2, 0x4, 0x3, 0x2, 0x29, 0x2a, 0x5, 0x2, 0x9, 0xc, 
    0x1b, 0x1f, 0x21, 0x26, 0x2, 0x126, 0x2, 0x42, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x84, 0x3, 0x2, 0x2, 0x2, 0x14, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xa3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xab, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x22, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xda, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x32, 0xff, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x104, 0x3, 0x2, 0x2, 0x2, 0x36, 0x111, 0x3, 0x2, 0x2, 0x2, 0x38, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x116, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x41, 0x5, 0x4, 0x3, 0x2, 0x3f, 0x41, 0x7, 0x27, 
    0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x45, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x2, 0x2, 0x3, 0x46, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x5, 0x6, 0x4, 0x2, 0x48, 0x4a, 0x5, 
    0xe, 0x8, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0xf, 0x2, 
    0x2, 0x4c, 0x4f, 0x7, 0x28, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x10, 0x2, 0x2, 
    0x4e, 0x50, 0x7, 0x28, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x7, 0x15, 0x2, 0x2, 0x52, 0x53, 0x5, 0x8, 0x5, 0x2, 0x53, 0x54, 0x7, 
    0x16, 0x2, 0x2, 0x54, 0x7, 0x3, 0x2, 0x2, 0x2, 0x55, 0x59, 0x5, 0xa, 
    0x6, 0x2, 0x56, 0x59, 0x5, 0xc, 0x7, 0x2, 0x57, 0x59, 0x7, 0x27, 0x2, 
    0x2, 0x58, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 
    0x28, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x28, 0x2, 0x2, 0x5f, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x61, 0x7, 0x11, 0x2, 0x2, 0x61, 0x62, 0x7, 0x28, 0x2, 
    0x2, 0x62, 0x63, 0x7, 0x13, 0x2, 0x2, 0x63, 0x64, 0x5, 0x10, 0x9, 0x2, 
    0x64, 0x67, 0x7, 0x14, 0x2, 0x2, 0x65, 0x66, 0x7, 0x3, 0x2, 0x2, 0x66, 
    0x68, 0x7, 0x28, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x5, 
    0x12, 0xa, 0x2, 0x6a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x11, 
    0x2, 0x2, 0x6c, 0x6d, 0x7, 0x28, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x13, 0x2, 
    0x2, 0x6e, 0x6f, 0x5, 0x10, 0x9, 0x2, 0x6f, 0x72, 0x7, 0x14, 0x2, 0x2, 
    0x70, 0x71, 0x7, 0x3, 0x2, 0x2, 0x71, 0x73, 0x7, 0x28, 0x2, 0x2, 0x72, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x5, 0x12, 0xa, 0x2, 0x75, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x28, 0x2, 0x2, 0x77, 0x78, 0x7, 0x28, 
    0x2, 0x2, 0x78, 0x7f, 0x8, 0x9, 0x1, 0x2, 0x79, 0x7a, 0x7, 0x4, 0x2, 
    0x2, 0x7a, 0x7b, 0x7, 0x28, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x28, 0x2, 0x2, 
    0x7c, 0x7e, 0x8, 0x9, 0x1, 0x2, 0x7d, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x76, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x11, 0x3, 0x2, 0x2, 0x2, 0x84, 0x89, 0x7, 0x15, 0x2, 
    0x2, 0x85, 0x86, 0x5, 0x14, 0xb, 0x2, 0x86, 0x87, 0x7, 0x27, 0x2, 0x2, 
    0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8a, 0x7, 0x27, 0x2, 0x2, 0x89, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x16, 
    0x2, 0x2, 0x8e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x9a, 0x5, 0x18, 0xd, 
    0x2, 0x90, 0x9a, 0x5, 0x1a, 0xe, 0x2, 0x91, 0x9a, 0x5, 0x1c, 0xf, 0x2, 
    0x92, 0x9a, 0x5, 0x1e, 0x10, 0x2, 0x93, 0x9a, 0x5, 0x20, 0x11, 0x2, 
    0x94, 0x9a, 0x5, 0x24, 0x13, 0x2, 0x95, 0x9a, 0x5, 0x26, 0x14, 0x2, 
    0x96, 0x9a, 0x5, 0x22, 0x12, 0x2, 0x97, 0x9a, 0x5, 0x28, 0x15, 0x2, 
    0x98, 0x9a, 0x5, 0x16, 0xc, 0x2, 0x99, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x99, 0x91, 0x3, 0x2, 0x2, 0x2, 0x99, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x93, 0x3, 0x2, 0x2, 0x2, 0x99, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x95, 0x3, 0x2, 0x2, 0x2, 0x99, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x12, 0x2, 0x2, 
    0x9c, 0x9d, 0x7, 0x13, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x28, 0x15, 0x2, 0x9e, 
    0x9f, 0x7, 0x14, 0x2, 0x2, 0x9f, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 
    0x7, 0x28, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x28, 0x2, 0x2, 0xa2, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0xa6, 0x7, 0x28, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x5, 
    0x2, 0x2, 0xa5, 0xa7, 0x7, 0x28, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xa9, 0x7, 0x6, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x28, 0x15, 0x2, 0xaa, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x28, 0x2, 0x2, 0xac, 0xad, 
    0x7, 0x28, 0x2, 0x2, 0xad, 0xae, 0x7, 0x6, 0x2, 0x2, 0xae, 0xaf, 0x5, 
    0x28, 0x15, 0x2, 0xaf, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x7, 0x17, 
    0x2, 0x2, 0xb1, 0xb3, 0x5, 0x28, 0x15, 0x2, 0xb2, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0xb5, 0x7, 0x18, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x3c, 0x1f, 0x2, 0xb6, 
    0xb7, 0x5, 0x12, 0xa, 0x2, 0xb7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 
    0x7, 0xd, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x13, 0x2, 0x2, 0xba, 0xbb, 0x7, 
    0x28, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0xe, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x28, 
    0x15, 0x2, 0xbd, 0xbe, 0x5, 0x12, 0xa, 0x2, 0xbe, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xc0, 0x7, 0x19, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0x3c, 0x1f, 0x2, 
    0xc1, 0xc2, 0x5, 0x12, 0xa, 0x2, 0xc2, 0x25, 0x3, 0x2, 0x2, 0x2, 0xc3, 
    0xc4, 0x7, 0x19, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x3c, 0x1f, 0x2, 0xc5, 0xc9, 
    0x5, 0x12, 0xa, 0x2, 0xc6, 0xc8, 0x7, 0x27, 0x2, 0x2, 0xc7, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x1a, 0x2, 0x2, 
    0xcd, 0xce, 0x5, 0x12, 0xa, 0x2, 0xce, 0x27, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd0, 0x8, 0x15, 0x1, 0x2, 0xd0, 0xdb, 0x5, 0x30, 0x19, 0x2, 0xd1, 0xd2, 
    0x7, 0xc, 0x2, 0x2, 0xd2, 0xdb, 0x5, 0x28, 0x15, 0xc, 0xd3, 0xdb, 0x5, 
    0x32, 0x1a, 0x2, 0xd4, 0xdb, 0x5, 0x2e, 0x18, 0x2, 0xd5, 0xdb, 0x5, 
    0x2c, 0x17, 0x2, 0xd6, 0xdb, 0x5, 0x34, 0x1b, 0x2, 0xd7, 0xdb, 0x5, 
    0x38, 0x1d, 0x2, 0xd8, 0xdb, 0x5, 0x2a, 0x16, 0x2, 0xd9, 0xdb, 0x5, 
    0x3c, 0x1f, 0x2, 0xda, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd1, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd4, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 
    0xc, 0x6, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x3a, 0x1e, 0x2, 0xde, 0xdf, 0x5, 
    0x28, 0x15, 0x7, 0xdf, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0xc, 0x8, 
    0x2, 0x2, 0xe1, 0xe2, 0x7, 0x7, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x28, 0x15, 
    0x2, 0xe3, 0xe4, 0x7, 0x8, 0x2, 0x2, 0xe4, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xe5, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe6, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0x29, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xf0, 0x7, 0x7, 0x2, 0x2, 0xeb, 0xee, 0x5, 0x28, 
    0x15, 0x2, 0xec, 0xed, 0x7, 0x4, 0x2, 0x2, 0xed, 0xef, 0x5, 0x28, 0x15, 
    0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 
    0x7, 0x8, 0x2, 0x2, 0xf3, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x7, 
    0x28, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x5, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x28, 
    0x2, 0x2, 0xf7, 0xf8, 0x7, 0x13, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x36, 0x1c, 
    0x2, 0xf9, 0xfa, 0x7, 0x14, 0x2, 0x2, 0xfa, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xfc, 0x7, 0x2b, 0x2, 0x2, 0xfc, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xfd, 
    0xfe, 0x9, 0x2, 0x2, 0x2, 0xfe, 0x31, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 
    0x7, 0x28, 0x2, 0x2, 0x100, 0x101, 0x7, 0x5, 0x2, 0x2, 0x101, 0x103, 
    0x7, 0x28, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0x33, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x7, 
    0x28, 0x2, 0x2, 0x105, 0x106, 0x7, 0x13, 0x2, 0x2, 0x106, 0x107, 0x5, 
    0x36, 0x1c, 0x2, 0x107, 0x108, 0x7, 0x14, 0x2, 0x2, 0x108, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x109, 0x10e, 0x5, 0x28, 0x15, 0x2, 0x10a, 0x10b, 0x7, 
    0x4, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0x28, 0x15, 0x2, 0x10c, 0x10a, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x111, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 0x2, 0x112, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x114, 0x7, 0x20, 0x2, 0x2, 0x114, 0x115, 0x5, 0x28, 
    0x15, 0x2, 0x115, 0x39, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x9, 0x3, 
    0x2, 0x2, 0x117, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x7, 0x13, 
    0x2, 0x2, 0x119, 0x11a, 0x5, 0x28, 0x15, 0x2, 0x11a, 0x11b, 0x7, 0x14, 
    0x2, 0x2, 0x11b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x40, 0x42, 0x49, 0x4f, 
    0x58, 0x5a, 0x67, 0x72, 0x7f, 0x82, 0x89, 0x8b, 0x99, 0xa6, 0xb2, 0xc9, 
    0xda, 0xe5, 0xe7, 0xee, 0xf0, 0x102, 0x10e, 0x111, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LemurParser::Initializer LemurParser::_init;
