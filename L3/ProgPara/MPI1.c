#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // NE PAS UTILISER ARGC ET ARGV AVANT L'APPEL à INIT
    int error = MPI_Init(&argc,&argv); // Fonction pour initialiser
    if(error) return 1;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("%d\n",rank);
    int end = MPI_Finalize(); // Finir le MPI
}
