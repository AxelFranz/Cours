CC = gcc
OPT = -Wall -Wextra
EXEC = main

$(EXEC): main_broken.o liste.o 
	$(CC) $^ -o $@ 

%.o: %.c %.h
	$(CC) -c $< $(OPT)

clean:
	rm -rf main *.o doc/

doc: 
	doxygen
