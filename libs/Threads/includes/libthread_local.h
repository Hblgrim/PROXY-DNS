#ifndef LIBTHREAD_LOCAL_H
#define LIBTHREAD_LOCAL_H


#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

#define NUMBER_MUTEX  20
typedef struct arg_s{
    void * (*f)(void *);
    void* arg;
}arg_t;

pthread_mutex_t mtx[NUMBER_MUTEX];

 

#endif
