#ifndef PARSER_H
#define PARSER_H
#include "AST.h"
#include "lexer.h"

typedef struct PARSER_S {
    lexer_t *lexer;
    token_t *currentToken;
} parser_t;

parser_t *parserInit(lexer_t *lexer);

void *parserEat(parser_t *parser, int tokenType);

ast_t *parserParse(parser_t *parser);

ast_t *parserParseStatement(parser_t *parser);

ast_t *parserParserMultipleStatements(parser_t *parser);

ast_t *parserParserExperssion(parser_t *parser);

ast_t *parserParseFactor(parser_t *parser);

ast_t *parserParseTerm(parser_t *parser);

ast_t *parserParseFunctionCall(parser_t *parser);

ast_t *parseParseVariable(parser_t *parser);

ast_t *parserParseString(parser_t *parser);

ast_t *parserParseId(parser_t *parser);

#endif