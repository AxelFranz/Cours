#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NMAX 500

int n_b (char *addr, int i) {
  char target_char = addr[i/8];
  return target_char >> i%8 & 0x1;
}

char d2c (int n){
  return (n<0 ? '?' : (n<10 ? '0'+n : (n<36 ? 'A' + (n-10) : '?')));
}

long long int P2(int n) {
  return 1 << n;
}

// Fonctions à compléter

// Exo 1
void base2(int n) {
  int tab[NMAX];
  int i;
  for(i = 0; n > 0;i++) {
    tab[i]=n%2; 
    n /= 2;
  }

  for(i--;i >= 0;i--) {
    printf("%d", tab[i]);
  }
  printf("\n");
}

// Exo 3
void baseB(int B, int n){
  char* tab = malloc(NMAX*sizeof(char));
  int i;
  for(i = 0;n > 0;i++) {
      tab[i] = d2c(n%B);
      n /= B;
  }
  for(i--;i >= 0;i--) {
    printf("%c", tab[i]);
  }
  printf("\n");
  free(tab);
  
}

// Exo 4
void mantisse(double f, int* result) {
    int i = 0;
    while(f != 1.000000){
      if(i > 23){
        fprintf(stderr,"Nombre non représentable\n");
        exit(0);
      }
      f = fmod(f,1.0);
      if(2 * f >= 1.0){
        result[i] = 1;
      } else {
        result[i] = 0;
      }
      f*=2;
      i++;
      printf("%lf\n",f);
    }

}

float mantisseNormalisee(float f){
  return 0.f;
}

void exposant(float f, int result[]) {
}

int exposantSansExces(float f) {
  return 0;
}

int signe(float f) {
  return 0;
}

int main(){
  int result[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  mantisse(5.278,result);
  for(int i = 0; i < 24;i++)
  {
    printf("%d ",result[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
