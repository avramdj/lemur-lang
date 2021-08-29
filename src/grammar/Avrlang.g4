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

functiondef : 'def' NAME;

NAME : [a-zA-Z_][a-zA-Z_0-9]* {

};

WHITESPACE : ' ' -> skip;
NEWLINE : '\n';