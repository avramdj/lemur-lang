//
// Created by avram on 30.8.21..
//

#ifndef AVRLANG_MODULE_H
#define AVRLANG_MODULE_H

#include <map>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;
using namespace legacy;

namespace backend {
    namespace Types {
        extern std::map<std::string, Type*> typeTable;
        extern std::map<Type*, std::string> typeNames;
        extern std::map<std::string, std::map<std::string, unsigned>> classVarTable;
        extern std::map<std::string, std::map<std::string, Type *>> classVarTypeTable;
        extern std::map<std::string, std::vector<std::string>> classFnTable;
        Value *getTypeConstant(Type *, float);
        Value *getTypeConstant(std::string, float);
        Type *getType(std::string name);
        bool isClassType(Type *t);
        Value *boolCast(Value *v);
        Value *floatCast(Value *v);
        Value *stringCast(Value *v);
    }
    extern Module *TheModule;
    extern LLVMContext TheContext;
    extern IRBuilder<> Builder;
    extern llvm::legacy::FunctionPassManager *TheFPM;
    extern Function *PrintfFja;

    extern Value *strIntFormat;
    extern Value *strFloatFormat;
    extern Value *strFormat;

    extern std::map<std::string, std::pair<AllocaInst *, Type *>> NamedValues;

    void InitializeContext(void);
    void InitializeStrings(void);
    void InitializeTypeTable(void);
    void InitializeModuleAndPassManager(void);
    void printModule(bool printIR, std::string outPath);

    std::string encodeFunctionName(std::string fnName, std::string clsName);

    class TargetErrorException: public std::exception {
    public:
        TargetErrorException(const std::string& msgstr)
                : msg(msgstr)
        {}
        const char * what() const throw () {
            return msg.c_str();
        }
    private:
        std::string msg;
    };

    class FileException: public std::exception {
    public:
        FileException(const std::string& msgstr)
                : msg(msgstr)
        {}
        const char * what() const throw () {
            return msg.c_str();
        }
    private:
        std::string msg;
    };
}

#endif //AVRLANG_MODULE_H