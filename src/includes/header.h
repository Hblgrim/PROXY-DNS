#ifndef HEADER_H
#define HEADER_H
#include "libreseau.h"
#include "genericLog.h"
#include "log_dns.h"
#include "libthread.h"
#include "libmemoire.h"
#include "args.h"
#include <unistd.h>
#include <strings.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_trait{
	unsigned char msg[512];
	unsigned char buffer[512];
	int nb; 
	void  *adresse;
	int taille;
}t_trait;

void parseArgs(int argc, char* argv[]);
int traitement(unsigned char *message, int nboc, void  *addresse, int taille );

#endif
