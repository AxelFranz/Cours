#include <stdio.h>
#include <stdlib.h>
#include "directCache.h"

void testAdresse(){
	int tab[2][3];
	for(int i = 0; i < 2; i++){
		printf("Ligne numero : %d\n",i);
		for(int j = 0; j < 3; j++){
			printf("     %d : %p\n",j,&tab[i][j]);
		}
	}
}

void temps1(){
	int tab[1024][1024];
	for(int i = 0; i < 1024;i++){
		for(int j = 0;j < 1024;j++){
			tab[i][j] = 0; 
		}
	}
}
void temps2(){
	int tab[1024][1024];
	for(int i = 0; i < 1024;i++){
		for(int j = 0;j < 1024;j++){
			tab[j][i] = 0; 
		}
	}
}

int main(void) {
	struct DCache a;
	a.taille=4;
	a.table->word=4;
	return 0;
}