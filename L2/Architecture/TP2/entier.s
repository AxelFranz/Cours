# Données
.data

coucou : .asciiz "Entrez un entier : "

.text
.globl __start


__start:

# Affichage d'une string
la $a0 coucou
li $v0 4
syscall

# On prend un entier stdin et il est dans v0
li $v0 5
syscall

# On affiche l'entier
move $a0, $v0
li $v0 1
syscall

j Exit # saut a la fin du programme
Exit: 
li $v0 10
syscall