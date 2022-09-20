#ifndef DNS_ETAPE1_H
#define DNS_ETAPE1_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <assert.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <string.h>


typedef struct s_header{
  uint16_t xid;      
  uint16_t flags;    
  uint16_t qdcount;  
  uint16_t ancount;  
  uint16_t nscount;  
  uint16_t arcount;  
} t_header;

typedef struct s_question{
  unsigned char *name;        
  uint16_t dnstype;  
  uint16_t dnsclass; 
} t_question;

typedef struct s_answear{
  uint16_t compression;    
  uint16_t type;
  uint16_t class;
  uint32_t ttl;
  uint16_t length;
  struct in_addr addr;
} __attribute__((packed)) t_answear;


#endif
