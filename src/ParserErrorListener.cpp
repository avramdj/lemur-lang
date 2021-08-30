//
// Created by avram on 30.8.21..
//

#include <ParserErrorListener.h>
#include <iostream>
#include <strstream>

void ParserErrorListener::syntaxError(
        antlr4::Recognizer *recognizer,
        antlr4::Token *offendingSymbol,
        size_t line,
        size_t charPositionInLine,
        const std::string &msg,
        std::exception_ptr e) {
    std::ostrstream s;
    s << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")";
    throw std::invalid_argument(s.str());
}
