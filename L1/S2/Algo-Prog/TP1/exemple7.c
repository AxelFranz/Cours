#include <stdio.h>

int main () {
  int a = 2, b= 3;
  int tmp;
  printf("a = %d et b= %d\n",a,b);
  tmp = b;
  b=a;
  a=tmp;
  printf("a = %d et b= %d\n",a,b);
  return 0;
}
