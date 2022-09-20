
#ifndef _LIBRESEAU_H_
#define _LIBRESEAU_H_
#include <sys/types.h>


ssize_t	send_to(int socket, unsigned  char *buffer, size_t buffer_size , void *address, size_t address_size);
int initialisationSocketUDP(char *service);
int messageUDP(char *hote, char *service, unsigned char *message, int taille, unsigned char *buffer);
int boucleServeurUDP(int s, int (*traitement)(unsigned char *, int, void *, int));

#endif