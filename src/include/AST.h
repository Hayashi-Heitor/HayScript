#ifndef AST_H
#define AST_H
#include <stdlib.h>

typedef struct AST_S {
    enum {
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,
        AST_FUNCTION_CALL,
        AST_STRING,
        AST_COMPOUND,
        AST_NO_OP // No operation
    } type;

    // AST_VARIABLE_DEFINITION
    char *variableDefinitionVariableName;
    struct AST_S *variableDefinitionValue;

    // AST_VARIABLE
    char *variableName;
    
    // AST_FUNCTION_CALL
    char *functionCallName;
    struct AST_S **functionCallArguments;
    size_t functionCallArgumentsSize;
    
    // AST_STRING
    char *stringValue;

    // AST_COMPOUND
    struct AST_S **compoundValue;
    size_t compoundSize;
} ast_t;

ast_t *astInit(int type);

#endif