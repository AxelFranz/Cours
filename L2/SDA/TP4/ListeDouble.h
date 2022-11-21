#include "base.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef LISTEDOUBLE_H
#define LISTEDOUBLE_H

typedef struct sldc{
    char v;
    struct sldc *s;
    struct sldc *p;
} StrListe, *Liste;

Liste newList();
bool isEmpty(Liste l); // A faire
char accessList(Liste l, int indice); // A faire
char accessFirst(Liste l);
Liste addList(Liste l, int indice, char a_aj);
Liste addListFirst(Liste l, char a_aj);
bool isIn(Liste l, char test);
size_t longueur(Liste l);
Liste removeList(Liste l, int indice);
Liste removeListFirst(Liste l);

#endif
