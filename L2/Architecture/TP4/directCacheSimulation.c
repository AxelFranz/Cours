#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "directCache.h"

int rand_Adresse(int inf, int supp){
  int interval = supp-inf;
  int adresse = (rand() % interval )+ inf;
  return adresse;
}


int main(int argc, char **argv){
 srand (time(NULL));
 ///à compléter
 return 0;
} 
