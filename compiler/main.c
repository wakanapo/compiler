#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"


int main(int argc, char ** argv)
{
  tokenizer_t t = mk_tokenizer(argv[1]);
  while (cur_tok(t).kind != TOK_EOF) {	/* EOFまで */
    next_tok(t);
  }
  return 0;
}

