#ifdef LEXER_H
#define LEXER_H
typedef struct lexer_s
{
   char ascii
   unsigned int index;
   char *content;
} lexer_t;

lexer_t *lexer_init(char *content);

void lexer_advance(lexer_t *lexer);

void lexer_skip_whitespace(lexer_t *lexer);
#endif
