CC=gcc
CFLAGS=-c -Wall -g
OBJS=cache_functions.o cache_program.o

all: cache_program

cache_program: $(OBJS)
			   $(CC) $(CFLAGS) cache_functions.o cache_program.c -o cache_program

cache_functions.o: cache_functions.c
				   $(CC) $(CFLAGS) cache_functions.c cache_functions.h
