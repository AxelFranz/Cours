import numpy as np
import matplotlib.pyplot as plt

# ____________________________________ EXO 1 ____________________________________ #

# ////////////// QUESTION 1 ////////////// #

def f(x) :
	return pow(x, 3)+2*pow(x, 2)+3

abs = np.linspace(0, 10, 11)
ord = f(abs)

plt.plot(abs, ord)
plt.xlabel('x')
plt.ylabel('y')
plt.show()

# ////////////// QUESTION 2 ////////////// #

polynomes = np.loadtxt('polynome.txt')

x = polynomes[:,0]
y = polynomes[:,1]

plt.plot(x, y, '+')
plt.xlabel('x')
plt.ylabel('y')
plt.show()

# //////////////////////////////////////// #

# ////////////// QUESTION 3 ////////////// #

# on cherche le degré du polynome
plt.plot(np.log(x), np.log(y))	# on cherche le coefficient directeur de cette droite (le degré)
plt.show()
n = np.polyfit(np.log(x), np.log(y), 1) # régression polynomiale avec polyfit (1 est le degré du polynome)
print(n)	# affiche les coefficients (a et b) du polynome

# //////////////////////////////////////// #


# ////////////// QUESTION 4 ////////////// #

n = np.polyfit(x, y, 2)	# valeurs trop grandes
print(n)
m = np.polyfit(x, y, 3)	# on voit avec les coefs que c'est le degré 3 qui fonctionne bien
print(m)
o = np.polyfit(x, y, 4)	# met le premier coef à 0 ce qui prouve que le degré est 3
# les coefficients supérieurs à deux de trois sont mis à 0
print(o)

# autre façon de faire (pour afficher les 4 courbes sur le même graphique)

plt.plot(x, y, '+')
plt.plot(x, y**2, label = 'X^2')	# degré 2
plt.plot(x, y**3, label = 'X^3')	# degré 3
plt.plot(x, y**4, label = 'X^4')	# degré 4
plt.legend()
plt.show()

# calcul des résidus #####################

# polynôme de degré 2 :

A2 = transpose(np.array(x**2, x, np.ones(np.shape(x))))
a2, b2, c2 = np.linalg.solve(np.dot(A2.T, A2), np.dot(A2.T, y))
def poly2(x) :
	return a2*x**2+b2*x+c2
residu2 = np.sum(np.abs(y-poly2(x)))
print(a2, b2, c2)
print('résidu poly2', residu2)

# polynôme de degré 3 :

A3 = np.transpose(np.array(x**3, x**2, x, np.ones(np.shape(x))))
a3,b3,c3, d3 = np.linalg.solve(np.dot(A3.T, A3), np.dot(A3.T, y))
def poly3(x) :
	return a3*x**3+b3*x**2+c3*x+d3
residu3 = np.sum(np.abs(y-poly3(x)))
print(a3, b3, c3, d3)
print('residu poly3', residu3)

# polynôme de degré 4 : pareil mais c'est laborieux donc flemme, on a compris le principe

# //////////////////////////////////////// #


# ____________________________________ EXO 2 ____________________________________ #

# ////////////// QUESTION 1 ////////////// #

kangourous = np.loadtxt('Kangourous.txt')
kangourous = np.transpose(kangourous) # ou kangourous.T
print(np.shape(kangourous))	# donne le nombre de lignes et colonnes d'un array

# //////////////////////////////////////// #

# ////////////// QUESTION 2 ////////////// #

a,b = np.polyfit(kangourous[0,:], kangourous[1,:], 1)
x = np.linspace(0, 900, 901)
Rc = a*x+b
plt.figure(1)
plt.clf()
plt.plot(x, Rc)
plt.plot(kangourous[0,:], kangourous[1,:], '+')
plt.show()

# //////////////////////////////////////// #

# ////////////// QUESTION 3 ////////////// #

C = np.cov(kangourous)

# //////////////////////////////////////// #

# ////////////// QUESTION 4 ////////////// #

d, P = np.linalg.eig(C)
D = np.diag(d)
print('verfi', np.dot(np.dot(P, D), np.linalg.inv(P))-C)

# //////////////////////////////////////// #

# ////////////// QUESTION 5 ////////////// #

Kvp = np.dot(np.linalg.inv(P), Kc)
plt.figure(2)
plt.clf
plt.plot(Kvp[0,:], Kvp[1,:], 'x')
plt.show()

# //////////////////////////////////////// #

















