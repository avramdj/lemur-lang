grammar Avrlang;

@header {
    #include <vector>
    #include <string>
}
@after {}

file : (globalstmt | NEWLINE)* EOF;

globalstmt : classdef | functiondef;

classdef : CLASS cName=NAME (ARROW baseName=NAME)? '{' body=classbody '}';

classbody: (classvardecl | classfunctiondef | NEWLINE)*;

classvardecl : typeName=NAME varName=NAME;

classfunctiondef : DEF fName=NAME OPEN params=paramlist CLOSED (':' retType=NAME)? body=block;

functiondef : DEF fName=NAME OPEN params=paramlist CLOSED (':' retType=NAME)? body=block;

paramlist returns [std::vector<std::string> types, std::vector<std::string> vars]
 : (
                typeName=NAME varName=NAME {$types.push_back($typeName.text);$vars.push_back($varName.text);}
                (',' typeName=NAME varName=NAME {{$types.push_back($typeName.text);$vars.push_back($varName.text);}})*
            )?;

block : LEFTBRACE ((stmt NEWLINE) | NEWLINE)+ RIGHTBRACE;

stmt : vardecl | assign | declassign | ret | whileloop | ifExpr | ifElseExpr | forloop | expr | printstmt;

printstmt : PRINT '(' expr ')';

vardecl : typeName=NAME varName=NAME;

assign : varName=NAME ('.'subName=NAME)? '=' expr;

declassign : typeName=NAME varName=NAME '=' expr;

ret : RET (expr)?;

whileloop : WHILE bracedexpr block;

forloop : FOR '(' varName=NAME IN listName=expr block;

ifExpr : IF cond=bracedexpr then=block;

ifElseExpr : IF cond=bracedexpr block (NEWLINE)* ELSE block;

expr : number #NumberRule |
    UMINUS expr #UminusRule |
    var #VarRule |
    string #StringRule |
    methodCall #MethodRule |
    expr '[' expr ']' #IndexRule |
    callexpr #CallExprRule|
    leftOp=expr binoperator rightOp=expr #OpExprRule |
    neg #NegRule |
    list #ListRule |
    bracedexpr #BraceExprRule;

list : '[' (expr (',' expr)?)? ']';

methodCall : varName=NAME '.' methodName=NAME OPEN args=arglist CLOSED;

string : STRING;

number : INT | FLOAT;

var : varName=NAME('.'subName=NAME)?;

callexpr : fName=NAME OPEN args=arglist CLOSED;

arglist : (expr (',' expr)*)?;

neg : NEG expr;

binoperator : '+' | '-' | '*' | '/' | SHL | SHR | AND | OR  | XOR | GT | LT | GE | LE | EQ | NE;

bracedexpr : OPEN expr CLOSED;

UMINUS : '-';
FOR : 'for';
IN : 'in';
CLASS : 'class';
ARROW : '<-';
DEF : 'def';
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
GT : '>';
GE : '>=';
LT : '<';
LE : '<=';
EQ : '==';
NE : '!=';
NEWLINE : '\n';
NAME : [a-zA-Z_][a-zA-Z_0-9]*;
INT : [0-9]+;
FLOAT : ([0-9]*[.])?[0-9]+;
STRING : '"'(ESC | ~["\\])*'"';
fragment ESC : '\\' (["\\/bfnrt]) ;
WHITESPACE : (' ' | '\t') -> skip;
COMMENT : '#' ~[\r\n\f]* -> skip;