#tableau en MIPS
.data
	t: .space 40

.text
	#t[0]=1
	li $t3,1
	la $t0, t
	sw $t3, 0($t0)

	#x=t[i]
	li $t4,4
	mul $t5, $t1, $t4
	lw $t2, 0($t1)
	
	#t[i+1]=x
	sw $t2, 4($t5) 