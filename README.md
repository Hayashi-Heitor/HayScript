# HayScript - My Educational Programming Language Project

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Work In Progress](https://img.shields.io/badge/status-WIP-red)

An educational programming language implementation built from scratch in C. This project includes a complete pipeline from lexical analysis to execution, serving as a comprehensive learning resource for compiler design, programming languages in general and low-level programming concepts.

# Current Features

### Core Components
- **Lexical Analysis** (lexer)
  - Identifiers and keywords
  - String literals with quotation support
  - Special symbols (`=`, `;`, `,`, `(`, `)`)
  - Whitespace and newline handling

- **Syntax Analysis** (parser)
  - Variable declarations (`var x = "value"`)
  - Function calls (`print(arg)`)
  - Compound statements with semicolon separation
  - Nested expression parsing
  - Parentheses handling for function calls

- **AST Generation** (abstract syntax tree)
  - Variable definition nodes
  - Function call nodes
  - Compound statement nodes
  - String literal nodes

- **Execution Engine** (visitor)
  - Variable resolution and lookup
  - Built-in `print` function
  - Memory-managed variable storage
  - Compound statement execution

### Runtime Features
- Direct file-to-memory mapping
- Variable assignment and value resolution
- Function argument processing
- String value interpolation
- Dynamic array handling for variables
- Automatic memory reallocation
- Context-aware variable storage
- Error handling:
  - Syntax error detection
  - Undefined variable warnings
  - Unknown function errors
  - Type safety for print operations

# Prerequisites
- C compiler (GCC recommended)
- Standard C library
- (good to have) Make build system

# Usage
### if you have makefile system
`make` to compile the code <br>
`./test.out <filename>` to execute <br>
`make clean` to clear all the .out
- Example
```make
  > make
    gcc -c -g src/AST.c -o src/AST.o
    gcc -c -g src/io.c -o src/io.o
    gcc -c -g src/lexer.c -o src/lexer.o
    gcc -c -g src/main.c -o src/main.o
    gcc -c -g src/parser.c -o src/parser.o
    gcc -c -g src/token.c -o src/token.o
    gcc -c -g src/visitor.c -o src/visitor.o
    gcc src/AST.o src/io.o src/lexer.o src/main.o src/parser.o src/token.o src/visitor.o -g -o test.out
  > ./test.out examples/printTest.hay
    It Worked!
```
### if you do not have makefile system
`gcc src/*.c -o test.out` to compile the code <br>
`./test.out <filename>` to execute <br>
`rm test.out` to clear the .out
- Example
```
  > gcc src/*.c -o test.out
  > ./test.out examples/printTest.hay
    It Worked!
```