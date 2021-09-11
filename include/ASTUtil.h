//
// Created by avram on 11.9.21..
//

#ifndef AVRLANG_ASTUTIL_H
#define AVRLANG_ASTUTIL_H

#include <string>
#include "llvm/IR/Value.h"

using namespace llvm;

bool replaceFormat(std::string& str, const std::string& from, const std::string& to);
std::string formatRawStr(std::string s);

Value *GetMemberPointer(const std::string& Name, const std::string& Var);

#endif //AVRLANG_ASTUTIL_H
