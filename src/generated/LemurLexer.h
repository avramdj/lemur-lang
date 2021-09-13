
    #include <vector>
    #include <string>


// Generated from Lemur.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  LemurLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, UMINUS = 10, FOR = 11, IN = 12, CLASS = 13, ARROW = 14, 
    DEF = 15, PRINT = 16, OPEN = 17, CLOSED = 18, LEFTBRACE = 19, RIGHTBRACE = 20, 
    RET = 21, WHILE = 22, IF = 23, ELSE = 24, AND = 25, OR = 26, XOR = 27, 
    SHL = 28, SHR = 29, NEG = 30, GT = 31, GE = 32, LT = 33, LE = 34, EQ = 35, 
    NE = 36, NEWLINE = 37, NAME = 38, INT = 39, FLOAT = 40, STRING = 41, 
    WHITESPACE = 42, COMMENT = 43
  };

  LemurLexer(antlr4::CharStream *input);
  ~LemurLexer();

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

