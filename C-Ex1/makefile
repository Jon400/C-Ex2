prog1: main.o basicClassification.o advancedClassificationLoop.o
	gcc main.o basicClassification.o advancedClassificationLoop.o -o prog1 -lm
main.o: main.c NumClass.h
	gcc -g -c main.c
basicClassification.o: basicClassification.c NumClass.h
	gcc -g -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -g -c advancedClassificationLoop.c