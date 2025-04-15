#ifndef PARSER_H
#define PARSER_H
#include "AST.h"
#include "lexer.h"

typedef struct PARSER_S {
    lexer_t *lexer;
    token_t *currentToken;
    token_t *previousToken;
} parser_t;

parser_t *parserInit(lexer_t *lexer);

void *parserEat(parser_t *parser, int tokenType);

ast_t *parserParse(parser_t *parser);

ast_t *parserParseStatement(parser_t *parser);

ast_t *parserParseMultipleStatements(parser_t *parser);

ast_t *parserParseExpression(parser_t *parser);

ast_t *parserParseFactor(parser_t *parser);

ast_t *parserParseTerm(parser_t *parser);

ast_t *parserParseFunctionCall(parser_t *parser);

ast_t *parserParseVariableDefinition(parser_t *parser);

ast_t *parserParseVariable(parser_t *parser);

ast_t *parserParseString(parser_t *parser);

ast_t *parserParseId(parser_t *parser);

#endif