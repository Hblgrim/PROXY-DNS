export CC=gcc
export CFLAGS=-Wall -Wextra -Werror -g  

SUBDIRS = libs/Reseau \
				libs/Log \
				libs/Threads \
				libs/Memoire\
				libs/sharedMemory\
				src
			

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir -f Makefile $@; \
	done

debug: all
debug: CFLAGS+=-g -DDEBUG

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir -f Makefile $@; \
	done

