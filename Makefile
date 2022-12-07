CFLAGS = -g -fPIC -Wall
CC=gcc
AR=ar

.PHONY: all clean

all: connections

connections: my_mat.a main.o
	$(CC) main.o my_mat.a -L. -o connections

my_mat.a: my_mat.o
	 $(AR) rcs my_mat.a my_mat.o

main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

clean:
	rm *.o *.a connections
