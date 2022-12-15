estarbrebin(t(nil,_,nil)).
estarbrebin(t(AG,_,nil)) :- estarbrebin(AG).
estarbrebin(t(nil,_,AD)) :- estarbrebin(AD).
estarbrebin(t(AG,_,AD)) :- estarbrebin(AG), estarbrebin(AD).

ag(t(nil,_,_),nil).
ag(t(AG,_,_),AG).

ad(t(_,_,nil),nil).
ad(t(_,_,AD),AD).

rac(t(_,X,_),X).

ed(t(_,X,nil),X) :- !.
ed(t(_,_,AD), X) :- ed(AD, X).

eg(t(nil,X,_),X) :- !.
eg(t(AG,_,_), X) :- eg(AG, X).

dans(t(nil,X,nil),X).
dans(t(AG,X,_),Y) :- X =\= Y, dans(AG,Y), !.
dans(t(_,X,AD),Y) :- X =\= Y, dans(AD,Y).

nn(nil,0).
nn(t(AD,_,AG),N) :- nn(AG,NG), nn(AD,ND), N is 1 + ND + NG.
