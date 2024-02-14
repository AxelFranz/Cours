# 1. Transformations géométriques

## 1 . Dans le plan

### a. Transformations linéaires et/ou affines

Définition : Une transformation d'un point P(x,y) est une application F(P) = TP (+ Q pour affine) avec T matrice 2x2 et Q matrice 2x1.
(Attention, chez les anglo-saxons)

### b. Ordre pour la composition de transformation

Attention à l'ordre, les transformations ne sont pas commutatives. Elles sont associatives.

Propriétés des transformations affine
- 2 droits restent paallèles par transformations affines
- La transformation du point d'intersection de deux droits donne le point d'intersection des deux droites transformées par la même transformation.
- **Invariance par transformation affine ** 

### c. Coordonnées homogènes dans le plan

Plan     Plan Projectif
(x,y) -> (x,y,1) (w)
w est la coordonnée homogène
Si w != 0 alors c'est un point
Si w == 0 alors c'est un vecteur
On a donc sur le plan projectif
(x/w, y/w, w) ex: P(1,2) => (2,4,2)

L'objectif des coordonnées homogènes est d'unifier les transformations linaires et affines dans un formalisme pour pouvoir les composer aisément. On l'obentient avec une écriture matricielle des transformations affines.

Ecriture en matrice :
(
a b 0
c d 0
0 0 w
)
(
x
y
)
avec w = 1 c'est trivial

### d. Transformations 2D en coordonnées homogènes

- Translation de dx selon la direction x et dy selon dy<br>
x' = 1 0  x  + dx donne   1 0 dx    x 
y'   0 1  y    dy         0 1 dy    y 
                          0 0 1     z
- mise à l'échelle 

hx 0  0
0  hy 0
0  0  1

- Symétrie par rapport à Ox (le point obtenu par la project sur l'axe des abscisses)
1  0  0
0  -1 0
0  0 -1

Oy : 
-1 0 0
0  1 0
0  0 1

O : 
-1 
   -1
      1

- Cisaillement dans le sens de x
a b 0    x        ax+by
0 d 0    y   =      dy
0 0 1    1          1

### e. Rotations dans le plan
Rotation d'angle O par rapport à l'origine
RO = cosO -sin0
     sin0  cos0
Voir livre cours pour preuve

### f. Transformations générales dans le plan 


- transformation non affine 
avec mn sur dernière ligne => (x,y,mx+my+1)
avec mx+my+1 != 0 alors en coordonnées carthésiennes on a 
P(x/mx+my+1, y/mx+my+1)

 
# 2. Géométrie linéaire

## 1. Droites dans le plan

### a. Équation générale de la droite dans le plan

D : ax + by + c
P(x,y) c- D ssi ax + by + c = 0
La normake à la droite est de coordonnées (a,b)

### b. Équation canonique

Soit m0 et v avec vv vecteur directeur de D alors P c- D ssi (x-x0)/u = (y-y0)/u

### c. Équation paramétrique

Cas général  : 
$
D = 
\begin{cases}
x = tu+x0   \\
y = tv + y0 
\end{cases}
\text{ avec } \vec{v} \text{ vecteur direction et } M0 \in D 
$

### d. Intersection de droites

$
\begin{cases}
a1x + b1y + c1 = 0 \\
a2x + b2y + c2 = 0
\end{cases}
\\
\Delta = a1b2 - a2b1
\\
\text{Si } \Delta = 0 : \frac{a1}{a2}=\frac{b1}{b2} \text{ => les normales sont colinéaires et D1 et D2 sont parallèles}
\\
\text{Si } \Delta \neq 0 : I(xI,yI) \in D1 \cap D2 \text{ tel que } xI = \Delta, yI = \Delta  
$

### e. Angles entre ces 2 droites D1 et D2 

L'angle Cf obtenu entre D1 et D2 est obtenu parle produit scalaire des 2 normales

$\vec{n1}\cdot\vec{n2} = a1a2 + b1b2$

### f. Conditions de parallèlisme et d'orthogonalité avec 2 droites sous forme canonique

Parallelisme : $\frac{u1}{u2}=\frac{v1}{v2}$

Angle : Produit scalaire entre v1 et v2

### g. Position d'un point par rapport à une droite définie par 2 points A et b
**Préliminaire** : On définit une orientation de A vers B avec b1 > a1 

Un point C est :
- à gauche sur detABC > 0 et ABC sens trigo 
- à droite < 0 et ABC sens aiguilles
- sur la droite = 0

En résumé, calculer le detABC ou la norme du triangle du produit vectoriel AB^AcC ou 2x l'aire du triangle donne le même résultat.

### h. Test d'intersection entre 2 segments via le test de position point/droite 

S1 = det ABC \
S2 = det ABD \
S3 = det CDA \
S4 = det CDB \

AB et CD s'intersectient ssi S1S2 < 0 et S3S4<0


<!-- Manque une partie du cours -->

## 2. Projections planaires sur un plan (non affines)

**Projection** : Transformation dégénérée telle que det = 0 \
2 types de projections planaires, les projections sont parallèles ou perspectives selon que la distance entre le centre de projection et le plan de projection est infinie ou finie.
\
Projection parallèles selon que la direction de projecion et la normale au plan de projection ont/n'ont pas la même direction est dite orthographique/oblique

**Cas usuels de projection orthographique**
- Projection orthogonale : Plan de projection perpendiculaire à Ox,Oy ou Oz
- Projection isométrique : Tranformée de i = j = z

**Cas usuels de projection obliques**
- Projection cavalière : 2 axes restent perpendiculaires et conservent leur longueur
- Projection cabaret : 2 axes restent perpendiculaire et la longueur du 3e axe est divisée par 2 ou 3

Projection perspectives => \
$
T = \begin{matrix} 
1 & 0 & 0 & 0 \\ 
0 & 1 & 0 & 0 \\
0 & 0 & 1 & 0 \\
l & m & n & 1
\end{matrix} 
\\
\begin{cases}
x'=x/(lx+my+nz+1) \\
y'=y/(lx+my+nz+1) \\
z'=z/(lx+my+nz+1)
\end{cases}
$

Informations à propoas de la matrice T
Observons l'image de $\vec{i} (1,0,0,0)$ => 1/l
Toutes els droits parallèles à Ox convergent vers ce point, c'est un point de fuite

Le centre de projection est le point tel que TC = $\vec{0}$
Le plan de projection est l'ensemble des points M = TM qui sont leur propre image


A partir du dossier de la projection, comment obtenir la matrice ? \
$\vec{OP}' = \vec{OP} + \lambda\vec{CP}$ d'où OP'=(x,y,0,xz+1) 

## 3. Droites dans l'espce

### Position relative d'une droite et d'un plan
