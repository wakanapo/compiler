#pragma once
#include <stdio.h>


typedef enum {
  TOK_BREAK,
  TOK_CONTINUE,
  TOK_ELSE,
  TOK_IF,
  TOK_INT,
  TOK_RETURN,
  TOK_WHILE,
  TOK_FOR,
  TOK_INT_LITERAL,
  TOK_ID,
  TOK_LPAREN,  // (
  TOK_RPAREN,  // )
  TOK_LBRACE,  // {
  TOK_RBRACE,  // }
  TOK_PLUS,
  TOK_MINUS,
  TOK_MUL,
  TOK_DIV,
  TOK_LOGNEG,  // !
  TOK_REM,  // %
  TOK_LT,  // <
  TOK_GT,  // >
  TOK_LE,  // <=
  TOK_GE,  // >=
  TOK_EQ,  // ==
  TOK_NEQ,  // !=
  TOK_SEMICOLON,  // ;
  TOK_ASSIGN, // =
  TOK_COMMA,  // ,
  TOK_EOF,
 } token_kind_t;

typedef struct token
{
  token_kind_t kind;
  int ival;
  char cval[20];
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
