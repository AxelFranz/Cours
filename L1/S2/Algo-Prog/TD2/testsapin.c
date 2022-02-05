#include <stdio.h>
#include "sapin.h"

int main(){
	int hs;
	printf("Quelle hauteur voulez vous ? ");
	scanf("%d",&hs);
	sapin(hs);
	putchar('\n');
}