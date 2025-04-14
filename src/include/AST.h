#ifndef AST_H
#define AST_H
#include <stdlib.h>

typedef struct AST_S {
    enum {
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,
        AST_FUNCTION_CALL,
        AST_STRING,
        AST_COMPOUND
    } type;

    char *variableDefinitionVariableName;
    struct AST_S *variableDefinitionValue;

    char *variableName;
    
    char *functionCallName;
    struct AST_S **functionCallArguments;
    size_t functionCallArgumentsSize;
    
    char *stringValue;

    struct AST_S **compoundValue;
    size_t compoundSize;
} ast_t;

ast_t *astInit(int type);

#endif