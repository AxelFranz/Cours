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
typedef struct {
    char tab[MAX_P];
    Nat h;
}Pile;

Pile pilenouv(); // Fait
Pile empiler(Pile p, char S); // Fait
Pile depiler(Pile p); // Fait
Pile remplacer(Pile p, char S); // Fait
char sommet(Pile p); // Fait
bool vide(Pile p); // Fait
Nat hauteur(Pile p); // Fait
void printPile(Pile p); // Fait

#endif 


