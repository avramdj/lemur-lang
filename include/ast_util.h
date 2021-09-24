//
// Created by avram on 11.9.21..
//

#ifndef LEMUR_ASTUTIL_H
#define LEMUR_ASTUTIL_H

#include <map>
#include <string>

#include "llvm/IR/Value.h"

namespace backend {

bool replaceFormat(std::string& str, const std::string& from,
                   const std::string& to);
std::string formatRawStr(std::string s);
llvm::Value* getPtrToPrim(const std::string& Name);
llvm::Value* getPtrToMember(const std::string& Name, const std::string& Sub);
llvm::Value* getPtrToValue(const std::string& Name, const std::string& Sub);
llvm::Value* GetMemberPointer(const std::string& Name, const std::string& Var);

}  // namespace backend

#endif  // LEMUR_ASTUTIL_H
