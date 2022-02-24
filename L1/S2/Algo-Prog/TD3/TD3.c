#include <stdlib.h>
#include <stdio.h>

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

int main(void)
{
	float tab[5];
	remplir(tab,5);
	afficher(tab,5);
	return 0;
}