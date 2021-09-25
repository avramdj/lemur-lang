#ifndef __AST_HPP__
#define __AST_HPP__ 1

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "llvm/IR/Instructions.h"
#include "llvm/IR/Value.h"
#include "types.h"

using namespace llvm;

namespace backend {

class ExprAST {
 public:
  virtual ~ExprAST();

  virtual Value *codegen() const = 0;
  virtual types::LemurTypes wellFormed() = 0;
};

class IntExprAST : public ExprAST {
 public:
  explicit IntExprAST(int v) : val_(v) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  int val_;
};

class FloatExprAST : public ExprAST {
 public:
  explicit FloatExprAST(float v) : val_(v) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  float val_;
};

class VariableExprAST : public ExprAST {
 public:
  explicit VariableExprAST(std::string n) : name_(std::move(n)) {}

  VariableExprAST(std::string n, std::string s)
      : name_(std::move(n)), sub_(std::move(s)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::string name_;
  std::string sub_;
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
  std::vector<std::shared_ptr<ExprAST>> nodes_;

 private:
  InnerExprAST(const InnerExprAST &i);

  InnerExprAST &operator=(const InnerExprAST &i);
};

class AndExprAST : public InnerExprAST {
 public:
  AndExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class OrExprAST : public InnerExprAST {
 public:
  OrExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class XorExprAST : public InnerExprAST {
 public:
  XorExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class ShlExprAST : public InnerExprAST {
 public:
  ShlExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class ShrExprAST : public InnerExprAST {
 public:
  ShrExprAST(std::shared_ptr<ExprAST> a, std::shared_ptr<ExprAST> b)
      : InnerExprAST(std::move(a), std::move(b)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class NotExprAST : public InnerExprAST {
 public:
  explicit NotExprAST(std::shared_ptr<ExprAST> a)
      : InnerExprAST(std::move(a)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class PrintExprAST : public InnerExprAST {
 public:
  explicit PrintExprAST(std::shared_ptr<ExprAST> a)
      : InnerExprAST(std::move(a)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class VarDeclExprAST : public ExprAST {
 public:
  VarDeclExprAST(std::string type, std::string name)
      : type_(std::move(type)), name_(std::move(name)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::string name_;
  std::string type_;
};

class DeclAssignExprAST : public InnerExprAST {
 public:
  DeclAssignExprAST(std::string t, std::string n, std::shared_ptr<ExprAST> a)
      : type_(std::move(t)), name_(std::move(n)), InnerExprAST(a) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::string type_;
  std::string name_;
};

class SetExprAST : public InnerExprAST {
 public:
  SetExprAST(std::shared_ptr<ExprAST> a, std::string n)
      : InnerExprAST(std::move(a)), name_(std::move(n)) {}

  SetExprAST(std::shared_ptr<ExprAST> a, std::string n, std::string s)
      : InnerExprAST(std::move(a)), name_(std::move(n)), sub_(std::move(s)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::string name_;
  std::string sub_;
};

class SeqExprAST : public InnerExprAST {
 public:
  explicit SeqExprAST(std::vector<std::shared_ptr<ExprAST>> a)
      : InnerExprAST(std::move(a)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

  void add(std::shared_ptr<ExprAST> node);
};

class FileAST : public SeqExprAST {
 public:
  explicit FileAST(std::vector<std::shared_ptr<ExprAST>> a)
      : SeqExprAST(std::move(a)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class FunctionDefAST : public ExprAST {
 public:
  FunctionDefAST(std::string n, std::vector<std::string> t,
                 std::vector<std::string> p, std::string ret_t,
                 std::shared_ptr<ExprAST> b, bool isMem = false)
      : name_(std::move(n)),
        param_types_(std::move(t)),
        param_names_(std::move(p)),
        ret_type_(std::move(ret_t)),
        body_(std::move(b)),
        is_member_(isMem) {}

  std::string getName() const;

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::string name_;
  std::string ret_type_;
  std::shared_ptr<ExprAST> body_;
  bool is_member_;

 protected:
  std::vector<std::string> param_names_;
  std::vector<std::string> param_types_;
};

class CallExprAST : public ExprAST {
 public:
  CallExprAST(std::string s, std::vector<std::shared_ptr<ExprAST>> v)
      : callee_(std::move(s)), args_(std::move(v)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  CallExprAST(const CallExprAST &);

  CallExprAST &operator=(const CallExprAST &);

  std::string callee_;
  std::vector<std::shared_ptr<ExprAST>> args_;
};

class MethodCallExprAST : public ExprAST {
 public:
  MethodCallExprAST(std::string name, std::string method,
                    std::vector<std::shared_ptr<ExprAST>> v)
      : name_(std::move(name)),
        method_(std::move(method)),
        args_(std::move(v)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  MethodCallExprAST(const MethodCallExprAST &);

  MethodCallExprAST &operator=(const MethodCallExprAST &);

  std::string name_;
  std::string method_;
  std::vector<std::shared_ptr<ExprAST>> args_;
};

class AddExprAST : public InnerExprAST {
 public:
  AddExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class SubExprAST : public InnerExprAST {
 public:
  SubExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class MulExprAST : public InnerExprAST {
 public:
  MulExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class DivExprAST : public InnerExprAST {
 public:
  DivExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class LtExprAST : public InnerExprAST {
 public:
  LtExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class GtExprAST : public InnerExprAST {
 public:
  GtExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class LteExprAST : public InnerExprAST {
 public:
  LteExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class GteExprAST : public InnerExprAST {
 public:
  GteExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class NeqExprAST : public InnerExprAST {
 public:
  NeqExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class EqExprAST : public InnerExprAST {
 public:
  EqExprAST(std::shared_ptr<ExprAST> l, std::shared_ptr<ExprAST> r)
      : InnerExprAST(std::move(l), std::move(r)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class WhileExprAST : public ExprAST {
 public:
  WhileExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> b)
      : cond_(std::move(c)), block_(std::move(b)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::shared_ptr<ExprAST> cond_;
  std::shared_ptr<ExprAST> block_;
};

class IfExprAST : public ExprAST {
 public:
  IfExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> b)
      : cond_(std::move(c)), block_(std::move(b)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::shared_ptr<ExprAST> cond_;
  std::shared_ptr<ExprAST> block_;
};

class IfElseExprAST : public ExprAST {
 public:
  IfElseExprAST(std::shared_ptr<ExprAST> c, std::shared_ptr<ExprAST> t,
                std::shared_ptr<ExprAST> e)
      : cond_(std::move(c)),
        then_block_(std::move(t)),
        else_block_(std::move(e)) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::shared_ptr<ExprAST> cond_;
  std::shared_ptr<ExprAST> then_block_;
  std::shared_ptr<ExprAST> else_block_;
};

class RetExprAST : public ExprAST {
 public:
  explicit RetExprAST(std::shared_ptr<ExprAST> e) : v(std::move(e)) {}

  RetExprAST() : v(nullptr) {}

  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::shared_ptr<ExprAST> v;
};

class StringExprAST : public ExprAST {
 public:
  explicit StringExprAST(std::string s) : str_(std::move(s)) {}
  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::string str_;
};

class ClassDefExprAST : public ExprAST {
 public:
  ClassDefExprAST(std::string name, std::string base_name,
                  std::vector<std::string> &ts, std::vector<std::string> &vs,
                  std::vector<FunctionDefAST *> fs)
      : name_(std::move(name)),
        base_name_(std::move(base_name)),
        types_(ts),
        vars_(vs),
        functions_(std::move(fs)){};
  Value *codegen() const override;
  types::LemurTypes wellFormed() override;

 private:
  std::string name_;
  std::string base_name_;
  std::vector<std::string> types_;
  std::vector<std::string> vars_;
  std::vector<FunctionDefAST *> functions_;
};

class CastExprAST : public InnerExprAST {
 public:
  explicit CastExprAST(const std::shared_ptr<ExprAST> &a);
};

class BoolCastExprAST : public CastExprAST {
 public:
  explicit BoolCastExprAST(const std::shared_ptr<ExprAST> &a);
  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

class FloatCastExprAST : public CastExprAST {
 public:
  explicit FloatCastExprAST(const std::shared_ptr<ExprAST> &a);
  Value *codegen() const override;
  types::LemurTypes wellFormed() override;
};

AllocaInst *CreateEntryBlockAlloca(Type *t, Function *the_function,
                                   const std::string &var_name);
bool isRet(Value *tmp);

}  // namespace backend

#endif
