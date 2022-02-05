#include <stdio.h>
#include <stdlib.h>


int bissextile(int annee)
{
	if((annee%400==0)||(annee%4==0 && annee%100 != 0))
		return 1;
	else
		return 0; 	 	
}

int jourdansmois(int n,int annee)
{
	if(n==1 || n ==3 || n == 5 || n== 7 || n == 8 || n == 10 || n == 12)
		return 31;
	else if (n == 2)
			if(bissextile(annee))
				return 29;
			else
				return 28;
	else
		return 30;
}


void lendemain(int jour,int mois,int annee)
{
	if(jour == jourdansmois(mois,annee))
		if(mois == 12)
		{
			jour=1;
			mois=1;
			annee++;
		}
		else
		{
			jour=1;
			mois++;
		}
	else
		jour++;
	printf("La date du lendemain est %d/%d/%d\n",jour,mois,annee);

}

void test_annee()
{
	int annee;
	scanf("%d",&annee);
	printf("%d\n",bissextile(annee));
}

void test_lendemain()
{
	int jour,mois,annee;
	printf("Merci d'entrer la date sous la forme JOUR/MOIS/ANNEE : ");
	scanf("%d/%d/%d",&jour,&mois,&annee);
	lendemain(jour,mois,annee);
}

int main(void)
{
	printf("%d",bissextile(2000));
	test_lendemain();
	return 0;
}