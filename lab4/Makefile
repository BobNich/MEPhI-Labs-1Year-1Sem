CC=cc

CFLAGS=-std=c99 -c -Wall

all: lab4

lab4: lab4.o errors_lab4.o file_struct.o struct_transf.o sort_struct.o timing_struct_lab4.o
        $(CC) lab4.o errors_lab4.o file_struct.o struct_transf.o sort_struct.o timing_struct_lab4.o -o lab4

main.o: lab4.c
        $(CC) $(CFLAGS) lab4.c

errors.o: errors_lab4.c
        $(CC) $(CFLAGS) errors_lab4.c

file_struct.o: file_struct.c
        $(CC) $(CFLAGS) file_struct.c

struct_transf.o : struct_transf.c
        $(CC) $(CFLAGS) struct_transf.c

sort_struct.o : sort_struct.c
        $(CC) $(CFLAGS) sort_struct.c

timing.o : timing_struct_lab4.c
        $(CC) $(CFLAGS) timing_struct_lab4.c

clean:
        rm -rf *.o lab4




