#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

struct arg {
    int p;
    int t;
    pthread_barrier_t *b;
};

void* thread_fn(void* arg) {

    struct arg args = *(struct arg*)arg;

    pthread_barrier_wait((pthread_barrier_t*)arg.b);;
    int* sum = calloc(sizeof(int),1);
    for(int i = 0; i < args.p;i++) {
        *sum =(args.t-1) * args.p+i;
    }

    return sum;
}


int main(int argc, char** argv) {

    if(argc != 3) {
        fprintf(stderr,"Usage: %s <n> <p>",argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int p = atoi(argv[2]);
    pthread_barrier_t b;
    pthread_barrier_init(&b,0,n);

    pthread_t tid[n];

    for(int t = 0; t < n; t++) {
        int args[] = {n,p};
        if((errno = pthread_create(&tid[t],NULL,thread_fn,&(struct arg){.p=p,.t=t+1,.b=&b})) > 0) {
            perror("pthread_create");
            exit(1);
        }
    }
    
    int res = 0;
    int* retval = NULL;

    for(int i = 0; i < n; i++) {
        if((errno = pthread_join(tid[i],(void**)&retval)) > 0) {
            perror("pthread_join");
            exit(1);
        }
        printf("%d\n",*retval);
        res += *retval;
        free(retval);
    }
    printf("Résultat : %d\n",res);
    return 0;




    return 0;
}
