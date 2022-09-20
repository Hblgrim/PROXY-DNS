#include "header.h"


static int dnssocket=-1;
static bool _close=false;
logMsg_t message_log;

void printUsage(void)
{
	printf("-h ou --help ; affiche ce message d'aide\n");
	printf("-p PORT ou --port=PORT : change le numéro du port d'écoute. Par défaut le port est 53\n");
	printf("-s SERVEUR ou --serveur=SERVEUR : permet de spécifier le serveur DNS à utiliser pour la résolution de nom\n");
	printf("-l STRATEGIE ou --logstrategy=STRATEGIE : permet de choisir la stratégie à charger\n");
	printf("-i INIT_ARGS_STRATEGIE et --initlogstrategie=INIT_ARGS_STRATEGIE : permet de passer des paramètres d'initialisation à la stratégie choisie\n");
}

void printMemory(const unsigned char mem[], int count)
{

    for (int i=0; i<count; i++) 
	{
		printf("%c ", mem[i]);
    }
	printf("\n");
}


void* interTraitement(void* arg)
{     
	t_trait *trait = arg;
	int nb_receive = messageUDP(argument.server, argument.port, trait->msg, trait->nb, trait->buffer);
	lock_mutex(0);
	writeMemory(trait->msg, trait->nb);
	unlock_mutex(0);
	if(dnssocket >= 0)
		send_to(dnssocket,trait->buffer, nb_receive, trait->adresse, trait->taille);
	// free(log.msg);
	free(trait->adresse);
	 return NULL;
}


void* interLog(void* arg)
{     
	 logMsg_t log;
	 (void)arg ;
	 uint8_t size;

	while (!_close)
	{
		lock_mutex(0);
		if (!memoryIsEmpty())
		{	
			log.msg = readMemory(&size);
			log.size = size;
			unlock_mutex(0);

			if (size != 0)
			{
				if(logStrategy(&log) == -1) 
					printf("Error send log\n");				
			}
			if (log.msg != NULL)
			{
				free(log.msg);
				log.msg = NULL;
				log.size =0;
			}
		}
		else 
			unlock_mutex(0);
		sleep(1);
	}
 	return NULL;
}


int traitement(unsigned char *message, int nboc, void  *addresse, int taille)
{
	t_trait t;
	memcpy(t.msg,message,nboc);
	t.adresse = malloc(taille);
	memcpy(t.adresse, addresse, taille);
	t.nb = nboc;
	t.taille = taille;

	if (launchThread((void*) interTraitement,&t, (size_t) sizeof(t)) != 0)
	{
		    perror("Failed theading traitement !!");
			exit(EXIT_FAILURE);
            return (-1);
    }  
 	return 1;
}


void interruption()
{
	_close = true;
	endStrategy();
	close(dnssocket);
	exit(SIGINT);
}

int main(int argc, char *argv[])
{

	struct sigaction action;
	action.sa_handler = interruption;
	sigaction(SIGINT, &action, NULL);

	parseArgs(argc, argv);
	allocateMemory(1000);
	printf("The port:%s\n", argument.port);
    printf("The Server:%s\n", argument.server);
    printf("The strategie:%s\n", argument.choice);
    printf("The init log:%s\n", argument.params);
	int_mutex();


	if(argument.help)
	{
		printUsage();
		exit(EXIT_SUCCESS);
	}

	if(loadStrategy(argument.choice) == -1) {
			printf("Loading strategie error:[LIBRARY:%s]\n",argument.choice);
			exit(EXIT_FAILURE);
	}


	if(initStrategy(argument.params) == -1){printf("Error init\n");}
	if (launchThread((void*) interLog,NULL, 0) != 0){
		    perror("Failed theading Log !!");
			exit(EXIT_FAILURE);
            return -1;
    }
	dnssocket = initialisationSocketUDP(argument.port);
	if(dnssocket<0)
	{
		fprintf(stderr,"Port DNS non utilisable\n");
		exit(EXIT_FAILURE);
	}
	boucleServeurUDP(dnssocket, traitement);
	return 0;
}
