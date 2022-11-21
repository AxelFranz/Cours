INCFLAGS=-I ~/DNT
ex1 : test.o ListeDouble.o
	gcc -g $(INCFLAGS) $^ -o xListe

%.o:%.c
	gcc -g $(INCFLAGS) -c $< -o $@ 

clean:
	rm *.o xListe
	
