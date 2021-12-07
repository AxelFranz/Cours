# -*- coding: utf-8 -*-

def insere_milieu(lst,n):
    milieu =len(lst)//2
    lst =  lst[:milieu]+[n]+lst[milieu:]
    return lst
#print(insere_milieu([1,2,3,4],10))

#----------------------------------------------#

def extrait_multiples(lst):
    lstf = []
    for i in lst:
        if not i[0] % i[1]:
            lstf += [i]
    return lstf
#print(extrait_multiples([(2,7), (8,2), (7,6), (10,5)]))

#----------------------------------------------#

def somme_elements_positifs(lstlst):
    f = 0
    for i in lstlst:
        for x in i:
            if x > 0:
                f += x
    return f
#print(somme_elements_positifs([[8,-9,-6,3],[5,0,-2,7],[1,2,-3,-4,-5]]))

#----------------------------------------------#

def lisse_liste(lst):
    if lst == []:
        return []
    i = 0
    liste = list(lst)
    for i in range(1,len(liste)):
        liste[i] = (lst[i]+lst[i-1])/2
    return liste
#print(lisse_liste([-1,1,-1,1,3,5,1]))

#----------------------------------------------#

def aire_sierpinski(n):
    if n == 0:
        return 1
    else:
        return (0.75)*aire_sierpinski(n-1)
#print(aire_sierpinski(3))

#----------------------------------------------#