#include "ListeDouble.h"

int main(){
    Liste l = newList();
    
    l = addListFirst(l, 1);
    l = addList(l, 0, 2);
    l = addListFirst(l, 3);
    l = removeList(l, 1);
    // Petit print
    printf("[");
    for(size_t i = 0; i < longueur(l);i++){
        printf(" %d",accessList(l,i));
    }
    printf("]\n");

    return 0;
}
