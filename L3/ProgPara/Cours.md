# Installer 
openmpi-bin
lib-openmpi
openmpi-doc

# Intro

Pas écouté il disait que de la merde

# Chapitre 1

SISD => Une seule unité de calcul séquentiielle
MISD => Plusieurs unités qui exécutent des instructions différentes mais accédant à une seule donnée à la fois
    - Fonctionnement de type pipeline
SIMD => Plusieurs unités de caulcul exécutant toutes la même instruction sur des jeux de données différents
    - Fonctionnement de type vectoriel
        - Exemple : Exécution de miultiplication sur 8 doubles en même temps
MIMD => Chaque machine a sa mémoire
    - Cluster de pc

MIMD-VSM (virtual shared memory) => MIMD avec mémoire partagée

# Modèles de prog
(Du plus gros au plus petit grain)
=> Décomposition trivial : un programme à lancer plusieurs fois avec des jeux de données différents
=> Décomposition fonctionnelle
    - Un programme est découpéen fonctions qui réalisent une opération
    - Il y a donc un graphe de dépendance qui se crée
=> Décomposition de données
    - avec équilibrage
        - Ferme de calcul
        - processus maître répartit les calculs
        - **Fonctionnement maître-esclave**
    - sans équilibrage (régulière)
        - les calculs et les données sont répartis de manière automatique et régulière
        - tous les processus participent au calcul d'un ensemble de données
        - **pas de processus maître**
=> **Faire très attention aux dépendances**

Conditions de bernstein entre S1 et S2 si ; 
true dep   : W(S1) ^ R(S2) = 0
anti dep   : R(S1) ^ W(S2) = 0
output dep : W(S1) ^ W(S2) = 0

## Ecrire un programme parallèle:
=> trivial = lancer le prog
=> fonctionnelle + avec équilibrage = inter-processus
=> régulière = threads  

# MPI

Voir MPI1.c
