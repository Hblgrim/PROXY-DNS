SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
MEMOIRE=libmemoire.so
LIBS=$(MEMOIRE) 
TESTSRC=test/memeory_unittets.c
TESTOBJS=$(SRC:.c=.o)
TESTEXEC=testMemoire
LIBMEMOIRE=../dynamic/libmemoire.so 

INCLUDES=-I ./includes

all: $(OBJS)
	$(CC) -shared libmemoire.o -o $(MEMOIRE)
	mkdir -p ../dynamic
	mv $(LIBS) ../dynamic

%.o:%.c
	$(CC)  -o $@ -fPIC -c  $< $(CFLAGS) $(INCLUDES)

test: $(TESTOBJS)
	$(CC) $(TESTSRC) -c -o $(TESTOBJS) 
	$(CC) $(TESTSRC) $(LIBMEMOIRE) -ldl -o $(TESTEXEC)

clean : 
	rm -f $(OBJS) 
mrproper: clean
	rm -f ../dynamic/$(MEMOIRE)
