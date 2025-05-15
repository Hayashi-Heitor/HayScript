#include "include/token.h"
#include <stdlib.h>

// Initializes the token with type and value
token_t *tokenInit(int type, char *value) {
    token_t *token = calloc(1, sizeof(struct TOKEN_S));
    token->type = type;
    token->value = value;

    return token;
}