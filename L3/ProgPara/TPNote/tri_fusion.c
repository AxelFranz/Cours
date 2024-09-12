#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>

#define N 10000000

// fonctions de vérification définies plus loin
void verif_init(int *);
int verif(int *);

// pour fusionner deux parties de tableau triées
//  en tab [deb..pos1-1] et tab [pos1..pos2-1]
// résultat en place dans tab. Utilise tmp (mêmes indices):
int tmp[N];
void fusion(int* restrict tab, int deb, int pos1, int pos2)
{
  int i1 = deb, i2 = pos1, ir = deb;

  while (i1 < pos1 && i2 < pos2) {
    if (tab[i2] < tab[i1])
      tmp[ir++] = tab[i2++];
    else
      tmp[ir++] = tab[i1++];
  }

  while (i1 < pos1)
    tmp[ir++] = tab[i1++];

  while (i2 < pos2)
    tmp[ir++] = tab[i2++];

  memcpy(tab+deb, tmp+deb, (pos2-deb)*sizeof(int));
}

// Fonction de tri à paralléliser :
// Arguments :
// - tab un tableau d'entiers, alloué, trié en place par la fonction entre
// les positions pos1 et pos2
void tri(int *tab, int pos1, int pos2)
{
  if(pos2 - pos1 > 1)
  {
    // Si le nombre est assez petit, le thread fait le calcul lui-même, ça gagne du temps 
    // car les calcul sont très rapides et évitent d'utiliser du threading couteux pour rien
    // J'ai fait des tests sur mon ordinateur. En normal on est à ~1secondes et en parllelisé on est 
    // à ~0.4secondes.
    // J'ai essayé de rajouter un 0 à N, après 20 secondes de single-thread, pas encore de résultat
    // alors que la version paralllèle peut le faire en 5 secondes
    if(pos2-pos1 < 10000) {
      tri(tab, pos1, (pos1+pos2)/2);
      tri(tab, (pos1+pos2)/2, pos2);
    } else {
#pragma omp parallel
#pragma omp single 
      {
#pragma omp task
        tri(tab, pos1, (pos1+pos2)/2);
#pragma omp task
        tri(tab, (pos1+pos2)/2, pos2);
      }
    }
    fusion(tab, pos1, (pos1+pos2)/2, pos2);
  }
}

// variable globale pour éviter le stack overflow
int tab[N];

// MAIN
int main(int argc, char* argv[])
{
  // initialisation
  srand(time(0) + getpid());
  for (int i = 0; i < N; i++) {
    tab[i] = rand()%N;
  }
  verif_init(tab);

  // le tri commence ici
  double t0 = omp_get_wtime();
  tri(tab, 0, N);
  double t1 = omp_get_wtime();

  printf("Execution time: %lfs\n", t1-t0);

  // renvoie le code de retour de la fonction de vérification du tri
  return verif(tab);
}

// ----------ci-dessous: fonctions de vérification-------------------------
// ------------------Ne pas modifier---------------------------------------
static int compte[N];

// fonction d'initialisation de la vérification
void verif_init(int* t) {
  for (int i = 0; i < N; i++)
    compte[i] = 0;
  for (int i = 0; i < N; i++)
    compte[t[i]]++;
}

// fonction de vérification : le tableau passé en argument est le tableau de
// verif_init() trié (renvoie 0 si succès, 1 si échec + message sur stderr)
int verif(int* t) {
  fprintf(stderr, "result:");
  for (int i = 0; i < 5 && i < N; i++)
    fprintf(stderr, " %d", t[i]);
  fprintf(stderr, " ...");
  for (int i = (N-5 > 0)? N - 5 : 0; i < N; i++)
    fprintf(stderr, " %d", t[i]);
  fprintf(stderr, "\n");

  // vérification que le tableau t est bien le tableau trié :
  // vérifie que les éléments sont dans l'ordre, et que le nombre
  // d'occurrences de chaque valeur correspond au tableau compte initialisé
  int nb = 1;
  for (int i = 1; i < N; i++) {
    if (t[i-1] == t[i]) {
      nb++;
    }
    else if (t[i-1] > t[i]) {
      fprintf(stderr, "Error (%d > %d at index %d-%d)\n", t[i-1], t[i], i-1, i);
      return 1;
    } else {
      // vérifie le nombre d'occurrences de la valeur précédente
      if (compte[t[i-1]] != nb) {
        fprintf(stderr,
                "Error (bad count of %d: %d occurences, should be %d)\n",
                t[i-1], nb, compte[t[i-1]]);
        return 1;
      }
      nb = 1;
    }
  }
  // vérifie le nombre d'occurrences de la dernière valeur
  if(compte[t[N-1]] != nb) {
    fprintf(stderr, "Error (bad count of %d: %d occurences, should be %d)\n",
            t[N-1], nb, compte[t[N-1]]);
    return 1;
  }
  fprintf(stderr, "Result OK!\n");
  return 0;
}
