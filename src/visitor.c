#include "include/visitor.h"
#include <stdio.h>
#include <string.h>

// Print builtin function
// Handles AST_STRING or prints address for other types
static ast_t *builtinFunctionPrint(visitor_t *visitor, ast_t **args, int argsSize) {
    for(int i = 0; i < argsSize; i++) {
        ast_t *arg = visitorVisit(visitor, args[i]);
        if(arg->type == AST_STRING) printf("%s", arg->stringValue);
        else printf("%p", arg); // Fallback for non-string types
    }
    return astInit(AST_NO_OP); // Returns no operation
}

// Initializes visitor with empty variable storage
visitor_t *visitorInit(void) {
    visitor_t *visitor = calloc(1, sizeof(struct VISITOR_S));
    visitor->variableDefinitions = NULL;
    visitor->variableDefinitionsSize = 0;
    return visitor;
}

// Main visitor
// Routes nodes to appropriate handlers
ast_t *visitorVisit(visitor_t *visitor, ast_t *node) {
    switch(node->type) {
        case AST_VARIABLE_DEFINITION: return visitorVisitVariableDefinition(visitor, node);
        case AST_VARIABLE: return visitorVisitVariable(visitor, node);
        case AST_FUNCTION_CALL: return visitorVisitFunctionCall(visitor, node);
        case AST_STRING: return visitorVisitString(visitor, node);
        case AST_COMPOUND: return visitorVisitCompound(visitor, node);
        case AST_NO_OP: return node;
        default: printf("Unknown node type: %d", node->type); exit(1);
    }
}

// Stores variable definitions in visitors context
ast_t *visitorVisitVariableDefinition(visitor_t *visitor, ast_t *node) {
    if(!visitor->variableDefinitions) {
        visitor->variableDefinitions = calloc(1, sizeof(struct AST_S*));
        visitor->variableDefinitionsSize = 1;
    } else {
        visitor->variableDefinitionsSize++;
        visitor->variableDefinitions = realloc(visitor->variableDefinitions, 
            visitor->variableDefinitionsSize * sizeof(struct AST_T*));
    }
    visitor->variableDefinitions[visitor->variableDefinitionsSize - 1] = node;
    
    return node;
}

// Resolves variable references to their values
ast_t *visitorVisitVariable(visitor_t *visitor, ast_t *node) {
    for(int i = 0; i < visitor->variableDefinitionsSize; i++) {
        ast_t *def = visitor->variableDefinitions[i];
        if(strcmp(def->variableDefinitionVariableName, node->variableName) == 0)
            return visitorVisit(visitor, def->variableDefinitionValue);
    }
    printf("Undefined variable: %s\n", node->variableName);
    return node;
}

// Handles function calls (only 'print' currently supported)
ast_t *visitorVisitFunctionCall(visitor_t *visitor, ast_t *node) {
    if(strcmp(node->functionCallName, "print") == 0)
        return builtinFunctionPrint(visitor, node->functionCallArguments, 
                                 node->functionCallArgumentsSize);
    printf("Unknown function: %s\n", node->functionCallName);
    exit(1);
}

// String nodes are terminal values
// Return as-is
ast_t *visitorVisitString(visitor_t *visitor, ast_t *node) {
    return node;
}

// Process all statements in compound nodes
ast_t *visitorVisitCompound(visitor_t *visitor, ast_t *node) {
    for(int i = 0; i < node->compoundSize; i++)
        visitorVisit(visitor, node->compoundValue[i]);
    return astInit(AST_NO_OP);
}