# Lemur
A compiled object-oriented programing language implemented with ANTLR4 and LLVM-12.

![CMake](https://github.com/avramdj/lemur-lang/actions/workflows/c-cpp.yml/badge.svg)

### Syntax 
```
class Base {
    float x
    string message
    
    def Base(float x) {
        this.x = x
    }
    def setMessage(string s) {
        message = s
    }
    def incX() {
        x = x + 1
    }
    def getX() : int {
        return x
    }
    def doSomething() : int {
        return x*x
    }
}

class Derived <- Base {
    int y
    def doSomething() : int {
        return x*y
    }
}

def main() {
    Base b = Derived()
    
    b.setMessage("We did it!")

    while(b.getX() < 10) {
        if(b.getX() < 5) {
            print("Not there yet...")
        } else {
            print("Keep going!")
        }
        b.incX()
    }
    print(b.getMessage())
}
```

### Types
Statically typed.

Weakly typed.

Class objects are passed by reference.

Built-in types: `int`, `float`, `bool`, `string`


### Dependencies
* LLVM-12
* CMake

### Build
* `cmake CMakeList.txt`
* `make`

### Run
* `./lemur source_file | llc -o out_name`

### TODO
* <strike> *AST class hierarchy* </strike>
* <strike> *antlr parser and lexer* </strike>
* <strike> *AST builder* </strike>
* <strike> *hook up llvm backend* </strike>
* <strike> *unit testing* </strike>
* <strike> *string support* </strike>
* <strike> *type infrastructure* </strike>
* <strike> *better scoping* </strike>
* advanced OOP concepts
* garbage collector
* JIT support
