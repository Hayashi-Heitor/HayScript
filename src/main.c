#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"

int main (int argc, char* argv[]) {

    lexer_t *lexer = lexerInit(
        "var name = \"teste  \";\n"
        "var otherName = \"  Julia\";\n"
       "print(name, otherName);\n"
    );

    parser_t *parser = parserInit(lexer);
    ast_t *root = parserParse(parser);
    visitor_t *visitor = visitorInit();
    visitorVisit(visitor, root);
}