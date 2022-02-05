#include "sapin.h"
#include <stdio.h>
void n_espace(int n){
	for(;n > 0;n--)
		putchar(' ');
}

void n_etoile(int n){
	for(;n > 0;n--)
		putchar('*');
}

void n_char(int n,char c){
	for(;n > 0;n--)
		putchar(c);
}

void sapin(int n)
{
	int a = n;
	for(;n>0;n--)
	{
		n_espace(n-1);
		n_etoile(2*a-2*n+1);
		putchar('\n');
	}
}