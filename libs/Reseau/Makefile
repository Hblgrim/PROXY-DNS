SRC=./srcs/libreseau.c
OBJS=$(SRC:.c=.o)
EXEC=libreseau.a
INCLUDES=-I ./includes
LIBRESEAU=-L ../static/
LIB=-lreseau
TESTEXEC=testReseau

TESTSRC=test/test_reseau.c
TESTOBJS=$(SRC:.c=.o)


all: $(OBJS)
	ar rc $(EXEC) $(OBJS)
	mkdir -p ../static
	mv $(EXEC) ../static
%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)


test: $(TESTOBJS)
	$(CC)  $(TESTSRC)  $(LIBRESEAU) $(LIB)  $(INCLUDES) -o $(TESTEXEC)
	mv $(TESTEXEC) ./test


tclean:
	rm -f ./test/$(TESTEXEC)
clean : 
	rm -f $(OBJS) 

mrproper: clean
	rm -f ../static/$(EXEC)
