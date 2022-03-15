#include <stdio.h>
#define MAX 128
#include <string.h>
#include <stdlib.h>
typedef struct 
{
	char nom[MAX];
	char adresse[MAX];
	int tel;
	char email[MAX];
}personne;

typedef struct
{
	personne tab[MAX];
	int size;
}carnet;

void print_carnet(carnet agenda)
{
	if(agenda.size == 0)
		printf("Le carnet est vide");
	printf("Le carnet a %d elements",agenda.size);
	for(int i = 0;i < agenda.size;i++)
	{
		printf("%d : %s ",i+1,agenda.tab[i].nom);
	}
	printf("\n");
}

void inserer_elem(carnet* agenda,personne elem)
{
	personne temp;
	for(int i = 0;i < agenda->size-1;i++)
	{
		temp = agenda->tab[i+1];
		agenda->tab[i+1]=agenda->tab[i];
	}
	agenda->tab[0] = elem;
	agenda->size++;
}

void supprimer_elem(carnet* agenda)
{
	int a_delete;
	print_carnet(*agenda);
	printf("\nChoisissez le numéro de la personne a supprimer : ");
	scanf("%d",&a_delete);
	a_delete--;
	for(int i = a_delete;i < agenda->size-1;i++)
	{
		agenda->tab[i]=agenda->tab[i+1];
	}
	agenda->size--;
}

void ajout_personne(carnet* agenda)
{
	char nom[MAX],adresse[MAX],email[MAX];
	int tel;
	personne add;
	printf("Entrez le nom de la personne : ");
	scanf("%s",nom);
	printf("Entrez l'adresse de la personne (avec des _ entre chaque mot) : ") ;
	scanf("%s",adresse);
	printf("Entrez le numero de telephone de la personne : ");
	scanf("%d",&tel);
	printf("Entrez l'email de la personne : ");
	scanf("%s",email);
	strcpy(add.adresse,adresse);
	strcpy(add.nom,nom);
	add.tel=tel;
	strcpy(add.email,email);
	inserer_elem(agenda,add);
}

void print_personne(carnet agenda)
{
	int n;
	printf("\n\nIl y a actuellement %d personnes dans l'agenda",agenda.size);
	printf("\nChoisissez le numéro de la personne a afficher : ");
	scanf("%d",&n);
	n--;
	if(n >= agenda.size)
	{
		printf("Veuillez choisir un numero de personne valide");
		exit(0);
	}
	printf("\nNom : %s,email : %s, numero de telephone : %d, adresse : %s\n",agenda.tab[n].nom,agenda.tab[n].email,agenda.tab[n].tel,agenda.tab[n].adresse);

}

int main(void)
{
	carnet agenda;
	agenda.size= 0;
	ajout_personne(&agenda);
	print_personne(agenda);
	supprimer_elem(&agenda);
	print_carnet(agenda);

	return 0;
}