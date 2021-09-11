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
    extern Module *TheModule;
    extern LLVMContext TheContext;
    extern IRBuilder<> Builder;
    extern llvm::legacy::FunctionPassManager *TheFPM;
    extern Function *PrintfFja;
    extern Function *Sprintf;
    extern std::map<std::string, std::pair<AllocaInst *, Type *>> NamedValues;
    namespace Types {
        extern std::map<std::string, Type*> typeTable;
        extern std::map<std::string, std::map<std::string, int>> classVarTable;
        extern std::map<std::string, std::vector<std::string>> classFnTable;
        Value *getTypeConstant(Type *, float);
        Value *getTypeConstant(std::string, float);
        Type *getType(std::string name);
        Value *boolCast(Value *v);
        Value *floatCast(Value *v);
    }
    void InitializeContext(void);
    void InitializeTypeTable(void);
    void InitializeModuleAndPassManager(void);
    void printModule(bool printIR, std::string outPath);

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