#ifndef LISTE_H
#define LISTE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_node{
    void *val;
    struct s_node *suiv, *prec;
} *listeg;

listeg adjtete(listeg lst, void *x, void * (*clone)(void *x));
listeg adjqueue(listeg lst, void *x, void * (*clone)(void *x));
listeg suptete(listeg lst, void (*det)(void *x));
void *tete(listeg lst);
int longueur(listeg lst);
bool estvide(listeg lst);
void detruire(listeg lst, void (*det)(void *x));
void affichage(listeg lst, void (*affiche)(void *x));

#endif //LISTE_H
