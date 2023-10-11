#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/* 

   Exercice 1 : 
    
   Il affiche un nombre aléatoire car l'ordre des threads n'est pas déterministe et chaque thread accède à la mémoire quand il peut
 
 * */

#define MAX 10

void *fonction (void* arg) {
    printf("%d\n", *(int*) arg);
    return NULL;
}

void raler (char* msg) {
    perror(msg); exit(1);
}

int main(int argc, char** argv) {
    pthread_t tid[MAX]; int i;
    for(i = 0; i < MAX; i++) {
        if((errno = pthread_create(&tid[i],NULL, fonction,&i)) > 0) 
            raler("pthread_create");
    }
    for(i = 0; i < MAX; i++)
        if((errno=pthread_join(tid[i],NULL)) > 0)
            raler("pthread_join");
    exit(0);
}
