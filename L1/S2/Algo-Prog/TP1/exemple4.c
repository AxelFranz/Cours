#include <stdio.h>

int main () {
  int i; // déclaration d'une variable sans initialisation
  printf("Entrez un entier au clavier : "); // affichage 
  scanf("%d",&i); // lecture de l'entrée clavier
  printf("l'entier entré vaut %d\n",i); // affichage
  return 0; // retour (toujours en fin de fonction)
}
