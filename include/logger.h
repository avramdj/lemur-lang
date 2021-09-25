//
// Created by avram on 25.9.21..
//

#ifndef LEMUR_INCLUDE_LOGGER_H_
#define LEMUR_INCLUDE_LOGGER_H_

#include <iostream>
#include <ostream>

namespace backend {
// class Logger {
//   enum LoggingLevel { ERROR, cWarn };
//
//  public:
//   Logger() = delete;
//   static std::ostream& getStream();
//
//  private:
//   static std::ostream& err_;
//   static LoggingLevel level;
// };
namespace log {
enum Color { cReset, cError, cWarn };
enum LoggingLevel { lError, lWarn };
std::ostream& operator<<(std::ostream& os, backend::log::Color);
void warn(std::string s);
void err(std::string s);
static LoggingLevel logLevel;
}  // namespace log
}  // namespace backend

#endif  // LEMUR_INCLUDE_LOGGER_H_
