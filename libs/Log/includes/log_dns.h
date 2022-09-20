#ifndef __LOG_DNS_H__
#define __LOG_DNS_H__

#define size_start_of_name 12

typedef struct logMsg_s {
	int size;
 unsigned	char *msg;
} logMsg_t;

int initLog(void *);
int addLog(logMsg_t *);

int closeLog();
#endif
