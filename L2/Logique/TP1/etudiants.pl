etudiant('Pierre Lapotre').
etudiant('Paul Bonvoisin').
etudiant('Jean Weiss-Muller').
etudiant('Toto Bellemirette').
etudiant('Jean Aivudotre').
etudiant('Kent Bowie').
etudiant('Alan Die').
etudiant('Alain Sisep').
etudiant('Alex Sisep').
etudiant('Cedric Edrac').
etudiant('Gaston Lagaffe').
etudiant('Bernard Lehrmitte').
etudiant('Laurent Lienju').
etudiant('Henri Lepetit').
etudiant('Eric Hochaud').
etudiant('Hans-Hubert Worm').

etudiante('Celia Vih').
etudiante('Bernadette Scoubidou').
etudiante('Nanette Rakchaud').
etudiante('Julie Nouvlahou').

habite('Pierre Lapotre', 3, 'rue des ecureuils').
habite('Paul Bonvoisin', 0, 'lieu dit de l\'impasse').
habite('Jean Weiss-Muller', 5,'rue du renard prechant').
habite('Toto Bellemirette', 0, 'quartier des pecheur').
habite('Jean Aivudotre', 3, 'rue des ecureuils').
habite('Kent Bowie', 4, 'rue des ecureuils').
habite('Alan Die', 5, 'rue des ecureuils').
habite('Alain Sisep', 5, 'rue du renard prechant').
habite('Alex Sisep', 0, 'lieu dit de l\'impasse').
habite('Cedric Edrac', 23, 'rue Oberweg').
habite('Gaston Lagaffe', 0, onzieme).
habite('Bernard Lehrmitte', 22, 'rue Oberweg - Nancy').
habite('Laurent Lienju', 0, nancy).
habite('Henri Lepetit', 0, krutenau).
habite('Eric Hochaud', 6, 'rue des bourgeois').
habite('Celia Vih', 6, 'rue des maçons').
habite('Hans-Hubert Worm', 0, colmar).
habite('Bernadette Scoubidou', 0, toulouse).
habite('Nanette Rakchaud',0, premier).
habite('Julie Nouvlahou', 7, 'rue des Pyrénées').

etud(X) :- etudiant(X).
etud(X) :- etudiante(X).

hab(X,Y,Z) :- habite(X,Y,Z),Y>0.

voisins(X,Y) :- hab(X,N,R),hab(Y,N,R),X\==Y.
voisins(X,Y) :- hab(X,N,R),hab(Y,N1,R),N is N1+1.
voisins(X,Y) :- hab(X,N,R),hab(Y,N1,R),N1 is N+1.
