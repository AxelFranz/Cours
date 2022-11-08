# Analyse de programme : complexité

#### Objectif : Evaleur le temps d'exécution et l'espace mémoire utilisé

## Exemple d'évaluation de la complexité

Recherche dans une liste tirée de n >= éléments de sorte S, muni de l'ordre <=

La lsite est supposée implantée de manière contigue

```c
Nat rech(Listet l, S z){ // A
    Nat n=lgr(l), i=1; // A
    while(i < n && l[i]<z) i++; // B
    return z==l[i]?i:0; // C
}
```

###### Séquentiel  MAXseq(n) = A + B(n-1) + C

* Comportement asymptotique n->$+\infin$ MAXseq(n) ~ B n
* Ordre de grandeur, il existe une constante k>0 el que MAXseq(n) <= Kn

=> Il est donc en O(n)

###### 1.2 recherche dichomotique

```c
Nat rech(Liste l, S z{
    Nat a=1, b=lgr(l);Nat n;
    while (a!=b){
        m=(a+b)/2;
        if(z < l[m])b=m;
        else a=n+1;
    }
    return l[a]==z?a:0;
)
```

On a 2^p-1<n<=2^p donc p=log²n

Pour évaluer la durée d'exécution (complexité), on choisit une unité d'évaluation du temps comme étant la durée d'un ou plusieurs opérations fondamentales

#### 2. Complexité en temps

Pour un algorithme A, on note Dm l'ensemble des données possibles de taille n

La complexté, ou coût en temps, de A est pour une donnée d$\in$Dn, la durée d'exécution  notée Ca(d)

- Dans le meilleur des cas MinA(n)=min d$\in$DnCa(d)

- Dans le pire, c'est le max

- En moyenne : $\sum_{d\in Dn}{pr(d) Ca(d)}$ où pr(d) est la probabilité de trailer la dnnée d avec $0 <= pr(d)$ et$\sum_{d\in Dn}{pr(d)}=1$

Exemple de calcul d'une complexité en moyenne

rech(l,z) si z==l[i] alors i snon fin

                avec n=lgr(l)

                          i= init 1 ttq i < n && z=/= l[i] rep i+1

Dn={(l,z}|lgr(n)}, n>= 1

p = probabilité que z soit dans l -> pr(l,l[i]) = pi=p/n

q = probabilité que z ne soit pas dans l donc q =1-p

Pour évaluer la cmplexité, comptons le nombre de comparaisons de z avec un éllément de la liste dans la boucle, sans compter la dernière comparaison.

On a crech(l,q=l[i])=i comparaisons

Ne pas trouver z dans l, nécessite z comparaisons

Moyenne : complexité en moyenne d'une recherche positive est de n+1/2

## Ordre de grandeur




