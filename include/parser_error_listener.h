//
// Created by avram on 30.8.21..
//

#ifndef LEMUR_PARSERERRORLISTENER_H
#define LEMUR_PARSERERRORLISTENER_H

#include <antlr4-runtime.h>

class ParserErrorListener : public antlr4::BaseErrorListener {
  void syntaxError(antlr4::Recognizer *recognizer,
                   antlr4::Token *offendingSymbol, size_t line,
                   size_t charPositionInLine, const std::string &msg,
                   std::exception_ptr e) override;
};

#endif  // LEMUR_PARSERERRORLISTENER_H
