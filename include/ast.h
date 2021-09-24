#ifndef __AST_HPP__
#define __AST_HPP__ 1

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "llvm/IR/Instructions.h"
#include "llvm/IR/Value.h"

using namespace llvm;

namespace backend {

class ExprAST {
 public:
  virtual ~ExprAST();

  virtual Value *codegen() const = 0;
};

class IntExprAST : public ExprAST {
 public:
  explicit IntExprAST(int v) : Val(v) {}

  Value *codegen() const override;

 private:
  int Val;
};

class FloatExprAST : public ExprAST {
 public:
  explicit FloatExprAST(float v) : Val(v) {}

  Value *codegen() const override;

 private:
  float Val;
};

class VariableExprAST : public ExprAST {
 public:
  explicit VariableExprAST(std::string n) : Name(std::move(n)) {}

  VariableExprAST(std::string n, std::string s)
      : Name(std::move(n)), Sub(std::move(s)) {}

  Value *codegen() const override;

 private:
  std::string Name;
  std::string Sub;
};

class InnerExprAST : public ExprAST {
 public:
  explicit InnerExprAST(std::shared_ptr<ExprAST> a);

  InnerExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b);

  InnerExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b,
               std::shared_ptr<ExprAST> c);

  InnerExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b,
               std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> d);

  explicit InnerExprAST(std::vector<std::shared_ptr<ExprAST>> a);

  ~InnerExprAST() override;

 protected:
  std::vector<std::shared_ptr<ExprAST>> _nodes;

 private:
  InnerExprAST(const InnerExprAST &i);

  InnerExprAST &operator=(const InnerExprAST &i);
};

class AndExprAST : public InnerExprAST {
 public:
  AndExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
};

class OrExprAST : public InnerExprAST {
 public:
  OrExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
};

class XorExprAST : public InnerExprAST {
 public:
  XorExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
};

class ShlExprAST : public InnerExprAST {
 public:
  ShlExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
};

class ShrExprAST : public InnerExprAST {
 public:
  ShrExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
};

class NotExprAST : public InnerExprAST {
 public:
  explicit NotExprAST(std::shared_ptr<ExprAST> a)
      : InnerExprAST(std::move(a)) {}

  Value *codegen() const override;
};

class PrintExprAST : public InnerExprAST {
 public:
  explicit PrintExprAST(std::shared_ptr<ExprAST> a)
      : InnerExprAST(std::move(a)) {}

  Value *codegen() const override;
};

class VarDeclExprAST : public ExprAST {
 public:
  VarDeclExprAST(std::string type, std::string name)
      : Type(std::move(type)), Name(std::move(name)) {}

  Value *codegen() const override;

 private:
  std::string Name;
  std::string Type;
};

class DeclAssignExprAST : public InnerExprAST {
 public:
  DeclAssignExprAST(std::string t, std::string n, std::shared_ptr<ExprAST> a)
      : Type(std::move(t)), Name(std::move(n)), InnerExprAST(a) {}

  Value *codegen() const override;

 private:
  std::string Type;
  std::string Name;
};

class SetExprAST : public InnerExprAST {
 public:
  SetExprAST(std::shared_ptr<ExprAST> a, std::string n)
      : InnerExprAST(std::move(a)), Name(std::move(n)) {}

  SetExprAST(std::shared_ptr<ExprAST> a, std::string n, std::string s)
      : InnerExprAST(std::move(a)), Name(std::move(n)), Sub(std::move(s)) {}

  Value *codegen() const override;

 private:
  std::string Name;
  std::string Sub;
};

class SeqExprAST : public InnerExprAST {
 public:
  explicit SeqExprAST(std::vector<std::shared_ptr<ExprAST>> a)
      : InnerExprAST(std::move(a)) {}

  Value *codegen() const override;

  void add(std::shared_ptr<ExprAST> node);
};

class FunctionDefAST : ExprAST {
 public:
  FunctionDefAST(std::string n, std::vector<std::string> t,
                 std::vector<std::string> p, std::string retT,
                 std::shared_ptr<ExprAST> b, bool isMem = false)
      : name(std::move(n)),
        paramTypes(std::move(t)),
        parameters(std::move(p)),
        retType(std::move(retT)),
        body(std::move(b)),
        isMember(isMem) {}

  std::string getName() const;

  Value *codegen() const override;

 private:
  std::string name;
  std::string retType;
  std::shared_ptr<ExprAST> body;
  bool isMember;

 protected:
  std::vector<std::string> parameters;
  std::vector<std::string> paramTypes;
};

class CallExprAST : public ExprAST {
 public:
  CallExprAST(std::string s, std::vector<std::shared_ptr<ExprAST>> v)
      : Callee(std::move(s)), Args(std::move(v)) {}

  Value *codegen() const override;

 private:
  CallExprAST(const CallExprAST &);

  CallExprAST &operator=(const CallExprAST &);

  std::string Callee;
  std::vector<std::shared_ptr<ExprAST>> Args;
};

class MethodCallExprAST : public ExprAST {
 public:
  MethodCallExprAST(std::string vName, std::string mthName,
                    std::vector<std::shared_ptr<ExprAST>> v)
      : Name(std::move(vName)),
        Method(std::move(mthName)),
        Args(std::move(v)) {}

  Value *codegen() const override;

 private:
  MethodCallExprAST(const MethodCallExprAST &);

  MethodCallExprAST &operator=(const MethodCallExprAST &);

  std::string Name;
  std::string Method;
  std::vector<std::shared_ptr<ExprAST>> Args;
};

class AddExprAST : public InnerExprAST {
 public:
  AddExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class SubExprAST : public InnerExprAST {
 public:
  SubExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class MulExprAST : public InnerExprAST {
 public:
  MulExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class DivExprAST : public InnerExprAST {
 public:
  DivExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class LtExprAST : public InnerExprAST {
 public:
  LtExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class GtExprAST : public InnerExprAST {
 public:
  GtExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class LteExprAST : public InnerExprAST {
 public:
  LteExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class GteExprAST : public InnerExprAST {
 public:
  GteExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class NeqExprAST : public InnerExprAST {
 public:
  NeqExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class EqExprAST : public InnerExprAST {
 public:
  EqExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
};

class WhileExprAST : public ExprAST {
 public:
  WhileExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> b)
      : cond(std::move(c)), block(std::move(b)) {}

  Value *codegen() const override;

 private:
  std::shared_ptr<ExprAST> cond;
  std::shared_ptr<ExprAST> block;
};

class IfExprAST : public ExprAST {
 public:
  IfExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> b)
      : cond(std::move(c)), block(std::move(b)) {}

  Value *codegen() const override;

 private:
  std::shared_ptr<ExprAST> cond;
  std::shared_ptr<ExprAST> block;
};

class IfElseExprAST : public ExprAST {
 public:
  IfElseExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> t,
                std::shared_ptr<ExprAST> e)
      : cond(std::move(c)), thenBlock(std::move(t)), elseBlock(std::move(e)) {}

  Value *codegen() const override;

 private:
  std::shared_ptr<ExprAST> cond;
  std::shared_ptr<ExprAST> thenBlock;
  std::shared_ptr<ExprAST> elseBlock;
};

class RetExprAST : public ExprAST {
 public:
  explicit RetExprAST(std::shared_ptr<ExprAST> e) : v(std::move(e)) {}

  RetExprAST() : v(nullptr) {}

  Value *codegen() const override;

 private:
  std::shared_ptr<ExprAST> v;
};

class StringExprAST : public ExprAST {
 public:
  explicit StringExprAST(std::string s) : Str(std::move(s)) {}
  Value *codegen() const override;

 private:
  std::string Str;
};

class ClassDefExprAST : public ExprAST {
 public:
  ClassDefExprAST(std::string name, std::string baseName,
                  std::vector<std::string> &ts, std::vector<std::string> &vs,
                  std::vector<FunctionDefAST *> fs)
      : Name(std::move(name)),
        BaseName(std::move(baseName)),
        types(ts),
        vars(vs),
        functions(std::move(fs)){};
  Value *codegen() const override;

 private:
  std::string Name;
  std::string BaseName;
  std::vector<std::string> types;
  std::vector<std::string> vars;
  std::vector<FunctionDefAST *> functions;
};

AllocaInst *CreateEntryBlockAlloca(Type *t, Function *TheFunction,
                                   const std::string &VarName);
bool isRet(Value *tmp);

}  // namespace backend

#endif
