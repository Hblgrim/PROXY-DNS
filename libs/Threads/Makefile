SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
THREAD=libthread.so
TESTSRC=test/thread_test.c
TESTOBJS=$(SRC:.c=.o)
LIBS=$(THREAD) 	 

INCLUDES=-I ./includes

all: $(OBJS)
	$(CC) -pthread -shared libthread.o -o $(THREAD)
	mkdir -p ../dynamic
	mv $(LIBS) ../dynamic

%.o:%.c
	$(CC) -pthread -o $@ -fPIC -c  $< $(CFLAGS) $(INCLUDES)


test: $(TESTOBJS)
	$(CC) $(TESTSRC) -c -o $(TESTOBJS) 
	$(CC)    test/thread_test.c ../dynamic/libthread.so -ldl -o test2

clean : 
	rm -f $(OBJS) 
mrproper: clean
	rm -f ../dynamic/$(THREAD)
