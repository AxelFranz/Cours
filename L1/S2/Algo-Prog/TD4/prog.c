#include <stdio.h>
#ifndef M_PI
#define M_PI 3.14159
#endif 

void incremente(int* p)
{
	*(p)++; 
}

void echange(int* a,int* b)
{
	int temp = *a;
	*a=*b;
	*b=temp; 
}

void disque(float rayon, float* diametre, float* perimetre,float* surface)
{
	*diametre=2*rayon;
	*perimetre=2*rayon*M_PI;
	*surface = M_PI*rayon*rayon;
}

typedef struct
{
	float re;
	float im;
}complexe;

complexe* new_complexe(float r,float i)
{
	complexe* c = (complexe*)malloc(sizeof(complexe));
	c->re=r;
	c->im=i;
	return c;
}

void print_complexe(complexe* c)
{
	printf("%g + %g*i",c->re,c->im);
}



int main(void)
{
	return 0;
}