// TP noté de programmation parallèle - exercice MPI - IL3S6P 2023/2024.
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

// affichage en couleurs :
#define YEL "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define NORM "\033[0m"

// taille du tableau par défaut [test2]
#define N 13

// variables globales, initialisées au début de main()
int rank, size;


// Fonction à écrire :
void mon_gather(void *sbuf, void *rbuf, int count, MPI_Datatype type,
                int root, MPI_Comm comm)
{
  // Ne passe pas le dernier test. Je ne comprends pas
  int typesize;
  MPI_Type_size(type,&typesize);
  if(root == rank) {
    for(int j = 0; j < size; j++) {
      if(root == j) {
        memcpy(rbuf + (j*count*typesize),sbuf,count*typesize);
        continue;
      };
      //fprintf(stdout,"%d Waiting %d\n",rank,j);
      if(MPI_Recv(rbuf + (j*count*typesize),count,type,j,0,comm,NULL) != MPI_SUCCESS) {
        //fprintf(stderr,RED"Err ssend\n"NORM);
        exit(1);
      }
      //fprintf(stdout, GREEN"%d received\n"NORM,j);
    }
    count++;
  } else {
    //fprintf(stdout,"%d Sending to %d\n",rank,root);
    if(MPI_Send(sbuf,count,type,root,0,comm) != MPI_SUCCESS) {
      
      //fprintf(stderr,RED"Err ssend\n");
      exit(1);
    }
    //fprintf(stdout,GREEN"Sending finished !\n"NORM);
  }
  // cette fonction doit faire la même chose que :
  // MPI_Gather(sbuf, count, type, rbuf, count, type, root, comm);
  // * sans utiliser de communication collective. *



  return;
}


// Programme de test, ne nécessite pas de modification.
int main( int argc, char **argv )
{
  srand(time(0)+getpid());
  // init
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank==0)
    printf("Nb process: %d\n", size);


  // test 1 : un caractère sur root=0
  char c = 'a' + rand()%26;
  char s_mon[size+1], s_mpi[size+1];
  s_mon[0] = s_mon[size] = s_mpi[size] = '\0';

  mon_gather(&c, s_mon, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
  MPI_Gather(&c, 1, MPI_CHAR, s_mpi, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

  if(rank==0 && argc==1)
  {
    printf(YEL"[test1] "NORM);
    if(strncmp(s_mon, s_mpi, size))
    {
      printf(RED"Failed!"NORM" ('%s' != '%s')\nAborting\n", s_mon, s_mpi);
      MPI_Abort(MPI_COMM_WORLD, 1);
      exit(1);
    }
    printf(GREEN"OK"NORM" results\n");
  }

  // synchro pour attendre le abort() éventuel du test1...
  MPI_Barrier(MPI_COMM_WORLD);

  // test 2 : tableau de N longs sur root=size-1
  long val[N];
  printf("val [on %d] =", rank);
  for(int i=0; i<N; i++)
  {
    val[i] = rand()%100;
    printf("%3ld", val[i]);
  }
  printf("\n");

  long *res_mon = calloc(size*N, sizeof(long));
  long *res_mpi = calloc(size*N, sizeof(long));

  mon_gather(val, res_mon, N, MPI_LONG, size-1, MPI_COMM_WORLD);
  MPI_Gather(val, N, MPI_LONG, res_mpi, N, MPI_LONG, size-1, MPI_COMM_WORLD);

  if(rank==size-1)
  {
    printf(YEL"[test2] "NORM);
    for(int i=0; i<N*size; i++)
    {
      if(res_mon[i] != res_mpi[i])
      {
        printf(RED"Failed!"NORM" ('%ld' != '%ld' [%d])\n",
                res_mon[i], res_mpi[i], i);
        MPI_Abort(MPI_COMM_WORLD, 1);
        exit(1);
      }
    }
    printf(GREEN"OK"NORM" results\n");
  }

  MPI_Finalize();
  return(0);
}
