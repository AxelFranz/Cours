ecrirelp([]) :- nl.
ecrirelpl([T|Q]) :- put(T), nl, ecrirelpl(Q).
 
epelle :- read(X), name(X,L), ecrirelpl(L).

concat([],X,X).
concat([T|Q],X,[T|L1]) :- concat(Q,X,L1).

aconcat(A1,A2,A) :- name(A1,L1), name(A2,L2), concat(L1,L2,L), name(A,L).

long([], 0).
long([_|Q], L) :- long(Q,L1), L is L1 + 1.

renverse([],[]).
renverse([T|Q], L) :- renverse(Q, L1), concat(L1, [T], L).

sousliste(_,_,0,[]).
sousliste([],_,_,_) :- fail.
sousliste([T|Q],0,N,[T1|Q1]) :- N>0, long(Q,L), N=<L+1,T =:= T1, N1 is N-1, sousliste(Q,0,N1,Q1).
sousliste([_|Q],D,N,L1) :- N>0, long(Q,L), N=<L+1, D>0, D1 is D-1, sousliste(Q,D1,N,L1).

substring(A,D,N,SA) :- name(A,L), name(SA,L1), sousliste(L,D,N,L1).

reversestring(A,A1) :- name(A,L1), renverse(L1,L), name(A1,L).

palin(A) :- name(A,L), renverse(L,L1), name(RA,L1), A==RA.

