# untitled-compiler 0.1
A compiled programing language implemented in ANTLR4 and LLVM-12

### Dependencies
* LLVM-12
* CMake

### Build
* `cmake CMakeList.txt`
* `make`

### Run
* `./avrlang file`

### Syntax 
```
def fib(x) {
  if(x < 2){
    return 1
  }
  return fib(x-1) + fib(x-2)
}

def main() {
  print(fib(42))
}
```

### Types
Currently only supports doubles.

### TODO
* hook up llvm backend
* compiler flags
* interpretation support
