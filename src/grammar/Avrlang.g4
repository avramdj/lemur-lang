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

stmt : assign | ret | whileloop | if_expr | ifelse_expr | expr;

assign : NAME '=' expr;

ret : RET expr;

whileloop : WHILE bracedexpr block;

if_expr : IF bracedexpr block;

ifelse_expr : IF bracedexpr block ELSE block;

expr : number | var | callexpr | leftOp=expr binoperator rightOp=expr | neg | bracedexpr;

number : NUM;

var : NAME;

callexpr : fName=NAME OPEN args=arglist CLOSED;

arglist : (expr (',' expr)*)?;

neg : NEG expr;

binoperator : '+' | '-' | '*' | '/' | AND | OR  | XOR | '>' | '<' | '>=' | '<=' | '==' | '!=';

bracedexpr : OPEN expr CLOSED;

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
NEG : 'not';
DEF : 'def';
WHITESPACE : (' ' | '\t') -> skip;
NEWLINE : '\n';
NAME : [a-zA-Z_][a-zA-Z_0-9]*;
NUM : [1-9][0-9]* | [0];
