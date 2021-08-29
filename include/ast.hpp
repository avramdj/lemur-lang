#ifndef __AST_HPP__
#define __AST_HPP__ 1

#include <string>
#include <vector>
using namespace std;

#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Support/FileSystem.h"

using namespace llvm;
using namespace llvm::legacy;

namespace backend {

    class ExprAST {
    public:
        virtual ~ExprAST();

        virtual Value *codegen() const = 0;
    };

    class NumberExprAST : public ExprAST {
    public:
        NumberExprAST(int v)
                : Val(v) {}

        Value *codegen() const;

    private:
        int Val;
    };

    class VariableExprAST : public ExprAST {
    public:
        VariableExprAST(string s)
                : Name(s) {}

        Value *codegen() const;

    private:
        string Name;
    };

    class InnerExprAST : public ExprAST {
    public:
        InnerExprAST(shared_ptr<ExprAST> a);

        InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b);

        InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b, shared_ptr<ExprAST> c);

        InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b, shared_ptr<ExprAST> c, shared_ptr<ExprAST> d);

        InnerExprAST(vector<shared_ptr<ExprAST> > a);

        ~InnerExprAST();

    protected:
        vector<shared_ptr<ExprAST> > _nodes;
    private:
        InnerExprAST(const InnerExprAST &i);

        InnerExprAST &operator=(const InnerExprAST &i);
    };

    class AndExprAST : public InnerExprAST {
    public:
        AndExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class OrExprAST : public InnerExprAST {
    public:
        OrExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class XorExprAST : public InnerExprAST {
    public:
        XorExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class ShlExprAST : public InnerExprAST {
    public:
        ShlExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class ShrExprAST : public InnerExprAST {
    public:
        ShrExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class NotExprAST : public InnerExprAST {
    public:
        NotExprAST(shared_ptr<ExprAST> a)
                : InnerExprAST(a) {}

        Value *codegen() const;
    };

    class PrintExprAST : public InnerExprAST {
    public:
        PrintExprAST(shared_ptr<ExprAST> a)
                : InnerExprAST(a) {}

        Value *codegen() const;
    };

    class SetExprAST : public InnerExprAST {
    public:
        SetExprAST(shared_ptr<ExprAST> a, string n)
                : InnerExprAST(a), Name(n) {}

        Value *codegen() const;

    private:
        string Name;
    };

    class SeqExprAST : public InnerExprAST {
    public:
        SeqExprAST(vector<shared_ptr<ExprAST> > a)
                : InnerExprAST(a) {}

        Value *codegen() const;

        void add(shared_ptr<ExprAST> node);
    };

    class FunctionDefintionAST : ExprAST {
    public:
        FunctionDefintionAST(string n, vector<string> p, shared_ptr<ExprAST> b)
                : name(n), parameters(p), body(b) {}

        string getName() const;

        Value *codegen() const;

    private:
        string name;
        vector<string> parameters;
        shared_ptr<ExprAST> body;
    };

    class CallExprAST : public ExprAST {
    public:
        CallExprAST(string s, vector<shared_ptr<ExprAST> > v)
                : Callee(s), Args(v) {}

        Value *codegen() const;

        ~CallExprAST();

    private:
        CallExprAST(const CallExprAST &);

        CallExprAST &operator=(const CallExprAST &);

        string Callee;
        vector<shared_ptr<ExprAST> > Args;
    };

    class AddExprAST : public InnerExprAST {
    public:
        AddExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class SubExprAST : public InnerExprAST {
    public:
        SubExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class LtExprAST : public InnerExprAST {
    public:
        LtExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class GtExprAST : public InnerExprAST {
    public:
        GtExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class LteExprAST : public InnerExprAST {
    public:
        LteExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class GteExprAST : public InnerExprAST {
    public:
        GteExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class NeqExprAST : public InnerExprAST {
    public:
        NeqExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class EqExprAST : public InnerExprAST {
    public:
        EqExprAST(shared_ptr<ExprAST> l, shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class WhileExprAST : public ExprAST {
    public:
        WhileExprAST(shared_ptr<ExprAST> c, shared_ptr<ExprAST> b)
                : cond(c), block(b) {}

        Value *codegen() const;

    private:
        shared_ptr<ExprAST> cond;
        shared_ptr<ExprAST> block;
    };

    class IfExprAST : public ExprAST {
    public:
        IfExprAST(shared_ptr<ExprAST> c, shared_ptr<ExprAST> b)
                : cond(c), block(b) {}

        Value *codegen() const;

    private:
        shared_ptr<ExprAST> cond;
        shared_ptr<ExprAST> block;
    };

    class IfElseExprAST : public ExprAST {
    public:
        IfElseExprAST(shared_ptr<ExprAST> c, shared_ptr<ExprAST> t, shared_ptr<ExprAST> e)
                : cond(c), thenBlock(t), elseBlock(e) {}

        Value *codegen() const;

    private:
        shared_ptr<ExprAST> cond;
        shared_ptr<ExprAST> thenBlock;
        shared_ptr<ExprAST> elseBlock;
    };

    class RetExprAST : public ExprAST {
    public:
        RetExprAST(shared_ptr<ExprAST> e)
                : v(e) {}

        Value *codegen() const;

    private:
        shared_ptr<ExprAST> v;
    };

    void InitializeModuleAndPassManager(void);

    AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const string &VarName);

    void printModule();

}

#endif
