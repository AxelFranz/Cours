# 1 Quelques questions de cours
1) a) Git est un gestionnaire de versions décentralisé qui permet de centraliser sur un dépot distant et local le code d'un projet. On fait les changements en local puis on peut les envoyer (push) sur le dépot distant.

b) GDB est un outil permettant de débuguer le code en mettant notamment des breakpoints et voir la mémoire de l'ordi à un instant t en exécutant le code pas à pas.

c) GCC est un ensemble d'outils de compilation pour le C. Il comporte entre autres le compilateur et l'éditeur de liens. Il existe aussi g++ pour le c++ ainsi que d'autres versions pour d'autres langages.

d) Valgrind est un outil d'analyse de mémoire pour voir s'il n'y a pas de fuites notamment.

e) Doxygen est un outil de génération de documentation à partir de commentaires spéciaux que le développeur va venir écrire dans son code.

2) `git clone` sert à copier sur son ordinateur un dépot distant tout en étant lié avec, c'est à dire pouvoir pull, push et autres dessus. Par exemple, si je veux continuer à travail sur mon projet Sokoban, je peux faire `git clone <URL git>` pour avoir accès à mes fichiers sur la machine.
3) `git add` sert à indiquer à git que les fichiers passés en arguments sont désormais suivis et devront donc être inclus lors du prochain commit.
`git commit` sert à créer un commit, c'est à dire un avancement de version du projet qui change tous les fichiers suivis.
`git push` sert à envoyer sur le dépot distant toutes les modifications (commit et branches).

4) Les branches servent à avoir plusieurs cheminements d'avancement d'un projet. On peut notament avoir une branche qui répertorie toutes les versions principales d'un projet puis travailler sur une branche parallèle pour développer les fonctionnalités qui arriveront sur la branche principale plus tard.

5) `git checkout tmp`

# 2. Création d'un Makefile
Voir Makefile

# 3. Débug de code
On pourrait mettre toutes les fonctions dans liste.c et les définitions dans liste.h. J'ai aussi rajouté de la documentation doxygen.

Voir main_broken.c

