#ifndef STOCK1
#define STOCK1
#define N 1000

#include <stdio.h>
#include <stdlib.h>
#include "base.h"
typedef struct produit {
	Nat ref;
	Nat q;
} produit;

typedef produit stock1[N];
typedef produit* stock2
/* écrire les fonctions : */
void new_stock1(stock1 s1);
void new_ref1(stock1 s, Nat r, Nat q);
bool exist_ref1(stock1 s, Nat r);
void reajust_quantite(stock1 s, Nat r, Nat q);
void afficher_stock1(stock1 s);

#endif