#include <stdlib.h>
#include <string.h>

char f(char *s, char *a, char *b, char *c, char *d);

char D[100];

int foo() {
  char A;
  char B[10];
  char *C = (char *)malloc(1);
  f("hello world\n", &A, B, C, D);
  strcpy(B, "dear sir.\n");
}

char f(char *s, char *a, char *b, char *c, char *d) {
  if (s[2] == a[2]) {
    return b[2];
  } else {
    return c[2] + d[2];
  }
}
