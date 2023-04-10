CC=gcc
CFLAGS=-Wall -g
objects=frisbee.o stack.o

all: frisbee

frisbee: $(objects)
	${CC} ${CFLAGS} -o frisbee $(objects)

frisbee.o: frisbee.c stack.h
stack.o: stack.c stack.h
