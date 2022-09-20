#ifndef LIBMEMOIRE_LOCAL_H
#define LIBMEMOIRE_LOCAL_H

#include <stdint.h>
#include <sys/types.h>
#include <stdbool.h>


bool memoryIsFull(void);
int allocateMemory(size_t size);
int writeMemory(void *data, uint8_t size);
void *readMemory(uint8_t *size);
bool memoryIsEmpty(void);
size_t    availableMemory(void);
void deallocate_memory();

#endif
