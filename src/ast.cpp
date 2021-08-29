#include "ast.hpp"
#include <iostream>

// #define _DISABLE_OPTS_ 1
#define _LIBCPP_DEBUG 1

LLVMContext TheContext;
map<string, AllocaInst*> NamedValues;
IRBuilder<> Builder(TheContext);
Module* TheModule;
llvm::legacy::FunctionPassManager *TheFPM;
Value* Str;
Value* Str1;
Function *PrintfFja;

ExprAST::~ExprAST() {

}

InnerExprAST::InnerExprAST(ExprAST* a) {
  _nodes.resize(0);
  _nodes.push_back(a);
}

InnerExprAST::InnerExprAST(ExprAST* a, ExprAST* b) {
  _nodes.resize(0);
  _nodes.push_back(a);
  _nodes.push_back(b);
}

InnerExprAST::InnerExprAST(ExprAST* a, ExprAST* b, ExprAST* c) {
  _nodes.resize(0);
  _nodes.push_back(a);
  _nodes.push_back(b);
  _nodes.push_back(c);
}

InnerExprAST::InnerExprAST(ExprAST* a, ExprAST* b, ExprAST* c, ExprAST* d) {
  _nodes.resize(0);
  _nodes.push_back(a);
  _nodes.push_back(b);
  _nodes.push_back(c);
  _nodes.push_back(d);
}

InnerExprAST::InnerExprAST(vector<ExprAST*> a) {
  _nodes = a;
}

InnerExprAST::~InnerExprAST() {
  for (unsigned i = 0; i < _nodes.size(); i++)
    delete _nodes[i];
}

Value* NumberExprAST::codegen() const {
  return ConstantInt::get(TheContext, APInt(32, Val));
}

Value* VariableExprAST::codegen() const {
  AllocaInst* tmp = NamedValues[Name];
  if (tmp == NULL) {
    cerr << "Promenljiva " + Name + " nije definisana" << endl;
    return NULL;
  }
  return Builder.CreateLoad(Type::getInt32Ty(TheContext), tmp, Name.c_str());
}

Value* AndExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == NULL || d == NULL)
    return NULL;
  return Builder.CreateAnd(l, d, "andtmp");
}

Value* OrExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == NULL || d == NULL)
    return NULL;
  return Builder.CreateOr(l, d, "ortmp");
}

Value* XorExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == NULL || d == NULL)
    return NULL;
  return Builder.CreateXor(l, d, "xortmp");
}

Value* ShlExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == NULL || d == NULL)
    return NULL;
  return Builder.CreateShl(l, d, "shltmp");
}

Value* ShrExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == NULL || d == NULL)
    return NULL;
  return Builder.CreateLShr(l, d, "shrtmp");
}

Value* NotExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  if (l == NULL)
    return NULL;
  return Builder.CreateNot(l, "nottmp");
}

Value* PrintExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  if (l == NULL)
    return NULL;

  if (Str == NULL) {
    Str = Builder.CreateGlobalStringPtr("%d\n");
  }  
  if (Str1 == NULL) {
    Str1 = Builder.CreateGlobalStringPtr("0x%x\n");
  }

  AllocaInst* Alloca = NamedValues["flag"];
  if (Alloca == NULL) {
    Function *F = Builder.GetInsertBlock()->getParent();
    Alloca = CreateEntryBlockAlloca(F, "flag");
    NamedValues["flag"] = Alloca;
    Builder.CreateStore(ConstantInt::get(TheContext, APInt(32, 0)), Alloca);
  }
  
  Value *tmp = Builder.CreateLoad(Type::getInt32Ty(TheContext), Alloca, "flag");
  Value *CondV = Builder.CreateICmpEQ(tmp, ConstantInt::get(TheContext, APInt(32, 0)));

  Function *TheFunction = Builder.GetInsertBlock()->getParent();
  BasicBlock *ThenBB =
    BasicBlock::Create(TheContext, "then", TheFunction);
  BasicBlock *ElseBB = BasicBlock::Create(TheContext, "else");
  BasicBlock *MergeBB = BasicBlock::Create(TheContext, "ifcont");
  
  Builder.CreateCondBr(CondV, ThenBB, ElseBB);
  Builder.SetInsertPoint(ThenBB);
  vector<Value *> ArgsV;
  ArgsV.push_back(Str);
  ArgsV.push_back(l);
  Builder.CreateCall(PrintfFja, ArgsV, "printfCall");
  Builder.CreateBr(MergeBB);
  ThenBB = Builder.GetInsertBlock();

  TheFunction->getBasicBlockList().push_back(ElseBB);
  Builder.SetInsertPoint(ElseBB);
  ArgsV.clear();
  ArgsV.push_back(Str1);
  ArgsV.push_back(l);
  Builder.CreateCall(PrintfFja, ArgsV, "printfCall");
  Builder.CreateBr(MergeBB);
  ElseBB = Builder.GetInsertBlock();

  TheFunction->getBasicBlockList().push_back(MergeBB);
  Builder.SetInsertPoint(MergeBB);
  return l;
}

Value* SetExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  if (l == NULL)
    return NULL;
  AllocaInst* Alloca = NamedValues[Name];
  if (Alloca == NULL) {
    Function *F = Builder.GetInsertBlock()->getParent();
    Alloca = CreateEntryBlockAlloca(F, Name);
    NamedValues[Name] = Alloca;
  }
  return Builder.CreateStore(l, Alloca);
}

Value* SeqExprAST::codegen() const {
  Value *tmp = NULL;
  for (unsigned i = 0; i < _nodes.size(); i++) {
    tmp = _nodes[i]->codegen();
    if (tmp == NULL)
      return NULL;
  }
  return tmp;
}

void SeqExprAST::add(ExprAST* node) {
  _nodes.push_back(node);
}

Value* FunctionDefintionAST::codegen() const {
  vector<Type*> tmp;
  for (unsigned i = 0; i < parameters.size(); i++)
    tmp.push_back(Type::getInt32Ty(TheContext));
  
  
  FunctionType *FT = FunctionType::get(Type::getInt32Ty(TheContext), tmp, false);
  
  Function* f = Function::Create(FT, Function::ExternalLinkage, name, TheModule);

  unsigned i = 0;
  for (auto &a : f->args())
    a.setName(parameters[i++]);

  if (!f)
    return nullptr;

  if (!f->empty()) {
    cerr << "Funkcija " << name << " ne moze da se redefinise" << endl;
    return nullptr;
  }
  BasicBlock *BB = BasicBlock::Create(TheContext, "entry", f);
  Builder.SetInsertPoint(BB);

  NamedValues.clear();
  for (auto &a : f->args()) {
    AllocaInst *Alloca = CreateEntryBlockAlloca(f, string(a.getName()));
    NamedValues[string(a.getName())] = Alloca;
    Builder.CreateStore(&a, Alloca);
  }

  Value* Body = body->codegen();
  if (Body != nullptr) {
    // Builder.CreateRet(ret);

    verifyFunction(*f);

    TheFPM->run(*f);
    
    return f;
  }

  f->eraseFromParent();
  
  return nullptr;
}

string FunctionDefintionAST::getName() const {
  return name;
}

Value* CallExprAST::codegen() const {
  Function *f = TheModule->getFunction(Callee);
  if (!f) {
    cerr << "Poziv nedefinisane funckije " << Callee << endl;
    return nullptr;
  }

  if (Args.size() != f->arg_size()) {
    cerr << "Funkcija " << Callee << " je pozvana sa neodgovarajucim brojem argumenata" << endl;
    return nullptr;
  }

  vector<Value*> ArgsV;
  for (unsigned i = 0; i < Args.size(); i++) {
    Value *tmp = Args[i]->codegen();
    if (!tmp)
      return nullptr;
    ArgsV.push_back(tmp);
  }

  return Builder.CreateCall(f, ArgsV, "calltmp");
}


CallExprAST::~CallExprAST() {
  for (vector<ExprAST*>::iterator i = Args.begin(); i != Args.end(); i++)
    delete *i;
}

Value* AddExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == NULL || d == NULL)
    return NULL;
  return Builder.CreateAdd(l, d, "andtmp");
}

Value* SubExprAST::codegen() const {
  Value *l = _nodes[0]->codegen();
  Value *d = _nodes[1]->codegen();
  if (l == NULL || d == NULL)
    return NULL;
  return Builder.CreateSub(l, d, "andtmp");
}

Value* LtExprAST::codegen() const {
  Value* L = _nodes[0]->codegen();
  Value* R = _nodes[1]->codegen();
  if (!L || !R)
    return nullptr;
  return Builder.CreateIntCast(Builder.CreateICmpSLT(L, R, "lttmp"), Type::getInt32Ty(TheContext), true);
}

Value* GtExprAST::codegen() const {
  Value* L = _nodes[0]->codegen();
  Value* R = _nodes[1]->codegen();
  if (!L || !R)
    return nullptr;
  return Builder.CreateIntCast(Builder.CreateICmpSGT(L, R, "gttmp"), Type::getInt32Ty(TheContext), true);
}

Value* EqExprAST::codegen() const {
  Value* L = _nodes[0]->codegen();
  Value* R = _nodes[1]->codegen();
  if (!L || !R)
    return nullptr;
  return Builder.CreateIntCast(Builder.CreateICmpEQ(L, R, "eqtmp"), Type::getInt32Ty(TheContext), true);
}

Value* NeqExprAST::codegen() const {
  Value* L = _nodes[0]->codegen();
  Value* R = _nodes[1]->codegen();
  if (!L || !R)
    return nullptr;
  return Builder.CreateIntCast(Builder.CreateICmpNE(L, R, "neqtmp"), Type::getInt32Ty(TheContext), true);
}

Value* LteExprAST::codegen() const {
  Value* L = _nodes[0]->codegen();
  Value* R = _nodes[1]->codegen();
  if (!L || !R)
    return nullptr;
  return Builder.CreateIntCast(Builder.CreateICmpSLE(L, R, "ltetmp"), Type::getInt32Ty(TheContext), true);
}

Value* GteExprAST::codegen() const {
  Value* L = _nodes[0]->codegen();
  Value* R = _nodes[1]->codegen();
  if (!L || !R)
    return nullptr;
  return Builder.CreateIntCast(Builder.CreateICmpSGE(L, R, "gtetmp"), Type::getInt32Ty(TheContext), true);
}

// Value* WhileExprAST::codegen() const {
//   Function *F = Builder.GetInsertBlock()->getParent();
//   BasicBlock *Loop1BB = BasicBlock::Create(TheContext, "loop1", F);
//   BasicBlock *Loop2BB = BasicBlock::Create(TheContext, "loop2", F);
//   BasicBlock *AfterLoopBB = BasicBlock::Create(TheContext, "afterloop", F);
//   Builder.CreateBr(Loop1BB);
  
//   Builder.SetInsertPoint(Loop1BB);
//   Value* CondVal = cond->codegen();
//   if (!CondVal)
//     return NULL;  
//   Builder.CreateCondBr(CondVal, Loop2BB, AfterLoopBB);
//   Loop1BB = Builder.GetInsertBlock();

//   Builder.SetInsertPoint(Loop2BB);
//   Value* Tmp = block->codegen();
//   if (Tmp == NULL)
//     return NULL;
//   Builder.CreateBr(Loop1BB);
//   Loop2BB = Builder.GetInsertBlock();

//   Builder.SetInsertPoint(AfterLoopBB);
//   return ConstantInt::get(TheContext, APInt(32, 0));
// }

Value* WhileExprAST::codegen() const {

  Function *f = Builder.GetInsertBlock()->getParent();
  BasicBlock *HeaderBB = BasicBlock::Create(TheContext, "header", f);
  BasicBlock *LoopBB = BasicBlock::Create(TheContext, "loop", f);
  BasicBlock *AfterLoopBB = BasicBlock::Create(TheContext, "afterloop", f);
  
  //header :
  Builder.CreateBr(HeaderBB);
  Builder.SetInsertPoint(HeaderBB);
  Value *Cond = cond->codegen();
  if(!Cond) {
    return nullptr;
  }
  Value *Cmp = Builder.CreateICmpNE(Cond, ConstantInt::get(TheContext, APInt(32, 0)), "loopcond");
  Builder.CreateCondBr(Cmp, LoopBB, AfterLoopBB);
  HeaderBB = Builder.GetInsertBlock();

  //loop :
  Builder.SetInsertPoint(LoopBB);
  Value *Block = block->codegen();
  if (!Block)
    return nullptr;
  Builder.CreateBr(HeaderBB);
  LoopBB = Builder.GetInsertBlock();
  Builder.SetInsertPoint(AfterLoopBB);

  return ConstantInt::get(TheContext, APInt(32, 0));
}


Value* IfExprAST::codegen() const {
  Function* f = Builder.GetInsertBlock()->getParent();
  BasicBlock* headerBB = BasicBlock::Create(TheContext, "header", f);
  BasicBlock* thenBB = BasicBlock::Create(TheContext, "then", f);
  BasicBlock* mergeBB = BasicBlock::Create(TheContext, "merge", f);

  Builder.CreateBr(headerBB);
  Builder.SetInsertPoint(headerBB);

  Value *Cond = cond->codegen();
  if(!Cond) {
    return nullptr;
  }
  headerBB = Builder.GetInsertBlock();
  Value *Cmp = Builder.CreateICmpNE(Cond, ConstantInt::get(TheContext, APInt(32, 0)), "cmptmp");
  BasicBlock* entryBB = Builder.GetInsertBlock();
  Builder.CreateCondBr(Cmp, thenBB, mergeBB);

  Builder.SetInsertPoint(thenBB);
  Value *ThenV = block->codegen();
  if(!ThenV) {
    return nullptr;
  }
  thenBB = Builder.GetInsertBlock();
  Builder.CreateBr(mergeBB);

  Builder.SetInsertPoint(mergeBB);
  return ConstantInt::get(TheContext, APInt(32, 0));
}

Value* IfElseExprAST::codegen() const {
  Function* f = Builder.GetInsertBlock()->getParent();
  BasicBlock* headerBB = BasicBlock::Create(TheContext, "header", f);
  BasicBlock* thenBB = BasicBlock::Create(TheContext, "then", f);
  BasicBlock* elseBB = BasicBlock::Create(TheContext, "else", f);
  BasicBlock* mergeBB = BasicBlock::Create(TheContext, "merge", f);

  Builder.CreateBr(headerBB);
  Builder.SetInsertPoint(headerBB);

  Value *Cond = cond->codegen();
  if(!Cond) {
    return nullptr;
  }
  headerBB = Builder.GetInsertBlock();
  Value *Cmp = Builder.CreateICmpNE(Cond, ConstantInt::get(TheContext, APInt(32, 0)), "cmptmp");
  Builder.CreateCondBr(Cmp, thenBB, elseBB);

  Builder.SetInsertPoint(thenBB);
  Value *ThenV = thenBlock->codegen(); 
  if(!ThenV) {
    return nullptr;
  }
  thenBB = Builder.GetInsertBlock();
  Builder.CreateBr(mergeBB);

  Builder.SetInsertPoint(elseBB);
  Value *ElseV = elseBlock->codegen();
  if(!ElseV) {
    return nullptr;
  }
  elseBB = Builder.GetInsertBlock();
  Builder.CreateBr(mergeBB);

  Builder.SetInsertPoint(mergeBB);
  
  return ConstantInt::get(TheContext, APInt(32, 0));
}

Value* RetExprAST::codegen() const {
  // Function *TheFunction = Builder.GetInsertBlock()->getParent();
  // BasicBlock *RetBB = BasicBlock::Create(TheContext, "theret", TheFunction);
  Value *ret = v->codegen();
  if(!ret) {
    return nullptr;
  }
  return Builder.CreateRet(ret);
}

void InitializeModuleAndPassManager(void) {
  TheModule = new Module("my_module", TheContext);

  /* printf fja */
  FunctionType *FT1 = FunctionType::get(IntegerType::getInt32Ty(TheContext), PointerType::get(Type::getInt8Ty(TheContext), 0), true);
  PrintfFja = Function::Create(FT1, Function::ExternalLinkage, "printf", TheModule);

  // Create a new pass manager attached to it.
  TheFPM = new llvm::legacy::FunctionPassManager(TheModule);

  #ifndef _DISABLE_OPTS_
  // Do simple "peephole" optimizations and bit-twiddling optzns.
  TheFPM->add(createInstructionCombiningPass());
  // Reassociate expressions.
  TheFPM->add(createReassociatePass());
  // Eliminate Common SubExpressions.
  TheFPM->add(createNewGVNPass());
  // Simplify the control flow graph (deleting unreachable blocks, etc).
  TheFPM->add(createCFGSimplificationPass());
  TheFPM->add(createPromoteMemoryToRegisterPass());
  #endif
  TheFPM->doInitialization();

}

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const string &VarName) {
  IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
  return TmpB.CreateAlloca(Type::getInt32Ty(TheContext), 0, VarName.c_str());
}
