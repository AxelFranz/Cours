#include <asm-generic/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <poll.h>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define CHECK(op)   do { if ( (op) == -1) { perror (#op); exit (EXIT_FAILURE); } \
                    } while (0)

#define PORT(p) htons(p)
#define BUFFER_SIZE 4096

// Commandes
#define CMD_SIZE 5 // Taille d'une commande

// On définit la structure du message ainsi que l'enum pour le header
#ifdef BIN

struct message {
    int type; // Le type de message (Voir define suivants)
    char text[BUFFER_SIZE]; // Le du message
};

#define CMD_HELO 1 // /HELO (champ text ignoré)
#define CMD_QUIT 2 // /QUIT (champ text ignoré)
#define CMD_READ 3 // Message normal 

#endif // BIN


void printName(struct sockaddr* s, socklen_t size) {
    char nom[NI_MAXHOST] = {0}; char port[NI_MAXSERV] = {0};
    int err = getnameinfo(s,size,nom,NI_MAXHOST,port,NI_MAXSERV,0);
    if(err != 0) {
        fprintf(stderr,"%s\n",gai_strerror(err));
        exit(EXIT_FAILURE);
    }
    fprintf(stdout,"%s %s\n",nom,port);
}

int main (int argc, char *argv [])
{
    /* test arg number */
    if(argc != 2) {
        fprintf(stderr,"usage: %s <port>\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    /* convert and check port number */
    int iPort = atoi(argv[1]);
    if(iPort < 10000 || iPort > 65000) {
        fprintf(stderr,"Port must be between 10000 and 65000\n");
        exit(EXIT_FAILURE);
    }

    /* create socket */
    int sockfd;
    CHECK(sockfd = socket(AF_INET6, SOCK_DGRAM, 0));

    /* set dual stack socket */
    int value = 0;
    CHECK (setsockopt (sockfd, IPPROTO_IPV6, IPV6_V6ONLY, &value, sizeof value));

    /* set local addr */
    struct sockaddr_storage ss;
    memset(&ss,0,sizeof ss);
    struct sockaddr *s       = (struct sockaddr *)     &ss;
    socklen_t size = sizeof ss;
    struct sockaddr_in6 *in6 = (struct sockaddr_in6 *) &ss;
    in6->sin6_addr           = in6addr_any;
    in6->sin6_family         = AF_INET6;
    in6->sin6_port = PORT(iPort);



    /* check if a client is already present */
    char message[BUFFER_SIZE] = {0};
    ssize_t msg_size = 0;
    int berror = bind(sockfd, s ,size);
#ifdef BIN
    struct message msg = {0};
    if(errno == EADDRINUSE) {
         msg.type = CMD_HELO;
         CHECK(sendto(sockfd,&msg,sizeof(struct message),0,s,size));
    } else {
        CHECK(berror);
        while(msg.type != CMD_HELO) {
            CHECK(recvfrom(sockfd,&msg,sizeof(struct message),0,s,&size));
        }
        printName(s,size);
    }
#else // BIN
    char helo[] = "/HELO"; char quit[] = "/QUIT";
    if(errno == EADDRINUSE) {
        CHECK(sendto(sockfd,&helo,strlen(helo),0,s,size));
    } else {
        // On ignore tous les messages jusqu'à recevoir un /HELO
        CHECK(berror);
        while(strcmp(message,helo) != 0) {
            CHECK(msg_size = recvfrom(sockfd,message,BUFFER_SIZE - 1, 0,s, &size));
        }
        printName(s,size);
    }

#endif //BIN

    /* prepare struct pollfd with stdin and socket for incoming data */
    struct pollfd fds[2] = {0};
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;
    fds[1].fd = sockfd;
    fds[1].events = POLLIN;

    /*main loop */
#ifdef BIN
    while(msg.type != CMD_QUIT) {
        memset(&msg,0,sizeof(struct message));
        CHECK(poll(fds,2,-1));
    }
#else //BIN
    while(strncmp(message,quit,5) != 0) {
        memset(message,0,BUFFER_SIZE);
        CHECK(poll(fds,2,-1));
        if(fds[0].revents & (POLLIN | POLLPRI)) {
            CHECK(read(STDIN_FILENO,message,BUFFER_SIZE-1));
            if(strncmp(message,quit,5) == 0) {
                CHECK(sendto(sockfd,quit,CMD_SIZE,0,s,size));
                break;
            };
            CHECK(sendto(sockfd,message,strlen(message),0,s,size));
        }
        if(fds[1].revents & (POLLIN | POLLPRI)) {
            CHECK(recvfrom(sockfd,message,BUFFER_SIZE-1,0,s,&size));
            if(strncmp(message,quit,5) == 0) break;
            fprintf(stdout,"%s",message);
        }
    }
#endif //BIN
    /* close socket */
    CHECK(close(sockfd));

    /* free memory */

    return 0;
}

