#ifndef BASE_H
#define BASE_H
#include "/home/axel/Cours/L2/SDA/base.h"
#endif

#ifndef IO
#define IO
#include <stdio.h>
#endif



#ifndef pilec
#define pilec
#define MAX_P 50
typedef struct spile {
    char v;
    struct spile *s; 
}Spile, *Pile;

Pile pilenouv();               // Fait
Pile empiler(Pile p, char S);  // A faire
Pile depiler(Pile p);          // A faire
Pile remplacer(Pile p, char S);// A faire
char sommet(Pile p);           // A faire
bool vide(Pile p);             // A faire
Nat hauteur(Pile p);           // A faire
void printPile(Pile p);        // A faire

#endif 