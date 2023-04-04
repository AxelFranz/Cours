#include "liste.h"

listeg adjtete(listeg lst, void *x, void * (*clone)(void *x)){
    listeg n = (listeg)malloc(sizeof(struct s_node));
    n->prec=NULL;
    n->suiv=lst;
    n->val=clone(x);
    if(lst != NULL) lst->prec=n;
    return n;
}

listeg adjqueue(listeg lst, void *x, void * (*clone)(void *x)){
    if(lst == NULL) adjtete(lst,x,clone);
    listeg new = (listeg)malloc(sizeof(struct s_node));
    new->val = clone(x);
    listeg tmp = lst;
    for(;tmp->suiv != NULL;tmp=tmp->suiv);
    tmp->suiv=new;
    new->prec = tmp;
    return lst;
}

listeg suptete(listeg lst, void (*det)(void *x)){
    if(lst == NULL) return lst;
    listeg n = lst->suiv;
    det(lst->val);
    free(lst);
    if(n!=NULL) n->prec = NULL;
    return n;
}

void *tete(listeg lst){

}

int longueur(listeg lst){

}

bool estvide(listeg lst){

}

void detruire(listeg lst, void (*det)(void *x)){

}

void affichage(listeg lst, void (*affiche)(void *x)){

}



int main(){
    return 0;
}
