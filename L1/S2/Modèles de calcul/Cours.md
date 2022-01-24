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

  





