# TD1

Octet : b8,b7,b6,b5,b4,b3,b2,b1
1 2 4 8
**Une adresse MAC est sur 6 octets.**
**Une trame est composée de {@MAC destination, @MAC src, type/longueur 2 octets, DONNEES(Entre 46 et 1500 octets pour détecter les collisions), FCS}.
Il y aussi une entête physique de 8octets pour synchroniser les horloges. A la fin il y a un temps de silence (ici 12 octets pour 10Mb/s).**

## Exercice 1

a) a8 = 1010 1000. On regarde le b1, l'adresse est unicaste donc une seule machine. b2 OUI valide. => Apple
b) ec = 1110 1100. b1 = 0 donc unicaste. b2 = 0 donc OUI Valide; => Lenovo
c) 01 = 0000 0001. b1 = 1 donc multicaste. b2 = 0 donc OUI Valide. => Protocole Spanning Tree
d) 00 = 0000 0000. b1 = 0 donc unicaste. b2 = 0 donc OUI Valide. => Adresse vide
e) ff = 1111 1111. b1 = 1 donc multicase. b2 = 1 donc OUI non Valide. => Broadcast (diffusion)

## Exercice 2

a) Ca dépend de la norme.
- 10 Mb/s (10base2,10base5,10baseT)
- 100 Mb/s
- 1 Gb/s
- 10 Gb/s

b)
10 Mb => 1 seconde
10 Mb * 1024 * 1024 octets = 10485760 octets.
1500 + 18 + 8 + 12 = 1538 (nombre maximal d'octets possibles).

1530 octets => 10 Mb/s
Donc 1500 octets => 9,75 Mb/s

c) Rendement = débit utile/débit du lien = 9,75 / 10 = 0,98

d) On suppose qu'on envoie donc 84 octets

84 octets => 10 Mb/s
46 => 5,47

5,47 / 10 = 54%

e) Il vaut mieux envoyer de grandes quantités de données.

### Exercice 3

a) Temps de transmission = temps de propagation + temps d'émission

Temps de propagation = 20 / 100 000 000

Temps d'émission = 1500*8 / 10^7

Temps de transmission = 1,2ms

Avec store and forward ! 2.4ms
