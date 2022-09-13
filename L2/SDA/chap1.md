# Structure de données et Algorithmique

## 1. Introduction à la spécification et rappels de programmation

### 1.1 Exemple d'illustration

<ins>**Enoncé**</ins> : Calculer x^n pour x rationnel et n entier positif 

<ins>**Spécification formelle**</ins> : 

- Prototype puiss : Rat Nat => Rat

- Eliminer 0^0 => x != 0 || n != 0
* Si pré_puis(x,n) == vrai alors y = puiss(x,n). Sinon message d'erreur

<ins>**Définitions / Axiomes**</ins>: 

* Entiers naturels : 2 opérations suffisent à les construire tous
  
  * 0 : Nat
  
  * n+1 : Nat => Nat

**1ere définition** : Par rapport aux constructeurs des entiers naturels 0 et ()+1

* puiss(x,0) = 1

* puiss(x,n+1) = x * puiss(x,n)

**2e définition "directe"** : 

* puiss(x,n) => si n==0 alors 1 sinon x * puiss(x,n-1)

**3e définition itérative** :

* puiss(x,n) = résultat
  
  * avec (i,résultat) = init(n,1) tant que (i !=0 ) répéter (i-1,x*r)

**4e définition itérative** : 

* puiss(x,n)=res
  
  * avec (i,res), init(0,1) tant que (i != n) répéter (i+1, x*res)

###### **Travail Personnel : Ecrire en C les 2 versions itératives**

En C, version récursive

```c
float puiss(float x,int n){ //Tkt c'est entier naturel
    return (n==0)?1:x*puiss(x,n-1);
}
```

### 1.2 Spécification des ensembles

Supposons que nous ayons un module de spécification BASE où figure des booléens, des entiers naturels, avec opérateurs et propriétés habituelles

**<ins>Enoncé</ins>** : Définir des ensembles finis d'entiers naturels tous distnctis dont le cardinal est borné par 100

**<ins>Spécification formelle</ins>** : ENSO étend BASE

**<ins>Type</ins>** : Ensemble

**<ins>Opérations</ins>** :

* Insertion : Ens Nat => Ens

* Ensemble vide

* Suppression : Ens Nat => Ens

* Cardinal : Ens => Nat

* Vide ? : Ens => Bool

* _ c- _ : Nat Ens => Bool  

**<ins>Préconditions</ins>** : e : Ensemble ; x : Nat

* pré-insertion(e,x) = x c/ e et card(e) < 100

**<ins>Définitions et axiomes</ins>** : 

* insertion(insertion(e,x),y) = insertion(insertion(e,y),x)

* x c- vide

* x c- insertion(e1,y)

* |vide| = 0

* vide(insertion(e,x))=faux

* |insertion(e,x)| = |e|+1

* suppression(insertion(e,x),y) : si x==y alors e1, sinon insertion(suppression(e1,y),x)

* minimum(insertion(e,x)) = si vide(e1) alors x sinon
                             si x < minmum(e1) alors x sinon minimum(e1) 
  
      
