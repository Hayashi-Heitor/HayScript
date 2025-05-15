#include "include/parser.h"
#include <stdio.h>
#include <string.h>

// Initializes a new parser with a given lexer
// Sets up current and previous tokens and returns the parser struct
parser_t *parserInit(lexer_t *lexer) {
    parser_t *parser = calloc(1, sizeof(struct PARSER_S));
    parser->lexer = lexer;
    parser->currentToken = lexerGetNextToken(lexer);
    parser->previousToken = parser->currentToken;

    return parser;
}

// "eats" the current token if it matches the expected type, otherwise, prints error and exits
void *parserEat(parser_t *parser, int tokenType) {
    if (parser->currentToken->type == tokenType) {
        parser->previousToken = parser->currentToken;
        parser->currentToken = lexerGetNextToken(parser->lexer);
    }
    else {
        printf("--Unexpected token: '%s' with type: %d", parser->currentToken->value, parser->currentToken->type);
        exit (1);
    }
}

// Main parse function that starts parsing multiple statements
ast_t *parserParse(parser_t *parser) {
    return parserParseMultipleStatements(parser);
}

// Parses a single statement based on current token type
ast_t *parserParseStatement(parser_t *parser) {
    switch (parser->currentToken->type) {
        case TOKEN_ID: return(parserParseId(parser));
    }
}

// Parses multiple statements separated by semicolons
// Returns a compound AST node containing all statements
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

// Parses an expression based on current token type
// Handles strings and identifiers
ast_t *parserParseExpression(parser_t *parser) {
    switch (parser->currentToken->type) {
        case TOKEN_STRING: return parserParseString(parser); break;
        case TOKEN_ID: return parserParseId(parser);
    }
}

// Parses a factor (to be implemented)
ast_t *parserParseFactor(parser_t *parser) {

}

// Parses a term (to be implemented)
ast_t *parserParseTerm(parser_t *parser) {

}

// Parses a function call
// Handles arguments in parentheses separated by commas
ast_t *parserParseFunctionCall(parser_t *parser) {
    ast_t *functionCall = astInit(AST_FUNCTION_CALL);

    parserEat(parser, TOKEN_LPAREN);
    functionCall->functionCallName = parser->previousToken->value;

    functionCall->functionCallArguments = calloc(1, sizeof(struct AST_S*));

    ast_t *astExpressions = parserParseExpression(parser);
    functionCall->functionCallArguments[0] = astExpressions;

    while (parser->currentToken->type == TOKEN_COMMA) {
        parserEat(parser, TOKEN_COMMA);

        ast_t *astExpressions = parserParseStatement(parser);
        functionCall->functionCallArgumentsSize++;
        functionCall->functionCallArguments = realloc(functionCall->functionCallArguments, functionCall->functionCallArgumentsSize * sizeof(struct AST_S*));
        functionCall->functionCallArguments[functionCall->functionCallArgumentsSize - 1] = astExpressions;
    }
    parserEat(parser, TOKEN_RPAREN);

    return functionCall;
}

// Parses a variable definition
// Format: var name = value
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

// Parses a variable reference or function call
ast_t *parserParseVariable(parser_t *parser) {
    char *tokenValue = parser->currentToken->value;

    parserEat(parser, TOKEN_ID);
    if (parser->currentToken->type == TOKEN_LPAREN)
        return parserParseFunctionCall(parser);

    ast_t *astVariable= astInit(AST_VARIABLE);
    astVariable->variableName = tokenValue;

    return astVariable;
}

// Parses a string literal
ast_t *parserParseString(parser_t *parser) {
    ast_t *astString = astInit(AST_STRING);
    astString->stringValue = parser->currentToken->value;
    parserEat(parser, TOKEN_STRING);

    return astString;
}

// Parses an identifier, could be variable definition or reference
ast_t *parserParseId(parser_t *parser) {
    if (strcmp(parser->currentToken->value, "var") == 0)
        return parserParseVariableDefinition(parser);
    else
        return parserParseVariable(parser);
}