grammar Avrlang;

@header {
    #include <iostream>
    #include <ast.hpp>
    using namespace std;
    using namespace llvm;
}
@after {

}

file : (globalstmt | NEWLINE)* EOF;

globalstmt : functiondef;

functiondef : DEF fName=NAME OPEN params=paramlist CLOSED body=block;

paramlist : (NAME(',' NAME)*)?;

block : LEFTBRACE ((stmt NEWLINE) | NEWLINE)+ RIGHTBRACE;

stmt : assign | ret | whileloop | if_expr | ifelse_expr | expr | printstmt;

printstmt : PRINT '(' expr ')';

assign : NAME '=' expr;

ret : RET expr;

whileloop : WHILE bracedexpr block;

if_expr : IF cond=bracedexpr then=block;

ifelse_expr : IF cond=bracedexpr block ELSE block;

expr : number #NumberRule |
    var #VarRule |
    callexpr #CallExprRule|
    leftOp=expr binoperator rightOp=expr #OpExprRule |
    neg #NegRule |
    bracedexpr #BraceExprRule;

number : NUM;

var : NAME;

callexpr : fName=NAME OPEN args=arglist CLOSED;

arglist : (expr (',' expr)*)?;

neg : NEG expr;

binoperator : '+' | '-' | '*' | '/' | SHL | SHR | AND | OR  | XOR | GT | LT | GE | LE | EQ | NE;

bracedexpr : OPEN expr CLOSED;

PRINT : 'print';
OPEN : '(';
CLOSED : ')';
LEFTBRACE : '{';
RIGHTBRACE : '}';
RET : 'return';
WHILE : 'while';
IF : 'if';
ELSE : 'else';
AND : 'and';
OR : 'or';
XOR : '^';
SHL : '<<';
SHR : '>>';
NEG : 'not';
DEF : 'def';
GT : '>';
GE : '>=';
LT : '<';
LE : '<=';
EQ : '==';
NE : '!=';
NEWLINE : '\n';
NAME : [a-zA-Z_][a-zA-Z_0-9]*;
NUM : [1-9][0-9]* | [0];
WHITESPACE : (' ' | '\t') -> skip;
COMMENT : '#' ~[\r\n\f]* -> skip;