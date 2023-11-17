# 1. Intro

## 1) Qu'est-ce qu'un SE ?

* Introduire un programme dans la mémoire de l'ordinateur.
    - Pour les périphériques
    - Enchaîner les jobs (lancer des programmes à la chaîne)
* Rentabiliser l'utilisation d'un ordinateur
    - Utiliser le parallélisme de l'I/O => Notion d'interruption (IT) matérielles
* Utiliser de nouveaux modes d'interaction
    - Développement du multitâche => Partage du temps CPU

## 2) Noyau

### a. Objectifs

* Assurer la sécurité des données
* Partage équitablement les ressources
=> Apparition de la distinction entre mode privilégié et non-privilégié^
    => 2 modes d'exécution dans le processeurtu

### b. Caractéristiques

* Seul programme qui s'exécute en mode Privilégié
* Chargé en mémoire au démarrage => Reste jusqu'à l'extinction
* Il ne doit pas avoir de bugs
=> Le noyau est difficile à mettre au point / à débuguer
Il doit être le plus simple possible

arbitre => Il y a des primitives systèmes pour demander à l'arbitre d'intervenir

Comment accéder aux ressources ? Fichier = Pour donner des accès à un groupe d'utilisateurs

Comment identifier/autoriser les accès ? => Notion d'utilisateurs

### c. Accès

Couches : Matériel => Noyau => Applications
Moyens d'entrer dans le noyau
    - Appel système
    - Interruptions
    - Exceptions


## 3) Support matériel
Cpu avec >= 2 modes d'éxec
Mécanisme d'IT
Mécanisme d'IT matériel

Protection mémoire MMU = Memory Management Unit

# 2. Mécanismes de base

## 1. Intro

Aled

## 2. Zorglub-33

### a. Description

5 Registres :
    - 2 Généraux : A et B
    - SP et PC
    - Status Register

RAM en décimale de 0 à 9999

3 bus : Adresse, Donnée, Contrôle

Contrôleurs de périphériques

### b. Appel de fonctions

rtr/call

### c. Accès aux périphériques

Ports d'E/S (ex 20/21 pour le clavier)
```
in [20], %a
annd 0x1, %a
cmp 0, %a
jeq lire_cleavier
```

## 3. Modes d'exécution

Mode privilégié = superviseur = noyau...
Mode non privilégié = utilisateurs )> certaines instructions sont interdites par le CPU (ex in/out)

## 4. Interruptions et Exceptions

### a) Interruptions
- Évènements matériels par les périphériques externes

L'IT vient d'un contrôleur de périphériques, il va mettre la ligne d'IT à 1 sur le bus de contrôle
A chaque instruction : Si le bit IE du SR est à 0, le cPU ignore l'IT
Sinon => Le CPU termine l'instruction courante
Puis le CPU
- PC à 100
- SR à 101
- Val 0 à 102
- SR:IE <- 0
- SR:S -> 1
- PC = 200

## 5. Protction mémoire



# 3. Processus et threads
=> #include <pthread.h> && cc -pthread
=> renvoient 0 si OK et ou directement le numéro d'erreur
errno = func()
if(errno > 0)
    raler();

## c) Fonctions thread safe
Fonction de bibliothèque -> Indépendantes des threads : strlen
                         -> modifiées pour marcher avec les threads : malloc
                         -> incompatibles avec les threads

Def une condition de concurrence : Lorsque plusieurs acivités accèdent à une variable partagée et que le résultat dépend de l'ordonnancement
