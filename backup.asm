.globl MAIN
.eqv MAXBUFFER 512
.data
msg: .asciz "# "
changeLine: .asciz "\n"
equation: .space MAXBUFFER
.text
.eqv EQUAL_OP 61
.eqv ADD_OP 43
.eqv SUB_OP 45
.eqv MUL_OP 120
.eqv DIV_OP 47
.eqv CHAR_ZERO 48

MAIN:
	# print # 
	la a0, msg 
	li a7, 4
	ecall
	
	# input equation
	la a0, equation
	lI a1,MAXBUFFER
	li a7, 8
	ecall
	
	#print equation
	li a7,4
	ecall
	
	add	s0, zero, a0
	li 	s8, EQUAL_OP
	li	s6,  0
	li	s2,  0
	li 	s11, 0
	
LOOP:
	#split char
	add 	s1, s0, s6
	lb 	s2, 0(s1)
	

	# print test
#	add 	a0, s2, zero
#	li 	a7, 11
#	ecall
	
	# char change intager
	li 	t0, CHAR_ZERO 
	li 	t1, 0
	li 	t3, 10
	sub 	t1, s2, t0
	bltu 	t1, t3, CHANGE
	
	
	#save operator
	addi 	t2, t1, CHAR_ZERO
	

NEXT:
	# meet EQAL_OP EXIT
	beq 	t2, s8,EXIT	
	
	# index += 1
	addi 	s6,s6,1
	#go to LOOP
	beq 	zero, zero, LOOP
	

START:	
	add s11,s10,zero
	jal ra, NEXT
	jalr zero,0(ra)


OPERATE:	
	#ADD
	li 	t4 , ADD_OP
	beq 	t2, t4, ADD
	
	#SUB
	li 	t4 , SUB_OP
	beq 	t2, t4, SUB
	
	#MUL
	li 	t4 , MUL_OP
	beq 	t2, t4, MUL
	
	#DIV
	li 	t4 , DIV_OP
	beq 	t2, t4, DIV
	
	bltu 	s10, t3, MULTTEN
	
	
	
ADD: 
	add s11,s11,s10	
	li t2,0
	jal ra,PRINT
	jalr zero,0(ra)

SUB: 
	sub s11,s11,s10	
	li t2,0
	jal ra,PRINT
	jalr zero,0(ra)
	
MUL: 
	mul s11,s11,s10	
	li t2 0
	jal ra,PRINT
	jalr zero,0(ra)
	
DIV: 
	div s11,s11,s10	
	li t2 0
	jal ra,PRINT
	jalr zero,0(ra)
	
PRINT:	
	add 	a0, s11, zero
	li 	a7, 1
	ecall
	
	la a0,changeLine
	li a7,4
	ecall
	
	jal ra,NEXT
	jalr zero,0(ra)


CHANGE:	 
	add s10,t1,zero
	beqz s11,START
	jal ra,OPERATE
	jalr zero,0(ra)
	
MULTTEN:
	li t6 10
	mul s11,s11,t6
	add s11,s11,s10
	jal ra,NEXT
	jalr zero,0(ra)
	

	
				
EXIT:
