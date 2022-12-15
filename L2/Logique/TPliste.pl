long([], 0).
long([_|Q], L) :- long(Q,L1), L is L1 + 1. 

estdans(_, []) :- fail.
estdans(X, [X|_]).
estdans(X, [_|Q]) :- estdans(X,Q). 

concat([],[],[]).
concat([],T,T).
concat([T|Q],L,[T|L1]) :- concat(Q,L,L1). 

renverse([],[]).
renverse([T|Q], L) :- renverse(Q, L1), concat(L1, [T], L).

insert([],X,[X]).
insert([T|Q],X,[T|[X|Q]]).

inserttri([T|Q],X,[T|[X|Q]]) :- T =< X.
inserttri([T|Q],X,[X|[T|Q]]) :- T > X.

tri([],[]).
tri([X],[X]).
tri([T|Q], L) :- tri(Q, L1), inserttri(L1, T, L).

aplat([],[]).
aplat([T|Q], L) :- atomic(T), aplat(Q, L1), concat([T], L1, L).
aplat([T|Q], L) :- aplat(T, L1), aplat(Q, L2), concat(L1, L2, L).

nieme(_, [], _) :- fail.
nieme(1, [X|_], X).
nieme(N, [_|Q], A) :- nieme(N1, Q, A), N is N1+1 .  
