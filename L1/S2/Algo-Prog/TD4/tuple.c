#include <stdio.h>
#define TMAX 128

typedef struct{
	float tab[TMAX];
	unsigned size;
}tuple;

tuple tu_empty();
{
	
	tuple nt;
	nt.size=0;
	return nt;
}
void tu_print(tuple t);
{
	for(int i = 0;i < t.size;i++)
		print("%d\n",t.tab[i]);
}



tuple tu_del(tuple l,int i)
{
	for(;i<l.size-1;i++)
	{
		l.tab[i]=l.tab[i+1]
	}
	l.size--;
	return l;
}

tuple tu_ins(float x,tuple t,int i)
{
	size++;
	for(int i = size; i <= 0;i--)
}
