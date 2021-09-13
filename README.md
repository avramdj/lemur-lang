# untitled-compiler 0.1
A compiled object-oriented programing language implemented with ANTLR4 and LLVM-12

### Dependencies
* LLVM-12
* CMake

### Build
* `cmake CMakeList.txt`
* `make`

### Run
* `./avrlang source_file | llc -o out_name`

### Syntax 
```
class Base {
    float x
    def Base(float x) {
        this.x = x
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

def someListFun(Base el) : List {
    int x = el.doSomething()
    return [x, x, x]
}

def main() {
    Base b = Derived()
    List list = someListFun(b)
    
    for (int i in list) {
        print(i*10)
    }
}
```

### Types
Weakly typed
Statically typed
Class objects passed by reference

### TODO
* <strike> *AST class hierarchy* </strike>
* <strike> *antlr parser and lexer* </strike>
* <strike> *AST builder* </strike>
* <strike> *hook up llvm backend* </strike>
* <strike> *unit testing* </strike>
* <strike> *string support* </strike>
* <strike> *type infrastructure* </strike>
* advanced OOP concepts
* compiler flags
* JIT support
* vscode extension (???)
