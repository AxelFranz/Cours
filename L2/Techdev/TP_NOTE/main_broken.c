/**
 * @file main_broken.c
 * @brief Fichier testant liste.h
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void) {
	
	Liste* l;
	printf("Création puis destruction d’une liste\n");
	l = new_liste();
	free_liste(l);
	
	printf("Ajout d’un élement\n");
	l = new_liste();
	push_liste(l,(void*)1);
    printf("%d\n\n", l->tete->content);
	free_liste(l);

	printf("Suppression d’un élement\n");
	l = new_liste();
	push_liste(l,(void*)1);
    printf("\nTaille avant suppression : %d",l->taille);
 	pop_liste(l);
    printf("\nTaille après suppression : %d\n",l->taille);
	free_liste(l);

	printf("\nVérification d'appartenance\n");
	l = new_liste();
	push_liste(l,(void*)1);
	if (contain_liste(l,(void*)1))
		printf("L'élément appartient à la liste\n");
	free_liste(l);

	return 0;
}


