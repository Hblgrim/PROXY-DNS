SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
SHAREDM=libshared.so
LIBS= $(SHAREDM)

TESTOBJS=$(SRC:.c=.o)

INCLUDES=-I ./includes

all: $(OBJS)
	$(CC) -shared shared.o -o $(SHAREDM)
	mkdir -p ../dynamic
	mv $(LIBS) ../dynamic

%.o:%.c
	$(CC) -o $@ -fPIC -c $< $(CFLAGS) $(INCLUDES)

clean : 
	rm -f $(OBJS)

mrproper: clean
	rm -f ../dynamic/$(SHAREDM)