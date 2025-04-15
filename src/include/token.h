#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKEN_S {

    enum {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_SEMI,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_COMMA,
        TOKEN_EOF
    } type;

    char *value;
} token_t;

token_t *tokenInit(int type, char *value);

#endif