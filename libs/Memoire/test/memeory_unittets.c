#include "../includes/libmemoire_local.h"
#include "../includes/libmemoire.h"
#include <assert.h>
#include <string.h>

// extern memoire_t* espace; 

// static void printMemory()
// {

//     for (int i=0; i<espace->size; i++) 
// 	{
// 		printf("[%c|%d] ", espace->data[i],  espace->data[i]);
//     }
// 	printf("\n");
// }



void test_allocateMemory_avilable_memory()
{
     allocateMemory(5000);
     assert(availableMemory() == 5000);
     deallocate_memory();
     printf("Success\n");
}
void test_allocateMemory_avilable_memory_0(size_t size)
{
     allocateMemory(size);
     assert  (allocateMemory(size) == 0);
     deallocate_memory();
    printf("Success\n");
}


void test_write_memory()
{
    allocateMemory(5000);
    long long num = 123456789;
     int ret = writeMemory(&num, sizeof(num));
     assert(ret == 0);
     deallocate_memory();
    printf("Success\n");
}

void test_write_memory_read_memory()
{
    allocateMemory(5000);
    long long num = 123456789;
    void *ptr;
    long long *r;
    uint8_t size;
    int ret = writeMemory(&num, sizeof(num));
    ptr = readMemory(&size);
    r = (long long *)ptr;
     assert(ret == 0);
     assert(ptr != NULL);
     assert(size == sizeof(num));
     assert(num == *r);
     deallocate_memory();
    printf("Success\n");
}



void test_memory_is_empty()
{
    allocateMemory(10);
    long long num = 123456789;
    void *ptr;
    long long *r;
    uint8_t size;
    int ret = writeMemory(&num, sizeof(num));
     assert(memoryIsEmpty() != true);
    ptr = readMemory(&size);
    r = (long long *)ptr;
     assert(ret == 0);
     assert(ptr != NULL);
     assert(size == sizeof(num));
     assert(num == *r);
     assert(memoryIsEmpty() == true);    
     printf("Success\n");
     deallocate_memory();
}


void test_memory_not_enough()
{
    allocateMemory(5);
    long long num = 123456789;
    // long long *r;
    // uint8_t size;
    int ret = writeMemory(&num, sizeof(num));
    assert(ret == -1);
    printf("Success\n");
    deallocate_memory();

}


void test_memory_circle()
{
    allocateMemory(10);
    long long num = 8888888; 
    void *ptr;
    long long *r;
    uint8_t size = 0;
    int ret = writeMemory(&num, sizeof(num)); // write 9  // sizeof(lonlo)
    assert(ret == 0);
    ptr = readMemory(&size);
    r = (long long *)ptr;
    assert(*r == num);
    ret = writeMemory(&num, sizeof(num));
    assert(ret == 0);
    ptr = readMemory(&size);
    r = (long long *)ptr;
    assert(*r == num);
    deallocate_memory();
}

void test_memory_circle_2()
{
    allocateMemory(10);
    uint8_t size;
    char *str = malloc(100);
    strcpy(str, "abcd");
    int ret = writeMemory(str, 5);
    assert(ret == 0);
    readMemory(&size);
    strcpy(str, "efjkl");
     ret = writeMemory(str, 6);
    deallocate_memory();
}



int main()
{
    test_allocateMemory_avilable_memory();
    test_allocateMemory_avilable_memory_0(80);
    test_allocateMemory_avilable_memory_0(50);
    test_write_memory();
    test_write_memory_read_memory();
    test_write_memory_read_memory();
    test_memory_is_empty();
    test_memory_not_enough();
    test_memory_circle();
    test_memory_circle_2();
    return 0;
}