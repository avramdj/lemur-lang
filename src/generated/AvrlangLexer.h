
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;


// Generated from Avrlang.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AvrlangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, PRINT = 7, 
    OPEN = 8, CLOSED = 9, LEFTBRACE = 10, RIGHTBRACE = 11, RET = 12, WHILE = 13, 
    IF = 14, ELSE = 15, AND = 16, OR = 17, XOR = 18, SHL = 19, SHR = 20, 
    NEG = 21, DEF = 22, GT = 23, GE = 24, LT = 25, LE = 26, EQ = 27, NE = 28, 
    NEWLINE = 29, NAME = 30, NUM = 31, WHITESPACE = 32, COMMENT = 33
  };

  AvrlangLexer(antlr4::CharStream *input);
  ~AvrlangLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

