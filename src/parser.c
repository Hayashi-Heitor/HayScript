#include "include/parser.h"
#include <stdio.h>

parser_t *parserInit(lexer_t *lexer) {
    parser_t *parser = calloc(1, sizeof(struct PARSER_S));
    parser->lexer = lexer;
    parser->currentToken = lexerGetNextToken(lexer);

    return parser;
}

void *parserEat(parser_t *parser, int tokenType) {
    if (parser->currentToken->type == tokenType)
        parser->currentToken = lexerGetNextToken(parser->lexer);
    else {
        printf("--Unexpected token: '%s' with type: %d", parser->currentToken->value, parser->currentToken->type);
        exit (1);
    }
}

ast_t *parserParse(parser_t *parser) {
    return parserParseMultipleStatement();
}

ast_t *parserParseStatement(parser_t *parser) {
    switch (parser->currentToken->type) {
        case TOKEN_ID: return(parserParseId(parser))
    }
}

ast_t *parserParserMultipleStatements(parser_t *parser) {
    ast_t *compound = astInit(AST_COMPOUND);
    compound->compoundValue = calloc(1, sizeof(struct AST_S*));

    ast_t *astStatement = parserParseStatement(parser);
    compound->compoundValue[0] = astStatement;
    compound->compoundSize++;

    while (parser->currentToken->type == TOKEN_SEMI) {
        parserEat(parser, TOKEN_SEMI);

        ast_t *astStatement = parserParseStatement(parser);
        compound->compoundSize++;
        compound->compountValue = realloc(compound->compoundValue, compound->compoundSize * sizeof(struct AST_S*));
        compound->compoundValue[compound->compoundSize - 1] = astStatement;
        
    }

    return compound;
}

ast_t *parserParserExperssion(parser_t *parser) {

}

ast_t *parserParseFactor(parser_t *parser) {

}

ast_t *parserParseTerm(parser_t *parser) {

}

ast_t *parserParseFunctionCall(parser_t *parser) {

}

ast_t *parseParseVariable(parser_t *parser) {

}

ast_t *parserParseString(parser_t *parser) {

}

ast_t *parserParseId(parser_t *parser) {
    
}