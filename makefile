CFLAGS = -g -fPIC -Wall
CC=gcc
AR=ar

.PHONY: loops recursives recursived loopd all clean

loops: libclassloops.a
libclassloops.a: advancedClassificationLoop.o basicClassification.o
	$(AR) rcs libclassloops.a advancedClassificationLoop.o basicClassification.o
recursives: libclassrec.a
libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	$(AR) rcs libclassrec.a advancedClassificationRecursion.o basicClassification.o
recursived: libclassrec.so
libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	 $(CC) -shared advancedClassificationRecursion.o basicClassification.o -o libclassrec.so
loopd: libclassloops.so
libclassloops.so: advancedClassificationLoop.o basicClassification.o
	 $(CC) -shared advancedClassificationLoop.o basicClassification.o -o libclassloops.so
mains: libclassrec.a main.o
	$(CC) main.o libclassrec.a -L. -o mains
maindloop: libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.c ./libclassloops.so
maindrec: libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.c ./libclassrec.so
all: loops recursives recursived loopd mains maindloop maindrec
clean:
	rm *.o *.a *.so mains maindloop maindrec


main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c

