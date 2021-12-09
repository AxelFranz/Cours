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

def indice_lst(lst, a_trouver):
    if a_trouver not in lst:
        return -1
    else:
        if lst[0] != a_trouver:
            return 1 + indice_lst(lst[1:], a_trouver)
        else:
            return 0
#print(indice_lst([1,2,3,4],5))

#----------------------------------------------#
 
def union(lst1,lst2):
    if lst1 == [] and lst2 == []:
        return []
    elif lst1 == []:
        return [lst2[0]]+union(lst1,lst2[1:])
    elif lst2 == []:
        return [lst1[0]]+union(lst1[1:],lst2)
    if lst1[0] < lst2[0]:
        return [lst1[0]]+union(lst1[1:],lst2)
    elif lst1[0] == lst2[0]:
        return [lst2[0]]+union(lst1[1:],lst2[1:])
    else:
        return [lst2[0]]+union(lst1,lst2[1:])
#print(union([3,5,6,7],[2,5,6]))

#----------------------------------------------#

def myAbs(n):
    if n < 0:
        return -n
    else:
        return n
#print(myAbs(-2))

#----------------------------------------------#

def myAbsList(lst):
    for i in range(len(lst)):
        lst[i] = myAbs(lst[i])
    return lst
#print(myAbsList([-1,0,1,-5]))

#----------------------------------------------#
 
def equalLists(l1,l2):
    return l1 == l2
#print(equalLists([-18,4,12,8], [12,4,-18,8]))

#----------------------------------------------#
 
def isPositiveList(lst):
    val = True
    for i in lst:
        if i < 0:
            val = False
    return val
#print(isPositiveList([-1,0,1,-5]))
#print(isPositiveList([1,0,1,5]))

#----------------------------------------------#
 
def mirror(lst):
    lstf = []
    while lst != []:
        lstf += [lst[-1]]
        lst = lst[:-1]
    return lstf
#print(mirror([6,4,1,3]))

#----------------------------------------------#
 
def isMirrorWhateverSign(lst1,lst2):
    lst2 = myAbsList(lst2)
    lst1 = myAbsList(lst1)
    lst1 = mirror(lst1)
    print(lst1,lst2)
    return equalLists(lst1,lst2)
#print(isMirrorWhateverSign([1,2,3,4], [1,2,3,4]))
#print(isMirrorWhateverSign([1,2,3,4], [4,3,2,1]))
#print(isMirrorWhateverSign([1,-2,3,-4],[4,-3,2,1]))
#----------------------------------------------#
 
def tri_selection(lst):
    n = len(lst)
    for k in range(n-1,1,-1):
        imax= 0
        for j in range(1,k):
            if lst[j] > lst[imax]:
                imax = j
        if imax != k:
            tmp = lst[k]
            lst[k] = lst[imax]
            lst[imax] = tmp
        print("itération",lst)
    return lst
print(tri_selection([3,6,9,1,5]))
#----------------------------------------------#
 

#----------------------------------------------#
 

#----------------------------------------------#
 