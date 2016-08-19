int fact(int n) {
  int f = 1;
  int i = 1;
  while (i <= n) {
    f = f * i;
    i++;
  }
  return f;
}
