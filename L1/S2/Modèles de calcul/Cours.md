# Lambda Calcul

## Introduction

1930 => Créé par Alonzo Church basé sur la notion de fonction

#### Notion de fonction

Point de vue extensionnel : Réponse à un énoncé de problème

Point de vue intentionnel : Algorithme ou programme

#### Formalisme

Le lambda calcul est un formalisme pour exprimer des fonctions

Les expressions du lamba-calcul notent des fonction anonymes et sont appelées lambda-termes (ou lambda expressions)

## Les Lambda-termes

Un lambda-terme est soit

* Une variable
* Une constante
* Une abstraction de la forme (λx.M)
* Une application de la forme (M *espace* N) où M et N sont des λ-termes

On parle de lambda-calcul pur pour une expression sans constante, sinon il est impur

#### Conventions

* (M) ≡ M

* λx.(M N) ≡ λx.M N

* λx.(λy.M) ≡ λx.λy.M

* (M N) O ≡ M N O

L'application est prioritaire par rapport à l'abstraction

#### Interprétation

* Constante : Nombre, opération (préfixée)

* Variable : Variable en maths

* Abstraction λx.M : fonction anonyme qui à tout x associe M

* Application M N : Image de N par M ==> M(N) en programmation
  
  | Maths         | HASKELL       | OCaml      | Lambda-calcul |
  | ------------- | ------------- | ---------- | ------------- |
  | x -> x        | \x -> x       | fun x -> x | λx.x          |
  | (x -> 2x) (1) | (\x -> 2x)(1) |            | (λx. * 2 x) 1 |

#### Curryfication

Opération qui consiste à transformer un fonction qui prend un N-uplet en une fonction qui prend N arguments un à un dans cet ordre.

​    
