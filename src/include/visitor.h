#ifndef VISITOR_H
#define VISITOR_H
#include "AST.h"

typedef struct VISITOR_S {
    ast_t **variableDefinitions;
    size_t variableDefinitionsSize;
} visitor_t;

visitor_t *visitorInit(void);

ast_t *visitorVisit(visitor_t *visitor, ast_t *node);

ast_t *visitorVisitVariableDefinition(visitor_t *visitor, ast_t *node);

ast_t *visitorVisitVariable(visitor_t *visitor, ast_t *node);

ast_t *visitorVisitFunctionCall(visitor_t *visitor, ast_t *node);

ast_t *visitorVisitString(visitor_t *visitor, ast_t *node);

ast_t *visitorVisitCompound(visitor_t *visitor, ast_t *node);

#endif