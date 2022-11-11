prog1: main.o basicClassification.o
	gcc main.o basicClassification.o -o prog1 -lm
main.o: main.c NumClass.h
	gcc -g -c main.c
basicClassification.o: basicClassification.c NumClass.h
	gcc -g -c basicClassification.c -lm