#include "log_dns.h"
#include "genericLog.h"

#include "genericLog_local.h"


int initLog(void *arg){
	time_t tm;
	time(&tm);
    file = fopen((char*)arg,"a+");
	fprintf(file,"Connection in log file at : %s",ctime(&tm));
    if(!file) return -1;
    return 0;
}

int addLog(logMsg_t *message_log){
    for(int i=0; i<(message_log)->size; i++){
        fprintf(file, "%x ", message_log->msg[i]);
    }
    fprintf(file, "\n");
    return 0;
}


int closeLog(){ 

    if ( fclose(file) ) {perror("fclose error"); return -1;}
    else printf("Log saved successfully .\n");
    return 0;
}
