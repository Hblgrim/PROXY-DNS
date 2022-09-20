#include "../includes/log_dns.h"
#include "../includes/genericLog.h"
#include "../includes/genericLog_local.h"
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void test_save_init()
{
    assert(initLog("file.txt") == 0);
    assert(closeLog() == 0);
    int fd = open("file.txt", O_RDWR); // check if fil exist
    assert(fd > 0);
}


void test_save_write()
{
    assert(initLog("file.txt") == 0);
    logMsg_t *t = malloc(sizeof(logMsg_t));
    t->msg="qqqqq";
    t->size=strlen("qqqqq");
    assert(addLog(t) == 0);
    assert(closeLog() == 0);
    printf("Success\n");
}


void test_loadStrategy(char *strat){

	printf("Test allocateMemory:=%s :",(char *)strat);
	assert(loadStrategy(strat)== -1);
	printf("Success\n");
	
}



int main ()
{
    test_save_init();
    test_save_write();
}