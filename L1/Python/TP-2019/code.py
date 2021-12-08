# -*- coding: utf-8 -*-

import graph 

def dessine_case(lgn,col,color="black"):
    rect(col*lcase,lgn*lcase,(col+1)*lcase,(lgn+1)*lcase,color)
    return None

def rect(x,y,w,h,color="black"):
    for cx in range(x,w):
        for cy in range(y,h):
            graph.plot(cy,cx,color)

def un_pas_fou_inf(lgn,col):
    return [(lgn+1,col+1),(lgn+1,col-1),(lgn-1,col+1),(lgn-1,col-1)]

def N_pas_fou_inf(lgn,col,n):
    return [(lgn+n,col+n),(lgn+n,col-n),(lgn-n,col+n),(lgn-n,col-n)]
 # Pareil que avant, on ajoute juste un N

def est_sur_echiquier(lgn,col):
    if lgn > 7 or lgn < 0 or col > 7 or col < 0:
        return False
    else:
        return True

def dessine_cases_accessibles(lgn,col,lcases):
    listefi = []
    couleur = 0
    for x in range(0,8):
        for y in range(0,8):
            couleur = couleur % 2
            if couleur == 1:
                dessine_case(x,y,"black")
            else:
                dessine_case(x,y,"white")
            couleur += 1
        couleur += 1
    for i in range(1,8):
        liste = N_pas_fou_fini(lgn, col, i)
        for x in liste:
            if est_sur_echiquier(x[0], x[1]):
                listefi += [x]
    for i in listefi:
        dessine_case(i[0],i[1],"red")
    
def N_pas_fou_fini(lgn,col,n):
    listef = []
    # Je prends la liste de base et je trie les élements pour garder les valides
    listenontriee = [(lgn+n,col+n),(lgn+n,col-n),(lgn-n,col+n),(lgn-n,col-n)]
    for i in listenontriee :
        if est_sur_echiquier(i[0], i[1]):
            listef += [i]
    return listef

def echiquier(lcase):  
    graph.ouvre_fenetre(8*lcase,8*lcase)

lcase = int(input("Largeur = "))
echiquier(lcase)
dessine_cases_accessibles(2,4,lcase)


graph.attend_fenetre()
