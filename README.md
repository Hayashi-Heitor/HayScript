# HayScript - My Educational Programming Language Project [INCOMPLETE]

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
- Make build system
