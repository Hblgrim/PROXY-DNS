#include "log_dns.h"
#include "genericLog.h"
#include "genericLog_local.h"

int (*log_Strategy)(logMsg_t *);
void *handle;
char *error;
int (*init_Strategy)(void*);
int (*end_Strategy)();


int loadStrategy(char *strategie){

	if (strategie==NULL){return 0;}
	handle = dlopen(strategie, RTLD_LAZY);
	if (!handle) {
        fputs (dlerror(), stderr);
        return -1;
    }
	return 0;
}

int logStrategy(logMsg_t * message_log)
{	

       log_Strategy = dlsym(handle, "addLog");
        if ((error = dlerror()) != NULL)   {
                fputs(error, stderr);
                return -1;
        }
        if((*log_Strategy)(message_log) == -1){
                printf("error\n");
                return -1;
        }
	return 0;
}

int initStrategy(void *arg){
	init_Strategy = dlsym(handle, "initLog");
        if ((error = dlerror()) != NULL)  {
            	fputs(error, stderr);
            	return -1;
        }
	if((*init_Strategy)(arg) == -1){
		printf("error\n");
		return -1;
	}
	return 0;
}



int endStrategy()
{
	end_Strategy = dlsym(handle, "closeLog");
    if ((error = dlerror()) != NULL)  {
            	fputs(error, stderr);
            	return -1;
    }
	if((*end_Strategy)() == -1){
		printf("error\n");
		return -1;
	}
	return 0;
}


