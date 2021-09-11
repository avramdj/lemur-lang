//
// Created by avram on 11.9.21..
//

#include <string>
#include <iostream>
#include <ASTUtil.h>
#include <context.h>
#include "llvm/IR/Instructions.h"

using namespace llvm;
using namespace backend;

bool replaceFormat(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
std::string formatRawStr(std::string s) {
    while(replaceFormat(s, "\\\\", "\\")) {}
    while(replaceFormat(s, "\\n", "\n")) {}
    s = s.substr(1, s.size()-2);
    return s;
}

Value *GetMemberPointer(const std::string& Name, const std::string& Var){
    AllocaInst *tmp = NamedValues[Name].first;
    if (tmp == nullptr) {
        std::cerr << "Variable " + Name + " is undefined" << std::endl;
        return nullptr;
    }
    Type *t = tmp->getAllocatedType();

    auto cit = Types::typeNames.find(t);
    if(cit == Types::typeNames.end()) {
        std::cerr << "Variable " << Name << " is not of class type" << std::endl;
        return nullptr;
    }
    std::string clsName = cit->second;
    auto it = Types::classVarTable[clsName].find(Var);
    if(it == Types::classVarTable[clsName].end()) {
        std::cerr << "Class " << clsName << " doesn't have member " << Var << std::endl;
        return nullptr;
    }
    unsigned memberIdx = it->second;
//    Value *tmp2 = Builder.CreateLoad(t, tmp, "derefstruct");
    Value *gep = Builder.CreateStructGEP(tmp, memberIdx);
    assert(gep);
//    return Builder.CreateLoad(Types::classVarTypeTable[Name][Var], gep, "derefstructmember");
    return gep;
}