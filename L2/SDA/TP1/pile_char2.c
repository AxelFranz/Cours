#include "pile_char2.h"

Pile pilenouv(){
	Pile p = malloc(sizeof(Spile));
	p->v='a';
	p->s=NULL;
	return p;
}
        
Pile empiler(Pile p, char S){
	Pile np = malloc(sizeof(Spile));
	np->v=S;
	np->s=p;
	return np;
}

Pile depiler(Pile p){
	p=p->s;
	return p;
}   

Pile remplacer(Pile p, char S){
	p->v=S;
	return p;
}
char sommet(Pile p){
	return p->v;
	return p;
}           
bool vide(Pile p);       
Nat hauteur(Pile p){
	Pile p = malloc(sizeof)
	while
}          
void printPile(Pile p);        