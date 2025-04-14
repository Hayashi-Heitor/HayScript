#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"

int main (int argc, char* argv[]) {

    lexer_t *lexer = lexerInit(
        "var name = \"Teste\";\n"
       "print(name);\n"
    );

    parser_t *parser = parserInit(lexer);
    ast_t *root = parserParse(parser);
    printf("%d\n", root->type);
    printf("%d\n", root->compoundSize);
}