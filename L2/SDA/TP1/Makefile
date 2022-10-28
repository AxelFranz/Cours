ex1 : test.o pile_char.o
	gcc $^ -o xpile

ex2: test.o pile_char2.o
	gcc $^ -o xpile

%.o:%.c
	gcc -c $< -o $@ 

test.c: pile_char.h pile_char2.h
pile_char.c:pile_char.h
pile_char2.c:pile_char2.h

clean:
	rm *.o xpile
	
