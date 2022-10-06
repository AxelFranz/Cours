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

* langagae des mots ne contenant pas ab $\Sigma^*\backslash ab $

* autant b,c puis a puis aa... puis c 

### 
