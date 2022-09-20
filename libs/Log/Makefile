SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
SAVE=libsave.so
DISPLAY=libdisplay.so
GENERIC=libgeneric.so
LIBS= $(SAVE) \
				$(DISPLAY) \
				$(GENERIC) 

TESTSRC=test/test_size.c
TESTOBJS=$(SRC:.c=.o)

INCLUDES=-I ./includes

TESTEXEC=testLog
TESTSRC=
LIBGEN=
LIBSAVE=

all: $(OBJS)
	$(CC) -shared display.o -o $(DISPLAY)
	$(CC) -shared genericLog.o -o $(GENERIC)
	$(CC) -shared save.o -o $(SAVE)
	mkdir -p ../dynamic
	mv $(LIBS) ../dynamic

%.o:%.c
	$(CC) -o $@ -fPIC -c $< $(CFLAGS) $(INCLUDES)

test: $(TESTOBJS)
	$(CC)     test/test_size.c  ../dynamic/libgeneric.so  ../dynamic/libsave.so -ldl -o $(TESTEXEC)


clean : 
	rm -f $(OBJS)
tclean:
	rm -f $(TESTEXEC)

mrproper: clean
	rm -f ../dynamic/$(SAVE)
	rm -f ../dynamic/$(DISPLAY)
	rm -f ../dynamic/$(GENERIC)
