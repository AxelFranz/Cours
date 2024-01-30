
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>


#define TAILLE_NOM 8 /* pour vendeurs et client, affichage seulement */
#define TAILLE_DEST 4 /* destination : 3 caractères + '\0' */

#define MAX_VECL 100

// TODO : modifiez le nom du segment de mémoire partagée
#define NOM_SHM "/vgierlowski" /* gardez le / en tête */


/* cette version de raler devrait être suffisante */
void raler (int sys, const char * msg)
{
    if (sys) /* erreur système */
        perror (msg);
    else /* erreur de l'application */
        fprintf (stderr, "fatal: %s\n", msg);
    exit (EXIT_FAILURE);
}

/* cette macro est utile pour les appels système */
#define CHECK(op) do { if ((op) == -1) raler (1, #op); } while (0)
/* attenton : vous ne pouvez pas l'utiliser avec mmap */

/* une fonction pour attendre en millisecondes */
void millisleep (unsigned long milliseconds)
{
    ldiv_t qr = ldiv (milliseconds*1000*1000, 1000*1000*1000);
    struct timespec ts = {.tv_sec=qr.quot, .tv_nsec=qr.rem};
    struct timespec rm;
    while (nanosleep (&ts, &rm) == -1 && errno == EINTR)
        ts = rm;
}



#define VENDEUR_S 2
#define CLIENT_S 1
struct guichet {
    // L'information de si un guichet est utilisé par un vendeur.
    char statut;
    // La ou le client donnera sa destination
    char dest[TAILLE_DEST];
    // Les sémaphore de synchronisation
    sem_t client;
    sem_t ticket;
};
/* la structure principale du segment de mémoire partagée */

struct guichets {
    size_t nguichets; /* nombre de guichets */
    // TODO : placer ici la structure de votre shm
    int shm_fd;
    // La condition qu'un guichet est libre
    sem_t guichetlibre;
    // NOTE : placer un bref commentaire après chaque champ
    // NOTE : vos pouvez définir des structures additionnelles
    //Structure individuelle pour chaque guichets.
    struct guichet g[];
};



int cmd_creer (size_t nguichets)
{

    //(void) nguichets; // TODO : supprimer cette ligne quand le code est écrit

    // TODO : créer le segment et initialiser tout ce qu'il contient
    int shm_fd;
    struct guichets * guichets;
    shm_fd = shm_open(NOM_SHM, O_CREAT | O_RDWR | O_TRUNC, 0666);
    CHECK(shm_fd);
    ssize_t taille_partager = sizeof(struct guichets) + sizeof(struct guichet)*nguichets;
    CHECK(ftruncate(shm_fd, taille_partager));
    guichets = mmap(NULL,taille_partager, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(guichets == MAP_FAILED) raler(1,  "mmap");
    // Rajoute dans la mémoire partager le fd de shm, le nombre de guichets 
    guichets->shm_fd = shm_fd;
    guichets->nguichets = nguichets;
    // Ainsi que le sémaphore des guichets qui permettra d'indiquer si un est libre

    CHECK(sem_init(&guichets->guichetlibre,1,0));

    // Initialise les guichets
    for(size_t i = 0; i < nguichets; i++){
        guichets->g[i].statut = 0;
        CHECK(sem_init(&guichets->g[i].client,1,0));
        CHECK(sem_init(&guichets->g[i].ticket,1,0));
    }
    
    return EXIT_SUCCESS;
}


/* les deux fonctions suivantes sont appelées plus bas */
struct guichets * guichets_map (void)
{

    // TODO : projeter le segment dans l'espace d'adressage du processus
    int shmfd = shm_open(NOM_SHM, O_RDWR | O_CREAT, 0666);
    CHECK(shmfd);

    struct stat shmstat;
    CHECK(fstat(shmfd,&shmstat));

    struct guichets * g;
    g = mmap(NULL, shmstat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if(g == MAP_FAILED) raler(1,"guichet mmap");


    return g; // TODO : modifier quand le code est écrit
}

void guichets_unmap (struct guichets * g)
{
//    (void) g; // TODO : supprimer cette ligne quand le code est écrit

    // TODO : supprimer la projection du segment (à l'adresse "g")
    CHECK(close(g->shm_fd));
    CHECK(munmap(g,sizeof(g)));

}


int cmd_detruire (void)
{

    // TODO : supprimer le segment et tout ce qu'il contient
    struct guichets * guichets = guichets_map();
    for(size_t i = 0; i < guichets->nguichets;i++){
        sem_destroy(&guichets->g[i].client);
        sem_destroy(&guichets->g[i].ticket);
    }
    sem_destroy(&guichets->guichetlibre);
    CHECK(shm_unlink(NOM_SHM));
    return EXIT_SUCCESS;
}


int cmd_vendeur (char * nom, int nventes)
{
    struct guichets * g;

    g = guichets_map ();

    // TODO : trouver un guichet fermé, ou partir avec un code d'erreur.
    size_t num = 0;
    while(num < g->nguichets){
        // pas de vendeur déjà en place
        if((g->g[num].statut & VENDEUR_S) == 0){
            g->g[num].statut |= VENDEUR_S;
            // sors de la boucle
            break;
        }
        num++;
    }
    // si on a dépasser le nombre de guichet alors on a pas trouvé et on fait l'erreur
    if(num >= g->nguichets) return(EXIT_FAILURE);


    // TODO : si trouvé, l'ouvrir et afficher son numéro
    printf ("Vendeur %s au guichet %zu\n", nom, num);

    for (int i=0 ; i<nventes ; i++)
    {

        // TODO : attendre un client et préparer son billet
        //Annonce un guichet libre
        sem_post(&g->guichetlibre);
        millisleep (500);
        sem_wait(&g->g[num].client);

        // TODO : modifier ce message pour afficher la vraie destination
        printf ("Vendeur %s emet un billet pour %s\n",
                nom, g->g[num].dest);

        // TODO : fournir le billet au client
        sem_post(&g->g[num].ticket);
    }

    // TODO : fermer le guichet
    g->g[num].statut = 0;
    guichets_unmap (g);
    printf ("Vendeur %s parti\n", nom);

    return EXIT_SUCCESS;
}


int cmd_client (char * nom, char * destination)
{
    struct guichets * g;

    printf ("Client  %s pour %s\n", nom, destination);
    g = guichets_map ();

    // TODO : attendre qu'un guichet soit disponible
    sem_wait(&g->guichetlibre);
    printf ("Client  %s va vers les guichets\n", nom);
    millisleep (200);

    // TODO : trouver un guichet disponible et l'occuper
    size_t num = 0;
    for(num = 0;num < g->nguichets;num++){
        if((g->g[num].statut & VENDEUR_S) && (g->g[num].statut & CLIENT_S) == 0){
            g->g[num].statut |= CLIENT_S;
            break;
        }
    }
    // TODO : afficher le vrai numéro de guichet dans ce printf
    printf ("Client  %s au guichet %zu\n", nom, num);

    // TODO : attendre de recevoir un ticket
    //Donne sa destination
    strcpy(g->g[num].dest,destination);
    //donne au vendeur sa destination et attend le ticket
    sem_post(&g->g[num].client);
    sem_wait(&g->g[num].ticket);
    //libère le guichet
    g->g[num].statut &= ~CLIENT_S;
    guichets_unmap (g);
    printf ("Client  %s parti\n", nom);

    return EXIT_SUCCESS;
}


//
// Ne rien modifier dans la suite
//

/* deux fonctions pour analyser les arguments */
int arg_int (char * arg, int * v)
{
    char dummy;
    return sscanf (arg, "%d%c", v, &dummy) == 1;
}
int arg_str (char * arg, size_t n, char * str)
{
    if (strlen (arg) >= n)
        return 0;
    strcpy (str, arg);
    return 1;
}

int main (int argc, char * argv [])
{
    int n;
    char nom [TAILLE_NOM];
    char destination [TAILLE_DEST];

    if (setvbuf (stdout, NULL, _IONBF, 0) != 0) /* _IOLBF? */
        fprintf (stderr, "Attention : stdout non-immédiat\n");

    if (argc == 3 && strcmp (argv[1], "creer") == 0 &&
        arg_int (argv[2], &n) &&
        n > 0)

        return cmd_creer (n);

    else if (argc == 2 && strcmp (argv[1], "detruire") == 0)

        return cmd_detruire ();

    else if (argc == 4 && strcmp (argv[1], "vendeur") == 0 &&
             arg_str (argv[2], TAILLE_NOM, nom) &&
             arg_int (argv[3], &n) &&
             n > 0)

        return cmd_vendeur (nom, n);

    else if (argc ==4 && strcmp (argv[1], "client") == 0 &&
             arg_str (argv[2], TAILLE_NOM, nom) &&
             arg_str (argv[3], TAILLE_DEST, destination))

        return cmd_client (nom, destination);

    else

        raler (0,
               "Usage: guichets creer <n>\n"
               "       guichets detruire\n"
               "       guichets vendeur <nom> <n>\n"
               "       guichets client <nom> <destination>\n");
}
