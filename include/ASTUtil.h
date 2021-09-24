//
// Created by avram on 11.9.21..
//

#ifndef LEMUR_ASTUTIL_H
#define LEMUR_ASTUTIL_H

#include <string>

#include "llvm/IR/Value.h"

using namespace llvm;

bool replaceFormat(std::string& str, const std::string& from,
                   const std::string& to);
std::string formatRawStr(std::string s);
Value* getPtrToPrim(const std::string& Name);
Value* getPtrToMember(const std::string& Name, const std::string& Sub);
Value* getPtrToValue(const std::string& Name, const std::string& Sub);
Value* GetMemberPointer(const std::string& Name, const std::string& Var);

#endif  // LEMUR_ASTUTIL_H
