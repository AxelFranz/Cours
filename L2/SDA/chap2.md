# 2.  Programmation

#### 2.1 Utilisation de types prédéfinis (bool,nat,rat,reel,car,... : base.h)

#### 2.2 Renommage des types de base

#### 2.3 Structure de données

#### 2.4 Prog fonctionnelle

#### 2.5 Rappels sur les pointeurs

Pour réaliser un passage par adresse

* Soit avec t x et en paramètre &x 

* Soit avec t* x et en paramètre x

Allocation dynamique:

ex : int* p = malloc(sizeof(int)

\#define sizeof(t) ((Nat sizeof(t))

\#define malloc(t) ((t*)malloc(sizeof(t)))
