/**
 * @file liste.h
 * @brief Header contenant les définitions de fonctions de liste.c
 */

#ifndef LISTE_H
#define LISTE_H

/**
 * @struct Maillon liste.h
 * @brief Maillon avec précédent, suivant et contenu
 */
typedef struct maillon
{
	struct maillon* suivant; ///< Maillon suivant
	struct maillon* precedent; ///< Maillon précédent
	void* content;
} Maillon;

/**
 * @struct Liste liste.h
 * @brief Structure avec tête, queue et taille
 */
typedef struct liste
{
	Maillon* tete; ///< Tête de la liste
	Maillon* queue; ///< Queue de la liste
	int taille; ///< Taille de la liste
} Liste;

/**
 * @brief Création d'une liste
 * @return Pointeur vers la liste
 */
Liste* new_liste();

/**
 * @brief Libération de la liste
 * @param l La liste à libérer
 */
void free_liste(Liste* l);

/**
 * @brief Ajoute un élément à la fin de la liste
 * @param l Pointeur vers la liste
 * @param elt Pointeur vers un élément
 * @return Pointeur vers la liste
 */
Liste* push_liste(Liste* l, void* elt);


/**
 * @brief Enlève le dernier élément de la liste
 * @param l Pointeur vers une liste
 * @return Pointeurs vers la liste
 */
Liste* pop_liste(Liste* l);

/**
 * @brief Test d'appartenance
 * @param l Pointeur vers la liste
 * @param elt Pointeur vers l'élément à tester
 * @return 1 si dans la liste sinon 0
 */
int contain_liste(Liste* l, void* elt);

/**
 * @brief Taille de la liste
 * @param l Pointeur vers la liste
 * @return Taille de la liste
 */
int taille_liste(Liste* l);

#endif
