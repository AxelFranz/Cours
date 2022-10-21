L1² = e U $\Sigma$ x e U $\Sigma$
    = $\omega \in \Sigma ^*,|\omega |<= 2$

Fermeture de Kleene

L\* =  {e} u L u L² u L^n

L* est l'ensemble des mots obtenus en faisant la concaténation d'un nombre quelconque de mots du langage L

# 2. Langages rationnels

Défintion : Soit $\Sigma$ un alphabet, l'ensemble des langages rationnels sur $\Sigma$ est un sous-ensemble de $P(\Sigma^*)$ définie par (sur $\Sigma$ est un sous-entendu la plupart du temps)

* $\empty$ : l'ensemble vide est un langage rationnel

* si a est une lettre de $\Sigma$, {a} est un langage rationnel

* {e} avec e le mot vide est un langage rationnel

* Si L1 et L2 sont des langages rationnels, alors il en est de même pour
  
  * L1 U L2
  
  * L1 . L2
  
  * L1*

On dit aussi que la classe des langages rationnels est stable par union, produitet étoile de Kleene

Exemple plus compliqés avec $\Sigma$ = {a,b}

=> Le langage des mts de longueur paire est rationnel : 

    Preuve : L = {aa,ab,ba,bb} est fini donc rationnel donc L* aussi

=> Ensemble des mots ayant au moins 4 lettres est rationnel

Montrer que $\Sigma^*\backslash\ (w) $

Avec $\Sigma$ = {a,b,c} donnez les expressions rationnelles représentatnt les langages suivants

* langage des mots finissant par a : $\Sigma^*.a$

* langagae des mots ne contenant pas ab $(b \lor c)^*(aa^*c(b\lor c)^*)^*a$

* autant b,c puis a puis aa... puis c 

## 3.1 Automate fini déterministe

M = (K, Sigma, delta, s, F) où

* K : ensemble fini où les éléments sont appelés états

* Sigma : Alphabet

* s c- K état initial

* F c K ensemble des états finaux

* delta : K c Z -> K fonction de transition



### ? Automate fini non déterministe

Intuitivement, on dira qu'un mot est reconnu s'il existe un chemin partant de s jusqu'à un état final (au moins 1) et il est refusé s'il n'en existe aucun.

**Formalisation** : On remplace la fonction de transition $\delta$ par une relation de transition $\triangle$ 

$\triangle(q,\alpha,p)$ signifie que l'on peut passer de l'état q à l'état p en lisant $\alpha$

si $\alpha$ = e, $\triangle(q,e,p)$ signifie que l'on peut passer spontanément de q à p.  Cette transition s'appelle une E-transition.

Avec l'exemple précédent, l'automate N est défini par 

K = {s,1,2} , $\Sigma$ = {a,b}

$\triangle$ = {(s,a,1),(1,b,s),(1,b,2)



On note L(M), l'ensemble de tous les mots acceptés par l'automate M



(q0,bab,q1)

(q1,ab,q3)

(q3,b,q4)

bab est accepté car il est en relation 



La classe des langages acceptés par les automates déterministes est incluse dans celle acceptée par les automates non déteministres.

La réciproque est vraie et on a une preuve constructive
