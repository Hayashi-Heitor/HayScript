#ifndef VISITOR_H
#define VISITOR_H
#include "AST.h"

ast_t *visitorVisit(ast_t *node);

ast_t visitorVisitVariableDefinition(ast_t *node);

ast_t visitorVisitVariable(ast_t *node);

ast_t visitorVisitFunctionCall(ast_t *node);

ast_t visitorVisitString(ast_t *node);

ast_t visitorVisitCompound(ast_t *node);

#endif