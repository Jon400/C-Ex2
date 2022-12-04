CFLAGS = -g -fPIC -Wall
CC=gcc

.PHONY: all clean

all: connections

connections: my_mat.so
	$(CC) $(CFLAGS) -o connections main.c -L. ./my_mat.so

my_mat.so: my_mat.o
	 $(CC) -shared my_mat.o -o my_mat.so

main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

clean:
	rm *.o *.so connections
	