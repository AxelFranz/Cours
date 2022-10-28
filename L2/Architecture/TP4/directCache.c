#include "directCache.h"

struct DCache * DCache_Create (int taille) {
  struct DCache* newCache;
  newCache->taille=2;
  newCache->word->tag=0;
  return NULL;
}

void DCache_Delete (struct DCache * c) {
  ///à compléter
  return;
}

void DCache_Disp(struct DCache *c) {
 if (c==NULL) {
   printf ("Cache directe non initialisée: %p\n", c);
   return;
 }
 printf("Nombre de ligne: %d\n", (c->taille==0?0:(0x1<<c->taille)));
 if (c->table==NULL){
   printf ("Table non initialisée: %p\n", c->table);
   return;
 }
 int i;
 int T = (c->taille==0?0:(0x1<<c->taille));
 printf ("--------------------------------Table:------------------------------------\n");
 for (i=0;i<T;i++){
  printf ("Tag: %10d | Valid: %1d | Word:",c->table[i].tag, c->table[i].valid);
  afficheBits(c->table[i].word);
 }
 printf ("--------------------------------------------------------------------------\n");
 return;
}

int getOffset(int adresse, struct DCache *c){
  ///à compléter
  return -1;
}

int getIndex(int adresse, struct DCache *c){
  ///à compléter
  return -1;
}

int getTag(int adresse, struct DCache *c){
  ///à compléter
  return -1;
}

int setDCache(int adresse, int mot, struct DCache *c){
  ///à compléter
  return -1;
}

int lwDC (int *registre, int adresse, struct DCache *c){
  ///à compléter
  return -1;
}
