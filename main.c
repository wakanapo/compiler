#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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
  FILE *fp;
} * tokenizer_t;

token next_tok(tokenizer_t t);

void syntax_error(tokenizer_t t) {
  printf("%c is syntax error\n", t->c);
}

tokenizer_t mk_tokenizer(char * filename)
{
  tokenizer_t t = (tokenizer_t)malloc(sizeof(struct tokenizer));
  t->fp = fopen(filename, "rb");
  if (t->fp == NULL) {
    perror("fopen");
    exit(1);
  }  
  t->c = fgetc(t->fp);
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
  while (t->c == ' ')
    t->c = fgetc(t->fp);
  if (t->c == '+') {
    t->tok.kind = tok_plus;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '\n') {
    t->tok.kind = tok_newline;
     t->c = fgetc(t->fp);
  }
  else if (t->c == EOF) {
    t->tok.kind = tok_eof;
  }
  else if (isdigit(t->c)) {
    while (isdigit(t->c)) {
      if (i == 9) syntax_error(t);
      digit[i] = t->c;
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

/* 現在の字句が 数 でなければエラー.
   OKなら次の字句を読んだ上でその数を返す. */
int eat_int(tokenizer_t t)
{
  token tok = cur_tok(t);
  if (tok.kind != tok_int) syntax_error(t);
  next_tok(t);
  return tok.ival;
}

/* 現在の字句が + でなければエラー.
   OKなら次の字句読む. */
void eat_plus(tokenizer_t t)
{
  token tok = cur_tok(t);
  if (tok.kind != tok_plus) syntax_error(t);
  next_tok(t);
}

int main(int argc, char ** argv)
{
  tokenizer_t t = mk_tokenizer(argv[1]);
  while (cur_tok(t).kind != tok_eof) {	/* EOFまで */
    int x = eat_int(t);			/* 数を読む. 違ったエラー */
    while (cur_tok(t).kind != tok_newline) { /* 改行まで ... */
      eat_plus(t);		/* +を読む. 違ったエラー */
      int y = eat_int(t);	/* 数を読む. 違ったエラー */
      x = x + y;
    }
    next_tok(t);
    printf("%d\n", x);
  }
  return 0;
}

