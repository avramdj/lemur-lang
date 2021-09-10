#include <ast.hpp>
#include <iostream>

// #define _DISABLE_OPTS_ 1
#define _LIBCPP_DEBUG 1

namespace backend {

    extern Module *TheModule;
    extern LLVMContext TheContext;
    extern llvm::legacy::FunctionPassManager *TheFPM;
    extern Function *PrintfFja;

    map<string, AllocaInst *> NamedValues;
    IRBuilder<> Builder(TheContext);
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

    Value *NumberExprAST::codegen() const {
        return ConstantInt::get(TheContext, APInt(32, Val));
    }

    Value *VariableExprAST::codegen() const {
        AllocaInst *tmp = NamedValues[Name];
        if (tmp == nullptr) {
            cerr << "Promenljiva " + Name + " nije definisana" << endl;
            return nullptr;
        }
        return Builder.CreateLoad(Type::getInt32Ty(TheContext), tmp, Name.c_str());
    }

    Value *AndExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateAnd(l, d, "andtmp");
    }

    Value *OrExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateOr(l, d, "ortmp");
    }

    Value *XorExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateXor(l, d, "xortmp");
    }

    Value *ShlExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateShl(l, d, "shltmp");
    }

    Value *ShrExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateLShr(l, d, "shrtmp");
    }

    Value *NotExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;
        return Builder.CreateNot(l, "nottmp");
    }

    Value *PrintExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;

        if (Str == nullptr) {
            Str = Builder.CreateGlobalStringPtr("%d\n");
        }
        vector<Value *> ArgsV;
        ArgsV.push_back(Str);
        ArgsV.push_back(l);
        Builder.CreateCall(PrintfFja, ArgsV, "printfCall");
        return l;
    }

    Value *PrintFormatExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;

        if (Str == nullptr) {
            Str = Builder.CreateGlobalStringPtr("%s\n");
        }
        vector<Value *> ArgsV;
        ArgsV.push_back(Str);
        ArgsV.push_back(l);
        Builder.CreateCall(PrintfFja, ArgsV, "printfCall");
        return l;
    }

    Value *DeclAssignExprAST::codegen() const {
        VarDeclExprAST decl = VarDeclExprAST(Type, Name);
        decl.codegen();
        AllocaInst *Alloca = NamedValues[Name];
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;
        return Builder.CreateStore(l, Alloca);
    }

    Value *VarDeclExprAST::codegen() const {
        AllocaInst *Alloca = NamedValues[Name];
        if(Alloca) {
            cerr << "Variable " << Name << " already defined" << endl;
            return nullptr;
        }
        Function *F = Builder.GetInsertBlock()->getParent();
        Alloca = CreateEntryBlockAlloca(F, Name);
        NamedValues[Name] = Alloca;
        return Builder.CreateStore(makeInt(0), Alloca);
    }

    Value *SetExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        if (l == nullptr)
            return nullptr;
        AllocaInst *Alloca = NamedValues[Name];
        if (!Alloca) {
            std::cerr << "Variable " << Name << " undefined" << std::endl;
            return nullptr;
        }
        return Builder.CreateStore(l, Alloca);
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
        for (unsigned i = 0; i < parameters.size(); i++)
            tmp.push_back(Type::getInt32Ty(TheContext));

        FunctionType *FT = FunctionType::get(Type::getInt32Ty(TheContext), tmp, false);

        Function *f = Function::Create(FT, Function::ExternalLinkage, name, TheModule);

        if (!f) {
            return nullptr;
        }

        unsigned i = 0;
        for (auto &a: f->args()) {
            a.setName(parameters[i++]);
        }

        if (!f->empty()) {
            cerr << "Funkcija " << name << " ne moze da se redefinise" << endl;
            return nullptr;
        }
        BasicBlock *BB = BasicBlock::Create(TheContext, "entry", f);
        Builder.SetInsertPoint(BB);

        NamedValues.clear();
        for (auto &a: f->args()) {
            AllocaInst *Alloca = CreateEntryBlockAlloca(f, string(a.getName()));
            NamedValues[string(a.getName())] = Alloca;
            Builder.CreateStore(&a, Alloca);
        }

        Value *Body = body->codegen();
        if (Body != nullptr) {
            if(!isRet(Body)) {
                Builder.CreateRet(ConstantInt::get(TheContext, APInt(32, 0)));
            }

            verifyFunction(*f);

            TheFPM->run(*f);

            return f;
        }

//        cerr << "DIDNT CREATE FUNCTION" << endl;
        f->eraseFromParent();

        return nullptr;
    }

    string FunctionDefintionAST::getName() const {
        return name;
    }

    Value *CallExprAST::codegen() const {
        Function *f = TheModule->getFunction(Callee);
        if (!f) {
            cerr << "Poziv nedefinisane funckije " << Callee << endl;
            return nullptr;
        }

        if (Args.size() != f->arg_size()) {
            cerr << "Funkcija " << Callee << " je pozvana sa neodgovarajucim brojem argumenata" << endl;
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


    CallExprAST::~CallExprAST() {

    }

    Value *AddExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateAdd(l, d, "andtmp");
    }

    Value *SubExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateSub(l, d, "subtmp");
    }

    Value *MulExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateMul(l, d, "multmp");
    }

    Value *DivExprAST::codegen() const {
        Value *l = _nodes[0]->codegen();
        Value *d = _nodes[1]->codegen();
        if (l == nullptr || d == nullptr)
            return nullptr;
        return Builder.CreateSDiv(l, d, "divtmp");
    }

    Value *LtExprAST::codegen() const {
        Value *L = _nodes[0]->codegen();
        Value *R = _nodes[1]->codegen();
        if (!L || !R)
            return nullptr;
        return Builder.CreateIntCast(Builder.CreateICmpSLT(L, R, "lttmp"), Type::getInt32Ty(TheContext), true);
    }

    Value *GtExprAST::codegen() const {
        Value *L = _nodes[0]->codegen();
        Value *R = _nodes[1]->codegen();
        if (!L || !R)
            return nullptr;
        return Builder.CreateIntCast(Builder.CreateICmpSGT(L, R, "gttmp"), Type::getInt32Ty(TheContext), true);
    }

    Value *EqExprAST::codegen() const {
        Value *L = _nodes[0]->codegen();
        Value *R = _nodes[1]->codegen();
        if (!L || !R)
            return nullptr;
        return Builder.CreateIntCast(Builder.CreateICmpEQ(L, R, "eqtmp"), Type::getInt32Ty(TheContext), true);
    }

    Value *NeqExprAST::codegen() const {
        Value *L = _nodes[0]->codegen();
        Value *R = _nodes[1]->codegen();
        if (!L || !R)
            return nullptr;
        return Builder.CreateIntCast(Builder.CreateICmpNE(L, R, "neqtmp"), Type::getInt32Ty(TheContext), true);
    }

    Value *LteExprAST::codegen() const {
        Value *L = _nodes[0]->codegen();
        Value *R = _nodes[1]->codegen();
        if (!L || !R)
            return nullptr;
        return Builder.CreateIntCast(Builder.CreateICmpSLE(L, R, "ltetmp"), Type::getInt32Ty(TheContext), true);
    }

    Value *GteExprAST::codegen() const {
        Value *L = _nodes[0]->codegen();
        Value *R = _nodes[1]->codegen();
        if (!L || !R)
            return nullptr;
        return Builder.CreateIntCast(Builder.CreateICmpSGE(L, R, "gtetmp"), Type::getInt32Ty(TheContext), true);
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
        Value *Cmp = Builder.CreateICmpNE(Cond, ConstantInt::get(TheContext, APInt(32, 0)), "loopcond");
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

        return ConstantInt::get(TheContext, APInt(32, 0));
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
        Value *Cmp = Builder.CreateICmpNE(Cond, ConstantInt::get(TheContext, APInt(32, 0)), "cmptmp");
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
        return ConstantInt::get(TheContext, APInt(32, 0));
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
        Value *Cmp = Builder.CreateICmpNE(Cond, ConstantInt::get(TheContext, APInt(32, 0)), "cmptmp");
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
        Value *ret = v->codegen();
        if (!ret) {
            return nullptr;
        }
        return Builder.CreateRet(ret);
    }

    AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const string &VarName) {
        IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
        return TmpB.CreateAlloca(Type::getInt32Ty(TheContext), 0, VarName.c_str());
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
}