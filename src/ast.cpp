#include <iostream>

#include <ast.hpp>
#include <ASTUtil.h>
#include <context.h>

#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"

#define _LIBCPP_DEBUG 1

using namespace std;

namespace backend {

    Value *Str;
    Value *Str1;

    ExprAST::~ExprAST() {

    }

    InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a) {
        _nodes.resize(0);
        _nodes.push_back(a);
    }

    InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b) {
        _nodes.resize(0);
        _nodes.push_back(a);
        _nodes.push_back(b);
    }

    InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b, shared_ptr<ExprAST> c) {
        _nodes.resize(0);
        _nodes.push_back(a);
        _nodes.push_back(b);
        _nodes.push_back(c);
    }

    InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b, shared_ptr<ExprAST> c, shared_ptr<ExprAST> d) {
        _nodes.resize(0);
        _nodes.push_back(a);
        _nodes.push_back(b);
        _nodes.push_back(c);
        _nodes.push_back(d);
    }

    InnerExprAST::InnerExprAST(vector<shared_ptr<ExprAST> > a) {
        _nodes = a;
    }

    InnerExprAST::~InnerExprAST() {

    }

    Value *IntExprAST::codegen() const {
        return Types::getTypeConstant("int", Val); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }

    Value *FloatExprAST::codegen() const {
        return Types::getTypeConstant("float", Val);
    }

    Value *VariableExprAST::codegen() const {
        Value *v = getPtrToValue(Name, Sub);
        Type *t = v->getType()->getPointerElementType();
        return Builder.CreateLoad(t, v, Name);
    }

    Value *AndExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Value *lC = Types::boolCast(l);
        if(!lC){
            std::cerr << "Can't bool cast" << std::endl;
            return nullptr;
        }
        Value *dC = Types::boolCast(l);
        if(!dC){
            std::cerr << "Can't bool cast" << std::endl;
            return nullptr;
        }
        return Builder.CreateAnd(lC, dC, "andtmp");
    }

    Value *OrExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Value *lC = Types::boolCast(l);
        if(!lC){
            std::cerr << "Cant bool cast" << std::endl;
            return nullptr;
        }
        Value *dC = Types::boolCast(l);
        if(!dC){
            std::cerr << "Cant bool cast" << std::endl;
            return nullptr;
        }
        return Builder.CreateOr(lC, dC, "ortmp");
    }

    Value *XorExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Value *lC = Types::boolCast(l);
        if(!lC){
            std::cerr << "Cant bool cast" << std::endl;
            return nullptr;
        }
        Value *dC = Types::boolCast(l);
        if(!dC){
            std::cerr << "Cant bool cast" << std::endl;
            return nullptr;
        }
        return Builder.CreateXor(lC, dC, "xortmp");
    }

    Value *ShlExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        Value *lC = l;
        Value *dC = d;
        return Builder.CreateShl(lC, dC, "shltmp");
    }

    Value *ShrExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        Value *lC = l;
        Value *dC = d;
        return Builder.CreateLShr(lC, dC, "shrtmp");
    }

    Value *NotExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;
        Value *lC = Types::boolCast(l);
        if(!lC){
            std::cerr << "Cant bool cast" << std::endl;
            return nullptr;
        }
        return Builder.CreateNot(lC, "nottmp");
    }

    Value *PrintExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;
        vector<Value *> ArgsV;
        Type *t = l->getType();
        Value *ftm;
        if(!strFormat) {
            InitializeStrings();
        }
        if(t == Types::getType("int")) {
            ftm = strIntFormat;
        } else if (t == Types::getType("float")) {
            ftm = strFloatFormat;
        } else if (t == Types::getType("string")) {
            ftm = strFormat;
        } else if (t == Types::getType("bool")){
            ftm = strIntFormat;
        } else {
            std::cerr << "Unknown type cast to string" << std::endl;
            return nullptr;
        }
        ArgsV.push_back(ftm);
        ArgsV.push_back(l);
        Builder.CreateCall(PrintFun, ArgsV, "printfCall");
        return l;
    }

    Value *DeclAssignExprAST::codegen() const {
        VarDeclExprAST decl(Type, Name);
        decl.codegen();
        SetExprAST set(_nodes[0], Name);
        return set.codegen();
    }

    Value *VarDeclExprAST::codegen() const {
        AllocaInst *Alloca = NamedValues[Name].first;
        if(Alloca) {
            cerr << "Variable " << Name << " already defined" << endl;
            return nullptr;
        }
        Function *F = Builder.GetInsertBlock()->getParent();
        llvm::Type* t = Types::getType(Type);
        if(!t) {
            std::cerr << "Unknown type " << Type << std::endl;
            return nullptr;
        }
        Alloca = CreateEntryBlockAlloca(t, F, Name);
        if(Types::isClassType(t)) {
//            Value *StructAlloca = CreateEntryBlockAlloca(t->getPointerElementType(), F, Name + string(".RAW"));
            Value *structSizeVal = Types::getStructSize(t);
            Value *StructAllocaRaw = Builder.CreateCall(MallocFun, structSizeVal);
            Value *StructAlloca = Builder.CreateBitCast(StructAllocaRaw, t);
            Builder.CreateStore(StructAlloca, Alloca);
        }
        NamedValues[Name] = {Alloca, t};
        return Alloca;
    }

    Value *SetExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;
        Value *el = getPtrToValue(Name, Sub);
        if(l->getType() != el->getType()->getPointerElementType()) {
            std::cerr << "Type mismatch with "
                << Name + (Sub.empty()? string("") : string(".") + Sub )
                << std::endl;
            return nullptr;
        }
        return Builder.CreateStore(l, el);
    }

    Value *SeqExprAST::codegen() const {
        Value *tmp = nullptr;
        for (unsigned i = 0; i < _nodes.size(); i++) {
            tmp = _nodes[i]->codegen();
            if(isRet(tmp)) {
                return tmp;
            }
            if (!tmp)
                return nullptr;
        }
        return tmp;
    }

    void SeqExprAST::add(shared_ptr<ExprAST> node) {
        _nodes.push_back(node);
    }

    Value *FunctionDefintionAST::codegen() const {
        vector<Type *> tmp;

        for (auto& typeName : ptypes) {
            Type *t = Types::getType(typeName);
            if(!t) {
                return nullptr;
            }
            tmp.push_back(t);
        }
        Type * retT= Types::getType(this->retType);
        if(!retT) {
            return nullptr;
        }
        FunctionType *FT = FunctionType::get(retT, tmp, false);

        Function *f = Function::Create(FT, Function::ExternalLinkage, name, TheModule);

        if (!f) {
            return nullptr;
        }

        unsigned i = 0;
        for (auto &a: f->args()) {
            a.setName(parameters[i++]);
        }

        if (!f->empty()) {
            cerr << "Function " << name << " can't be redefined" << endl;
            return nullptr;
        }
        BasicBlock *BB = BasicBlock::Create(TheContext, "entry", f);
        Builder.SetInsertPoint(BB);

        NamedValues.clear();
        for (auto &a: f->args()) {
            AllocaInst *Alloca = CreateEntryBlockAlloca(a.getType(), f, string(a.getName()));
            NamedValues[string(a.getName())] = {Alloca, a.getType()};
            Builder.CreateStore(&a, Alloca);
        }

        Value *Body = body->codegen();
        if (Body != nullptr) {
            if(!isRet(Body)) {
                auto retV = Types::getTypeConstant(retType, 0);
                if(!retV) {
                    std::cerr << "Function " << name << " can't create implicit return" << std::endl;
                    return nullptr;
                }
                Builder.CreateRet(retV);
            }

            verifyFunction(*f);

            TheFPM->run(*f);

            return f;
        }

        f->eraseFromParent();

        return nullptr;
    }

//    Value *MemberFunctionDefAST::codegen() const {
//        vector<Type *> tmp;
//        Type *clsPtrTy = Types::typeTable[cls]->getPointerTo();
//        tmp.push_back(clsPtrTy);
//        for (auto& typeName : ptypes) {
//            Type *t = Types::getType(typeName);
//            if(!t) {
//                return nullptr;
//            }
//            tmp.push_back(t);
//        }
//
//        Type * retT= Types::getType(this->retType);
//        if(!retT) {
//            return nullptr;
//        }
//        FunctionType *FT = FunctionType::get(retT, tmp, false);
//
//        Function *f = Function::Create(FT, Function::ExternalLinkage, name, TheModule);
//
//        if (!f) {
//            return nullptr;
//        }
//
//        unsigned i = 0;
//        std::vector<std::string> newparams;
//        newparams.emplace_back("__tmpptr_this");
//        for(auto &p: parameters){
//            newparams.push_back(p);
//        }
//        for (auto &a: f->args()) {
//            a.setName(newparams[i++]);
//        }
//
//        if (!f->empty()) {
//            cerr << "Function " << name << " can't be redefined" << endl;
//            return nullptr;
//        }
//        BasicBlock *BB = BasicBlock::Create(TheContext, "entry", f);
//        Builder.SetInsertPoint(BB);
//
//        NamedValues.clear();
//        Type *clsTy = Types::getType(cls);
//        Value *zis = Builder.CreateGEP(clsTy, f->args().begin(), Types::getTypeConstant("int", 0), "thiscast");
//        i = 0;
//        for (auto &a: f->args()) {
//            if(i == 0) {
//                AllocaInst *Alloca = CreateEntryBlockAlloca(clsTy, f, string("this"));
//                NamedValues[string("this")] = {Alloca, clsTy};
//                Builder.CreateStore(zis, Alloca);
//            } else {
//                AllocaInst *Alloca = CreateEntryBlockAlloca(a.getType(), f, string(a.getName()));
//                NamedValues[string(a.getName())] = {Alloca, a.getType()};
//                Builder.CreateStore(&a, Alloca);
//            }
//            i++;
//        }
//
//        Value *Body = body->codegen();
//        if (Body != nullptr) {
//            if(!isRet(Body)) {
//                auto retV = Types::getTypeConstant(retType, 0);
//                if(!retV) {
//                    std::cerr << "Function " << name << " can't create implicit return" << std::endl;
//                    return nullptr;
//                }
//                Builder.CreateRet(retV);
//            }
//
//            verifyFunction(*f);
//
//            TheFPM->run(*f);
//
//            return f;
//        }
//
//        f->eraseFromParent();
//
//        return nullptr;
//    }

    string FunctionDefintionAST::getName() const {
        return name;
    }

    Value *CallExprAST::codegen() const {
        Function *f = TheModule->getFunction(Callee);
        if (!f) {
            cerr << "Call of undefined function " << Callee << endl;
            return nullptr;
        }

        if (Args.size() != f->arg_size()) {
            cerr << "Function " << Callee << " called with " << Args.size() << " arguments but takes " <<
            f->arg_size() << endl;
            return nullptr;
        }

        vector<Value *> ArgsV;
        for (unsigned i = 0; i < Args.size(); i++) {
            Value *tmp = Args[i]->codegen();
            if (!tmp)
                return nullptr;
            ArgsV.push_back(tmp);
        }

        return Builder.CreateCall(f, ArgsV, "calltmp");
    }

    Value *MethodCallExprAST::codegen() const {
        AllocaInst *tmp = NamedValues[Name].first;
        if (tmp == nullptr) {
            cerr << "Variable " + Name + " is undefined" << endl;
            return nullptr;
        }
        Type *t = tmp->getAllocatedType();

//        bool isPtr = t->isPointerTy();
        auto cit = Types::typeNames.find(t);
        if(cit == Types::typeNames.end()) {
            std::cerr << "Variable " << Name << " is not of class type" << std::endl;
            return nullptr;
        }
        std::string clsName = cit->second;
        std::string encodedMethod = encodeFunctionName(Method, clsName);
        Function *f = TheModule->getFunction(encodedMethod);
        if (!f) {
            cerr << "Call of undefined method " << Method << endl;
            return nullptr;
        }
        Value *loadTmp = Builder.CreateLoad(t, tmp);
        vector<Value *> ArgsV;
        ArgsV.push_back(loadTmp);
        for (unsigned i = 0; i < Args.size(); i++) {
            Value *tmpParam = Args[i]->codegen();
            if (!tmpParam)
                return nullptr;
            ArgsV.push_back(tmpParam);
        }

        if (ArgsV.size() != f->arg_size()) {
            cerr << "Method " << Method << " called with " << ArgsV.size()-1 << " arguments but takes " <<
                 f->arg_size()-1 << endl;
            return nullptr;
        }

        return Builder.CreateCall(f, ArgsV, "methodcalltmp");
    }

//    Value *ClassAccessExprAST::codegen() const {
//        Value *gep = GetMemberPointer(Name, Var);
//        Type *mt = gep->getType();
//        return Builder.CreateLoad(mt, gep, "membload");
//    }

    Value *AddExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFAdd(l, d, "addtmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateAdd(l, d, "addtmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFAdd(lC, dC, "addtmp");
    }

    Value *SubExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFSub(l, d, "subtmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateSub(l, d, "subtmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFSub(lC, dC, "subtmp");
    }

    Value *MulExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFMul(l, d, "multmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateMul(l, d, "multmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFMul(lC, dC, "multmp");
    }

    Value *DivExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFDiv(l, d, "divtmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateSDiv(l, d, "divtmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFDiv(lC, dC, "divtmp");
    }

    Value *LtExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (!l || !d)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFCmpOLT(l, d, "lttmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateICmpSLT(l, d, "lttmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFCmpOLT(lC, dC, "lttmp");
    }

    Value *GtExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (!l || !d)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFCmpOGT(l, d, "lttmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateICmpSGT(l, d, "lttmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFCmpOGT(lC, dC, "lttmp");
    }

    Value *EqExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (!l || !d)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFCmpOEQ(l, d, "eqtmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateICmpEQ(l, d, "eqtmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFCmpOEQ(lC, dC, "eqtmp");
    }

    Value *NeqExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (!l || !d)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFCmpONE(l, d, "netmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateICmpNE(l, d, "netmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFCmpONE(lC, dC, "netmp");
    }

    Value *LteExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (!l || !d)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFCmpOLE(l, d, "letmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateICmpSLE(l, d, "letmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFCmpOLE(lC, dC, "letmp");
    }

    Value *GteExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (!l || !d)
            return nullptr;
        Type *lT = l->getType();
        Type *dT = d->getType();
        if(lT == dT && lT == Types::getType("float")){
            return Builder.CreateFCmpOGE(l, d, "getmp");
        }
        if(lT == dT && lT == Types::getType("int")){
            return Builder.CreateICmpSGE(l, d, "getmp");
        }
        Value *lC = Types::floatCast(l);
        Value *dC = Types::floatCast(d);
        return Builder.CreateFCmpOGE(lC, dC, "getmp");
    }

    Value *WhileExprAST::codegen() const {

        Function *f = Builder.GetInsertBlock()->getParent();
        BasicBlock *HeaderBB = BasicBlock::Create(TheContext, "header", f);
        BasicBlock *LoopBB = BasicBlock::Create(TheContext, "loop", f);
        BasicBlock *AfterLoopBB = BasicBlock::Create(TheContext, "afterloop", f);

        //header :
        Builder.CreateBr(HeaderBB);
        Builder.SetInsertPoint(HeaderBB);
        Value *Cond = cond->codegen();
        if (!Cond) {
            return nullptr;
        }
        Value *Cmp = Builder.CreateICmpNE(Types::boolCast(Cond), ConstantInt::get(TheContext, APInt(1, 0)), "loopcond");
        Builder.CreateCondBr(Cmp, LoopBB, AfterLoopBB);
        HeaderBB = Builder.GetInsertBlock();

        //loop :
        Builder.SetInsertPoint(LoopBB);
        Value *BlockV = block->codegen();
        if (!BlockV)
            return nullptr;

        if(!isRet(BlockV)) {
            Builder.CreateBr(HeaderBB);
        }

        LoopBB = Builder.GetInsertBlock();
        Builder.SetInsertPoint(AfterLoopBB);

        return ConstantInt::get(TheContext, APInt(1, 0));
    }


    Value *IfExprAST::codegen() const {
        Function *f = Builder.GetInsertBlock()->getParent();
        BasicBlock *headerBB = BasicBlock::Create(TheContext, "header", f);
        BasicBlock *thenBB = BasicBlock::Create(TheContext, "then", f);
        BasicBlock *mergeBB = BasicBlock::Create(TheContext, "merge", f);

        Builder.CreateBr(headerBB);
        Builder.SetInsertPoint(headerBB);

        Value *Cond = cond->codegen();
        if (!Cond) {
            return nullptr;
        }
        Value *Cmp = Builder.CreateICmpNE(Types::boolCast(Cond), ConstantInt::get(TheContext, APInt(1, 0)), "cmptmp");
        Builder.CreateCondBr(Cmp, thenBB, mergeBB);

        Builder.SetInsertPoint(thenBB);
        Value *ThenV = block->codegen();
        if (!ThenV) {
            return nullptr;
        }

        if(!isRet(ThenV)) {
            Builder.CreateBr(mergeBB);
        }

        Builder.SetInsertPoint(mergeBB);
        return ConstantInt::get(TheContext, APInt(1, 0));
    }

    Value *IfElseExprAST::codegen() const {
        Function *f = Builder.GetInsertBlock()->getParent();
        BasicBlock *headerBB = BasicBlock::Create(TheContext, "header", f);
        BasicBlock *thenBB = BasicBlock::Create(TheContext, "then", f);
        BasicBlock *elseBB = BasicBlock::Create(TheContext, "else", f);
        BasicBlock *mergeBB = BasicBlock::Create(TheContext, "merge");

        Builder.CreateBr(headerBB);
        Builder.SetInsertPoint(headerBB);

        Value *Cond = cond->codegen();
        if (!Cond) {
            return nullptr;
        }
        headerBB = Builder.GetInsertBlock();
        Value *Cmp = Builder.CreateICmpNE(Types::boolCast(Cond), ConstantInt::get(TheContext, APInt(1, 0)), "cmptmp");
        Builder.CreateCondBr(Cmp, thenBB, elseBB);

        Builder.SetInsertPoint(thenBB);
        Value *ThenV = thenBlock->codegen();
        if (!ThenV) {
            return nullptr;
        }
        thenBB = Builder.GetInsertBlock();
        bool thenRet = isRet(ThenV);
        if(!thenRet) {
            Builder.CreateBr(mergeBB);
        }
        Builder.SetInsertPoint(elseBB);
        Value *ElseV = elseBlock->codegen();
        if (!ElseV) {
            return nullptr;
        }
        bool elseRet = isRet(ElseV);
        if(!elseRet) {
            Builder.CreateBr(mergeBB);
        }
        elseBB = Builder.GetInsertBlock();


        if(thenRet && elseRet) {
            return ThenV; //returns ReturnInst*, code after is unreachable
        }

        f->getBasicBlockList().push_back(mergeBB);
        Builder.SetInsertPoint(mergeBB);

        return ConstantInt::get(TheContext, APInt(32, 0));
    }

    Value *RetExprAST::codegen() const {
        Function *f = Builder.GetInsertBlock()->getParent();
        if(v == nullptr) {
            if(f->getReturnType() != Types::getType("void")) {
                std::cerr << "Void return in non void function " << f->getName().str() << std::endl;
                return nullptr;
            }
            return Builder.CreateRet(Types::getTypeConstant("void", 0));
        }
        Value *ret = v->codegen();
        if (!ret) {
            return nullptr;
        }
        return Builder.CreateRet(ret);
    }

    AllocaInst *CreateEntryBlockAlloca(Type *t, Function *TheFunction, const string &VarName) {
        IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
        return TmpB.CreateAlloca(t, nullptr, VarName.c_str());
    }

    bool isRet(Value* tmp) {
        return llvm::dyn_cast<ReturnInst>(tmp);
    }
    Value *makeInt(int value) {
        return ConstantInt::get(TheContext, APInt(32, value));
    }
    Value *makeDouble(double value) {
        return ConstantFP::get(Type::getDoubleTy(TheContext), value);
    }

    Value *StringExprAST::codegen() const {
        auto charType = llvm::IntegerType::get(TheContext, 8);

        std::vector<llvm::Constant *> chars(Str.length());
        for(unsigned int i = 0; i < Str.size(); i++) {
            chars[i] = llvm::ConstantInt::get(charType, Str[i]);
        }
        chars.push_back(llvm::ConstantInt::get(charType, 0));

        auto stringType = llvm::ArrayType::get(charType, chars.size());
        auto globalDeclaration = (llvm::GlobalVariable*) TheModule->getOrInsertGlobal(".str", stringType);
        globalDeclaration->setInitializer(llvm::ConstantArray::get(stringType, chars));
        globalDeclaration->setConstant(true);
        globalDeclaration->setLinkage(llvm::GlobalValue::LinkageTypes::PrivateLinkage);
        globalDeclaration->setUnnamedAddr (llvm::GlobalValue::UnnamedAddr::Global);

        return llvm::ConstantExpr::getBitCast(globalDeclaration, charType->getPointerTo());
    }

    Value *ClassDefExprAST::codegen() const {
        if(Types::typeTable.find(Name) != Types::typeTable.end()) {
            std::cerr << "Class " << Name << " already exists" << std::endl;
        }
        vector<Type *> subtypes;
        for(int i = 0; i < types.size(); i++){
            Type * t = Types::getType(types[i]);
            if(!t){
                return nullptr;
            }
            if(Types::classVarTable[Name].find(vars[i]) != Types::classVarTable[Name].end()) {
                std::cerr << "Class variable " << types[i] << " already defined" << std::endl;
                return nullptr;
            }
            subtypes.push_back(t);
            Types::classVarTable[Name][vars[i]] = i;
            Types::classVarTypeTable[Name][vars[i]] = t;
        }
        StructType* classType = StructType::create(TheContext, subtypes, Name);
        Types::typeTable[Name] = classType->getPointerTo();
        Types::typeNames[Types::typeTable[Name]] = Name;
        for(auto& f : functions) {
            f->codegen();
        }
        return nullptr;
    }
}