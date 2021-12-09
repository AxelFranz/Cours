# -*- coding: utf-8 -*-

import random
cell = (2,3)

def entre0etN(n):
    return random.randint(0,n)
#print(entre0etN(5))

def elementAuHasard(lst):
    x = len(lst)
    y = entre0etN(x-1)
    return lst[y]
#print(elementAuHasard([2,0,20]))

def listeZeros(n):
    lst = []
    for i in range(n):
        lst += [0]
    return lst
#print(listeZeros(3))

def plateauZeros(nblignes,nbcolonnes):
    lst = []
    for i in range(nblignes):
        lst += [listeZeros(nbcolonnes)]
    return lst
#print(plateauZeros(3,2))

def voisines_PI(cell):
    lgn = cell[0]
    col = cell[1]
    return [(lgn+1,col+1),(lgn+1,col-1),(lgn-1,col+1),(lgn-1,col-1)]
#print(voisines_PI(cell)

def voisines_PI_alea(cell):
    return elementAuHasard(voisines_PI(cell))
#print(voisines_PI_alea(cell))

def afficheParcoursNpas_PI(cell,nb_pas):
    print(cell)
    if nb_pas == 0:
        return
    else:
        afficheParcoursNpas_PI(voisines_PI_alea(cell), nb_pas-1)
print(afficheParcoursNpas_PI(cell,3))