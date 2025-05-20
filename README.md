# My Programming Language Project [INCOMPLETE]

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

A educational programming language implementation built from scratch in C. This project includes a lexical analyzer, parser, and abstract syntax tree (AST), serving as a learning resource for compiler design concepts, programming languages in general and low level concepts comprehension.

## Current Features

- **Lexical Analysis** (lexer)
  - Identifiers and keywords
  - String literals
  - Special symbols (= ; , ( ) )
  - Whitespace handling

- **Syntax Analysis** (parser)
  - Variable declarations (`var x = value`)
  - Function calls (`func(arg1, arg2)`)
  - Multiple statement handling with semicolons
  - Basic expression parsing

- **AST Generation**
  - Variable definitions
  - Function calls
  - Compound statements
  - String literals

- **Error Handling**
  - Unexpected token detection
  - Basic syntax error reporting

## Prerequisites
- C compiler (GCC recommended)
- Make build system
