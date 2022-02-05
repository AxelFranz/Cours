#include <stdio.h>
#include <math.h>

int jourdansmois(int n)
{
	if(n==1 || n ==3 || n == 5 || n== 7 || n == 8 || n == 10 || n == 12)
		return 31;
	else if (n == 2)
		return 29;
	else
		return 30;
}


void exo2()
{
	float cote;
	printf("Quel est la longueur du côté : ");
	scanf("%f",&cote);
	printf("Le périmètre de ce carré est de %f et sa diagonale vaut %f\n",4*cote,sqrt(2*cote*cote));
}

void exo3()
{
	int mois;
	printf("Tu veux le combientième mois de l'année  : ");
	scanf("%d",&mois);
	int nbrjour = jourdansmois(mois);
	printf("Il y a %d jours dans ce mois ci\n",nbrjour);
}

int main()
{
	exo3();
	return 0;
}