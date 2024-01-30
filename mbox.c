#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <unistd.h>

#define CHK(op)                                                                \
    do                                                                         \
    {                                                                          \
        if ((op) == -1)                                                        \
            raler(#op);                                                        \
    } while (0)
#define CHKN(op)                                                               \
    do                                                                         \
    {                                                                          \
        if ((op) == NULL)                                                      \
            raler(#op);                                                        \
    } while (0)
#define TCHK(op)                                                               \
    do                                                                         \
    {                                                                          \
        if ((errno = (op)) > 0)                                                \
            raler(#op);                                                        \
    } while (0)

noreturn void raler(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

noreturn void usage(const char *argv0)
{
    fprintf(stderr, "usage: %s t p nr ne\n", argv0);
    exit(EXIT_FAILURE);
}

// attend un délai aléatoire borné par tmax ms
void attente_aleatoire(int tmax, unsigned int *seed)
{
    useconds_t delai;
    delai = tmax * (rand_r(seed) / ((double)RAND_MAX + 1));
    usleep(delai * 1000);
}

// la boîte aux lettres avec ses mécanismes de synchronisation
struct mbox
{
    int msg; // le message à transmettre (= 1 ici)
    pthread_cond_t* cond_recepteur, *cond_emetteur;
    pthread_mutex_t* mutex;
    int tmax, p, nb_emmeteur_actif;
    unsigned int seed;
};

struct thread_param 
{
    int num_thread;
    int nb_msg_lu;
    struct mbox* mbox;
};

void *emetteur(void *arg)
{
    struct thread_param* param = (struct thread_param*)arg;

    for (int i = 0; i < param->mbox->p; i++)
    {
        // attendre un délai aléatoire
        attente_aleatoire(param->mbox->tmax, &param->mbox->seed);

        // attendre que la boîte aux lettres soit libre
        TCHK(pthread_mutex_lock(param->mbox->mutex));
        while (param->mbox->msg != 0) 
        {
            TCHK(pthread_cond_wait(param->mbox->cond_emetteur, param->mbox->mutex));
        }

        // déposer le message
        //printf("E%d produit\n", param->num_thread);
        param->mbox->msg = 1;
        TCHK(pthread_mutex_unlock(param->mbox->mutex));

        // indiquer aux récepteurs qu'ils peuvent consulter la boîte
        TCHK(pthread_cond_broadcast(param->mbox->cond_recepteur));
    }

    // prévenir que j'ai fini
    TCHK(pthread_mutex_lock(param->mbox->mutex));
    param->mbox->nb_emmeteur_actif--;
    TCHK(pthread_mutex_unlock(param->mbox->mutex));
    TCHK(pthread_cond_broadcast(param->mbox->cond_recepteur));

    return NULL;
}

void *recepteur(void *arg)
{
    struct thread_param* param = (struct thread_param*)arg;
    int nbmsg = 0; // nb de messages reçus

    // attendre un événement, le traiter, et attendre
    while (1) 
    {
        TCHK(pthread_mutex_lock(param->mbox->mutex));
        while (param->mbox->msg == 0) 
        {
            TCHK(pthread_cond_wait(param->mbox->cond_recepteur, param->mbox->mutex));
            if (param->mbox->nb_emmeteur_actif == 0) 
            {
                //printf("R%d je dois m'arrêter\n", param->num_thread);
                break;
            }
        }
        if (param->mbox->nb_emmeteur_actif == 0) 
        {
            if (param->mbox->msg == 1) 
            {
                nbmsg++;
                param->mbox->msg = 0;
            }
            TCHK(pthread_mutex_unlock(param->mbox->mutex));
            break;
        }

        //printf("R%d lit\n", param->num_thread);
        nbmsg++;
        param->mbox->msg = 0;

        TCHK(pthread_mutex_unlock(param->mbox->mutex));
        TCHK(pthread_cond_broadcast(param->mbox->cond_emetteur));
    }

    // bilan des messages reçus par ce thread
    printf("T%d : nb recus = %d\n", param->num_thread, nbmsg);
    param->nb_msg_lu = nbmsg;

    return NULL;
}

int main(int argc, char *argv[])
{
    int tmax, p, ne, nr;
    int n;

    if (argc != 5)
    {
        usage(argv[0]);
    }

    tmax = atoi(argv[1]);
    p = atoi(argv[2]);
    ne = atoi(argv[3]);
    nr = atoi(argv[4]);
    if (tmax < 0 || p < 0 || ne < 1 || nr < 1)
    {
        usage(argv[0]);
    }
    n = ne + nr;

    struct mbox mbox;
    struct thread_param* params;
    pthread_t* threads_emetteur, *threads_recepteur;
    pthread_cond_t cond_emetteur, cond_recepteur;
    pthread_mutex_t mutex;
    CHKN(params = malloc(n * sizeof(struct thread_param)));
    CHKN(threads_emetteur = malloc(ne * sizeof(pthread_t)));
    CHKN(threads_recepteur = malloc(nr * sizeof(pthread_t)));
    TCHK(pthread_cond_init(&cond_emetteur, NULL));
    TCHK(pthread_cond_init(&cond_recepteur, NULL));
    TCHK(pthread_mutex_init(&mutex, NULL));

    mbox.msg = 0;
    mbox.cond_emetteur = &cond_emetteur;
    mbox.cond_recepteur = &cond_recepteur;
    mbox.mutex = &mutex;
    mbox.p = p;
    mbox.tmax = tmax;
    mbox.seed = 1;
    mbox.nb_emmeteur_actif = ne;

    // Création des threads
    for (int i = 0; i < ne; i++) 
    {
        params[i].mbox = &mbox;
        params[i].num_thread = i;
        TCHK(pthread_create(&threads_emetteur[i], NULL, emetteur, (void*)&params[i]));
    }
    for (int i = 0; i < nr; i++)
    {
        params[ne + i].mbox = &mbox;
        params[ne + i].num_thread = ne + i;
        TCHK(pthread_create(&threads_recepteur[i], NULL, recepteur, (void*)&params[ne + i]));
    }

    // Attente des threads
    for (int i = 0; i < ne; i++) 
    {
        TCHK(pthread_join(threads_emetteur[i], NULL));
    }
    for (int i = 0; i < nr; i++)
    {
        TCHK(pthread_join(threads_recepteur[i], NULL));
    }

    int somme = 0;
    for (int i = 0; i < nr; i++) 
    {
        somme += params[ne + i].nb_msg_lu;
    }
    printf("total = %d, attendu = %d\n", somme, ne * p);

    TCHK(pthread_mutex_destroy(&mutex));
    TCHK(pthread_cond_destroy(&cond_emetteur));
    TCHK(pthread_cond_destroy(&cond_recepteur));
    free(params);
    free(threads_recepteur);
    free(threads_emetteur);

    exit(EXIT_SUCCESS);
}
