#include <stdio.h>

int pointer() {
  int a[10];
  a[0] = 123;
  int *p = a;
  printf("%d\n", p);
}
