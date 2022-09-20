#include "./includes/libmemoire.h"
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include "libmemoire_local.h"
memoire_t* espace; 

int allocateMemory(size_t size){ 

	espace = malloc(sizeof(memoire_t)); 
	bzero(espace, sizeof(memoire_t));
	espace->data = (unsigned char *)malloc(size);
	espace->size = size;
	espace->end = espace->data + size;
	espace->writer_ptr = espace->data ; 
	espace->read_ptr = espace->data ; 
	return 0;        
}



void	deallocate_memory()
{
	free(espace->data);
	free(espace);
	espace = NULL;
}


size_t availableMemory(void)
{
	if (espace->to_read == 0)
		return espace->size;
	return  espace->end - espace->writer_ptr;
}

bool memoryIsFull(void)
{
	return availableMemory() == 0;
}

bool memoryIsEmpty(void)
{
	return espace->to_read == 0;
}


static void 		*addvance_write()
{
	if (espace->writer_ptr + 1 == espace->end)
		return espace->data;
	return  espace->writer_ptr + sizeof(uint8_t);
}


static void 		*addvance_read()
{
	if (espace->read_ptr + 1 == espace->end)
		return espace->data;
	return  espace->read_ptr + sizeof(uint8_t);
}

int writeMemory(void *data, uint8_t size)
{   

	size_t count = 0;
	unsigned char *_data = data;
	if (size > espace->size)
	{
		return (-1);
	}
	if (espace->writer_ptr +  (size_t)size  +1 > espace->end)
	{
		size_t rest = espace->end - espace->writer_ptr;
		if (espace->data + (size +1 - rest)   > espace->read_ptr)
		{
			return (-1);
		}
		if (espace->writer_ptr  + 1 == espace->end)
			espace->writer_ptr = espace->data;
		memcpy(espace->writer_ptr, &size, sizeof(size));
		espace->writer_ptr =  addvance_write();
		if (espace->writer_ptr+1 == espace->end)
			espace->writer_ptr = espace->data;
		while (count < size)
		{
			*(uint8_t *)espace->writer_ptr =  _data[count];
			espace->writer_ptr = addvance_write();
			count ++;
		}
		espace->to_read ++;
		return 0;
	}
	memcpy(espace->writer_ptr, &size, sizeof(size));
	espace->writer_ptr += sizeof(size);
	memcpy(espace->writer_ptr, data, size);
	espace->writer_ptr += size;
	espace->to_read++;
	return (0);
}


void *readMemory(uint8_t *size)
{
	void *ret;
	uint8_t _size;

	if (espace->to_read  <= 0 && espace->read_ptr + (size_t)size > espace->writer_ptr)
	{
		*size = 0;
		return NULL;
	}
	if (espace->end == espace->read_ptr + 1)
		espace->read_ptr = espace->data;
	memcpy(&_size, espace->read_ptr, sizeof(_size));
	*size  = _size;
	espace->read_ptr =  addvance_read();
	if (espace->end == espace->read_ptr + 1)
		espace->read_ptr = espace->data;
	ret = malloc((size_t)_size);
	if (espace->read_ptr +  (size_t)_size > espace->end)
	{
		size_t rest = espace->end - espace->read_ptr;
		if (rest == 0)
			espace->read_ptr = espace->data;
		size_t restInDebut = _size - rest;
		memcpy(ret, espace->read_ptr, rest);
		espace->read_ptr = rest == 0 ? espace->data + rest : espace->data;
		memcpy(ret, espace->read_ptr + rest, restInDebut);
	}
	else
	{
		memcpy(ret, espace->read_ptr, (size_t)_size);
		espace->read_ptr += _size;
	}
	espace->to_read --;

	return ret;
}
