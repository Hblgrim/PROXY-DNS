#include "dns.h"
#include "dns_etape1.h"
#include "libreseau.h"
#include <assert.h>


void test_socket()
{
    int server = initialisationSocketUDP("4567");
    assert(server > 0);
    printf("Success\n");
}



void test_bad_socket()
{
    int server = initialisationSocketUDP("-4567");
    printf("==%d\n", server);
    assert(server < 0);
    printf("Success\n");
}


int main()
{
    test_socket();
    test_bad_socket();
}