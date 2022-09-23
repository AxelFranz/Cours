#include "TD1.h"

void new_stock1(stock1 s) {
    for(i = 0 ; i < N ; i++) {
        s[i].ref = 0;
        s[i].q = 0;
    }
}

/* nouvelle référence, ajoute une référence et sa quantité, s'il y a de la place */
void new_ref1(stock1 s, Nat r, Nat q) {
    for(i = 0 ; i < N && s[i].ref != 0 ; i++);
    // si on est pas à la fin, ou, si on est a la fin mais que la dernière case est libre
    if(i < N - 1 || s[i].ref == 0) { 
        s[i].ref = r;
        s[i].q = q;
    } 
}

/* teste l'existence de la référence en argument */
bool exist_ref1(stock1 s, Nat r) {
    for(i = 0 ; i < N && s[i].ref != r ; i++);
    if(s[i].ref == r) { return true; } else { return false; }
}

/* met à jour la quantité d'une référence */
void reajust_quantite(stock1 s, Nat r, Nat q) {
    // on s'arrete si fin, ou si 0, ou si trouvé...
    for(i = 0 ; i < N && s[i].ref != 0 && s[i].ref != r ; i++);
    if(s[i].ref == r) { s[i].q = q; }
}

/* affiche le stock à l'écran */
void afficher_stock1(stock1 s) {
    for(i = 0 ; i < N && s[i].ref != 0 ; i++) {
        if(s[i].ref > 0) {
            printf("(id=%d) reference : %d , quantité : %d\n", i, s[i].ref, s[i].q);
        }
    }
}

int main(int argc, char** argv){
	printf("Coucou\n");
	return 0;
}