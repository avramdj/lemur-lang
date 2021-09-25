//
// Created by avram on 25.9.21..
//

#include "logger.h"

#include <iostream>

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
