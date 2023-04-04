#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef unsigned int Nat;

typedef struct s_vecteur{
    float *val; // Sous tableau de 10 valeurs
    Nat nb_nonnulles; // nombre de valeurs non nulles
    struct s_vecteur *suiv; // Pour chainer avec le tableau suivant
}Vec, *vecteur;

vecteur vecnouv(){
    vecteur ar = (vecteur)malloc(sizeof(Vec)); vecteur v = ar;
    v->nb_nonnulles=0;
    v->val=NULL;
    for(size_t i = 0; i < 4; i++){
        v->suiv = malloc(sizeof(Vec));
        v->suiv->val=NULL;
        v->suiv->nb_nonnulles=0;
        v = v->suiv;
    }
    return ar;
}

void set(vecteur v, Nat i, float x){
    for(size_t j = 0; j < (i/10); j++) v = v->suiv;
    if(!v->val){
        v->val=calloc(10,10*sizeof(float));
        v->nb_nonnulles++;
    }
    v->val[i%10]=x;
}

float get(vecteur v, Nat i){
    for(size_t j = 0; j < (i/10); j++) v = v->suiv;
    if(!v->nb_nonnulles) return 0;
    return v->val[i%10];
}

vecteur addvec(vecteur v, vecteur w){
    vecteur ar = vecnouv();
    for(size_t i = 0; i < 50; i++){
        set(ar,i,get(v,i)+get(w,i));
    }
    return ar;
}

Nat nZeros(vecteur v){
    size_t nbZeros = 50;
    while(v){
        nbZeros -= v->nb_nonnulles;
        v=v->suiv;
    }
    return nbZeros;
}



int main(void){
    vecteur v = vecnouv();
    set(v, 3, 9.0);
    set(v, 12, -1.0);
    vecteur v2 = addvec(v,v);
    printf("12 : %f\n", get(v2,12));
    return 0;
}
