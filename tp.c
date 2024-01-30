#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>
#include <stdnoreturn.h>
#include <pthread.h>
#include <string.h>

// Quelques macros classiques, mais qui rendent bien service
#define TCHK(op)        do { if ((errno = (op)) > 0) raler (1, #op); } while (0)
#define CHKN(op)        do { if ((op) == NULL) raler (1, #op); } while (0)

// Une fonction "raler" admettant un nombre variable d'arguments
// L'argument syserr doit être à 1 s'il s'agit d'une erreur système
// ou à 0 si c'est une erreur applicative
noreturn void raler(int syserr, const char *msg, ...) {
    va_list ap;

    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    fprintf(stderr, "\n");
    va_end(ap);

    if (syserr == 1)
        perror("");

    exit(1);
}

struct datas
{
    pthread_barrier_t *attendre_print_thread_principal, *attendre_dessiner_symbole_suivant;
    pthread_cond_t *cond;
    pthread_mutex_t *mutex;
    int numThread, delai_max, *nombre_a_dessiner;
    char *symbole;
};

void usage (const char *argv0)
{
    raler (0, "usage: %s délai-max nb-threads taille-côté", argv0) ;
}

void attente_aleatoire (int delai_max)
{
    int delai ;                 // en ms

    delai = ((double) rand () / RAND_MAX) * delai_max ;
    usleep (delai * 1000) ;     // usleep attend un délai en micro-secondes
}

void *thr (void *arg)
{
    int numthr ;
    int nbaff ;                 // nombre de symboles affichés au total
    int delai_max ;

    struct datas *data = arg ;                // TODO il faudrait sans doute utiliser "arg"
    numthr = data->numThread ;               // TODO récupérer le numéro du thread courant
    delai_max = data->delai_max ;          // TODO récupérer le délai maximum (en ms)

    // on attend un délai aléatoire avant de démarrer
    attente_aleatoire (delai_max) ;

    // chaque thread s'annonce
    // TODO le message ne doit pas être affiché avant celui du thread principal
    TCHK(pthread_barrier_wait(data->attendre_print_thread_principal));
    printf ("thread %d prêt\n", numthr) ; fflush (stdout) ;

    //ON ATTEND A NOUVEAU TOUT LE MONDE POUR NE PAS QU'UN THREAD PRINT UN BOUT DU CARRE AVANT QU'UN THREAD DISE QU'IL EST PRET
    TCHK(pthread_barrier_wait(data->attendre_print_thread_principal));

    // TODO tant que le nombre de symboles à afficher != -1
    while (*data->nombre_a_dessiner != -1)
    {
        // TODO attendre si ce nombre est devenu nul
        TCHK(pthread_mutex_lock(data->mutex));

        while(*data->nombre_a_dessiner == 0)
        {
            TCHK(pthread_cond_wait(data->cond, data->mutex));
        }

        // TODO si le nombre est > 0, il faut afficher le symbole
        if (*data->nombre_a_dessiner > 0)
        {
            char *symb;  // symbole à afficher encodé en UTF-8

            // TODO récupérer la valeur du symbole
            symb = data->symbole;      // attention UTF-8 => peut-être plusieurs octets
            // afficher le symbole (fflush pour le cas où c'est dans un fichier)
            fputs (symb, stdout) ; fflush (stdout) ;
            nbaff++ ;

            // TODO décrémenter le nb de symboles à afficher
            --*data->nombre_a_dessiner;

            // TODO avertir thread principal si on est le dernier à décrémenter
            if(*data->nombre_a_dessiner == 0) TCHK(pthread_barrier_wait(data->attendre_dessiner_symbole_suivant));
        }

        TCHK(pthread_mutex_unlock(data->mutex));

        // Un peu d'attente pour voir les problèmes éventuels apparaître
        // attention : les threads doivent attendre en parallèle
        attente_aleatoire (delai_max) ;

    }

    printf ("thread %d fini, %d symboles affichés\n", numthr, nbaff) ;
    fflush (stdout) ;

    return NULL ;
}

// attention : symb est une chaîne de caractères, car le symbole est un
// code Unicode encodé en UTF-8, qui peut donc prendre plusieurs octets.
void dessiner (int nb, const char *symb, pthread_cond_t *cond, pthread_mutex_t *mutex, int *nombre_a_dessiner,
               char *symbole_partagee, pthread_barrier_t *attendre_dessiner_symbole_suivant)
{
    // TODO communiquer nb et symb aux threads
    TCHK(pthread_mutex_lock(mutex));

    *nombre_a_dessiner = nb;
    if(nb != -1) strcpy(symbole_partagee,symb);

    // TODO réveiller 1 ou tous les threads suivant nb
    if(nb == 1) TCHK(pthread_cond_signal(cond));
    else TCHK(pthread_cond_broadcast(cond));

    TCHK(pthread_mutex_unlock(mutex));
    // TODO attendre qu'ils aient terminé

    if(nb != -1) TCHK(pthread_barrier_wait(attendre_dessiner_symbole_suivant));
}

int main (int argc, const char *argv [])
{
    int delai_max ;             // delai maximum d'attente en ms
    int nthr ;                  // nombre de threads de chaque sorte
    int cote ;                  // taille d'un côté (hors coin)
    int i ;                     // compte-tours de boucle

    /*
     * Étape 1 : vérification sommaire des arguments
     */

    if (argc != 4)
        usage (argv [0]) ;
    delai_max = atoi (argv [1]) ;
    nthr = atoi (argv [2]) ;
    cote = atoi (argv [3]) ;
    if (delai_max < 0 || nthr < 1 || cote < 0)
        usage (argv [0]) ;

    pthread_t *tid ;
    CHKN (tid = calloc (nthr, sizeof *tid)) ;

    struct datas *datas = calloc(nthr, sizeof(struct datas));
    CHKN(datas);

    pthread_barrier_t attendre_print_thread_principal, attendre_dessiner_symbole_suivant;
    TCHK(pthread_barrier_init(&attendre_print_thread_principal, NULL, nthr+1));
    TCHK(pthread_barrier_init(&attendre_dessiner_symbole_suivant, NULL, 2));

    pthread_cond_t cond;
    TCHK(pthread_cond_init(&cond, NULL));

    pthread_mutex_t mutex;
    TCHK(pthread_mutex_init(&mutex, NULL));

    /*
     * Étape 2 : démarrer les threads
     */

    int nombre_a_dessiner = 0;
    char symbole[56];

    for (i = 0 ; i < nthr ; i++)
    {
        datas[i].attendre_print_thread_principal = &attendre_print_thread_principal;
        datas[i].attendre_dessiner_symbole_suivant = &attendre_dessiner_symbole_suivant;
        datas[i].mutex = &mutex;
        datas[i].cond = &cond;
        datas[i].numThread = i+1;
        datas[i].delai_max = delai_max;
        datas[i].nombre_a_dessiner = &nombre_a_dessiner;
        datas[i].symbole = symbole;

        // TODO démarrer le thread avec les bons arguments
        TCHK (pthread_create (&tid [i], NULL, thr, &datas[i])) ;     // TODO arg ?
    }

    // TODO Cet affichage doit être effectué avant tout autre affichage
    printf ("Début, %d threads créés\n", nthr) ; fflush (stdout) ;

    TCHK(pthread_barrier_wait(&attendre_print_thread_principal));

    TCHK(pthread_barrier_wait(&attendre_print_thread_principal));

    /*
     * Étape 3 : dessiner
     */

    // TODO il faut sans doute des arguments en plus à dessiner()
    // ligne du haut
    dessiner (1,    "┌", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;            // caractère UTF-8 => plusieurs octets
    dessiner (cote, "─", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
    dessiner (1,    "┐", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
    dessiner (1,   "\n", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;

    // les "côté" lignes du milieu
    for (i = 0 ; i < cote ; i++)
    {
        dessiner (1,    "│", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
        dessiner (cote, " ", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
        dessiner (1,    "│", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
        dessiner (1,   "\n", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
    }

    // ligne du bas
    dessiner (1,    "└", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
    dessiner (cote, "─", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
    dessiner (1,    "┘", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;
    dessiner (1,   "\n", &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;

    /*
     * étape 4 : terminaison des threads
     */

    // prévenir les threads de s'arrêter
    dessiner (-1, NULL, &cond, &mutex, &nombre_a_dessiner, symbole, &attendre_dessiner_symbole_suivant) ;

    for (i = 0 ; i < nthr ; i++)
        TCHK (pthread_join (tid [i], NULL)) ;

    TCHK(pthread_mutex_destroy(&mutex));
    TCHK(pthread_cond_destroy(&cond));
    TCHK(pthread_barrier_destroy(&attendre_dessiner_symbole_suivant));
    TCHK(pthread_barrier_destroy(&attendre_print_thread_principal));
    free(tid);

    exit (0);
}
