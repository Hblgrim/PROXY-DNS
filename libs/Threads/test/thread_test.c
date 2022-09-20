# include "../includes/libthread.h"
# include "../includes/libthread_local.h"
#include <assert.h>


static  int test = 0;
void *fonction_long_arg(void *data)
{
   
    long *num =  data;
    assert(num != NULL);
    assert(*num == 456789);
    printf("Success\n");
        return NULL;
}


void    test_thread_long_arg()
{
    long num = 456789;
    launchThread(fonction_long_arg, &num , sizeof(num));
}



void *random_test(void *d)
{
    (void)d;
    lock_mutex(0);
    ++test;
    unlock_mutex(0);
    return NULL;
}

void test_mutex()
{

    int_mutex();
    for (size_t i = 0; i < 100000; i++)
    {
            launchThread(random_test, NULL , 0);
    }
    int i = 0; // wiat the thread
    while (i<1000000)
    {
        i++;
    }
    assert(test == 100000);
    test = 0;
    printf("Success\n");

}

int main()
{
    test_thread_long_arg();
    test_mutex();
}

