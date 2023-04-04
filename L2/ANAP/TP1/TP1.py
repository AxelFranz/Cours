import numpy as np
import matplotlib.pyplot as plt

def racineCarreEnsemble():
    x = np.linspace(0,10,11)
    plt.plot(x,np.sqrt(x),label="y=sqrt(x)")
    plt.plot(x,x**2,label="y=x²")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend()
    plt.show()

def racineCarreSeparee():
    x = np.linspace(0,10,1000)
    #fig=plt.figure()
    plt.figure(figsize=(100,100))
    plt.subplot(2,1,1)
    plt.plot(x,np.sqrt(x))
    plt.title("Racine carré de x")
    plt.subplot(2,1,2)
    plt.plot(x,x**2,label="y=x²")
    plt.title("x au carré")
    plt.show()
    #fig.savefig("coucou.png")

def aled():
    mat = np.array([[1,-1,2],
                    [4,-6,12],
                    [-1,-5,12]])
    print(mat)
    print(mat+mat)
    print(mat@mat)
    print(np.linalg.det(mat))
    print(np.linalg.inv(mat))
    x = np.array([])
    for y in mat:
        x = np.append(x,np.sum(y))
    print(x)

def parseFichierParceQueNiqueNumpy(name):
    f = open(name,"r")
    lignes = f.readlines()
    for x in range(len(lignes)):
        lignes[x] = lignes[x].strip()
        lignes[x] = lignes[x].replace('\t',' ')
        lignes[x] = lignes[x].split(' ')
        for y in range(len(lignes[x])):
            lignes[x][y] = int(lignes[x][y])
    f.close()
    x = []
    for a in lignes:
        x.append(a[0])
    y = []
    for a in lignes:
        y.append(a[1])
    return x,y

def kangourou():
    x,y = parseFichierParceQueNiqueNumpy("kangourou.txt")
    plt.scatter(x,y,label="droite kangourou")
    approx = np.polyfit(x,y,1)
    plt.scatter(x,x*approx,label="Approximation")
    plt.legend()
    plt.show()
    
kangourou()
