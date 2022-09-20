#ifndef __ARGS_H__
#define __ARGS_H__

#include <stdbool.h>
#include <getopt.h>

#define MAX_PORT_SIZE	8
#define MAX_SERVICE_SIZE	256
#define MAX_CHOICE_SIZE	300
#define MAX_PARAMS_SIZE	256
#define DEFAULT_STRATEGY "libdisplay.so"
#define DEFAULT_INIT_LOG "log.txt"

#define DNS_PORT_STR	"53"

typedef struct args_s {
	bool help;
	char port[MAX_CHOICE_SIZE];
	char server[MAX_CHOICE_SIZE];
	char choice[MAX_CHOICE_SIZE];
	char params[MAX_PARAMS_SIZE];

} args_t;

extern args_t argument;

void analyseArgs(int argc, char *argv[]);

#endif
