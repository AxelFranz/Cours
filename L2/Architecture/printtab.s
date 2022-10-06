# t0 = indice i
# a0 = taille du tableau (en nombre d'éléments)
# a1 = adresse du tableau

.data
espace : .asciiz " "

.text
move $s0, $a0
li $t0, 0
li $t4, 4

debut : bge $t0, $a0, fin
mul $t5, $t4, $t0
add $t5, $t5, $a1
lw $a0, 0($t5)
li $v0, 1
syscall
la $a0, espace
li $v0, 4
syscall
addi $t0, $t0, 1
b debut

fin : li $v0, 10
syscall