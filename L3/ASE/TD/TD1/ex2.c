#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

struct arg {
    int p;
    int t;
};

void* thread_fn(void* arg) {

        struct arg args= *(struct arg*)arg;

    printf("%d %d\n",args.p,args.t);

    return NULL;
}


int main(int argc, char** argv) {

    if(argc != 3) {
        fprintf(stderr,"Usage: %s <n> <p>",argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int p = atoi(argv[2]);

    pthread_t tid[n];

    for(int t = 1; t <= n; t++) {
        int args[] = {n,p};
        if((errno = pthread_create(&tid[t-1],NULL,thread_fn,&(struct arg){.p=p,.t=t})) > 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for(int i = 0; i < n; i++) {
        if((errno = pthread_join(tid[i],NULL)) > 0) {
            perror("pthread_join");
            exit(1);
        }

    }




    return 0;
}
