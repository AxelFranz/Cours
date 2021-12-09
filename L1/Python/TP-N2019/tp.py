# -*- coding: utf-8 -*-

def init() :
  return [
             [0,0,0,0,0,0,0,0],
             [0,0,0,0,0,0,0,0],
             [0,0,0,0,0,0,0,0],
             [0,0,0,0,0,0,0,0],
             [0,0,0,0,0,0,0,0],
             [0,0,0,0,0,0,0,0],
             [0,0,0,0,0,0,0,0],
             [0,0,0,0,0,0,0,0]
            ]

# ------------------------------------------ #

# J'initialise tôt l'échiquier pour les tests
echiquier = init()

# ------------------------------------------ #
def affiche( e ):
    larg_case = 3
    trait = '-' * (8*larg_case+9)
    case_vide = ' ' * larg_case

    nrows = len(e)
    ncols = len(e[0])
    for lin in range(nrows):
      print('  ' + trait)
      # affiche le numero de ligne
      print(f'{8-lin} ', end='')
      # affiche les cases de la ligne
      for col in range(ncols):
        if e[lin][col] == 0:
          print(f'|{case_vide}', end='')
        else:
          print(f'| {e[lin][col]} ', end='')
      print('|')
    # dernier trait horizontal
    print('  ' + trait)
    # affiche nom colonne
    print('   ', end = '')
    for lettre in range(ncols):
      nom = chr(ord('A') + lettre)
      fill = ' '
      print(f"{fill}{nom}{fill} ", end = '')
    print('')

# ------------------------------------------ #

def place_piece(e,coord,piece):
    # On vérifie l'intervalle pour les coordonnées
    if coord[0] >= 0 and coord[0] < 8 and coord[1] < 8 and coord[1] >= 0:
        e[coord[0]][coord[1]] = piece
        return True
    else:
        return False
# Test
"""result = place_piece(echiquier,(1,0),'Q') # => bon
def test(result):
    if result:
        print(echiquier)
    else:
        print("Coordonnées invalides")
test(result)
result = place_piece(echiquier,(9,5),'Q') # => invalide
test(result)"""

# ------------------------------------------ #

def convert_vers_coord(alge):
    a = ord(alge[0])-ord("A")
    b = 8-int(alge[1])
    return(b,a) # On inverse a et b car la colonne est en second
# Test
"""print(convert_vers_coord("B5")) # => (3,1)
print(convert_vers_coord("H1")) # => (7,7)
print(convert_vers_coord("A4")) # => (4,0)"""

# ------------------------------------------ #

def mouv_lig(coord):
    numl = coord[0]
    lstf = []
    for i in range(8):
        if i != coord[1]:
            lstf += [(numl,i)]
    return lstf
# Test 
#print(mouv_lig((3,4))) => [(3, 0), (3, 1), (3, 2), (3, 3), (3, 5), (3, 6), (3, 7)]

# ------------------------------------------ #

def mouv_col(coord):
    numc = coord[1]
    lstf = []
    for i in range(8):
        if i != coord[0]:
            lstf += [(i,numc)]
    return lstf
# Test
#print(mouv_col((3,4))) #=> [(0, 4), (1, 4), (2, 4), (4, 4), (5, 4), (6, 4), (7, 4)]
 
# ------------------------------------------ #
 
def mouv_diag(coord):
    listef = []
# Je prends le nombre maximal de cas possibles (8 cases dans chaque direction)
# et j'enlève les cas qui ne sont pas sur le plateau
    for n in range(1,8): # On gère les diagonales à n cases du point
        listenontriee = [(coord[0]+n,coord[1]+n),(coord[0]+n,coord[1]-n),(coord[0]-n,coord[1]+n),(coord[0]-n,coord[1]-n)]
        for i in listenontriee :
           if i[0] >= 0 and i[0] < 8 and i[1] < 8 and i[1] >= 0:
               listef += [i]
    return listef
# Test
#print(mouv_diag((3,2)))

# ------------------------------------------ #
 
def mouv_dame(coord):
    return mouv_lig(coord)+mouv_col(coord)+mouv_diag(coord)
# Test
#print(mouv_dame( (2,3) )) #==> doit donner les 25 valeurs du sujet

# ------------------------------------------ #
 
def saisie(n):
    lstf = []
    for i in range(n):
        # On pose la question
        rep = input("Quelle est la position algébrique de la dame ? = ")
        
        # On convertit en coordonnées matrices
        place = convert_vers_coord(rep)
        
        # On place la pièce dans la liste à renvoyer et on place la pièce
        place_piece(echiquier, place, 'Q')
        lstf += [place]
    return(lstf)
# Test 
#print(saisie(3)) # => Je réponds B2,D7 et H8 puis ça doit donner [(6, 1), (1, 3), (0, 7)]

# ------------------------------------------ #

def collision(lst):
    lstcol = []
    for i in lst: # On initialise une liste avec les collisions de chaque dame
        lstcol += [mouv_dame(i)]
    for i in lst: # On prend chaque dame
        for x in lstcol: # On prend chaque liste de collision
            if i in x: # On vérifie si la dame est dans une des listes de collision
                return True
    return False
# Test doit dire "Ne se prennent pas, se prennent et ne se prennent pas"
"""lst1 = [(4,0),(6,1),(3,6),(5,5)]
lst2 = [(5,0),(3,6),(6,1)]
for lst in [lst1,lst2,[]]:
    print('Pour',lst)
    if collision(lst):
        print("Les dames se prennent")
    else:
        print("Les dames ne se prennent pas")"""



# ------------------------------------------ #


# Test Final réalisé avec 3 dames
"""lst = saisie(3)
if collision(lst):
    print("Elles se touchent")
else:
    print("Elles ne se touchent pas")
affiche(echiquier)"""

# ------------------------------------------ #

# J'en déduis un wrapper pour utiliser la fonction plus facilement et afficher l'échiquier

def testF(n,echiquier):
    lst = saisie(n) # On saisit les dames
    res = collision(lst) # On gère les collisions
    affiche(echiquier) # On affiche l'échiquier complet
    if res: # On affiche le résultat après l'échiquier
        print("\nElles se touchent")
    else:
        print("\nElles ne se touchent pas")
    

#Test du wrapper
testF(3,echiquier) #==> A1, C2 et E3 ne se touchent pas
# testF(3,echiquier) #==> D5, D7 et A1 se touchent
    





