
// Generated from Avrlang.g4 by ANTLR 4.7.2


#include "AvrlangListener.h"

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

std::vector<AvrlangParser::GlobalcmdContext *> AvrlangParser::FileContext::globalcmd() {
  return getRuleContexts<AvrlangParser::GlobalcmdContext>();
}

AvrlangParser::GlobalcmdContext* AvrlangParser::FileContext::globalcmd(size_t i) {
  return getRuleContext<AvrlangParser::GlobalcmdContext>(i);
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

AvrlangParser::FileContext* AvrlangParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, AvrlangParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(5); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(4);
      globalcmd();
      setState(7); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AvrlangParser::T__0

    || _la == AvrlangParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalcmdContext ------------------------------------------------------------------

AvrlangParser::GlobalcmdContext::GlobalcmdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AvrlangParser::GlobalcmdContext::getRuleIndex() const {
  return AvrlangParser::RuleGlobalcmd;
}

void AvrlangParser::GlobalcmdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalcmd(this);
}

void AvrlangParser::GlobalcmdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AvrlangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalcmd(this);
}

AvrlangParser::GlobalcmdContext* AvrlangParser::globalcmd() {
  GlobalcmdContext *_localctx = _tracker.createInstance<GlobalcmdContext>(_ctx, getState());
  enterRule(_localctx, 2, AvrlangParser::RuleGlobalcmd);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9);
    _la = _input->LA(1);
    if (!(_la == AvrlangParser::T__0

    || _la == AvrlangParser::T__1)) {
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

// Static vars and initialization.
std::vector<dfa::DFA> AvrlangParser::_decisionToDFA;
atn::PredictionContextCache AvrlangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AvrlangParser::_atn;
std::vector<uint16_t> AvrlangParser::_serializedATN;

std::vector<std::string> AvrlangParser::_ruleNames = {
  "file", "globalcmd"
};

std::vector<std::string> AvrlangParser::_literalNames = {
  "", "'hello'", "'world'"
};

std::vector<std::string> AvrlangParser::_symbolicNames = {
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
    0x3, 0x4, 0xe, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x6, 
    0x2, 0x8, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x9, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x2, 0x2, 0x4, 0x2, 0x4, 0x2, 0x3, 0x3, 0x2, 0x3, 0x4, 0x2, 0xc, 
    0x2, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8, 
    0x5, 0x4, 0x3, 0x2, 0x7, 0x6, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x9, 0x7, 0x3, 0x2, 0x2, 0x2, 0x9, 0xa, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x3, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x9, 0x2, 0x2, 0x2, 0xc, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x3, 0x9, 
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
