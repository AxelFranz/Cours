#define PL_BLOC 128
#include <stdlib.h>
#include <stdio.h>
/* -------------------------- */
typedef struct{
	float *tab;
	int size;
	int alloc;
} plist;
/* -------------------------- */

plist pl_empty()
{
	plist pl;
	pl.tab = (float *) malloc(PL_BLOC*sizeof(float));
}
plist pl_ins(float x,plist l,int i)
{
	if(i>l.size || i < 0)
	{
		printf("en dehors : taille : %d et index : %d",l.size,i);
		exit(1);
	}
	if(l.size==l.alloc)
	{
		l.tab = (float*) realloc(l.tab,(l.alloc.PL_BLOC)*sizeof(float))
		l.alloc += PL_BLOC;
	}
	for(int j = l.size;j>i;j++)
		l.tab[j] = l.tab[j-1]
	l.tab[i] = x;
	l.size++;return l;
}
plist pl_des(plist l,int i);

void pl_print(plist l)
{
	for(int i = 0;i < l.size;i++)
		printf("%f\n",*(l.tab+1));
}

int main(void)
{
	printf("%d\n",sizeof(plist));
	return 0;
}