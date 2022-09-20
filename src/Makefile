SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
EXEC=server
LIBSTATIC=-L ../libs/static/
LIBDYNAMIC=-L ../libs/dynamic/


RESEAUINC=-I ../libs/Reseau/includes
LOGINC=-I ../libs/Log/includes
THREADINC=-I ../libs/Threads/includes
MEMOIREINC=-I ../libs/Memoire/includes
SHAREDINC=-I ../libs/sharedMemory/includes
LIB=-lreseau -lgeneric -lthread -lmemoire -lshared
INCLUDES=-I ./includes \
						$(RESEAUINC) \
						$(LOGINC) \
						$(SHAREDINC)\
						$(THREADINC) \
						$(MEMOIREINC)


all: $(OBJS)
	$(CC)    -o $(EXEC) $^ $(LIBSTATIC) $(LIBDYNAMIC) $(LIB) -ldl
	mkdir -p ../bin
	mv $(EXEC) ../bin

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

clean : 
	rm -f $(OBJS)  
mrproper: clean
	rm -f ../bin/$(EXEC)

.PHONY : all 