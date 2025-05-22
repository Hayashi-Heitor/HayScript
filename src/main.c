#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"
#include "include/io.h"

void help() {
    printf("Usage: test.out <filename>\n");
    exit(1);
}

int main (int argc, char* argv[]) {

    if (argc < 2)
        help();
    
    lexer_t *lexer = lexerInit(getFileContents(argv[1]));

    parser_t *parser = parserInit(lexer);
    ast_t *root = parserParse(parser);
    visitor_t *visitor = visitorInit();
    visitorVisit(visitor, root);
}