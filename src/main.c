#include <stdio.h>
#include "include/lexer.h"

int main (int argc, char* argv[]) {

    lexer_t *lexer = lexerInit(
        "var name = \"Teste\";\n"
       "print(name);\n"
    );

    token_t *token = (void*)0;

    while ((token = lexerGetNextToken(lexer)) != (void*)0)
        printf("TOKEN(%d, %s)\n", token->type, token->value);

    return 0;
}