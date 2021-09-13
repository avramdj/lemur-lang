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
    string message
    def Base(float x) {
        this.x = x
    }
    def setMessage(string s) {
        this.message = s
    }
    def incX() {
        this.x = this.x + 1
    }
    def getX() : int {
        return this.x
    }
    def doSomething() : int {
        return this.x*this.x
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
Weakly typed (implicit conversions possible)

Statically typed (variable type must be known at compile time)

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
