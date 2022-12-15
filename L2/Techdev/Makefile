CC = gcc
OPT = -Wall -Wextra
EXEC = main.exe

$(EXEC): main.o element.o liste.o 
	$(CC) $^ -o $@ 

main.o: main.c # Règle spécale pour main.c car make faisait pas la bonne commande pour ce fichier
	$(CC) -c $< $(OPT)

%.o: %.c %.h
	$(CC) -c $< $(OPT)

clean:
	rm main.exe *.o
