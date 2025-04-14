#include "include/AST.h"

ast_t *astInit(int type) {
    ast_t *ast = calloc(1, sizeof(struct AST_S));
    ast->type = type;

    ast->variableDefinitionVariableName = (void*) 0;
    ast->variableDefinitionValue = (void*) 0;

    ast->variableName = (void*) 0;
    
    ast->functionCallName = (void*) 0;
    ast->functionCallArguments = (void*) 0;
    ast->functionCallArgumentsSize = 0;
    
    ast->stringValue = (void*) 0;

    ast->compoundValue = (void*) 0;
    ast->compoundSize = 0;
    return ast;
}

