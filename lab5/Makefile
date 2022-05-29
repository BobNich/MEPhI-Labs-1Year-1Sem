CC=cc

CFLAGS=-std=c99 -c -Wall

all: lab5

lab5: lab5.o errors_lab5.o matrix_change.o matrix_file.o
        $(CC) lab5.o errors_lab5.o matrix_file.o matrix_change.o -o lab5

main.o: lab5.c
        $(CC) $(CFLAGS) lab5.c

errors.o: errors_lab5.c
        $(CC) $(CFLAGS) errors_lab5.c

file_struct.o: matrix_file.c
        $(CC) $(CFLAGS) matrix_file.c

struct_transf.o : matrix_change.c
        $(CC) $(CFLAGS) matrix_change.c

clean:
        rm -rf *.o lab5
