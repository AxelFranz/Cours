#include <stdio.h>

int main () {
  int a = 2, b= 3;
  printf("a = %d et b= %d\n",a,b);
  b=a;
  a=b;
  printf("a = %d et b= %d\n",a,b);
  return 0;
}
