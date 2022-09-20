#ifndef LIBTHREAD_H
#define LIBTHREAD_H

#include <sys/types.h>
#include <stdint.h>
 
int launchThread(void *(*fonction)(void *), void *arg, size_t argSize);

void int_mutex();

void lock_mutex(uint8_t index);

void unlock_mutex(uint8_t index);

#endif