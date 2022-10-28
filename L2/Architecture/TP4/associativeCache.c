#include "associativeCache.h"
#include <time.h>

struct ACache * ACache_Create (int taille, int nbTable){
  ///à compléter
  return NULL;
}

void ACache_Delete (struct ACache * c){
  ///à compléter
  return;
}

void ACache_Disp(struct ACache *c){
  if (c==NULL) return;
  for (int i=0; i<c->nbTable; i++) {
    printf("###################### Table: %d ##########################\n", i);
    DCache_Disp(c->DTable[i]);
  }
  return;
}

int setACache(int adresse, int mot, struct ACache *c){
  ///à compléter
  return -1;
}

int lwAC(int *registre, int adresse, struct ACache *c){
  ///à compléter
  return -1;
}
