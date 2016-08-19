#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"

char* get_kind_name(token_kind_t kind) {
  switch (kind) {
  case  TOK_BREAK: return "TOK_BREAK";
  case TOK_CONTINUE: return "TOK_CONTINUE";
  case TOK_ELSE: return "TOK_ELSE";
  case TOK_IF: return "TOK_IF";
  case TOK_INT: return "TOK_INT";
  case TOK_RETURN: return "TOK_RETURN";
  case TOK_WHILE: return "TOK_WHILE";
  case TOK_FOR: return "TOK_FOR";
  case TOK_INT_LITERAL: return "TOK_INT_LITERAL";
  case TOK_ID: return "TOK_ID";
  case TOK_LPAREN: return "TOK_LPAREN";
  case TOK_RPAREN: return "TOK_RPAREN";
  case TOK_LBRACE: return "TOK_LBRACE";
  case TOK_RBRACE: return "TOK_RBRACE";
  case TOK_PLUS: return "TOK_PLUS";
  case TOK_MINUS: return "TOK_MINUS";
  case TOK_MUL: return "TOK_MUL";
  case TOK_DIV: return "TOK_DIV";
  case TOK_LOGNEG: return "TOK_LOGNEG";
  case TOK_REM: return "TOK_REM";
  case TOK_LT: return "TOK_LT";
  case TOK_GT: return "TOK_GT";
  case TOK_LE: return "TOK_LE";
  case TOK_GE: return "TOK_GE";
  case TOK_EQ: return "TOK_EQ";
  case TOK_NEQ: return "TOK_NEQ";
  case TOK_SEMICOLON: return "TOK_SEMICOLON";
  case TOK_ASSIGN: return "TOK_ASSIGN";
  case TOK_COMMA: return "TOK_COMMA";
  case TOK_EOF: return "TOK_EOF";
      }
}

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
  char id[20];
  char str_int[] = "int";
  char str_break[] = "break";
  char str_continue[] = "continue";
  char str_else[] = "else";
  char str_if[] = "if";
  char str_return[] = "return";
  char str_while[] = "while";
  char str_for[] = "for";
  int i = 0;
  while (t->c == ' ') {
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  if (t->c == '+') {
    t->tok.kind = TOK_PLUS;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '-') {
     t->tok.kind = TOK_MINUS;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '*') {
     t->tok.kind = TOK_MUL;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '/') {
     t->tok.kind = TOK_DIV;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '(') {
    t->tok.kind = TOK_LPAREN;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == ')') {
    t->tok.kind = TOK_RPAREN;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '{') {
    t->tok.kind = TOK_LBRACE;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '}') {
    t->tok.kind = TOK_RBRACE;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
   else if (t->c == '!') {
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
    if (t->c == '=') {
      t->tok.kind = TOK_NEQ;
      t->word++;
      t->str[t->word - 1] = t->c;
      t->c = fgetc(t->fp);
    }
    else
      t->tok.kind = TOK_LOGNEG;
  }
  else if (t->c == '%') {
    t->tok.kind = TOK_REM;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
   else if (t->c == '<') {
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
    if (t->c == '=') {
      t->tok.kind = TOK_LE;
      t->word++;
      t->str[t->word - 1] = t->c;
      t->c = fgetc(t->fp);
    }
    else
      t->tok.kind = TOK_LT;
  }
  else if (t->c == '>') {
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
    if (t->c == '=') {
      t->tok.kind = TOK_GE;
      t->word++;
      t->str[t->word - 1] = t->c;
      t->c = fgetc(t->fp);
    }
    else
      t->tok.kind = TOK_GT;
  }
  else if (t->c == '=') {
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
    if (t->c == '=') {
      t->tok.kind = TOK_EQ;
      t->word++;
      t->str[t->word - 1] = t->c;
      t->c = fgetc(t->fp);
    }
    else
      t->tok.kind = TOK_ASSIGN;
  }
  else if (t->c == ';') {
    t->tok.kind = TOK_SEMICOLON;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == ',') {
    t->tok.kind = TOK_COMMA;
    t->word++;
    t->str[t->word - 1] = t->c;
    t->c = fgetc(t->fp);
  }
  else if (t->c == '\n') {
    t->line++;
    t->word = 0;
    t->c = fgetc(t->fp);
    return t->tok;
  }
  else if (t->c == EOF) {
    t->tok.kind = TOK_EOF;
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
    t->tok.kind = TOK_INT_LITERAL;
    t->tok.ival = atoi(digit);
  }
   else if ('a' <= t->c && t->c <= 'z') {
    while ('a' <= t->c && t->c <= 'z') {
      if (i == 19) syntax_error(t);
      id[i] = t->c;
      t->word++;
      t->str[t->word - 1] = t->c;
      t->c = fgetc(t->fp);
      i++;
    }
    assert(i < 20);
    id[i] = 0;
    if (strcmp(id, str_int) == 0)
      t->tok.kind = TOK_INT;
    else if (strcmp(id, str_break) == 0)
      t->tok.kind = TOK_BREAK;
    else if (strcmp(id, str_continue) == 0)
      t->tok.kind = TOK_CONTINUE;
    else if (strcmp(id, str_else) == 0)
      t->tok.kind = TOK_ELSE;
    else if (strcmp(id, str_if) == 0)
      t->tok.kind = TOK_IF;
    else if (strcmp(id, str_return) == 0)
      t->tok.kind = TOK_RETURN;
    else if (strcmp(id, str_while) == 0)
      t->tok.kind = TOK_WHILE;
    else if (strcmp(id, str_for) == 0)
      t->tok.kind = TOK_FOR;
    else {
      t->tok.kind = TOK_ID;
      strcpy(t->tok.cval, id); 
    }
  }
  else syntax_error(t);
  printf("%d:%s", t->line, get_kind_name(t->tok.kind));
  if (t->tok.kind == TOK_ID)
    printf("(%s)", t->tok.cval);
  else if (t->tok.kind == TOK_INT_LITERAL)
    printf("(%d)", t->tok.ival);
  printf("\n");
  return t->tok;
}
