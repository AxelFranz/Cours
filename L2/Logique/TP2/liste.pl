longueur([],0).
longueur([_|R],X) :- longueur(R,Y), X is Y+1.

estdans(_,[]) :- false.
estdans(Elem,[X|Y]) :- X == Elem; estdans(Elem,Y). 


