//
// Created by avram on 11.9.21..
//

#ifndef AVRLANG_ASTUTIL_H
#define AVRLANG_ASTUTIL_H

#include <string>

bool replaceFormat(std::string& str, const std::string& from, const std::string& to);
std::string formatRawStr(std::string s);

#endif //AVRLANG_ASTUTIL_H
