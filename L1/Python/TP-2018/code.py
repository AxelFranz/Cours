# -*- coding: utf-8 -*-

import random

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

print(listeZeros(3))        