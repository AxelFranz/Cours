#include "stock.h"

int main(){
    stock test = creer_stock();
    test = new_ref(test,3,5);
    Affiche(test);
    printf("%d",nb_ref(test));
    return 0;
}
