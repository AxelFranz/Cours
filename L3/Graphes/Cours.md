# Propriété

G est un graphe non orienté, supposons qu'il existe une marche entre deux sommets u et v, alors il existe un existe un chemin entre u et v
Démonstration 1 Par L'Absurde :
L'ensemble des marches de u à v est non vide. Il existe plu courte marche M.
Supposons que M n'est pas un chemin, alors il existe w qui se répète, c'est-à-dire que M peut s'écrire.
u0 = u, ui = w, up = v
Alors u0 = u, ui = w, up = v est encore une marche plus courte que M.

Démo constructive
On part de la marche M connue entre u et v et on applique l'algorithme suivant
- Tant qu'il existe un sommet w qui se répète, on définit ui et uj comme deux occurences de w
    - M = uO = u,...., ui = w, uj+1,..., up=v
Quand l'algorithme s'arrête, aucun sommet n'est répété donc la marche M obtenue est en fait un chemin
Or, les marches successives ont des longueurs ed plus en plus petites et toute suite d'entiers positifs strictement décroisemment est finie donc l'algorithme s'arrête

Définition :
Un cycle (orienté) de longueur k est un chemin orienté de longueur k dont les sommets de départ et d'arrivée sont confondus

# II 4 Connexité
**Définition** Un graphe non orienté G est connexe si toute paire de sommets est réliée par un chemin 
Si le graphe non orienté n'est pas connexe, il se décompose de façon unique en composantes connexes qui sont des sous-graphes connexes maximaux

**Définition** : Un graphe orienté est fortement connexe si pour toute paire de sommets u et v, il y a un chemin orienté de u à v et de v à u
Si le graphe dont on a supprimé les orientations est connexe, on dit que le graphe orienté est simplement connexe.

# II 5 Distance et diamètre

La distance entre deux sommets u et v appartenant à la même composante connexe est la longueur du plus court chemin entre u et v.

Remarques : 
- Si G est orienté, on considère le plus court chemin orienté
- Si G est valué, la longueur d'un chemin est la somme du poids des arêtes

Le diamètre d'un graphe est la plus grande distance qu'on peut trouver entre deux points


# Chap II Parcours de graphes non valués

## I Arbres Courants
### 1 Arbre
**Définition** : Un graphe G non orienté est un arbre  s'il est connexe et acyclique

**Propriété** : Un graphe connexe est un arbre si et seulement si toute suppression d'arête le rend non connexe

**Démonstration** : => Soit T un arbre et e=(u,v) Supposons qe T\e est connexe. Alors il existe un chemin de u à v dans T\e. En y ajoutant e, on obtient un cycle dans T. Or, T est un arbre don T est acyclique. On obtient une contradicition donc T\E n'est pas connexe.
Cice est vrai pour toute arrête e.

Soit T connexe tel que poru toute arête e, T\e est non connexe. Supposons que T contient un cycle et soit e une arête du cycle. Nou allons montrer que T\e est connexe.
Soit u et v deux sommets. T est connexe donc il existe un chemin de u à v dans T.
- Cas 1 : Ce chemin ne contient pas e, ce chemin est encore valide dans T\e
- Cas 2 : Ce chemin contient e, il existe une marche entre u et v dnas T\e en concaténant le sous-chemina vant e, le cycle privéde e et le sous-hemin après e.
    - Or s'il existe une marche, il existe un chemin entre u et v.
Ceci étant vrai pour tout couple de sommet, T\e st connexe

Être connexe + acyclique = être connexe minimal

**Définition** : Un graphe G est un graphe enraciné s'il est construit par le processus suivant :
- On initilialise V(G) à un sommet r de niveau 0 et E(G) à l'ensemble vide
- Pour toiut sommet v
    - On ajoute à V(G) un nomnbre fini desommetw w1, wkv et à E(G) les arves (v,wi)
    - Si v est de niveaui, tous les wj sont de niveau i+1

Toutes les arêtes relient un père et un fils et chaque sommet n'a qu'un père

### 2. Arbres couvrants
**Définition** : Soit G uyn graphe. Un arbre couvrant T de G est un arbre tel que V(T)=V(G) (en gros s'il a un arbre qui relie tous les sommets)
**Propriété** : G est connexe si et seulement si G admet un arbre courant T
(= On suppose qu'il existe un arber courant T
Soit u et v deux sommets de G. Comme T est couvrant, il existe un chemin de u à v dans T. Ce chemin est aussi un chemin dans G. Donc G est connexe
=> Soit T le plus grand arbre inclus dans G. Supposons que V(T)=/=V(G), c'est-à-dire q'il existe w c- V(G) qui n'appartient pas à T.
Soit r un sommet qui est dans T. Comme G est connexe, il existe un chemin entre r c- T et w c/-T. Donc il existe une arête (u,v) de ce chemin avec u c- T et v c/- T

# Parcours en largeur ou BFS

Principe : 
- On choisit un sommet racine r
- On construit un arbre enraciné en prenant les sommets dans l'ordre dans l'equel ils ont été aoutés à la structure.
- D'un point de vue pratique, cela revient à mettre àjour une file. L epremier sommet est le sommet courant de la file, on ajoute ses voisins au bout de la file et on s'arrête quand la fle est vide

Un BFS découvre exactement les sommets de la composante connexe de la racine

### 3. Complexité du BFS
Le BFS est de complexité O(n)

Démonstration : Chaque sommet v estconsidéré au plus une fois comme la tête de file. A Ce moment-là, le nombre d'opéations à faire est borné par la taille de son voisinage multiplié par un coût constant (pour chaque voisin de v, vérifier s'il est visité, éventuellement l'ajouter à la file, à l'arbre et le marqer comme visité).
Le coût tant que v est tête de file est dnc borné par C d(v)
Le coût total est donc brné par la somme v c- V(G) Cd(v)= 2cm

Remarque : O(m) est l'ordre de grandeur de la lecture du graphe. En ce sens, BFS est optima


### 4. BFS et Distance

# ?
Propriété : L'ensembe des sommets découverts par un DFS enraciné en r est l'ensemble des sommets de la composante connexe de r
Soit T un DFS enraciné en r, Tous les sommets de T sont bien dans la même composante Connexe (cc) de r,
Supposons qu'il existe w dans la même cc de r, tel que w c- V(T) Il existe un chemin entre r et w. Sur ce chemin, il existe forcément une arête entre u et v or u ne peut pas être dépilé par le dfs sans que celui-ci visite v. 
On a donc une contradiction

Complexité du DFS
Il est de O(m)

## Topologie d'un DFS
Propriété : Soit (u,v) une arête de G, et T un DFS sur la composantede u et v enraciné en r.
Alors u est forcémen un ancêtre de v dans T ou inversement
