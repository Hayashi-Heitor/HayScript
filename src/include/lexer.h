#ifndef LEXER_H
#define LEXER_H
#include "token.h"

typedef struct LEXER_S {
   char ascii;
   unsigned int index;
   char *contents;
} lexer_t;

lexer_t *lexerInit(char *content);

void lexerAdvance(lexer_t *lexer);

void lexerSkipWhitespace(lexer_t *lexer);

token_t *lexerGetNextToken(lexer_t *lexer);

token_t *lexerCollectString(lexer_t *lexer);

token_t *lexerCollectId(lexer_t *lexer);

token_t *lexerAdvanceWithToken(lexer_t *lexer, token_t *token);

char *lexerGetCurrentCharAsString(lexer_t *lexer);
#endif
