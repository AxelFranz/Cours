/*
sup1 Liste -> S -> Liste: supprime première occurence d'un élément :
	- sup1(listenouv,x) = listenouv
	- sup1(adjt(l,x),y) = si x == y l sinon adjt(sup1(l,y),x)
chg1 Liste -> S -> S -> Liste : remplace premiere occurence d'unélément : 
	- chg1(listenouv,x,y) = listenouv
	- chg(adjt(l,x),y,z) = si x == y adjt(l,z) sinon adjt(chg1(l,y,z),x)
rech1(l,x) Liste S -> Ent : première occuprence d'un élément :
	-rech1(listenouv,x) = -1
	- rech1(adjt(l,x),y) = si x == y 0 sinon sinon si rech1(l,y) == 1 sinon 1 + rech1(l,y)
rech2(l,x) Liste S -> Liste: liste commençant à la première occurence d'un élément : 
	- rech2(listenouv,x) = listenouv
	- rech2(adjt(l,x),y) = si x == y adjt(l,x) sinon rech2(l,y)

*/

#include "/home/axel/Cours/L2/SDA/base.h"

typedef int S;
typedef struct strliste {
	S v;
	struct strliste *s;
} StrListe, *Liste;

Liste liste_vide(){
	return NULL;
}

Liste ajout_tete(Liste l, int v){
	Liste l2 = MALLOC(StrListe);
	if(l2 == NULL){
		fprintf(stderr,"Erreur malloc\n");
		exit(1);
	}
	l2->v = v;
	l2->s=l;
	return l2;
}

bool est_vide(Liste l){
	return l == NULL;
}

S tete(Liste l){
	return l->v;
}

int longueur(Liste l){
	int v = 0;
	while(l->s != NULL){
		v+=1;
		l = l->s;
	}
	return v;
}

Liste suppression_tete(Liste l){
	Liste l2 = l->s;
	FREE(l);
	return l2;
}

int main(){
	return 0;
}