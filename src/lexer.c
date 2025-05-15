#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Initializes a new lexer with source code contents
// Sets up the index and current character (ascii)
lexer_t *lexerInit(char *contents) {
    lexer_t *lexer = calloc(1, sizeof(struct LEXER_S));
    lexer->contents = contents;
    lexer->index = 0;
    lexer->ascii = contents[lexer->index];

    return lexer;
}

// Moves to the next character in the source code
void lexerAdvance(lexer_t *lexer) {
    if (lexer->ascii != '\0' && lexer->index < strlen(lexer->contents))
    {
        lexer->index++;
        lexer->ascii = lexer->contents[lexer->index];
    }
}

// Skips whitespace and newline characters
void lexerSkipWhitespace(lexer_t *lexer) {
    while (lexer->ascii == ' ' || lexer->ascii == 10) {
        lexerAdvance(lexer);
    }
}

// Main function to get the next token from source code
// Handles identifiers, strings, and special characters
token_t *lexerGetNextToken(lexer_t *lexer) {
    while (lexer->ascii != '\0' && lexer->index < strlen(lexer->contents)) {

        if (lexer->ascii == ' ' || lexer->ascii == 10)
            lexerSkipWhitespace(lexer);
        
        if (isalnum(lexer->ascii))
            return lexerCollectId(lexer);

        if (lexer->ascii == '"') {
            return lexerCollectString(lexer);
        }

        // Checks the current character and returns the correspondent function
        switch (lexer->ascii) {
            case '=': return lexerAdvanceWithToken(lexer, tokenInit(TOKEN_EQUALS, lexerGetCurrentCharAsString(lexer))); break;
            case ';': return lexerAdvanceWithToken(lexer, tokenInit(TOKEN_SEMI, lexerGetCurrentCharAsString(lexer))); break;
            case '(': return lexerAdvanceWithToken(lexer, tokenInit(TOKEN_LPAREN, lexerGetCurrentCharAsString(lexer))); break;
            case ')': return lexerAdvanceWithToken(lexer, tokenInit(TOKEN_RPAREN, lexerGetCurrentCharAsString(lexer))); break;
            case ',': return lexerAdvanceWithToken(lexer, tokenInit(TOKEN_COMMA, lexerGetCurrentCharAsString(lexer))); break;
        }
    }
    return tokenInit(TOKEN_EOF, "\0");
}

// Collects a string literal between quotes
token_t *lexerCollectString(lexer_t *lexer) {
    lexerAdvance(lexer); // Skips opening quote

    char *value = calloc(1, sizeof(char));
    value[0] = '\0';

    // Collects all characters until closing quote
    while (lexer->ascii != '"') {
        char *s = lexerGetCurrentCharAsString(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        lexerAdvance(lexer);
    }

    lexerAdvance(lexer); // Skips closing quote

    return tokenInit(TOKEN_STRING, value);
}

// Collects an identifier (variable / function name)
// Identifiers can contain alphanumeric characters
token_t *lexerCollectId(lexer_t *lexer) {
    char *value = calloc(1, sizeof(char));
    value[0] = '\0';

    // Collects consecutive alphanumeric characters
    while (isalnum(lexer->ascii)) {
        char *s = lexerGetCurrentCharAsString(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        lexerAdvance(lexer);
    }

    return tokenInit(TOKEN_ID, value);
}

// Helper function to advance the lexer and return a token
token_t *lexerAdvanceWithToken(lexer_t *lexer, token_t *token) {
    lexerAdvance(lexer);
    return token;
}

// Gets current character as a string (for the token)
char *lexerGetCurrentCharAsString(lexer_t *lexer) {
    char *str = calloc(2, sizeof(char));
    str[0] = lexer->ascii;
    str[1] = '\0';

    return str;
}