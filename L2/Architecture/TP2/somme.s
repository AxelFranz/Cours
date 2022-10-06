.data

str1: .asciiz "Entrez le premier entier : "
str2: .asciiz "Entrez le deuxième entier : "

.text
.globl __start

__start:

# Affichage de la str1
la $a0 str1
li $v0 4
syscall
# On prend un entier stdin et il est dans v0 puis on le move dans t0
li $v0 5
syscall
move $t0 $v0

# Affichage de la str1
la $a0 str2
li $v0 4
syscall
# On prend un entier stdin et il est dans v0 puis on le move dans t0
li $v0 5
syscall
move $t1 $v0

# On ajoute les 2 et on print
add $a0 $t0 $t1
jal print 
j Exit

print: li $v0 1
syscall
jr $ra


j Exit #saut vers la fin du processus
Exit:
li $v0 10 # appel système 10: fin du programme
syscall
