#include <stdio.h>

void f(int x) {
  x=x+1;
}

int main () {
  int x = 3;
  printf("%d\n",x);
  f(x);
  printf("%d\n",x);
  return 0;
}
