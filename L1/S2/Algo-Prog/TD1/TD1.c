#include <stdio.h>


/* Spécifier une fonction
nom = 
role = 
paramètre =
sortie = 
préconditions = 
*/




int a_la_suite(int a,int b,int c);

void l_suite()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int res = a_la_suite(a,b,c);
	if(res)
		printf("Ils se suivent");
	else;
		printf("Ils ne se suivent pas");

}

float solveur_premier(float a,float b, float c)
{
	return (c-b)/a;
}

int main()
{
	l_suite();
	return 0;
}


