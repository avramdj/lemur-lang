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

class ExprAST {
public:
  virtual ~ExprAST();
  virtual Value* codegen() const = 0;
};

class NumberExprAST : public ExprAST {
public:
  NumberExprAST(int v)
    :Val(v)
  {}
  Value* codegen() const;
private:
  int Val;
};

class VariableExprAST : public ExprAST {
public:
  VariableExprAST(string s)
    :Name(s)
  {}
  Value* codegen() const;
private:
  string Name;
};

class InnerExprAST : public ExprAST {
public:
  InnerExprAST(ExprAST* a);
  InnerExprAST(ExprAST* a, ExprAST* b);
  InnerExprAST(ExprAST* a, ExprAST* b, ExprAST* c);
  InnerExprAST(ExprAST* a, ExprAST* b, ExprAST* c, ExprAST* d);
  InnerExprAST(vector<ExprAST*> a);
  ~InnerExprAST();
protected:
  vector<ExprAST*> _nodes;
private:
  InnerExprAST(const InnerExprAST& i);
  InnerExprAST& operator=(const InnerExprAST& i);
};

class AndExprAST : public InnerExprAST {
public:
  AndExprAST(ExprAST* a, ExprAST* b)
    :InnerExprAST(a, b)
  {}
  Value* codegen() const;
};

class OrExprAST : public InnerExprAST {
public:
  OrExprAST(ExprAST* a, ExprAST* b)
    :InnerExprAST(a, b)
  {}
  Value* codegen() const;
};

class XorExprAST : public InnerExprAST {
public:
  XorExprAST(ExprAST* a, ExprAST* b)
    :InnerExprAST(a, b)
  {}
  Value* codegen() const;
};

class ShlExprAST : public InnerExprAST {
public:
  ShlExprAST(ExprAST* a, ExprAST* b)
    :InnerExprAST(a, b)
  {}
  Value* codegen() const;
};

class ShrExprAST : public InnerExprAST {
public:
  ShrExprAST(ExprAST* a, ExprAST* b)
    :InnerExprAST(a, b)
  {}
  Value* codegen() const;
};

class NotExprAST : public InnerExprAST {
public:
  NotExprAST(ExprAST* a)
    :InnerExprAST(a)
  {}
  Value* codegen() const;
};

class PrintExprAST : public InnerExprAST {
public:
  PrintExprAST(ExprAST* a)
    :InnerExprAST(a)
  {}
  Value* codegen() const;
};

class SetExprAST : public InnerExprAST {
public:
  SetExprAST(ExprAST* a, string n)
    :InnerExprAST(a), Name(n)
  {}
  Value* codegen() const;
private:
  string Name;
};

class SeqExprAST : public InnerExprAST {
public:
  SeqExprAST(vector<ExprAST*> a)
    :InnerExprAST(a)
  {}
  Value* codegen() const;
  void add(ExprAST *node);
};

class FunctionDefintionAST : ExprAST {
public:
  FunctionDefintionAST(string n, vector<string> p, SeqExprAST* b)
    : name(n), parameters(p), body(b) 
  {}
  string getName() const;
  Value* codegen() const;
private:
  string name;
  vector<string> parameters;
  SeqExprAST* body;
};

class CallExprAST : public ExprAST {
public:
  CallExprAST(string s, vector<ExprAST*> v)
    :Callee(s), Args(v)
  {}
  Value* codegen() const;
  ~CallExprAST();
private:
  CallExprAST(const CallExprAST&);
  CallExprAST& operator=(const CallExprAST&);
  string Callee;
  vector<ExprAST*> Args;
};

class AddExprAST : public InnerExprAST {
public:
  AddExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class SubExprAST : public InnerExprAST {
public:
  SubExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class LtExprAST : public InnerExprAST {
public:
  LtExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class GtExprAST : public InnerExprAST {
public:
  GtExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class LteExprAST : public InnerExprAST {
public:
  LteExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class GteExprAST : public InnerExprAST {
public:
  GteExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class NeqExprAST : public InnerExprAST {
public:
  NeqExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class EqExprAST : public InnerExprAST {
public:
  EqExprAST(ExprAST *l, ExprAST *r)
    :InnerExprAST(l, r)
  {}
  Value* codegen() const;
};

class WhileExprAST : public ExprAST {
public:
  WhileExprAST(ExprAST *c, SeqExprAST *b)
    :cond(c), block(b)
  {}
  Value* codegen() const;
private:
  ExprAST *cond;
  SeqExprAST *block;
};

class IfExprAST : public ExprAST {
public:
  IfExprAST(ExprAST *c, SeqExprAST *b)
    :cond(c), block(b)
  {}
  Value* codegen() const;
private:
  ExprAST *cond;
  SeqExprAST *block;
};

class IfElseExprAST : public ExprAST {
public:
  IfElseExprAST(ExprAST *c, SeqExprAST *t, SeqExprAST *e)
    :cond(c), thenBlock(t), elseBlock(e)
  {}
  Value* codegen() const;
private:
  ExprAST *cond;
  SeqExprAST *thenBlock;
  SeqExprAST *elseBlock;
};

class RetExprAST : public ExprAST {
public:
  RetExprAST(ExprAST *e)
    :v(e)
  {}
  Value* codegen() const;
private:
  ExprAST *v;
};

void InitializeModuleAndPassManager(void);
AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const string &VarName);

#endif
