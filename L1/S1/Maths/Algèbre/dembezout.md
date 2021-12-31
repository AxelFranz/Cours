## Démonstration du Théorème de Bézout

### Enoncé du théorème

___

Deux entiers relatifs a et b sont premiers entre eux **si et seulement si**, il existe deux entiers relatifs u et v tels que :
$$
au+bv=1
$$
Si et seulement si => Implication dans les deux sens



###  Sens direct :

___

Immédiat grâce à l'identité de Bézout
$$
\text{Soit } a \text{ et } b \in Z, \exist (u,v)\in\Z^2 : au+bv=PGCD(a,b)
$$
Ici, vu que PGCD (a,b) = 1, le théorème est validé dans ce sens.



### Réciproque:
___
On suppose qu'il existe deux entiers u et v tels que
$$
au+bv = 1 \\ 
\text{Si } \space D=PGCD(a,b), \text{alors } \space D\space|\space a \text{ et }D\space|\space b \text{ donc } D\space | \space au+bv
$$
Donc D divise 1. On a alors bien D = 1 car 1 est son seul diviseur et deux nombres tels que PGCD(a,b) = 1 sont forcément premiers entre eux.

