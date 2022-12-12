#include "base.h"
#ifndef STOCK_H
#define STOCK_H

typedef Nat ref;

typedef struct marchd{
    ref r;
    Nat q;
    struct marchd* suivante;
}marchandise, *stock;

stock creer_stock();

stock new_ref(stock s, ref r, Nat q);

void Affiche(stock s);

Nat nb_ref(stock s);
/**/
/* Bool existe(stock s,Nat r); */
/**/
/* Nat quant_ref(stock s,Nat r); */
/**/
/* stock erase_ref(stock s,ref r); */
/**/
/* stock ajout_quantite(stock s, Nat r, Nat q); */
/**/
/* stock sup_quantite(stock s, Nat r, Nat q); */
/**/
/* stock reajust_quantite(stock s, Nat r, Nat q); */
/**/

#endif
