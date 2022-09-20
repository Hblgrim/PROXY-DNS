#include "libthread_local.h"
#include "libthread.h"
#include <stdint.h>


void* intfonction(void* v)
{
    arg_t *argument = v;
    argument->f(argument->arg); //
    free(argument->arg);
    free(argument);
    return NULL;
}

void *test(void *s)
{
    printf("tes\n");
    (void)s;
    return NULL;
}

int launchThread(void *(*fonction)(void *), void *arg, size_t argSize)
{
 
    pthread_t thread;
    pthread_attr_t attr;                                         
    pthread_attr_init(&attr);                                   
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    arg_t *a = malloc(sizeof(arg_t));
    a->arg = malloc(argSize);
    memcpy(a->arg, arg, argSize);
    a->f = fonction;
    if (pthread_create(&thread, &attr, intfonction, a) != 0)
    {
            perror("Failed to create thread");
            return -1;
    }
    return 0;
}

void int_mutex()
{
    for (size_t i = 0; i < NUMBER_MUTEX; i++)
    {
        pthread_mutex_init(&mtx[i], NULL);
    }
}

void lock_mutex(uint8_t index)
{
    pthread_mutex_lock(&mtx[index]);
}

void unlock_mutex(uint8_t index)
{
    pthread_mutex_unlock(&mtx[index]);
}
