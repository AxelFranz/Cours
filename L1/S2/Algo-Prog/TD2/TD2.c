#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int r_factorielle(int n)
{
	if(n==1)
		return n;
	else
		return n*r_factorielle(n-1);
}


int i_factorielle(int n)
{
	int res = 1;
	for(int i = 1; i <= n; i++)
		res *= i;
	return res;
}

int r_fibonacci(int n)
{
	if(n<=1)
		return n;
	else
		return r_fibonacci(n-2)+r_fibonacci(n-1);
}

int pgcd(int a,int b)
{
	if(a!=0 && b==0)
		return abs(a);
	else
		return(pgcd(b,a%b));
}


int main() {
	printf("%d\n",pgcd(221,782));
    return 0;
}