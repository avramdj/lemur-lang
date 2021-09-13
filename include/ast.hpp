#ifndef __AST_HPP__
#define __AST_HPP__ 1

#include <string>
#include <vector>
#include <memory>

#include "llvm/IR/Value.h"
#include "llvm/IR/Instructions.h"

using namespace llvm;

namespace backend {

    class ExprAST {
    public:
        virtual ~ExprAST();

        virtual Value *codegen() const = 0;
    };

    class IntExprAST : public ExprAST {
    public:
        IntExprAST(int v)
                : Val(v) {}

        Value *codegen() const;

    private:
        int Val;
    };

    class FloatExprAST : public ExprAST {
    public:
        FloatExprAST(float v)
                : Val(v) {}

        Value *codegen() const;

    private:
        float Val;
    };

    class VariableExprAST : public ExprAST {
    public:
        VariableExprAST(std::string n)
                : Name(n) {}

        VariableExprAST(std::string n, std::string s)
                : Name(n), Sub(s) {}

        Value *codegen() const;

    private:
        std::string Name;
        std::string Sub;
    };

    class InnerExprAST : public ExprAST {
    public:
        InnerExprAST(std::shared_ptr<ExprAST> a);

        InnerExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b);

        InnerExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b, std::shared_ptr<ExprAST> c);

        InnerExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b, std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> d);

        InnerExprAST(std::vector<std::shared_ptr<ExprAST> > a);

        ~InnerExprAST();

    protected:
        std::vector<std::shared_ptr<ExprAST> > _nodes;
    private:
        InnerExprAST(const InnerExprAST &i);

        InnerExprAST &operator=(const InnerExprAST &i);
    };

    class AndExprAST : public InnerExprAST {
    public:
        AndExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class OrExprAST : public InnerExprAST {
    public:
        OrExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class XorExprAST : public InnerExprAST {
    public:
        XorExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class ShlExprAST : public InnerExprAST {
    public:
        ShlExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class ShrExprAST : public InnerExprAST {
    public:
        ShrExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
                : InnerExprAST(a, b) {}

        Value *codegen() const;
    };

    class NotExprAST : public InnerExprAST {
    public:
        NotExprAST(std::shared_ptr<ExprAST> a)
                : InnerExprAST(a) {}

        Value *codegen() const;
    };

    class PrintExprAST : public InnerExprAST {
    public:
        PrintExprAST(std::shared_ptr<ExprAST> a)
                : InnerExprAST(a) {}

        Value *codegen() const;
    };

    class VarDeclExprAST : public ExprAST {
    public:
        VarDeclExprAST(std::string type, std::string name)
                : Type(type), Name(name) {}

        Value *codegen() const;

    private:
        std::string Name;
        std::string Type;
    };

    class DeclAssignExprAST : public InnerExprAST {
    public:
        DeclAssignExprAST(std::string t, std::string n, std::shared_ptr<ExprAST> a)
                : Type(t), Name(n), InnerExprAST(a) {}

        Value *codegen() const;

    private:
        std::string Type;
        std::string Name;
    };

    class SetExprAST : public InnerExprAST {
    public:
        SetExprAST(std::shared_ptr<ExprAST> a, std::string n)
                : InnerExprAST(a), Name(n) {}

        SetExprAST(std::shared_ptr<ExprAST> a, std::string n, std::string s)
                : InnerExprAST(a), Name(n), Sub(s) {}

        Value *codegen() const;

    private:
        std::string Name;
        std::string Sub;
    };

    class SeqExprAST : public InnerExprAST {
    public:
        SeqExprAST(std::vector<std::shared_ptr<ExprAST> > a)
                : InnerExprAST(a) {}

        Value *codegen() const;

        void add(std::shared_ptr<ExprAST> node);
    };

    class FunctionDefintionAST : ExprAST {
    public:
        FunctionDefintionAST(std::string n,
                             std::vector<std::string> t,
                             std::vector<std::string> p,
                             std::string retT,
                             std::shared_ptr<ExprAST> b,
                             bool isMem = false)
                : name(n), ptypes(t), parameters(std::move(p)), retType(retT), body(b), isMember(isMem) {}

        std::string getName() const;

        Value *codegen() const;

    private:
        std::string name;
        std::string retType;
        std::shared_ptr<ExprAST> body;
        bool isMember;
    protected:
        std::vector<std::string> parameters;
        std::vector<std::string> ptypes;
    };

//    class MemberFunctionDefAST : ExprAST {
//    public:
//        MemberFunctionDefAST(std::string c, std::string n,
//                             std::vector<std::string> t, std::vector<std::string> p,
//                             std::string retT, std::shared_ptr<ExprAST> b)
//                : cls(c), name(n), ptypes(t), parameters(std::move(p)), retType(retT), body(b) {}
//
//        Value *codegen() const;
//
//    private:
//        std::string cls;
//        std::string name;
//        std::string retType;
//        std::shared_ptr<ExprAST> body;
//    protected:
//        std::vector<std::string> parameters;
//        std::vector<std::string> ptypes;
//    };

    class CallExprAST : public ExprAST {
    public:
        CallExprAST(std::string s, std::vector<std::shared_ptr<ExprAST> > v)
                : Callee(s), Args(v) {}

        Value *codegen() const;

    private:
        CallExprAST(const CallExprAST &);

        CallExprAST &operator=(const CallExprAST &);

        std::string Callee;
        std::vector<std::shared_ptr<ExprAST> > Args;
    };

    class MethodCallExprAST : public ExprAST {
    public:
        MethodCallExprAST(std::string vName, std::string mthName, std::vector<std::shared_ptr<ExprAST> > v)
                : Name(vName), Method(mthName), Args(v) {}

        Value *codegen() const;

    private:
        MethodCallExprAST(const MethodCallExprAST &);

        MethodCallExprAST &operator=(const MethodCallExprAST &);

        std::string Name;
        std::string Method;
        std::vector<std::shared_ptr<ExprAST> > Args;
    };

//    class ClassAccessExprAST : public ExprAST {
//    public:
//        ClassAccessExprAST(std::string n, std::string s)
//            : Name(n), Var(s) {}
//
//        Value *codegen() const;
//
//    private:
//        std::string Name;
//        std::string Var;
//    };

    class AddExprAST : public InnerExprAST {
    public:
        AddExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class SubExprAST : public InnerExprAST {
    public:
        SubExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class MulExprAST : public InnerExprAST {
    public:
        MulExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class DivExprAST : public InnerExprAST {
    public:
        DivExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class LtExprAST : public InnerExprAST {
    public:
        LtExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class GtExprAST : public InnerExprAST {
    public:
        GtExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class LteExprAST : public InnerExprAST {
    public:
        LteExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class GteExprAST : public InnerExprAST {
    public:
        GteExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class NeqExprAST : public InnerExprAST {
    public:
        NeqExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class EqExprAST : public InnerExprAST {
    public:
        EqExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
                : InnerExprAST(l, r) {}

        Value *codegen() const;
    };

    class WhileExprAST : public ExprAST {
    public:
        WhileExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> b)
                : cond(c), block(b) {}

        Value *codegen() const;

    private:
        std::shared_ptr<ExprAST> cond;
        std::shared_ptr<ExprAST> block;
    };

    class IfExprAST : public ExprAST {
    public:
        IfExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> b)
                : cond(c), block(b) {}

        Value *codegen() const;

    private:
        std::shared_ptr<ExprAST> cond;
        std::shared_ptr<ExprAST> block;
    };

    class IfElseExprAST : public ExprAST {
    public:
        IfElseExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> t, std::shared_ptr<ExprAST> e)
                : cond(c), thenBlock(t), elseBlock(e) {}

        Value *codegen() const;

    private:
        std::shared_ptr<ExprAST> cond;
        std::shared_ptr<ExprAST> thenBlock;
        std::shared_ptr<ExprAST> elseBlock;
    };

    class RetExprAST : public ExprAST {
    public:
        RetExprAST(std::shared_ptr<ExprAST> e)
                : v(e) {}

        RetExprAST()
                : v(nullptr) {}

        Value *codegen() const;

    private:
        std::shared_ptr<ExprAST> v;
    };

    class StringExprAST : public ExprAST {
    public:
        StringExprAST(std::string s)
                : Str(s) {}
        Value *codegen() const;
    private:
        std::string Str;
    };

    class ClassDefExprAST : public ExprAST {
    public:
        ClassDefExprAST(std::string name,
                        std::string baseName,
                        std::vector<std::string>& ts,
                        std::vector<std::string>& vs,
                        std::vector<FunctionDefintionAST *> fs)
                : Name(name), BaseName(baseName), types(ts), vars(vs), functions(fs) {};
        Value *codegen() const;
    private:
        std::string Name;
        std::string BaseName;
        std::vector<std::string> types;
        std::vector<std::string> vars;
        std::vector<FunctionDefintionAST *> functions;
    };

    AllocaInst *CreateEntryBlockAlloca(Type *t, Function *TheFunction, const std::string &VarName);
    bool isRet(Value* tmp);
    Value *makeInt(int value);
    Value *makeDouble(double value);
}

#endif
