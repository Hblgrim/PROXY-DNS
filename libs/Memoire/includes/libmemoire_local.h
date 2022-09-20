#ifndef LIBMEMOIRE_H
#define LIBMEMOIRE_H


#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <stdint.h>
#include <string.h>


typedef struct{ 
        unsigned char* data; 
        unsigned char* writer_ptr;  
        unsigned char* end;
        unsigned char* read_ptr;
        size_t  size;
        size_t to_read;
}memoire_t;
bool memoryIsFull(void);
int allocateMemory(size_t size);
int writeMemory(void *data, uint8_t size);
void *readMemory(uint8_t *size);
bool memoryIsEmpty(void);

size_t    availableMemory(void);

void deallocate_memory();



#endif
