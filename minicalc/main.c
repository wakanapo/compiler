#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"


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
    if (cur_tok(t).kind == tok_newline) {
      printf("\n");
      next_tok(t);
    }
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

