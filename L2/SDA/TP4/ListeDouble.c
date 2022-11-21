#include "ListeDouble.h"

Liste newList(){
    return NULL;
}

bool isEmpty(Liste l){
    return l==NULL;
}

char accessList(Liste l, int indice){
    Liste l1 = l; 
    for(int i = 0; i < indice;i++){
        l1 = l1->s;
    }
    return l1->v;
}

char accessFirst(Liste l){
    return accessList(l,0);
}

Liste addList(Liste l, int indice, char a_aj){
    if(l == NULL){
        l = MALLOC(StrListe);
        l->v=a_aj;
        l->s = l;
        l->p = l;
        return l;
    }
    for(int i = 0;i < indice;i++){
        l=l->s;
    }
    Liste l1 = MALLOC(StrListe);
    l1->v=a_aj;
    l1->s=l->s;
    l1->p=l;
    l->s=l1; // :D
    l=l1; // :D
    return l;
}

Liste removeList(Liste l, int indice){
    Liste l1 = l;
    for(size_t i = 0; i < indice;i++){
        l=l->s;
    }
    l->p->s=l->s;
    l->s->p=l->p;
    free(l);
    return l1;
}

size_t longueur(Liste l){
    if(l == NULL) return 0;
    Liste l1 = l->s;
    size_t i = 1;
    while(l != l1){
        l1=l1->s;
        i++;
    }
    return i;
}

Liste addListFirst(Liste l, char a_aj){
    return addList(l,0,a_aj);
}
