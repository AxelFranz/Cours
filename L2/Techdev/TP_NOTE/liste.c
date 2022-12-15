/**
 * @file liste.c
 * @brief Définition des fonctions de liste.h
 */
#include "liste.h"
#include <stdlib.h>
Liste* new_liste()
{
	Liste* result = (Liste*)malloc(sizeof(Liste));
	result->tete = NULL;
	result->queue = NULL;
	result->taille = 0;

	return result;
}

void free_liste(Liste* liste)
{
	Maillon* elt = liste->tete;
	while(elt != NULL)
	{
		liste->tete = elt->suivant;
		free(elt);
		elt = liste->tete;
	}

	free(liste);
}

Liste* push_liste(Liste* liste, void* elt)
{
	Maillon* new_elt = malloc(sizeof(Maillon));
	new_elt->content = elt;
	new_elt->suivant = NULL;
	new_elt->precedent = liste->queue;
	if (liste->queue != NULL)
	{
		liste->queue->suivant = new_elt;
	}
	
	liste->queue = new_elt;
	if (liste->tete==NULL)
	{
		liste->tete = new_elt;
	}
    liste->taille++;
    return liste;
}

Liste* pop_liste(Liste* liste)
{
	if (liste->taille == 0)
	{
		return liste;
	}

	Maillon* queue = liste->queue;
	liste->queue = queue->precedent;
	
	if (liste->taille == 1)
	{
		liste->tete = NULL;
	}
	
	if (liste->taille > 1)
	{
        queue->precedent->suivant = NULL;
	}
    liste->taille--;
    return liste;
}

int contain_liste(Liste* liste, void* elt)
{
	if (liste->taille == 0)
	{
		return(0);
	}

	Maillon* current_elt = liste->tete;
	for (int i=0; i<liste->taille; i++)
	{
		if (current_elt->content == elt)
		{
			return(1);
		}
		current_elt = current_elt->suivant;
	}
	
	return(0);
}

int taille_liste(Liste* l){
    return l->taille;
}
