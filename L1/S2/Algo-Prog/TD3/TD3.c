#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void remplir(float tab[],int size)
{
	for(int i = 0;i < size;i++)
	{
		printf("%d ème valeur : ",i);
		scanf("%f",&tab[i]);
	}
}

void afficher(float tab[],int size)
{
	for(int i = 0; i < size;i++)
		printf("%f \t",tab[i]);
	printf("\n");
}

int comparer(int tab[],int tab2[],int size)
{
	int fin = 0;
	for(int i = 0;i < size;i++)
		if (tab[i] == tab2[i])
			fin = 1;
	return fin;
}

int decompte(int tab[],int size,int elem)
{
	int compteur = 0;
	for(int i = 0;i < size;i++)
		if (tab[i] == elem)
				compteur++;
	return compteur;
	
}

int maximum(int tab[],int size)
{
	int max = tab[0];
	for(int i = 0;i < size;i++)
		if (tab[i] > max)
			max = tab[i];
	return max;
}

int indiceMaximum(int tab[],int size)
{
	int max = 0;
	for(int i = 0;i < size;i++)
		if (tab[i] > max)
			max = i;
	return max;
}

<<<<<<< HEAD
 int copie(int tab[]);	
=======
bool EstSousChaine(char* chaine,char* sousChaine)
{
	int lenChaine = strlen(chaine)
	int lenSousChaine = strlen(chaine)
	for(int i = 0;)
}	
>>>>>>> 1c7685be3fb4a7c0a877584f209956ca3f6eff3a

int main(void)
{
	return 0;
}