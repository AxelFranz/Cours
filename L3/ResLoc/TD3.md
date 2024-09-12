**Addition : XOR**
**Multiplication : AND**

# 1. Codes de haming 

1. 3 et 3
Les 3 premières colonnes sont la matrice identité (bits d'info) et les 3 autres sont les bits de contrôle

2. Etapes : 
On découpe en 3 par 3 bits
puis on fait
011 . G | 001 . G  | 010 . G | 101 . G | 110 . G | 001 . G
Ex : Colonne 1 
0 & 1 ^ 1 & 0 ^ 1 & 0 = 0
... => 
011110|001101|010011|101011|110101|001101

3. Si I3 = partie gauche et A partie droite
Si G = (I3,A) alors H = (At, I3)


# 3. Codes polynomiaux


