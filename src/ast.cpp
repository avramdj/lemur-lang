#include "ast.h"

#include <iostream>

#include "ast_util.h"
#include "context.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/Scalar.h"
#include "logger.h"
#include "types.h"

#define _LIBCPP_DEBUG 1

using std::cerr;
using std::cout;
using std::endl;
using std::operator""s;
using std::shared_ptr;
using std::string;
using std::vector;

namespace backend {

ExprAST::~ExprAST() = default;

InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a) {
  nodes_.resize(0);
  nodes_.push_back(a);
}

InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b) {
  nodes_.resize(0);
  nodes_.push_back(a);
  nodes_.push_back(b);
}

InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b,
                           shared_ptr<ExprAST> c) {
  nodes_.resize(0);
  nodes_.push_back(a);
  nodes_.push_back(b);
  nodes_.push_back(c);
}

InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b,
                           shared_ptr<ExprAST> c, shared_ptr<ExprAST> d) {
  nodes_.resize(0);
  nodes_.push_back(a);
  nodes_.push_back(b);
  nodes_.push_back(c);
  nodes_.push_back(d);
}

InnerExprAST::InnerExprAST(vector<shared_ptr<ExprAST>> a) { nodes_ = a; }

InnerExprAST::~InnerExprAST() = default;

Value *IntExprAST::codegen() const {
  return types::getTypeConstant(
      "int", val_);  // NOLINT(cppcoreguidelines-narrowing-conversions)
}
types::LemurTypes IntExprAST::wellFormed() { return types::kInt; }

Value *FloatExprAST::codegen() const {
  return types::getTypeConstant("float", val_);
}
types::LemurTypes FloatExprAST::wellFormed() { return types::kFloat; }

Value *VariableExprAST::codegen() const {
  Value *v = getPtrToValue(name_, sub_);
  Type *t = v->getType()->getPointerElementType();
  return Builder.CreateLoad(t, v, name_);
}
types::LemurTypes VariableExprAST::wellFormed() {
  types::LemurTypes type = named_analysis_values[name_];
  if (type == types::kError) {
    log::warn("Reference to undefined variable "s + name_);
  }
  return type;
}

Value *AndExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Value *lC = types::boolCast(l);
  if (!lC) {
    std::cerr << "Can't bool cast" << std::endl;
    return nullptr;
  }
  Value *dC = types::boolCast(l);
  if (!dC) {
    std::cerr << "Can't bool cast" << std::endl;
    return nullptr;
  }
  return Builder.CreateAnd(lC, dC, "andtmp");
}
types::LemurTypes AndExprAST::wellFormed() {
  auto left = nodes_[0]->wellFormed();
  auto right = nodes_[1]->wellFormed();
  if (left == types::kError || right == types::kError) {
    return types::kError;
  }
  if (left != types::kBool) {
    nodes_[0] = std::shared_ptr<ExprAST>(new BoolCastExprAST(nodes_[0]));
  }
  if (right != types::kBool) {
    nodes_[1] = std::shared_ptr<ExprAST>(new BoolCastExprAST(nodes_[1]));
  }
  return types::kBool;
}

Value *OrExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Value *lC = types::boolCast(l);
  if (!lC) {
    std::cerr << "Cant bool cast" << std::endl;
    return nullptr;
  }
  Value *dC = types::boolCast(l);
  if (!dC) {
    std::cerr << "Cant bool cast" << std::endl;
    return nullptr;
  }
  return Builder.CreateOr(lC, dC, "ortmp");
}
types::LemurTypes OrExprAST::wellFormed() {
  auto left = nodes_[0]->wellFormed();
  auto right = nodes_[1]->wellFormed();
  if (left == types::kError || right == types::kError) {
    return types::kError;
  }
  if (left != types::kBool) {
    nodes_[0] = std::shared_ptr<ExprAST>(new BoolCastExprAST(nodes_[0]));
  }
  if (right != types::kBool) {
    nodes_[1] = std::shared_ptr<ExprAST>(new BoolCastExprAST(nodes_[1]));
  }
  return types::kBool;
}

Value *XorExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Value *lC = types::boolCast(l);
  if (!lC) {
    std::cerr << "Cant bool cast" << std::endl;
    return nullptr;
  }
  Value *dC = types::boolCast(l);
  if (!dC) {
    std::cerr << "Cant bool cast" << std::endl;
    return nullptr;
  }
  return Builder.CreateXor(lC, dC, "xortmp");
}
types::LemurTypes XorExprAST::wellFormed() {
  auto left = nodes_[0]->wellFormed();
  auto right = nodes_[1]->wellFormed();
  if (left == types::kError || right == types::kError) {
    return types::kError;
  }
  if (left != types::kBool) {
    nodes_[0] = std::shared_ptr<ExprAST>(new BoolCastExprAST(nodes_[0]));
  }
  if (right != types::kBool) {
    nodes_[1] = std::shared_ptr<ExprAST>(new BoolCastExprAST(nodes_[1]));
  }
  return types::kBool;
}

Value *ShlExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  Value *lC = l;
  Value *dC = d;
  return Builder.CreateShl(lC, dC, "shltmp");
}
types::LemurTypes ShlExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *ShrExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  Value *lC = l;
  Value *dC = d;
  return Builder.CreateLShr(lC, dC, "shrtmp");
}
types::LemurTypes ShrExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *NotExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  if (l == nullptr) return nullptr;
  Value *lC = types::boolCast(l);
  if (!lC) {
    std::cerr << "Cant bool cast" << std::endl;
    return nullptr;
  }
  return Builder.CreateNot(lC, "nottmp");
}
types::LemurTypes NotExprAST::wellFormed() {
  auto node = nodes_[0]->wellFormed();
  if (node == types::kError) {
    return types::kError;
  }
  if (node != types::kBool) {
    nodes_[0] = std::shared_ptr<ExprAST>(new BoolCastExprAST(nodes_[0]));
  }
  return types::kBool;
}

Value *PrintExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  if (l == nullptr) return nullptr;
  vector<Value *> args_v;
  Type *t = l->getType();
  Value *ftm;
  if (!str_format) {
    InitializeStrings();
  }
  if (t == types::getType("int")) {
    ftm = str_int_format;
  } else if (t == types::getType("float")) {
    ftm = str_float_format;
  } else if (t == types::getType("string")) {
    ftm = str_format;
  } else if (t == types::getType("bool")) {
    ftm = str_int_format;
  } else {
    std::cerr << "Unknown type cast to string" << std::endl;
    return nullptr;
  }
  args_v.push_back(ftm);
  args_v.push_back(l);
  Builder.CreateCall(libc::print, args_v, "printCall");
  return l;
}
types::LemurTypes PrintExprAST::wellFormed() {
  if(nodes_[0]->wellFormed() == types::kError) {
    return types::kError;
  }
  return types::LemurTypes::kNone;
}

Value *DeclAssignExprAST::codegen() const {
  VarDeclExprAST decl(type_, name_);
  decl.codegen();
  SetExprAST set(nodes_[0], name_);
  return set.codegen();
}
types::LemurTypes DeclAssignExprAST::wellFormed() {
  return types::LemurTypes::kNone;
}

Value *VarDeclExprAST::codegen() const {
  Function *F = Builder.GetInsertBlock()->getParent();
  llvm::Type *t = types::getType(type_);
  if (!t) {
    std::cerr << "Unknown type " << type_ << std::endl;
    return nullptr;
  }
  AllocaInst *Alloca = CreateEntryBlockAlloca(t, F, name_);
  if (types::isClassType(t)) {
    Value *structSizeVal = types::getStructSize(t);
    Value *StructAllocaRaw = Builder.CreateCall(libc::malloc, structSizeVal);
    Value *StructAlloca = Builder.CreateBitCast(StructAllocaRaw, t);
    Builder.CreateStore(StructAlloca, Alloca);
  }
  named_values.set(name_, Alloca);
  return Alloca;
}
types::LemurTypes VarDeclExprAST::wellFormed() {
  if (named_analysis_values.isInCurrentScope(name_)) {
    log::err("Variable "s + name_ + " already defined"s);
    return types::kError;
  }
  auto type = types::getLemurType(type_);
  named_analysis_values.set(name_, type);
  return types::kError;
}

Value *SetExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  if (l == nullptr) return nullptr;
  Value *el = getPtrToValue(name_, sub_);
  if (l->getType() != el->getType()->getPointerElementType()) {
    std::cerr << "Type mismatch with "
              << name_ + (sub_.empty() ? ""s : "."s + sub_) << std::endl;
    return nullptr;
  }
  return Builder.CreateStore(l, el);
}
types::LemurTypes SetExprAST::wellFormed() {

}

Value *SeqExprAST::codegen() const {
  named_values.pushScope();
  Value *tmp = nullptr;
  for (const auto &node : nodes_) {
    tmp = node->codegen();
    if (isRet(tmp)) {
      return tmp;
    }
    if (!tmp) return nullptr;
  }
  named_values.popScope();
  return tmp;
}
void SeqExprAST::add(shared_ptr<ExprAST> node) { nodes_.push_back(node); }
types::LemurTypes SeqExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *FileAST::codegen() const {
  named_values.pushScope();
  Value *tmp = nullptr;
  for (const auto &node : nodes_) {
    tmp = node->codegen();
  }
  named_values.popScope();
  return tmp;
}
types::LemurTypes FileAST::wellFormed() { return SeqExprAST::wellFormed(); }

Value *FunctionDefAST::codegen() const {
  vector<Type *> tmp;

  for (auto &typeName : param_types_) {
    Type *t = types::getType(typeName);
    if (!t) {
      return nullptr;
    }
    tmp.push_back(t);
  }
  Type *retT = types::getType(this->ret_type_);
  if (!retT) {
    return nullptr;
  }
  FunctionType *FT = FunctionType::get(retT, tmp, false);

  Function *f =
      Function::Create(FT, Function::ExternalLinkage, name_, TheModule);

  if (!f) {
    return nullptr;
  }

  unsigned i = 0;
  for (auto &a : f->args()) {
    a.setName(param_names_[i++]);
  }

  if (!f->empty()) {
    cerr << "Function " << name_ << " can't be redefined" << endl;
    return nullptr;
  }
  BasicBlock *BB = BasicBlock::Create(TheContext, "entry", f);
  Builder.SetInsertPoint(BB);

  named_values.pushScope();
  for (auto &a : f->args()) {
    AllocaInst *Alloca =
        CreateEntryBlockAlloca(a.getType(), f, std::string(a.getName()));
    named_values.set(std::string(a.getName()), Alloca);
    Builder.CreateStore(&a, Alloca);
  }
  if (is_member_) {
    named_values.pushScope();
    Value *thisPtr = f->getArg(0);
    std::string clsName = types::type_names[thisPtr->getType()];
    for (const auto &it : types::class_var_table[clsName]) {
      const auto &memberName = it.first;
      Value *memberAddr = getPtrToMember("this", memberName);
      named_values.set(memberName, memberAddr);
    }
    named_values.swapLastTwo();
  }
  Value *Body = body_->codegen();
  named_values.popScope();
  if (is_member_) {
    named_values.popScope();
  }

  if (Body != nullptr) {
    if (!isRet(Body)) {
      auto retV = types::getTypeConstant(ret_type_, 0);
      if (!retV) {
        std::cerr << "Function " << name_ << " can't create implicit return"
                  << std::endl;
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

std::string FunctionDefAST::getName() const { return name_; }
types::LemurTypes FunctionDefAST::wellFormed() {
  return types::LemurTypes::kError;
}

Value *CallExprAST::codegen() const {
  Function *f = TheModule->getFunction(callee_);
  if (!f) {
    cerr << "Call of undefined function " << callee_ << endl;
    return nullptr;
  }

  if (args_.size() != f->arg_size()) {
    cerr << "Function " << callee_ << " called with " << args_.size()
         << " arguments but takes " << f->arg_size() << endl;
    return nullptr;
  }

  vector<Value *> ArgsV;
  for (const auto &Arg : args_) {
    Value *tmp = Arg->codegen();
    if (!tmp) return nullptr;
    ArgsV.push_back(tmp);
  }

  return Builder.CreateCall(f, ArgsV, "calltmp");
}
types::LemurTypes CallExprAST::wellFormed() {
  return types::LemurTypes::kError;
}

Value *MethodCallExprAST::codegen() const {
  Value *tmp = named_values[name_];
  if (!tmp) {
    cerr << "Variable " + name_ + " is undefined" << endl;
    return nullptr;
  }
  Type *t = tmp->getType()->getPointerElementType();

  auto cit = types::type_names.find(t);
  if (cit == types::type_names.end()) {
    std::cerr << "Variable " << name_ << " is not of class type" << std::endl;
    return nullptr;
  }
  std::string clsName = cit->second;
  std::string encodedMethod = encodeFunctionName(method_, clsName);
  Function *f = TheModule->getFunction(encodedMethod);
  if (!f) {
    cerr << "Call of undefined method " << method_ << endl;
    return nullptr;
  }
  Value *loadTmp = Builder.CreateLoad(t, tmp);
  vector<Value *> ArgsV;
  ArgsV.push_back(loadTmp);
  for (const auto &Arg : args_) {
    Value *tmpParam = Arg->codegen();
    if (!tmpParam) return nullptr;
    ArgsV.push_back(tmpParam);
  }

  if (ArgsV.size() != f->arg_size()) {
    cerr << "Method " << method_ << " called with " << ArgsV.size() - 1
         << " arguments but takes " << f->arg_size() - 1 << endl;
    return nullptr;
  }

  return Builder.CreateCall(f, ArgsV, "methodcalltmp");
}
types::LemurTypes MethodCallExprAST::wellFormed() {
  return types::LemurTypes::kError;
}

Value *AddExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFAdd(l, d, "addtmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateAdd(l, d, "addtmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFAdd(lC, dC, "addtmp");
}
types::LemurTypes AddExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *SubExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFSub(l, d, "subtmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateSub(l, d, "subtmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFSub(lC, dC, "subtmp");
}
types::LemurTypes SubExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *MulExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFMul(l, d, "multmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateMul(l, d, "multmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFMul(lC, dC, "multmp");
}
types::LemurTypes MulExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *DivExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFDiv(l, d, "divtmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateSDiv(l, d, "divtmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFDiv(lC, dC, "divtmp");
}
types::LemurTypes DivExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *LtExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (!l || !d) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFCmpOLT(l, d, "lttmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateICmpSLT(l, d, "lttmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFCmpOLT(lC, dC, "lttmp");
}
types::LemurTypes LtExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *GtExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (!l || !d) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFCmpOGT(l, d, "lttmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateICmpSGT(l, d, "lttmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFCmpOGT(lC, dC, "lttmp");
}
types::LemurTypes GtExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *EqExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (!l || !d) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFCmpOEQ(l, d, "eqtmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateICmpEQ(l, d, "eqtmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFCmpOEQ(lC, dC, "eqtmp");
}
types::LemurTypes EqExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *NeqExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (!l || !d) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFCmpONE(l, d, "netmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateICmpNE(l, d, "netmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFCmpONE(lC, dC, "netmp");
}
types::LemurTypes NeqExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *LteExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (!l || !d) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFCmpOLE(l, d, "letmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateICmpSLE(l, d, "letmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFCmpOLE(lC, dC, "letmp");
}
types::LemurTypes LteExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *GteExprAST::codegen() const {
  Value *l = nodes_[0]->codegen();
  Value *d = nodes_[1]->codegen();
  if (!l || !d) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  if (lT == dT && lT == types::getType("float")) {
    return Builder.CreateFCmpOGE(l, d, "getmp");
  }
  if (lT == dT && lT == types::getType("int")) {
    return Builder.CreateICmpSGE(l, d, "getmp");
  }
  Value *lC = types::floatCast(l);
  Value *dC = types::floatCast(d);
  return Builder.CreateFCmpOGE(lC, dC, "getmp");
}
types::LemurTypes GteExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *WhileExprAST::codegen() const {
  Function *f = Builder.GetInsertBlock()->getParent();
  BasicBlock *HeaderBB = BasicBlock::Create(TheContext, "header", f);
  BasicBlock *LoopBB = BasicBlock::Create(TheContext, "loop", f);
  BasicBlock *AfterLoopBB = BasicBlock::Create(TheContext, "afterloop", f);

  // header :
  Builder.CreateBr(HeaderBB);
  Builder.SetInsertPoint(HeaderBB);
  Value *Cond = cond_->codegen();
  if (!Cond) {
    return nullptr;
  }
  Value *Cmp = Builder.CreateICmpNE(types::boolCast(Cond),
                                    ConstantInt::get(TheContext, APInt(1, 0)),
                                    "loopcond");
  Builder.CreateCondBr(Cmp, LoopBB, AfterLoopBB);
  HeaderBB = Builder.GetInsertBlock();

  // loop :
  Builder.SetInsertPoint(LoopBB);
  Value *BlockV = block_->codegen();
  if (!BlockV) return nullptr;

  if (!isRet(BlockV)) {
    Builder.CreateBr(HeaderBB);
  }

  Builder.SetInsertPoint(AfterLoopBB);

  return ConstantInt::get(TheContext, APInt(1, 0));
}
types::LemurTypes WhileExprAST::wellFormed() {
  return types::LemurTypes::kError;
}

Value *IfExprAST::codegen() const {
  Function *f = Builder.GetInsertBlock()->getParent();
  BasicBlock *headerBB = BasicBlock::Create(TheContext, "header", f);
  BasicBlock *thenBB = BasicBlock::Create(TheContext, "then", f);
  BasicBlock *mergeBB = BasicBlock::Create(TheContext, "merge", f);

  Builder.CreateBr(headerBB);
  Builder.SetInsertPoint(headerBB);

  Value *Cond = cond_->codegen();
  if (!Cond) {
    return nullptr;
  }
  Value *Cmp =
      Builder.CreateICmpNE(types::boolCast(Cond),
                           ConstantInt::get(TheContext, APInt(1, 0)), "cmptmp");
  Builder.CreateCondBr(Cmp, thenBB, mergeBB);

  Builder.SetInsertPoint(thenBB);
  Value *ThenV = block_->codegen();
  if (!ThenV) {
    return nullptr;
  }

  if (!isRet(ThenV)) {
    Builder.CreateBr(mergeBB);
  }

  Builder.SetInsertPoint(mergeBB);
  return ConstantInt::get(TheContext, APInt(1, 0));
}
types::LemurTypes IfExprAST::wellFormed() { return types::LemurTypes::kError; }

Value *IfElseExprAST::codegen() const {
  Function *f = Builder.GetInsertBlock()->getParent();
  BasicBlock *headerBB = BasicBlock::Create(TheContext, "header", f);
  BasicBlock *thenBB = BasicBlock::Create(TheContext, "then", f);
  BasicBlock *elseBB = BasicBlock::Create(TheContext, "else", f);
  BasicBlock *mergeBB = BasicBlock::Create(TheContext, "merge");

  Builder.CreateBr(headerBB);
  Builder.SetInsertPoint(headerBB);

  Value *Cond = cond_->codegen();
  if (!Cond) {
    return nullptr;
  }
  Value *Cmp =
      Builder.CreateICmpNE(types::boolCast(Cond),
                           ConstantInt::get(TheContext, APInt(1, 0)), "cmptmp");
  Builder.CreateCondBr(Cmp, thenBB, elseBB);

  Builder.SetInsertPoint(thenBB);
  Value *ThenV = then_block_->codegen();
  if (!ThenV) {
    return nullptr;
  }
  bool thenRet = isRet(ThenV);
  if (!thenRet) {
    Builder.CreateBr(mergeBB);
  }
  Builder.SetInsertPoint(elseBB);
  Value *ElseV = else_block_->codegen();
  if (!ElseV) {
    return nullptr;
  }
  bool elseRet = isRet(ElseV);
  if (!elseRet) {
    Builder.CreateBr(mergeBB);
  }

  if (thenRet && elseRet) {
    return ThenV;  // returns ReturnInst*, code after is unreachable
  }

  f->getBasicBlockList().push_back(mergeBB);
  Builder.SetInsertPoint(mergeBB);

  return ConstantInt::get(TheContext, APInt(32, 0));
}
types::LemurTypes IfElseExprAST::wellFormed() {
  return types::LemurTypes::kError;
}

Value *RetExprAST::codegen() const {
  Function *f = Builder.GetInsertBlock()->getParent();
  if (v == nullptr) {
    if (f->getReturnType() != types::getType("void")) {
      std::cerr << "Void return in non void function " << f->getName().str()
                << std::endl;
      return nullptr;
    }
    return Builder.CreateRet(types::getTypeConstant("void", 0));
  }
  Value *ret = v->codegen();
  if (!ret) {
    return nullptr;
  }
  return Builder.CreateRet(ret);
}
types::LemurTypes RetExprAST::wellFormed() { return types::LemurTypes::kError; }

AllocaInst *CreateEntryBlockAlloca(Type *t, Function *the_function,
                                   const std::string &var_name) {
  IRBuilder<> TmpB(&the_function->getEntryBlock(),
                   the_function->getEntryBlock().begin());
  return TmpB.CreateAlloca(t, nullptr, var_name);
}

bool isRet(Value *tmp) { return llvm::dyn_cast<ReturnInst>(tmp); }

Value *StringExprAST::codegen() const {
  auto charType = llvm::IntegerType::get(TheContext, 8);

  std::vector<llvm::Constant *> chars(str_.length());
  for (unsigned int i = 0; i < str_.size(); i++) {
    chars[i] = llvm::ConstantInt::get(charType, str_[i]);
  }
  chars.push_back(llvm::ConstantInt::get(charType, 0));

  auto stringType = llvm::ArrayType::get(charType, chars.size());
  auto globalDeclaration =
      (llvm::GlobalVariable *)TheModule->getOrInsertGlobal(".str", stringType);
  globalDeclaration->setInitializer(
      llvm::ConstantArray::get(stringType, chars));
  globalDeclaration->setConstant(true);
  globalDeclaration->setLinkage(
      llvm::GlobalValue::LinkageTypes::PrivateLinkage);
  globalDeclaration->setUnnamedAddr(llvm::GlobalValue::UnnamedAddr::Global);

  return llvm::ConstantExpr::getBitCast(globalDeclaration,
                                        charType->getPointerTo());
}
types::LemurTypes StringExprAST::wellFormed() {
  return types::LemurTypes::kError;
}

Value *ClassDefExprAST::codegen() const {
  if (types::type_table.find(name_) != types::type_table.end()) {
    std::cerr << "Class " << name_ << " already exists" << std::endl;
  }
  vector<Type *> subtypes;
  for (int i = 0; i < types_.size(); i++) {
    Type *t = types::getType(types_[i]);
    if (!t) {
      return nullptr;
    }
    if (types::class_var_table[name_].find(vars_[i]) !=
        types::class_var_table[name_].end()) {
      std::cerr << "Class variable " << vars_[i] << " already defined"
                << std::endl;
      return nullptr;
    }
    subtypes.push_back(t);
    types::class_var_table[name_][vars_[i]] = i;
    types::class_var_types[name_][vars_[i]] = t;
  }
  StructType *classType = StructType::create(TheContext, subtypes, name_);
  types::type_table[name_] = classType->getPointerTo();
  types::type_names[types::type_table[name_]] = name_;
  for (auto &f : functions_) {
    f->codegen();
  }
  return nullptr;
}
types::LemurTypes ClassDefExprAST::wellFormed() {
  return types::LemurTypes::kError;
}
CastExprAST::CastExprAST(const shared_ptr<ExprAST> &a) : InnerExprAST(a) {}

BoolCastExprAST::BoolCastExprAST(const shared_ptr<ExprAST> &a)
    : CastExprAST(a) {}

Value *BoolCastExprAST::codegen() const {
  Value *expr = nodes_[0]->codegen();
  return types::boolCast(expr);
}
types::LemurTypes BoolCastExprAST::wellFormed() { return types::kBool; }

Value *FloatCastExprAST::codegen() const {
  Value *expr = nodes_[0]->codegen();
  return types::floatCast(expr);
}
types::LemurTypes FloatCastExprAST::wellFormed() { return types::kFloat; }
}  // namespace backend