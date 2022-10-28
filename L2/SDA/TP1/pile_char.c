#include "pile_char.h"

void printPile(Pile p){
	if(p.h==0){
		fprintf(stdout,"Pile vide\n");
	}
	int i = 0;
	while(i < p.h){
		fprintf(stdout,"%d : %c \n",i,p.tab[i]);
		i++;
	}
}

Pile pilenouv(){
	Pile a_r;
	a_r.h=0;
	return a_r;
}

Pile empiler(Pile p, char S){
	p.tab[p.h]=S;
	p.h++;
	return p;
}

Pile depiler(Pile p){
	p.h--;
	return p;
}

Pile remplacer(Pile p, char S){
	p.tab[p.h-1]=S;
	return p;
}

char sommet(Pile p){
	return p.tab[p.h-1];
}

Nat hauteur(Pile p){
	return p.h;
}

bool vide(Pile p){
	if(p.h==0)
		return true;
	return false;
}
