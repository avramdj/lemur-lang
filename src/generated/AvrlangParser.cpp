
    #include <vector>
    #include <string>


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
    setState(64);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::CLASS)
      | (1ULL << AvrlangParser::DEF)
      | (1ULL << AvrlangParser::NEWLINE))) != 0)) {
      setState(62);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AvrlangParser::CLASS:
        case AvrlangParser::DEF: {
          setState(60);
          globalstmt();
          break;
        }

        case AvrlangParser::NEWLINE: {
          setState(61);
          match(AvrlangParser::NEWLINE);
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
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AvrlangParser::CLASS: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        classdef();
        break;
      }

      case AvrlangParser::DEF: {
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
    setState(73);
    match(AvrlangParser::CLASS);
    setState(74);
    dynamic_cast<ClassdefContext *>(_localctx)->cName = match(AvrlangParser::NAME);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AvrlangParser::ARROW) {
      setState(75);
      match(AvrlangParser::ARROW);
      setState(76);
      dynamic_cast<ClassdefContext *>(_localctx)->baseName = match(AvrlangParser::NAME);
    }
    setState(79);
    match(AvrlangParser::LEFTBRACE);
    setState(80);
    dynamic_cast<ClassdefContext *>(_localctx)->body = classbody();
    setState(81);
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

std::vector<AvrlangParser::ClassvardeclContext *> AvrlangParser::ClassbodyContext::classvardecl() {
  return getRuleContexts<AvrlangParser::ClassvardeclContext>();
}

AvrlangParser::ClassvardeclContext* AvrlangParser::ClassbodyContext::classvardecl(size_t i) {
  return getRuleContext<AvrlangParser::ClassvardeclContext>(i);
}

std::vector<AvrlangParser::ClassfunctiondefContext *> AvrlangParser::ClassbodyContext::classfunctiondef() {
  return getRuleContexts<AvrlangParser::ClassfunctiondefContext>();
}

AvrlangParser::ClassfunctiondefContext* AvrlangParser::ClassbodyContext::classfunctiondef(size_t i) {
  return getRuleContext<AvrlangParser::ClassfunctiondefContext>(i);
}

std::vector<tree::TerminalNode *> AvrlangParser::ClassbodyContext::NEWLINE() {
  return getTokens(AvrlangParser::NEWLINE);
}

tree::TerminalNode* AvrlangParser::ClassbodyContext::NEWLINE(size_t i) {
  return getToken(AvrlangParser::NEWLINE, i);
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
      ((1ULL << _la) & ((1ULL << AvrlangParser::DEF)
      | (1ULL << AvrlangParser::NEWLINE)
      | (1ULL << AvrlangParser::NAME))) != 0)) {
      setState(86);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AvrlangParser::NAME: {
          setState(83);
          classvardecl();
          break;
        }

        case AvrlangParser::DEF: {
          setState(84);
          classfunctiondef();
          break;
        }

        case AvrlangParser::NEWLINE: {
          setState(85);
          match(AvrlangParser::NEWLINE);
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

AvrlangParser::ClassvardeclContext::ClassvardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AvrlangParser::ClassvardeclContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::ClassvardeclContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
}


size_t AvrlangParser::ClassvardeclContext::getRuleIndex() const {
  return AvrlangParser::RuleClassvardecl;
}

void AvrlangParser::ClassvardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassvardecl(this);
}

void AvrlangParser::ClassvardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassvardecl(this);
}


antlrcpp::Any AvrlangParser::ClassvardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitClassvardecl(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ClassvardeclContext* AvrlangParser::classvardecl() {
  ClassvardeclContext *_localctx = _tracker.createInstance<ClassvardeclContext>(_ctx, getState());
  enterRule(_localctx, 8, AvrlangParser::RuleClassvardecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    dynamic_cast<ClassvardeclContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
    setState(92);
    dynamic_cast<ClassvardeclContext *>(_localctx)->varName = match(AvrlangParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassfunctiondefContext ------------------------------------------------------------------

AvrlangParser::ClassfunctiondefContext::ClassfunctiondefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AvrlangParser::ClassfunctiondefContext::DEF() {
  return getToken(AvrlangParser::DEF, 0);
}

tree::TerminalNode* AvrlangParser::ClassfunctiondefContext::OPEN() {
  return getToken(AvrlangParser::OPEN, 0);
}

tree::TerminalNode* AvrlangParser::ClassfunctiondefContext::CLOSED() {
  return getToken(AvrlangParser::CLOSED, 0);
}

std::vector<tree::TerminalNode *> AvrlangParser::ClassfunctiondefContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::ClassfunctiondefContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
}

AvrlangParser::ParamlistContext* AvrlangParser::ClassfunctiondefContext::paramlist() {
  return getRuleContext<AvrlangParser::ParamlistContext>(0);
}

AvrlangParser::BlockContext* AvrlangParser::ClassfunctiondefContext::block() {
  return getRuleContext<AvrlangParser::BlockContext>(0);
}


size_t AvrlangParser::ClassfunctiondefContext::getRuleIndex() const {
  return AvrlangParser::RuleClassfunctiondef;
}

void AvrlangParser::ClassfunctiondefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassfunctiondef(this);
}

void AvrlangParser::ClassfunctiondefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassfunctiondef(this);
}


antlrcpp::Any AvrlangParser::ClassfunctiondefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AvrlangVisitor*>(visitor))
    return parserVisitor->visitClassfunctiondef(this);
  else
    return visitor->visitChildren(this);
}

AvrlangParser::ClassfunctiondefContext* AvrlangParser::classfunctiondef() {
  ClassfunctiondefContext *_localctx = _tracker.createInstance<ClassfunctiondefContext>(_ctx, getState());
  enterRule(_localctx, 10, AvrlangParser::RuleClassfunctiondef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(AvrlangParser::DEF);
    setState(95);
    dynamic_cast<ClassfunctiondefContext *>(_localctx)->fName = match(AvrlangParser::NAME);
    setState(96);
    match(AvrlangParser::OPEN);
    setState(97);
    dynamic_cast<ClassfunctiondefContext *>(_localctx)->params = paramlist();
    setState(98);
    match(AvrlangParser::CLOSED);
    setState(99);
    match(AvrlangParser::T__0);
    setState(100);
    dynamic_cast<ClassfunctiondefContext *>(_localctx)->retType = match(AvrlangParser::NAME);
    setState(101);
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
  enterRule(_localctx, 12, AvrlangParser::RuleFunctiondef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(AvrlangParser::DEF);
    setState(104);
    dynamic_cast<FunctiondefContext *>(_localctx)->fName = match(AvrlangParser::NAME);
    setState(105);
    match(AvrlangParser::OPEN);
    setState(106);
    dynamic_cast<FunctiondefContext *>(_localctx)->params = paramlist();
    setState(107);
    match(AvrlangParser::CLOSED);
    setState(108);
    match(AvrlangParser::T__0);
    setState(109);
    dynamic_cast<FunctiondefContext *>(_localctx)->retType = match(AvrlangParser::NAME);
    setState(110);
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
  enterRule(_localctx, 14, AvrlangParser::RuleParamlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AvrlangParser::NAME) {
      setState(112);
      dynamic_cast<ParamlistContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
      setState(113);
      dynamic_cast<ParamlistContext *>(_localctx)->varName = match(AvrlangParser::NAME);
      _localctx->types.push_back((dynamic_cast<ParamlistContext *>(_localctx)->typeName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->typeName->getText() : ""));_localctx->vars.push_back((dynamic_cast<ParamlistContext *>(_localctx)->varName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->varName->getText() : ""));
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AvrlangParser::T__1) {
        setState(115);
        match(AvrlangParser::T__1);
        setState(116);
        dynamic_cast<ParamlistContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
        setState(117);
        dynamic_cast<ParamlistContext *>(_localctx)->varName = match(AvrlangParser::NAME);
        {_localctx->types.push_back((dynamic_cast<ParamlistContext *>(_localctx)->typeName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->typeName->getText() : ""));_localctx->vars.push_back((dynamic_cast<ParamlistContext *>(_localctx)->varName != nullptr ? dynamic_cast<ParamlistContext *>(_localctx)->varName->getText() : ""));}
        setState(123);
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
  enterRule(_localctx, 16, AvrlangParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(AvrlangParser::LEFTBRACE);
    setState(131); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(131);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AvrlangParser::T__4:
        case AvrlangParser::UMINUS:
        case AvrlangParser::FOR:
        case AvrlangParser::PRINT:
        case AvrlangParser::OPEN:
        case AvrlangParser::RET:
        case AvrlangParser::WHILE:
        case AvrlangParser::IF:
        case AvrlangParser::NEG:
        case AvrlangParser::NAME:
        case AvrlangParser::INT:
        case AvrlangParser::FLOAT:
        case AvrlangParser::STRING: {
          setState(127);
          stmt();
          setState(128);
          match(AvrlangParser::NEWLINE);
          break;
        }

        case AvrlangParser::NEWLINE: {
          setState(130);
          match(AvrlangParser::NEWLINE);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(133); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__4)
      | (1ULL << AvrlangParser::UMINUS)
      | (1ULL << AvrlangParser::FOR)
      | (1ULL << AvrlangParser::PRINT)
      | (1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::RET)
      | (1ULL << AvrlangParser::WHILE)
      | (1ULL << AvrlangParser::IF)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NEWLINE)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::INT)
      | (1ULL << AvrlangParser::FLOAT)
      | (1ULL << AvrlangParser::STRING))) != 0));
    setState(135);
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
  enterRule(_localctx, 18, AvrlangParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(137);
      vardecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      assign();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(139);
      declassign();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(140);
      ret();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(141);
      whileloop();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(142);
      ifExpr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(143);
      ifElseExpr();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(144);
      forloop();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(145);
      expr(0);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(146);
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
  enterRule(_localctx, 20, AvrlangParser::RulePrintstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(AvrlangParser::PRINT);
    setState(150);
    match(AvrlangParser::OPEN);
    setState(151);
    expr(0);
    setState(152);
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
  enterRule(_localctx, 22, AvrlangParser::RuleVardecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    dynamic_cast<VardeclContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
    setState(155);
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

std::vector<tree::TerminalNode *> AvrlangParser::AssignContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::AssignContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
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
  enterRule(_localctx, 24, AvrlangParser::RuleAssign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    dynamic_cast<AssignContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AvrlangParser::T__2) {
      setState(158);
      match(AvrlangParser::T__2);
      setState(159);
      dynamic_cast<AssignContext *>(_localctx)->subName = match(AvrlangParser::NAME);
    }
    setState(162);
    match(AvrlangParser::T__3);
    setState(163);
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
  enterRule(_localctx, 26, AvrlangParser::RuleDeclassign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    dynamic_cast<DeclassignContext *>(_localctx)->typeName = match(AvrlangParser::NAME);
    setState(166);
    dynamic_cast<DeclassignContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(167);
    match(AvrlangParser::T__3);
    setState(168);
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
  enterRule(_localctx, 28, AvrlangParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(AvrlangParser::RET);
    setState(171);
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
  enterRule(_localctx, 30, AvrlangParser::RuleWhileloop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(AvrlangParser::WHILE);
    setState(174);
    bracedexpr();
    setState(175);
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
  enterRule(_localctx, 32, AvrlangParser::RuleForloop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(AvrlangParser::FOR);
    setState(178);
    match(AvrlangParser::OPEN);
    setState(179);
    dynamic_cast<ForloopContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(180);
    match(AvrlangParser::IN);
    setState(181);
    dynamic_cast<ForloopContext *>(_localctx)->listName = expr(0);
    setState(182);
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
  enterRule(_localctx, 34, AvrlangParser::RuleIfExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(AvrlangParser::IF);
    setState(185);
    dynamic_cast<IfExprContext *>(_localctx)->cond = bracedexpr();
    setState(186);
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
  enterRule(_localctx, 36, AvrlangParser::RuleIfElseExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(AvrlangParser::IF);
    setState(189);
    dynamic_cast<IfElseExprContext *>(_localctx)->cond = bracedexpr();
    setState(190);
    block();
    setState(191);
    match(AvrlangParser::ELSE);
    setState(192);
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, AvrlangParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(205);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NumberRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(195);
      number();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UminusRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(196);
      match(AvrlangParser::UMINUS);
      setState(197);
      expr(10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<VarRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(198);
      var();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<StringRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(199);
      string();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MethodRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(200);
      methodCall();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CallExprRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(201);
      callexpr();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<NegRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(202);
      neg();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ListRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(203);
      list();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BraceExprRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(204);
      bracedexpr();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(216);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<OpExprRuleContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->leftOp = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(207);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(208);
          binoperator();
          setState(209);
          dynamic_cast<OpExprRuleContext *>(_localctx)->rightOp = expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<IndexRuleContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(211);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(212);
          match(AvrlangParser::T__4);
          setState(213);
          expr(0);
          setState(214);
          match(AvrlangParser::T__5);
          break;
        }

        } 
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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
  enterRule(_localctx, 40, AvrlangParser::RuleList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(AvrlangParser::T__4);
    setState(227);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__4)
      | (1ULL << AvrlangParser::UMINUS)
      | (1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::INT)
      | (1ULL << AvrlangParser::FLOAT)
      | (1ULL << AvrlangParser::STRING))) != 0)) {
      setState(222);
      expr(0);
      setState(225);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AvrlangParser::T__1) {
        setState(223);
        match(AvrlangParser::T__1);
        setState(224);
        expr(0);
      }
    }
    setState(229);
    match(AvrlangParser::T__5);
   
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
  enterRule(_localctx, 42, AvrlangParser::RuleMethodCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    dynamic_cast<MethodCallContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(232);
    match(AvrlangParser::T__2);
    setState(233);
    dynamic_cast<MethodCallContext *>(_localctx)->methodName = match(AvrlangParser::NAME);
    setState(234);
    match(AvrlangParser::OPEN);
    setState(235);
    dynamic_cast<MethodCallContext *>(_localctx)->args = arglist();
    setState(236);
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
  enterRule(_localctx, 44, AvrlangParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
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

tree::TerminalNode* AvrlangParser::NumberContext::INT() {
  return getToken(AvrlangParser::INT, 0);
}

tree::TerminalNode* AvrlangParser::NumberContext::FLOAT() {
  return getToken(AvrlangParser::FLOAT, 0);
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
  enterRule(_localctx, 46, AvrlangParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    _la = _input->LA(1);
    if (!(_la == AvrlangParser::INT

    || _la == AvrlangParser::FLOAT)) {
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

AvrlangParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AvrlangParser::VarContext::NAME() {
  return getTokens(AvrlangParser::NAME);
}

tree::TerminalNode* AvrlangParser::VarContext::NAME(size_t i) {
  return getToken(AvrlangParser::NAME, i);
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
  enterRule(_localctx, 48, AvrlangParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    dynamic_cast<VarContext *>(_localctx)->varName = match(AvrlangParser::NAME);
    setState(245);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(243);
      match(AvrlangParser::T__2);
      setState(244);
      dynamic_cast<VarContext *>(_localctx)->subName = match(AvrlangParser::NAME);
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
  enterRule(_localctx, 50, AvrlangParser::RuleCallexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    dynamic_cast<CallexprContext *>(_localctx)->fName = match(AvrlangParser::NAME);
    setState(248);
    match(AvrlangParser::OPEN);
    setState(249);
    dynamic_cast<CallexprContext *>(_localctx)->args = arglist();
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
  enterRule(_localctx, 52, AvrlangParser::RuleArglist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AvrlangParser::T__4)
      | (1ULL << AvrlangParser::UMINUS)
      | (1ULL << AvrlangParser::OPEN)
      | (1ULL << AvrlangParser::NEG)
      | (1ULL << AvrlangParser::NAME)
      | (1ULL << AvrlangParser::INT)
      | (1ULL << AvrlangParser::FLOAT)
      | (1ULL << AvrlangParser::STRING))) != 0)) {
      setState(252);
      expr(0);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AvrlangParser::T__1) {
        setState(253);
        match(AvrlangParser::T__1);
        setState(254);
        expr(0);
        setState(259);
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
  enterRule(_localctx, 54, AvrlangParser::RuleNeg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(AvrlangParser::NEG);
    setState(263);
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
  enterRule(_localctx, 56, AvrlangParser::RuleBinoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
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
  enterRule(_localctx, 58, AvrlangParser::RuleBracedexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(AvrlangParser::OPEN);
    setState(268);
    expr(0);
    setState(269);
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
    case 19: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
  "file", "globalstmt", "classdef", "classbody", "classvardecl", "classfunctiondef", 
  "functiondef", "paramlist", "block", "stmt", "printstmt", "vardecl", "assign", 
  "declassign", "ret", "whileloop", "forloop", "ifExpr", "ifElseExpr", "expr", 
  "list", "methodCall", "string", "number", "var", "callexpr", "arglist", 
  "neg", "binoperator", "bracedexpr"
};

std::vector<std::string> AvrlangParser::_literalNames = {
  "", "':'", "','", "'.'", "'='", "'['", "']'", "'+'", "'*'", "'/'", "'-'", 
  "'for'", "'in'", "'class'", "'<-'", "'def'", "'print'", "'('", "')'", 
  "'{'", "'}'", "'return'", "'while'", "'if'", "'else'", "'and'", "'or'", 
  "'^'", "'<<'", "'>>'", "'not'", "'>'", "'>='", "'<'", "'<='", "'=='", 
  "'!='", "'\n'"
};

std::vector<std::string> AvrlangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "UMINUS", "FOR", "IN", "CLASS", 
  "ARROW", "DEF", "PRINT", "OPEN", "CLOSED", "LEFTBRACE", "RIGHTBRACE", 
  "RET", "WHILE", "IF", "ELSE", "AND", "OR", "XOR", "SHL", "SHR", "NEG", 
  "GT", "GE", "LT", "LE", "EQ", "NE", "NEWLINE", "NAME", "INT", "FLOAT", 
  "STRING", "WHITESPACE", "COMMENT"
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
    0x3, 0x2d, 0x112, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x7, 0x9, 0x7a, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x7d, 0xb, 0x9, 
    0x5, 0x9, 0x7f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x6, 0xa, 0x86, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x87, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x96, 0xa, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xa3, 0xa, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xd0, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x7, 0x15, 0xdb, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xde, 0xb, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xe4, 0xa, 0x16, 
    0x5, 0x16, 0xe6, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
    0xf8, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x102, 0xa, 0x1c, 0xc, 0x1c, 
    0xe, 0x1c, 0x105, 0xb, 0x1c, 0x5, 0x1c, 0x107, 0xa, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x2, 0x3, 0x28, 0x20, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x2, 0x4, 0x3, 0x2, 0x29, 0x2a, 0x5, 0x2, 0x9, 0xc, 0x1b, 
    0x1f, 0x21, 0x26, 0x2, 0x117, 0x2, 0x42, 0x3, 0x2, 0x2, 0x2, 0x4, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x69, 0x3, 0x2, 0x2, 0x2, 0x10, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x14, 0x95, 0x3, 0x2, 0x2, 0x2, 0x16, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x22, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xba, 0x3, 0x2, 0x2, 0x2, 0x26, 0xbe, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x34, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x106, 0x3, 0x2, 0x2, 0x2, 0x38, 0x108, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x10d, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x41, 0x5, 0x4, 0x3, 0x2, 0x3f, 0x41, 0x7, 0x27, 0x2, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x45, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x2, 0x2, 0x3, 0x46, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x4a, 0x5, 0x6, 0x4, 0x2, 0x48, 0x4a, 0x5, 0xe, 0x8, 
    0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0xf, 0x2, 0x2, 0x4c, 
    0x4f, 0x7, 0x28, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x10, 0x2, 0x2, 0x4e, 0x50, 
    0x7, 0x28, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x15, 
    0x2, 0x2, 0x52, 0x53, 0x5, 0x8, 0x5, 0x2, 0x53, 0x54, 0x7, 0x16, 0x2, 
    0x2, 0x54, 0x7, 0x3, 0x2, 0x2, 0x2, 0x55, 0x59, 0x5, 0xa, 0x6, 0x2, 
    0x56, 0x59, 0x5, 0xc, 0x7, 0x2, 0x57, 0x59, 0x7, 0x27, 0x2, 0x2, 0x58, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x28, 0x2, 
    0x2, 0x5e, 0x5f, 0x7, 0x28, 0x2, 0x2, 0x5f, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x61, 0x7, 0x11, 0x2, 0x2, 0x61, 0x62, 0x7, 0x28, 0x2, 0x2, 0x62, 
    0x63, 0x7, 0x13, 0x2, 0x2, 0x63, 0x64, 0x5, 0x10, 0x9, 0x2, 0x64, 0x65, 
    0x7, 0x14, 0x2, 0x2, 0x65, 0x66, 0x7, 0x3, 0x2, 0x2, 0x66, 0x67, 0x7, 
    0x28, 0x2, 0x2, 0x67, 0x68, 0x5, 0x12, 0xa, 0x2, 0x68, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x6a, 0x7, 0x11, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x28, 0x2, 
    0x2, 0x6b, 0x6c, 0x7, 0x13, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0x10, 0x9, 0x2, 
    0x6d, 0x6e, 0x7, 0x14, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x3, 0x2, 0x2, 0x6f, 
    0x70, 0x7, 0x28, 0x2, 0x2, 0x70, 0x71, 0x5, 0x12, 0xa, 0x2, 0x71, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x7, 0x28, 0x2, 0x2, 0x73, 0x74, 0x7, 
    0x28, 0x2, 0x2, 0x74, 0x7b, 0x8, 0x9, 0x1, 0x2, 0x75, 0x76, 0x7, 0x4, 
    0x2, 0x2, 0x76, 0x77, 0x7, 0x28, 0x2, 0x2, 0x77, 0x78, 0x7, 0x28, 0x2, 
    0x2, 0x78, 0x7a, 0x8, 0x9, 0x1, 0x2, 0x79, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x72, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x80, 0x85, 0x7, 0x15, 
    0x2, 0x2, 0x81, 0x82, 0x5, 0x14, 0xb, 0x2, 0x82, 0x83, 0x7, 0x27, 0x2, 
    0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x86, 0x7, 0x27, 0x2, 0x2, 
    0x85, 0x81, 0x3, 0x2, 0x2, 0x2, 0x85, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 
    0x16, 0x2, 0x2, 0x8a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x96, 0x5, 0x18, 
    0xd, 0x2, 0x8c, 0x96, 0x5, 0x1a, 0xe, 0x2, 0x8d, 0x96, 0x5, 0x1c, 0xf, 
    0x2, 0x8e, 0x96, 0x5, 0x1e, 0x10, 0x2, 0x8f, 0x96, 0x5, 0x20, 0x11, 
    0x2, 0x90, 0x96, 0x5, 0x24, 0x13, 0x2, 0x91, 0x96, 0x5, 0x26, 0x14, 
    0x2, 0x92, 0x96, 0x5, 0x22, 0x12, 0x2, 0x93, 0x96, 0x5, 0x28, 0x15, 
    0x2, 0x94, 0x96, 0x5, 0x16, 0xc, 0x2, 0x95, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x95, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x95, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x95, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x95, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x91, 0x3, 0x2, 0x2, 0x2, 0x95, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x15, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 0x12, 0x2, 
    0x2, 0x98, 0x99, 0x7, 0x13, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x28, 0x15, 0x2, 
    0x9a, 0x9b, 0x7, 0x14, 0x2, 0x2, 0x9b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9d, 0x7, 0x28, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x28, 0x2, 0x2, 0x9e, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x7, 0x28, 0x2, 0x2, 0xa0, 0xa1, 0x7, 
    0x5, 0x2, 0x2, 0xa1, 0xa3, 0x7, 0x28, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x7, 0x6, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x28, 0x15, 0x2, 
    0xa6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x28, 0x2, 0x2, 0xa8, 
    0xa9, 0x7, 0x28, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x6, 0x2, 0x2, 0xaa, 0xab, 
    0x5, 0x28, 0x15, 0x2, 0xab, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x7, 
    0x17, 0x2, 0x2, 0xad, 0xae, 0x5, 0x28, 0x15, 0x2, 0xae, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xaf, 0xb0, 0x7, 0x18, 0x2, 0x2, 0xb0, 0xb1, 0x5, 0x3c, 0x1f, 
    0x2, 0xb1, 0xb2, 0x5, 0x12, 0xa, 0x2, 0xb2, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xb4, 0x7, 0xd, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x13, 0x2, 0x2, 0xb5, 
    0xb6, 0x7, 0x28, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0xe, 0x2, 0x2, 0xb7, 0xb8, 
    0x5, 0x28, 0x15, 0x2, 0xb8, 0xb9, 0x5, 0x12, 0xa, 0x2, 0xb9, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x19, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x3c, 
    0x1f, 0x2, 0xbc, 0xbd, 0x5, 0x12, 0xa, 0x2, 0xbd, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbf, 0x7, 0x19, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x3c, 0x1f, 0x2, 
    0xc0, 0xc1, 0x5, 0x12, 0xa, 0x2, 0xc1, 0xc2, 0x7, 0x1a, 0x2, 0x2, 0xc2, 
    0xc3, 0x5, 0x12, 0xa, 0x2, 0xc3, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 
    0x8, 0x15, 0x1, 0x2, 0xc5, 0xd0, 0x5, 0x30, 0x19, 0x2, 0xc6, 0xc7, 0x7, 
    0xc, 0x2, 0x2, 0xc7, 0xd0, 0x5, 0x28, 0x15, 0xc, 0xc8, 0xd0, 0x5, 0x32, 
    0x1a, 0x2, 0xc9, 0xd0, 0x5, 0x2e, 0x18, 0x2, 0xca, 0xd0, 0x5, 0x2c, 
    0x17, 0x2, 0xcb, 0xd0, 0x5, 0x34, 0x1b, 0x2, 0xcc, 0xd0, 0x5, 0x38, 
    0x1d, 0x2, 0xcd, 0xd0, 0x5, 0x2a, 0x16, 0x2, 0xce, 0xd0, 0x5, 0x3c, 
    0x1f, 0x2, 0xcf, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc6, 0x3, 0x2, 0x2, 
    0x2, 0xcf, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0xc, 
    0x6, 0x2, 0x2, 0xd2, 0xd3, 0x5, 0x3a, 0x1e, 0x2, 0xd3, 0xd4, 0x5, 0x28, 
    0x15, 0x7, 0xd4, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0xc, 0x8, 0x2, 
    0x2, 0xd6, 0xd7, 0x7, 0x7, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x28, 0x15, 0x2, 
    0xd8, 0xd9, 0x7, 0x8, 0x2, 0x2, 0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xd1, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 
    0x2, 0x2, 0x2, 0xdd, 0x29, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe5, 0x7, 0x7, 0x2, 0x2, 0xe0, 0xe3, 0x5, 0x28, 0x15, 
    0x2, 0xe1, 0xe2, 0x7, 0x4, 0x2, 0x2, 0xe2, 0xe4, 0x5, 0x28, 0x15, 0x2, 
    0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0xe6, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 
    0x8, 0x2, 0x2, 0xe8, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x28, 
    0x2, 0x2, 0xea, 0xeb, 0x7, 0x5, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x28, 0x2, 
    0x2, 0xec, 0xed, 0x7, 0x13, 0x2, 0x2, 0xed, 0xee, 0x5, 0x36, 0x1c, 0x2, 
    0xee, 0xef, 0x7, 0x14, 0x2, 0x2, 0xef, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xf1, 0x7, 0x2b, 0x2, 0x2, 0xf1, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 
    0x9, 0x2, 0x2, 0x2, 0xf3, 0x31, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x7, 
    0x28, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x5, 0x2, 0x2, 0xf6, 0xf8, 0x7, 0x28, 
    0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0x33, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x28, 0x2, 0x2, 
    0xfa, 0xfb, 0x7, 0x13, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x36, 0x1c, 0x2, 0xfc, 
    0xfd, 0x7, 0x14, 0x2, 0x2, 0xfd, 0x35, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x103, 
    0x5, 0x28, 0x15, 0x2, 0xff, 0x100, 0x7, 0x4, 0x2, 0x2, 0x100, 0x102, 
    0x5, 0x28, 0x15, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x104, 0x107, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x37, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x7, 0x20, 
    0x2, 0x2, 0x109, 0x10a, 0x5, 0x28, 0x15, 0x2, 0x10a, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x10c, 0x9, 0x3, 0x2, 0x2, 0x10c, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x10d, 0x10e, 0x7, 0x13, 0x2, 0x2, 0x10e, 0x10f, 0x5, 0x28, 0x15, 
    0x2, 0x10f, 0x110, 0x7, 0x14, 0x2, 0x2, 0x110, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x40, 0x42, 0x49, 0x4f, 0x58, 0x5a, 0x7b, 0x7e, 0x85, 0x87, 
    0x95, 0xa2, 0xcf, 0xda, 0xdc, 0xe3, 0xe5, 0xf7, 0x103, 0x106, 
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
