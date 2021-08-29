
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;


// Generated from Avrlang.g4 by ANTLR 4.7.2


#include "AvrlangLexer.h"


using namespace antlr4;


AvrlangLexer::AvrlangLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AvrlangLexer::~AvrlangLexer() {
  delete _interpreter;
}

std::string AvrlangLexer::getGrammarFileName() const {
  return "Avrlang.g4";
}

const std::vector<std::string>& AvrlangLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& AvrlangLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& AvrlangLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& AvrlangLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& AvrlangLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> AvrlangLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& AvrlangLexer::getATN() const {
  return _atn;
}


void AvrlangLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 1: NAMEAction(dynamic_cast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void AvrlangLexer::NAMEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 

     break;

  default:
    break;
  }
}



// Static vars and initialization.
std::vector<dfa::DFA> AvrlangLexer::_decisionToDFA;
atn::PredictionContextCache AvrlangLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AvrlangLexer::_atn;
std::vector<uint16_t> AvrlangLexer::_serializedATN;

std::vector<std::string> AvrlangLexer::_ruleNames = {
  u8"T__0", u8"NAME", u8"WHITESPACE", u8"NEWLINE"
};

std::vector<std::string> AvrlangLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> AvrlangLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> AvrlangLexer::_literalNames = {
  "", u8"'def'", "", u8"' '", u8"'\n'"
};

std::vector<std::string> AvrlangLexer::_symbolicNames = {
  "", "", u8"NAME", u8"WHITESPACE", u8"NEWLINE"
};

dfa::Vocabulary AvrlangLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AvrlangLexer::_tokenNames;

AvrlangLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
    0x2, 0x6, 0x1e, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 
    0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x12, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x15, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 
    0x9, 0x6, 0x3, 0x2, 0x4, 0x5, 0x2, 0x43, 0x5c, 0x61, 0x61, 0x63, 0x7c, 
    0x6, 0x2, 0x32, 0x3b, 0x43, 0x5c, 0x61, 0x61, 0x63, 0x7c, 0x2, 0x1e, 
    0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x5, 0xf, 0x3, 0x2, 0x2, 0x2, 0x7, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x9, 0x1c, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x7, 0x66, 0x2, 0x2, 0xc, 0xd, 
    0x7, 0x67, 0x2, 0x2, 0xd, 0xe, 0x7, 0x68, 0x2, 0x2, 0xe, 0x4, 0x3, 0x2, 
    0x2, 0x2, 0xf, 0x13, 0x9, 0x2, 0x2, 0x2, 0x10, 0x12, 0x9, 0x3, 0x2, 
    0x2, 0x11, 0x10, 0x3, 0x2, 0x2, 0x2, 0x12, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x16, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 
    0x8, 0x3, 0x2, 0x2, 0x17, 0x6, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x7, 
    0x22, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x8, 0x4, 
    0x3, 0x2, 0x1b, 0x8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0xc, 0x2, 
    0x2, 0x1d, 0xa, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2, 0x13, 0x4, 0x3, 0x3, 0x2, 
    0x8, 0x2, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AvrlangLexer::Initializer AvrlangLexer::_init;
