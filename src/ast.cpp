#include <ast.h>
#include <ast_util.h>
#include <context.h>

#include <iostream>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/Scalar.h"

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
  _nodes.resize(0);
  _nodes.push_back(a);
}

InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b) {
  _nodes.resize(0);
  _nodes.push_back(a);
  _nodes.push_back(b);
}

InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b,
                           shared_ptr<ExprAST> c) {
  _nodes.resize(0);
  _nodes.push_back(a);
  _nodes.push_back(b);
  _nodes.push_back(c);
}

InnerExprAST::InnerExprAST(shared_ptr<ExprAST> a, shared_ptr<ExprAST> b,
                           shared_ptr<ExprAST> c, shared_ptr<ExprAST> d) {
  _nodes.resize(0);
  _nodes.push_back(a);
  _nodes.push_back(b);
  _nodes.push_back(c);
  _nodes.push_back(d);
}

InnerExprAST::InnerExprAST(vector<shared_ptr<ExprAST>> a) { _nodes = a; }

InnerExprAST::~InnerExprAST() = default;

Value *IntExprAST::codegen() const {
  return types::getTypeConstant(
      "int", Val);  // NOLINT(cppcoreguidelines-narrowing-conversions)
}

Value *FloatExprAST::codegen() const {
  return types::getTypeConstant("float", Val);
}

Value *VariableExprAST::codegen() const {
  Value *v = getPtrToValue(Name, Sub);
  Type *t = v->getType()->getPointerElementType();
  return Builder.CreateLoad(t, v, Name);
}

Value *AndExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *OrExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *XorExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *ShlExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  Value *lC = l;
  Value *dC = d;
  return Builder.CreateShl(lC, dC, "shltmp");
}

Value *ShrExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == nullptr || d == nullptr) return nullptr;
  Type *lT = l->getType();
  Type *dT = d->getType();
  Value *lC = l;
  Value *dC = d;
  return Builder.CreateLShr(lC, dC, "shrtmp");
}

Value *NotExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  if (l == nullptr) return nullptr;
  Value *lC = types::boolCast(l);
  if (!lC) {
    std::cerr << "Cant bool cast" << std::endl;
    return nullptr;
  }
  return Builder.CreateNot(lC, "nottmp");
}

Value *PrintExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
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

Value *DeclAssignExprAST::codegen() const {
  VarDeclExprAST decl(Type, Name);
  decl.codegen();
  SetExprAST set(_nodes[0], Name);
  return set.codegen();
}

Value *VarDeclExprAST::codegen() const {
  if (NamedValues.isInCurrentScope(Name)) {
    cerr << "Variable " << Name << " already defined" << endl;
    return nullptr;
  }
  Function *F = Builder.GetInsertBlock()->getParent();
  llvm::Type *t = types::getType(Type);
  if (!t) {
    std::cerr << "Unknown type " << Type << std::endl;
    return nullptr;
  }
  AllocaInst *Alloca = CreateEntryBlockAlloca(t, F, Name);
  if (types::isClassType(t)) {
    Value *structSizeVal = types::getStructSize(t);
    Value *StructAllocaRaw = Builder.CreateCall(libc::malloc, structSizeVal);
    Value *StructAlloca = Builder.CreateBitCast(StructAllocaRaw, t);
    Builder.CreateStore(StructAlloca, Alloca);
  }
  NamedValues.set(Name, Alloca);
  return Alloca;
}

Value *SetExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  if (l == nullptr) return nullptr;
  Value *el = getPtrToValue(Name, Sub);
  if (l->getType() != el->getType()->getPointerElementType()) {
    std::cerr << "Type mismatch with "
              << Name + (Sub.empty() ? ""s : "."s + Sub) << std::endl;
    return nullptr;
  }
  return Builder.CreateStore(l, el);
}

Value *SeqExprAST::codegen() const {
  NamedValues.pushScope();
  Value *tmp = nullptr;
  for (const auto &_node : _nodes) {
    tmp = _node->codegen();
    if (isRet(tmp)) {
      return tmp;
    }
    if (!tmp) return nullptr;
  }
  NamedValues.popScope();
  return tmp;
}

void SeqExprAST::add(shared_ptr<ExprAST> node) { _nodes.push_back(node); }

Value *FunctionDefAST::codegen() const {
  vector<Type *> tmp;

  for (auto &typeName : paramTypes) {
    Type *t = types::getType(typeName);
    if (!t) {
      return nullptr;
    }
    tmp.push_back(t);
  }
  Type *retT = types::getType(this->retType);
  if (!retT) {
    return nullptr;
  }
  FunctionType *FT = FunctionType::get(retT, tmp, false);

  Function *f =
      Function::Create(FT, Function::ExternalLinkage, name, TheModule);

  if (!f) {
    return nullptr;
  }

  unsigned i = 0;
  for (auto &a : f->args()) {
    a.setName(parameters[i++]);
  }

  if (!f->empty()) {
    cerr << "Function " << name << " can't be redefined" << endl;
    return nullptr;
  }
  BasicBlock *BB = BasicBlock::Create(TheContext, "entry", f);
  Builder.SetInsertPoint(BB);

  NamedValues.pushScope();
  for (auto &a : f->args()) {
    AllocaInst *Alloca =
        CreateEntryBlockAlloca(a.getType(), f, std::string(a.getName()));
    NamedValues.set(std::string(a.getName()), Alloca);
    Builder.CreateStore(&a, Alloca);
  }
  if (isMember) {
    NamedValues.pushScope();
    Value *thisPtr = f->getArg(0);
    std::string clsName = types::type_names[thisPtr->getType()];
    for (const auto &it : types::class_var_table[clsName]) {
      const auto &memberName = it.first;
      Value *memberAddr = getPtrToMember("this", memberName);
      NamedValues.set(memberName, memberAddr);
    }
    NamedValues.swapLastTwo();
  }
  Value *Body = body->codegen();
  NamedValues.popScope();
  if (isMember) {
    NamedValues.popScope();
  }

  if (Body != nullptr) {
    if (!isRet(Body)) {
      auto retV = types::getTypeConstant(retType, 0);
      if (!retV) {
        std::cerr << "Function " << name << " can't create implicit return"
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

std::string FunctionDefAST::getName() const { return name; }

Value *CallExprAST::codegen() const {
  Function *f = TheModule->getFunction(Callee);
  if (!f) {
    cerr << "Call of undefined function " << Callee << endl;
    return nullptr;
  }

  if (Args.size() != f->arg_size()) {
    cerr << "Function " << Callee << " called with " << Args.size()
         << " arguments but takes " << f->arg_size() << endl;
    return nullptr;
  }

  vector<Value *> ArgsV;
  for (const auto &Arg : Args) {
    Value *tmp = Arg->codegen();
    if (!tmp) return nullptr;
    ArgsV.push_back(tmp);
  }

  return Builder.CreateCall(f, ArgsV, "calltmp");
}

Value *MethodCallExprAST::codegen() const {
  Value *tmp = NamedValues[Name];
  if (!tmp) {
    cerr << "Variable " + Name + " is undefined" << endl;
    return nullptr;
  }
  Type *t = tmp->getType()->getPointerElementType();

  auto cit = types::type_names.find(t);
  if (cit == types::type_names.end()) {
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
  for (const auto &Arg : Args) {
    Value *tmpParam = Arg->codegen();
    if (!tmpParam) return nullptr;
    ArgsV.push_back(tmpParam);
  }

  if (ArgsV.size() != f->arg_size()) {
    cerr << "Method " << Method << " called with " << ArgsV.size() - 1
         << " arguments but takes " << f->arg_size() - 1 << endl;
    return nullptr;
  }

  return Builder.CreateCall(f, ArgsV, "methodcalltmp");
}

Value *AddExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *SubExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *MulExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *DivExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *LtExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *GtExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *EqExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *NeqExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *LteExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *GteExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
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

Value *WhileExprAST::codegen() const {
  Function *f = Builder.GetInsertBlock()->getParent();
  BasicBlock *HeaderBB = BasicBlock::Create(TheContext, "header", f);
  BasicBlock *LoopBB = BasicBlock::Create(TheContext, "loop", f);
  BasicBlock *AfterLoopBB = BasicBlock::Create(TheContext, "afterloop", f);

  // header :
  Builder.CreateBr(HeaderBB);
  Builder.SetInsertPoint(HeaderBB);
  Value *Cond = cond->codegen();
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
  Value *BlockV = block->codegen();
  if (!BlockV) return nullptr;

  if (!isRet(BlockV)) {
    Builder.CreateBr(HeaderBB);
  }

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
  Value *Cmp =
      Builder.CreateICmpNE(types::boolCast(Cond),
                           ConstantInt::get(TheContext, APInt(1, 0)), "cmptmp");
  Builder.CreateCondBr(Cmp, thenBB, mergeBB);

  Builder.SetInsertPoint(thenBB);
  Value *ThenV = block->codegen();
  if (!ThenV) {
    return nullptr;
  }

  if (!isRet(ThenV)) {
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
  Value *Cmp =
      Builder.CreateICmpNE(types::boolCast(Cond),
                           ConstantInt::get(TheContext, APInt(1, 0)), "cmptmp");
  Builder.CreateCondBr(Cmp, thenBB, elseBB);

  Builder.SetInsertPoint(thenBB);
  Value *ThenV = thenBlock->codegen();
  if (!ThenV) {
    return nullptr;
  }
  bool thenRet = isRet(ThenV);
  if (!thenRet) {
    Builder.CreateBr(mergeBB);
  }
  Builder.SetInsertPoint(elseBB);
  Value *ElseV = elseBlock->codegen();
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

AllocaInst *CreateEntryBlockAlloca(Type *t, Function *TheFunction,
                                   const std::string &VarName) {
  IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
                   TheFunction->getEntryBlock().begin());
  return TmpB.CreateAlloca(t, nullptr, VarName);
}

bool isRet(Value *tmp) { return llvm::dyn_cast<ReturnInst>(tmp); }

Value *StringExprAST::codegen() const {
  auto charType = llvm::IntegerType::get(TheContext, 8);

  std::vector<llvm::Constant *> chars(Str.length());
  for (unsigned int i = 0; i < Str.size(); i++) {
    chars[i] = llvm::ConstantInt::get(charType, Str[i]);
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

Value *ClassDefExprAST::codegen() const {
  if (types::type_table.find(Name) != types::type_table.end()) {
    std::cerr << "Class " << Name << " already exists" << std::endl;
  }
  vector<Type *> subtypes;
  for (int i = 0; i < types.size(); i++) {
    Type *t = types::getType(types[i]);
    if (!t) {
      return nullptr;
    }
    if (types::class_var_table[Name].find(vars[i]) !=
        types::class_var_table[Name].end()) {
      std::cerr << "Class variable " << types[i] << " already defined"
                << std::endl;
      return nullptr;
    }
    subtypes.push_back(t);
    types::class_var_table[Name][vars[i]] = i;
    types::class_var_types[Name][vars[i]] = t;
  }
  StructType *classType = StructType::create(TheContext, subtypes, Name);
  types::type_table[Name] = classType->getPointerTo();
  types::type_names[types::type_table[Name]] = Name;
  for (auto &f : functions) {
    f->codegen();
  }
  return nullptr;
}
}  // namespace backend