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

_[_] : Liste -> Nat -> S : Renvoie le ième élément 
	- listenouv[x] =  NULL;
	- adjt(l,x)[y] = if x == y then 0 else 1+l[y]

lid : Liste -> Nat -> Liste : Sous liste déboutant au ième élément
	- lid(listenouv,x) = listenouv
	- lid(adjt(l,x),i-1) = if i == 0 then adjt(l,x) else lid(l,i-1)

sup : Liste-> Nat -> Liste : Insère à la ième position
	- lid(listenouv, x,y) =  

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

Liste sup1(Liste l, int s){
	if(l == NULL)
		return l;
	if(l->v == s){
		return l->s;
	}else{
		return sup1(l->s,s);
	}
}

Liste chg1(Liste l, int s1, int s2){
	if(l==NULL)
		return NULL;
	if(l->v == s1){
		l->v == s2;
		return l;
	} else {
		l->s = chg1(l->s,s1,s2);
		return l;
	}
}

int rech1(Liste l, S x){
	int i = 0;
	while(!est_vide(l)){
		if(l->v==x){
			return i;
		}
		i++;
		l=l->s;
	}
	return -1;
}

Liste rech2(Liste l, S x){
	while(l != NULL){
		if(l->v == x)
			return l;
		l = l->s;
	}
	return l;
}

S acces(Liste l, int i){
	int i2=0;
	while(i2 != i){
		l = l->s;
		i2++;
	}
	return l->v;
}

Liste lid(Liste l, int i){
	int i2=0;
	while(i2 != i){
		l = l->s;
		i2++;
	}
	return l;
}

int main(){
	return 0;
}