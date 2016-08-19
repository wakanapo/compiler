#pragma once
#include <stdio.h>


typedef enum {
  tok_int,
  tok_newline,
  tok_plus,
  tok_eof
} token_kind_t;

typedef struct token
{
  token_kind_t kind;
  int ival;
} token;

typedef struct tokenizer
{
  token tok;     /* 最後に読んだ字句 */
  int c;
  int line;
  int word;
  char str[50];
  FILE *fp;
} * tokenizer_t;

void syntax_error(tokenizer_t t);
tokenizer_t mk_tokenizer(char * filename);
token cur_tok(tokenizer_t t);
token next_tok(tokenizer_t t);
