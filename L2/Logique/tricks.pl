% coupure : stopper l'exécution quand pas nécessaire
!.

% pour évaluer des expressions : is
% comparations mathématiques : =:=, =\=, >=, =<, <, >

% pour "copier" syntaxiquement des expressions : =
% comparaisons syntaxiques : ==, \==

% activer / désactiver le "déboguer"
% trace / notrace (dans le terminal)

% concaténer liste
append(L1, L2, Lres).

% concaténer string
atom_concat(L1, L2, Lres).

% transforme string en ascii
name(Chaine, Ascii).

% appartenance liste
member(X, L).

% non logique
not(X).

% longeur liste
length(L, Taille).

% longueur chaine
atom_length(Chaine, Taille).

% Get random value between L and H
random(L,H,X).	

% Get all values between L and H
between(L,H,X).	

% Add 1 and assign it to X
succ(X,Y).

% Get absolute value of X
abs(X).	

% Get largest value between X and Y
max(X,Y).	

% Get smallest value between X and Y
min(X,Y).	

% Round a value near to X
round(X).	

% Convert float to integer, delete the fractional part
truncate(X).	

% Round down
loor(X).	

% Round up
ceiling(X).	

% Square root
sqrt(X).

% print sur le terminal
write(X).

% lire depuis le terminal
read(X).

% renverser une liste
reverse(L, Lreversed).

% supprimer toutes les occurences dans une liste
delete(L, X, Lres).

% supprimer une occurence dans une liste
select(X, L, Lres).

% supprimer tous les éléments de L2 dans L1
substract(L1, L2, Lres).

% permuter les éléments d'une liste
permutation(L, Lres).

% dernier élément d'une liste
last(L, X).

% max liste
max_list(L, Max).

% min liste
min_list(L, Min).

% somme éléments d'une liste
sum_list(L, Somme).

% trier une liste
sort(L, Ltriee).
