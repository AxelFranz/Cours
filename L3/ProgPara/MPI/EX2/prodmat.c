#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <mpi.h>

/* matrix size */
#define N 2496

// Random values are [0, MAX_VAL]
#define MAX_VAL 5

// Nomber of checks
#define NBCHECKS 10
// acceptable error (in check)
#define ERROR   1.e-3

#define DIFFTEMPS(a,b) (((b).tv_sec - (a).tv_sec) + ((b).tv_usec - (a).tv_usec)/1000000.)

/* global to avoid stack overflow */
double a[N][N],b[N][N],c[N][N];

int main(int argc, char** argv)
{
  struct timeval tv_init, tv_begin, tv_end;
  int size;
  int rank;
  gettimeofday( &tv_init, NULL);
  
  if(MPI_Init(&argc,&argv)) {
      fprintf(stderr,"Error MPI_Init\n");
      exit(EXIT_FAILURE);
  }

  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  if(N%size != 0) {
      if(rank == 0) {
        fprintf(stderr,"Error => Le nombre de processus doit diviser N : %d\n",N);
      }
      MPI_Finalize();
      exit(EXIT_FAILURE);
  }


  /***************************************************************************/
  // initialization
  srand((unsigned int)time(NULL));
  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
    {
      b[i][j]=(double)rand()/(double)(RAND_MAX/MAX_VAL);
      a[i][j]=(double)rand()/(double)(RAND_MAX/MAX_VAL);
      c[i][j]=0;
    }



  /***************************************************************************/
  // compute
  size_t count = (N*N)/size;
  gettimeofday( &tv_begin, NULL);
  MPI_Scatter(a,count,MPI_DOUBLE,a,count,MPI_DOUBLE,0,MPI_COMM_WORLD);
  MPI_Bcast(b,N*N,MPI_DOUBLE,0,MPI_COMM_WORLD);
  for(int i=0 ; i<N/size ; i++) {
      for(int j=0 ; j<N ; j++)
          for(int k=0 ; k<N ; k++)
              c[i][j] += a[i][k] * b[k][j];
  }

  
  gettimeofday( &tv_end, NULL);
  MPI_Gather(c,count,MPI_DOUBLE,c,count,MPI_DOUBLE,0,MPI_COMM_WORLD);
  /***************************************************************************/
  // check some arbitrary values
  if(rank == 0) {
      int check_ok = 1;
      for(int checks=0 ; checks<NBCHECKS ; checks++)
      {
          int i = rand()%N;
          int j = rand()%N;
          double val = 0.;
          for(int k=0 ; k<N ; k++)
              val += a[i][k] * b[k][j];
          if(fabs(val - c[i][j]) > ERROR)
          {
              fprintf(stderr, "BAD RESULTS !");
              fprintf(stderr, " (value[%d][%d] = %g should be %g)\n",
                      i, j, c[i][j], val);
              check_ok = 0;
          }
      }
      if(check_ok)
          fprintf(stderr, "Ok results :)\n");

      printf("Init : %lfs, Compute : %lfs\n",
              DIFFTEMPS(tv_init,tv_begin),
              DIFFTEMPS(tv_begin,tv_end));
  }

  /***************************************************************************/
  /* execution times */


  MPI_Finalize();
  return( 0 );
}
