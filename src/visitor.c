#include "include/visitor.h"

ast_t *visitorVisit(ast_t *node) {

    // The switch checks the type of the node and returns the correct function
    switch(node->type) {
        case AST_VARIABLE_DEFINITION: return visitorVisitVariableDefinition(node); break;
        case AST_VARIABLE: return visitorVisitVariable(node); break;
        case AST_FUNCTION_CALL: return visitorVisitFunctionCall(node); break;
        case AST_STRING: return visitorVisitString(node); break;
        case AST_COMPOUND: return visitorVisitCompound(node);
    }

    // If none of the cases are true exhibits error message with the type
    printf("Uncaught statement of type %d", node->type);
    exit(1);

    return (void*)0;
}

ast_t visitorVisitVariableDefinition(ast_t *node) {

}

ast_t visitorVisitVariable(ast_t *node) {

}

ast_t visitorVisitFunctionCall(ast_t *node) {

}

ast_t visitorVisitString(ast_t *node) {

}

ast_t visitorVisitCompound(ast_t *node) {

}