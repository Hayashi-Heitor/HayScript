#include "include/parser.h"
#include <stdio.h>
#include <string.h>

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
    return parserParseMultipleStatements(parser);
}

ast_t *parserParseStatement(parser_t *parser) {
    switch (parser->currentToken->type) {
        case TOKEN_ID: return(parserParseId(parser));
    }
}

ast_t *parserParseMultipleStatements(parser_t *parser) {
    ast_t *compound = astInit(AST_COMPOUND);
    compound->compoundValue = calloc(1, sizeof(struct AST_S*));

    ast_t *astStatement = parserParseStatement(parser);
    compound->compoundValue[0] = astStatement;

    while (parser->currentToken->type == TOKEN_SEMI) {
        parserEat(parser, TOKEN_SEMI);

        ast_t *astStatement = parserParseStatement(parser);
        compound->compoundSize++;
        compound->compoundValue = realloc(compound->compoundValue, compound->compoundSize * sizeof(struct AST_S*));
        compound->compoundValue[compound->compoundSize - 1] = astStatement;
        
    }

    return compound;
}

ast_t *parserParseExpression(parser_t *parser) {
    switch (parser->currentToken->type) {
        case TOKEN_STRING: return parserParseString(parser);
    }
}

ast_t *parserParseFactor(parser_t *parser) {

}

ast_t *parserParseTerm(parser_t *parser) {

}

ast_t *parserParseFunctionCall(parser_t *parser) {

}

ast_t *parserParseVariableDefinition(parser_t *parser) {
    parserEat(parser, TOKEN_ID);
    char *variableDefinitionVariableName = parser->currentToken->value;
    parserEat(parser, TOKEN_ID);
    parserEat(parser, TOKEN_EQUALS);
    ast_t *variableDefinitionValue = parserParseExpression(parser);

    ast_t *variableDefinition = astInit(AST_VARIABLE_DEFINITION);
    variableDefinition->variableDefinitionVariableName = variableDefinitionVariableName;
    variableDefinition->variableDefinitionValue = variableDefinitionValue;

    return variableDefinition;
}

ast_t *parserParseVariable(parser_t *parser) {
    char *tokenValue = parser->currentToken->value;

    parserEat(parser, TOKEN_ID);
    if (parser->currentToken->type == TOKEN_LPAREN)
        return parserParseFunctionCall(parser);

    ast_t *astVariable= astInit(AST_VARIABLE);
    astVariable->variableName = tokenValue;

    return astVariable;
}

ast_t *parserParseString(parser_t *parser) {
    ast_t *astString = astInit(AST_STRING);
    astString->stringValue = parser->currentToken->value;
    parserEat(parser, TOKEN_STRING);

    return astString;
}

ast_t *parserParseId(parser_t *parser) {
    if (strcmp(parser->currentToken->value, "var") == 0)
        return parserParseVariableDefinition(parser);
    else
        return parserParseVariable(parser);
}