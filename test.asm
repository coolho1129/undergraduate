.data
msg: .asciz "# "
changeLine: .asciz "\n"
equation: .space 512
.text
MAIN:	la 	a0, msg 
	li 	a7, 4
	ecall
	la 	a0, equation
	lI 	a1, 512
	li 	a7, 8
	ecall
	li 	a7,4
	ecall
	add	s0, zero, a0
	li 	s8, 61
	li 	s4, 2
LOOP: add 	s1, s0, s6
	lb 	s2, 0(s1)
	add 	a4, zero, t3
	li 	t0, 48 
	li 	a2, 10
	li 	a5, 1
	sub 	t1, s2, t0
	bltu 	t1, a2, CHANGE
	addi 	t3, t1, 48
	addi 	t5, t5, 1	
	beq 	t5, s4,CHECK
NEXT:  beq 	t3, s8,EXIT	
	addi 	s6,s6,1
	beq 	zero, zero, LOOP
CHECK: bnez 	s10,OPERATE
	add 	s10, s7, zero
OPERATE:li 	t4 , 43
	beq 	a4, t4, ADD
	li 	t4 , 45
	beq 	a4, t4, SUB
	li 	t4 , 120
	beq 	a4, t4, MUL
	li 	t4 , 47
	beq 	a4, t4, DIV
	bltu 	s7, a2, MULTFORMER
ADD: add 	s11 ,s11 ,s10	
	jal 	zero, PRINT
SUB: sub 	s11, s11, s10	
	jal 	zero, PRINT
MUL: mul 	s11, s11, s10	
	jal 	zero, PRINT
	
DIV: div 	s11, s11, s10	
	jal 	zero, PRINT
PRINT:	add 	a0, s11, zero
	li 	a7, 1
	ecall
	la 	a0, changeLine
	li 	a7, 4
	ecall
	sub 	t5, t5,a5
	li 	s10, 0
	jal 	zero, NEXT
CHANGE:	 beqz 	s11, FORMER
	beqz  	t5, OPERATE
	bnez 	s11, LATER
FORMER:	bnez t5, LATER
	add s11,t1,zero
	jal zero, NEXT
LATER:add 	s9, s7, zero
	add 	s7, t1, zero
	blt  	t5,s4,MULTLATER
	 jal 	zero, OPERATE
MULTLATER: li 	t6, 10
	mul 	s10,s10,t6
	add 	s10,s10,s7
	jal 	zero, NEXT	
MULTFORMER:li 	t6, 10
	mul 	s11, s11, t6
	add 	s11, s11, t1
	jal 	zero, NEXT
EXIT:
