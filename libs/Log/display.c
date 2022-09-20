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

	for(int i=0; i<message_log->size; i++){
		int start_of_name=0,size_name=0,size_domaine=0;
		bool start=true, name=false, domaine=false;
		if(i == size_start_of_name){
			start_of_name=(int)message_log->msg[i];
			i++;	
			for(int j=0; j<message_log->size; j++){
				if(j==start_of_name && start){
					fprintf(file, ".");
                    printf(".");
					size_name=(int)message_log->msg[i];
					i++;
					j=0;
					start=false;
					name=true;
				}
				if(j==size_name && name){
					fprintf(file, ".");
                    printf(".");
					size_domaine=(int)message_log->msg[i];
					j=0;
					i++;
					name=false;
					domaine=true;
				}
				if(j==size_domaine && domaine) break;
				fprintf(file, "%c", message_log->msg[i]);
                printf("%c", message_log->msg[i]);
				i++;
			}
		}

	}
	fprintf(file, "\n");
    printf("\n");
	return 0;
}


int closeLog(){ 

    if ( fclose(file) ) {perror("fclose error"); return -1;}
    else printf("Log saved successfully .\n");
    return 0;
}