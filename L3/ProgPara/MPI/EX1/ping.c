#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv) {

    int rang;
    int turn;
    int number;
    int size;
    double t;
    double time_taken;
    double debitMO;

    if(MPI_Init(&argc,&argv)) {
        fprintf(stderr,"Error while initializing MPI\n");
        exit(1);
    }

    if(argc != 3) {
        fprintf(stderr,"usage: %s <number> <size>\n",argv[0]);
    }
    number = atoi(argv[1]);
    size   = atoi(argv[2]);
    char buffer[size];

    MPI_Comm_rank(MPI_COMM_WORLD,&rang);
    turn = rang;

    t = MPI_Wtime();
    for(int i = 0; i < number; i++) {
        if(turn == 0) {
            MPI_Ssend(buffer,size,MPI_CHAR,(rang+1)%2,0,MPI_COMM_WORLD);
        } else {
            MPI_Recv(buffer,size,MPI_CHAR,(rang+1)%2,0,MPI_COMM_WORLD,NULL);
        }
        turn = (turn + 1) % 2;
    }

    t = MPI_Wtime() - t;
    time_taken = t;
    if(rang == 0) {
        printf("Temps (process %d) : %f s\n", rang, time_taken);
        printf("%d pingpong effectués avec un message de taille %d\n",number,size);
        printf("Temps de transmission d'un message : %E s\n", time_taken/number);
        debitMO = (((double)size*number)/time_taken/2)*0.000000001;
        printf("Débit : %E Goctets/s\n", debitMO);
    }
    MPI_Finalize();
    return 0;
};
