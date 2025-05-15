#include "include/visitor.h"
#include <stdio.h>

// Starts and callocs the visitor
visitor_t *visitorInit(void) {
    visitor_t *visitor = calloc(1, sizeof(struct VISITOR_S));
    visitor->variableDefinitions = (void*) 0;
    visitor->variableDefinitionsSize = 0;

    return visitor;
}

// Main visit function
ast_t *visitorVisit(visitor_t *visitor, ast_t *node) {
    // The switch checks the type of the node and returns the correct function
    switch(node->type) {
        case AST_VARIABLE_DEFINITION: return visitorVisitVariableDefinition(visitor, node); break;
        case AST_VARIABLE: return visitorVisitVariable(visitor,node); break;
        case AST_FUNCTION_CALL: return visitorVisitFunctionCall(visitor,node); break;
        case AST_STRING: return visitorVisitString(visitor,node); break;
        case AST_COMPOUND: return visitorVisitCompound(visitor, node); break;
        case AST_NO_OP: return node;
    }

    // If none of the cases are true exhibits error message with the type
    printf("Uncaught statement of type %d", node->type);
    exit(1);

    return astInit(AST_NO_OP);
}

ast_t *visitorVisitVariableDefinition(visitor_t *visitor, ast_t *node) {

    if(visitor->variableDefinitions == (void*) 0 ) {
        visitor->variableDefinitions = calloc(1, sizeof(struct AST_S*));
        visitor->variableDefinitions[0] = node;
        visitor->variableDefinitionsSize++;
    }

    else {
        visitor->variableDefinitionsSize++;
        visitor->variableDefinitions = realloc(visitor->variableDefinitions, visitor->variableDefinitionsSize * sizeof(struct AST_T*));
    }
    visitor->variableDefinitions[visitor->variableDefinitionsSize - 1] = node;

    return node;
}

ast_t *visitorVisitVariable(visitor_t *visitor, ast_t *node) {

}

ast_t *visitorVisitFunctionCall(visitor_t *visitor, ast_t *node) {
    if(strcmp(node->functionCallName, "print") == 0) {
        return buildinFunctionPrint(node->functionCallArguments);
    }

    printf("Undefined Method %s\n", node->functionCallName);
    exit(1);
}

ast_t *visitorVisitString(visitor_t *visitor, ast_t *node) {

}

ast_t *visitorVisitCompound(visitor_t *visitor, ast_t *node) {
    
    // Calls visit method on every children
    for(int i = 0; i < node->compoundSize; i++)
        visitorVisit(visitor, node->compoundValue[i]);

    return astInit(AST_NO_OP);
}