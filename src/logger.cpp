//
// Created by avram on 25.9.21..
//

#include "logger.h"

#include <iostream>

//#define cReset   "\033[0m"
//#define BLACK   "\033[30m"      /* Black */
//#define RED     "\033[31m"      /* Red */
//#define GREEN   "\033[32m"      /* Green */
//#define YELLOW  "\033[33m"      /* Yellow */
//#define BLUE    "\033[34m"      /* Blue */
//#define MAGENTA "\033[35m"      /* Magenta */
//#define CYAN    "\033[36m"      /* Cyan */
//#define WHITE   "\033[37m"      /* White */
//#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
//#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
//#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
//#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
//#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
//#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
//#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
//#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
namespace backend {
void log::warn(std::string s) {
  if (logLevel == lWarn) {
    std::cerr << cWarn << "warning: " << cReset << s << std::endl;
  }
}
void log::err(std::string s) {
  std::cerr << cError << "error: " << cReset << s << std::endl;
}
std::ostream& log::operator<<(std::ostream& os, backend::log::Color color) {
  if (color == log::cReset) {
    os << "\033[0m";
  } else if (color == log::cWarn) {
    os << "\033[1m\033[31m";
  } else if (color == log::cError) {
    os << "\033[1m\033[34m";
  }
  return os;
}
}  // namespace backend
