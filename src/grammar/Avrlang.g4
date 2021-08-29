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

functiondef : DEF NAME OPEN paramlist CLOSED block;

paramlist : (NAME(',' NAME)*)?;

block : LEFTBRACE ((stmt NEWLINE) | NEWLINE)+ RIGHTBRACE;

stmt : assign | ret | whileloop | if_expr | ifelse_expr | expr;

assign : NAME '=' expr;

ret : RET expr;

whileloop : WHILE OPEN expr CLOSED block;

if_expr : IF OPEN expr CLOSED block;

ifelse_expr : IF OPEN expr CLOSED block ELSE block;

expr : NUM | NAME | NAME OPEN arglist CLOSED | expr binoperator expr | neg | OPEN expr CLOSED;

arglist : (expr (',' expr)*)?;

neg : NEG expr;

binoperator : '+' | '-' | '*' | '/' | AND | OR  | XOR | '>' | '<' | '>=' | '<=' | '==' | '!=';

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
