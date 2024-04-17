#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <mpi.h>

#define N 10000000

int rank,size;

// pour qsort
int compare(const void *p1, const void *p2)
{
  int v1=*(int *)p1, v2=*(int *)p2;
  if(v1<v2)
    return(-1);
  else if(v2<v1)
    return(1);
  else
    return(0);
}


// pour fusionner deux parties de tableau triées tab1 et tab2
// remplit res avec la fusion
void fusion(int *restrict res, int *restrict tab1, int len1, int *restrict tab2, int len2)
{
  int is=0, js=0, r=0;

  while(is<len1 && js<len2)
  {
    if(tab2[js] < tab1[is])
      res[r++] = tab2[js++];
    else
      res[r++] = tab1[is++];
  }
  while(is<len1)
    res[r++] = tab1[is++];
  while(js<len2)
    res[r++] = tab2[js++];

}

int tab[N], res[N];

// fonction d'initialisation de la vérification
void verif_init(int *);
// fonction de vérification : le tableau passé en argument est le tableau de verif_init() trié
// (renvoie 0 si succès, 1 si échec + message sur stderr)
int verif(int *);

int main(int argc, char **argv)
{
  if(MPI_Init(&argc,&argv)) {
        exit(EXIT_FAILURE);
  }
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  if(N%size != 0) {
      fprintf(stderr,"Pas divisible par %d\n",N);
      exit(EXIT_FAILURE);
  }
  /* initialisation */
  srand(time(0)+getpid());
  for(int i=0 ; i<N ; i++)
  {
    tab[i] = rand()%N;
  }
  verif_init(tab);
  /* fin initialisation */


  /* le tri commence ici */
  qsort(&tab[0], N/2, sizeof(int), compare);
  qsort(&tab[N/2], N/2, sizeof(int), compare);

  fusion(res, tab, N/2, tab+N/2, N/2);
  /* le tri termine ici, le résultat est dans le tableau res */

  MPI_Finalize();
  return(verif(res));
}

static int compte[N];
void verif_init(int *t)
{
  for(int i=0 ; i<N ; i++)
    compte[i]=0;
  for(int i=0 ; i<N ; i++)
    compte[t[i]]++;
}
int verif(int *t)
{
  fprintf(stderr, "result:");
  for(int i=0 ; i<5&&i<N ; i++)
    fprintf(stderr, " %d", t[i]);
  fprintf(stderr, " ...");
  for(int i=N-5>0?N-5:0 ; i<N ; i++)
    fprintf(stderr, " %d", t[i]);
  fprintf(stderr, "\n");

  /* vérification que le tableau t est bien le tableau trié : */
  /* vérifie que les éléments sont dans l'ordre, et que le nombre   */
  /* d'occurrences de chaque valeur correspond au tableau compte.   */
  int nb = 1;
  for(int i=1 ; i<N ; i++)
  {
    if(t[i-1] == t[i])
    {
      nb++;
    }
    else if(t[i-1] > t[i])
    {
      fprintf(stderr, "Error (%d > %d at index %d-%d)\n", t[i-1], t[i], i-1, i);
      return(1);
    }
    else
    {
      // vérifie le nombre d'occurrences de la valeur précédente
      if(compte[t[i-1]] != nb)
      {
        fprintf(stderr, "Error (bad count of %d: %d occurences, should be %d)\n", t[i-1], nb, compte[t[i-1]]);
        return(1);
      }
      nb = 1;
    }
  }
  // vérifie le nombre d'occurrences de la dernière valeur
  if(compte[t[N-1]] != nb)
  {
    fprintf(stderr, "Error (bad count of %d: %d occurences, should be %d)\n", t[N-1], nb, compte[t[N-1]]);
    return(1);
  }
  fprintf(stderr, "Result OK!\n");
  return(0);
}
