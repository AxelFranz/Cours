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



int main(void)
{
}