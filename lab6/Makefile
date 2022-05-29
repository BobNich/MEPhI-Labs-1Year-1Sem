CC=cc

CFLAGS=-std=c99 -c -Wall

all: lab6

lab6: lab6.o list_lab6.o
        $(CC) lab6.o list_lab6.o -o lab6

main.o: lab6.c
        $(CC) $(CFLAGS) lab6.c

list_lab6.o: list_lab6.c
        $(CC) $(CFLAGS) list_lab6.c

clean:
        rm -rf *.o lab6

