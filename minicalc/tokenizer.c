#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"

void syntax_error(tokenizer_t t) {
  int i;
  char ch = t->c;
  printf("syntax error:%d:%d\n", t->line, t->word);
  for (i = 0; i < t->word; i++)
    printf("%c", t->str[i]);
  while (ch != '\n') {
    printf("%c", ch);
    ch = fgetc(t->fp);
  }
  printf("\n");
  for (i = 0; i < t->word - 1; i++)
    printf(" ");
  printf("^\n");
  exit(1);
}

tokenizer_t mk_tokenizer(char * filename)
{
  tokenizer_t t = (tokenizer_t)malloc(sizeof(struct tokenizer));
  t->fp = fopen(filename, "rb");
  if (t->fp == NULL) {
    perror("fopen");
    exit(1);
  }
  t->line = 1;
  t->word = 1;
  t->c = fgetc(t->fp);
  t->str[t->word - 1] = t->c;
  t->tok = next_tok(t);
  return t;
}

token cur_tok(tokenizer_t t)
{
  return t->tok;
}

token next_tok(tokenizer_t t)
{
  char digit[10];
  int i = 0;
  while (t->c == ' ') {
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  if (t->c == '+') {
    t->tok.kind = tok_plus;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '\n') {
    t->tok.kind = tok_newline;
    t->line++;
    t->word = 0;
    t->c = fgetc(t->fp);
  }
  else if (t->c == EOF) {
    t->tok.kind = tok_eof;
  }
  else if (isdigit(t->c)) {
    while (isdigit(t->c)) {
      if (i == 9) syntax_error(t);
      digit[i] = t->c;
      t->word++;
      t->str[t->word - 1] = t->c;
      t->c = fgetc(t->fp);
      i++;
    }
    assert(i < 10);
    digit[i] = 0;
    t->tok.kind = tok_int;
    t->tok.ival = atoi(digit);
  }
  else syntax_error(t);
  return t->tok;
}
