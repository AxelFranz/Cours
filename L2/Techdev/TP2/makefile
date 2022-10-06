main: main.o alea.o io.o tri.o
	gcc main.o alea.o io.o tri.o -o main

main.o: alea.o io.o tri.o
	gcc -c main.c

alea.o:alea.h alea.c
	gcc -c alea.c

io.o:io.h alea.c
	gcc -c io.c

tri.o:tri.h tableau.h tri.c
	gcc -c tri.c

clean:
	rm alea.o io.o tri.o main.o