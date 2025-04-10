#include "include/token.h"
#include <stdlib.h>

token_t *tokenInit(int type, char *value) {
    token_t *token = calloc(1, sizeof(struct TOKEN_S));
    token->type = type;
    token->value = value;

    return token;
}