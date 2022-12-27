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

# t0 save '0' ASCII 
# t1 save split char
# t2 save operator(+,-,x,/,=) 
# t3  save operator ASCII	
# t4 save operator count 
# a0 save String
# a1 save string Buffer
# a2 save int 10
# a4 save former operator
# a5 save int 1
# a7 save enviroment call num
# s0 save equation address
# s1 save equation add index address
# s2 save equation data
# s4 save int 2
# s6 save index
# s7 save change split char to int 
# s8 save Eual sign ASCII
# s10 save operand
# s11 save result


MAIN:
	# print # 
	la 	a0, msg 
	li 	a7, 4
	ecall
	
	# input equation
	la 	a0, equation
	lI 	a1, MAXBUFFER
	li 	a7, 8
	ecall
	
	#print equation
	li 	a7,4
	ecall
	
	# save equation
	add	s0, zero, a0
	# init register 
	li 	s8, EQUAL_OP
	li	s6,  0
	li	s2,  0
	li 	s11, 0
	li 	t1, 0
	li 	t4, 0
	li 	s4, 2
	
	
LOOP:
	#split char
	add 	s1, s0, s6
	lb 	s2, 0(s1)
	

	# split char test print
	#add 	a0, s2, zero
	#li 	a7, 11
	#ecall
	
	#save former operator
	add 	a4, zero, t2
	
	# char change intager
	li 	t0, CHAR_ZERO 
	li 	a2, 10
	li 	a5, 1
	
	sub 	t1, s2, t0
	
	bltu 	t1, a2, CHANGE
	
	
	#save operator
	addi 	t2, t1, CHAR_ZERO
	#count operator
	addi 	t4, t4, 1
	
	beq 	t4, s4,CHECK

NEXT:
	# meet EQAL_OP EXIT
	beq 	t2, s8,EXIT	
	
	# index += 1
	addi 	s6,s6,1
	#go to LOOP
	beq 	zero, zero, LOOP
	
	
CHECK:
	
	bnez 	s10,OPERATE
	#save s10
	add 	s10, s7, zero


OPERATE:	
	#ADD
	li 	t3 , ADD_OP
	beq 	a4, t3, ADD
	
	#SUB
	li 	t3 , SUB_OP
	beq 	a4, t3, SUB
	
	#MUL
	li 	t3 , MUL_OP
	beq 	a4, t3, MUL
	
	#DIV
	li 	t3 , DIV_OP
	beq 	a4, t3, DIV
	
	bltu 	s7, a2, MULTFORMER
	
ADD: 
	add 	s11 ,s11 ,s10	
	jal 	ra, PRINT
	jalr 	zero, 0(ra)


SUB: 
	sub 	s11, s11, s10	
	jal 	ra, PRINT
	jalr 	zero, 0(ra)
	

MUL: 
	mul 	s11, s11, s10	
	jal 	ra, PRINT
	jalr 	zero, 0(ra)
	

DIV: 
	div 	s11, s11, s10	
	jal 	ra, PRINT
	jalr 	zero, 0(ra)
	

PRINT:	
	add 	a0, s11, zero
	li 	a7, 1
	ecall
	
	la 	a0, changeLine
	li 	a7, 4
	ecall
	
	sub 	t4, t4,a5
	li 	s10, 0
	
	jal 	ra, NEXT
	jalr 	zero, 0(ra)


CHANGE:	 
	beqz 	s11, FORMER
	beqz  	t4, OPERATE
	bnez 	s11, LATER


FORMER:	
	bnez t4, LATER
	add s11,t1,zero
	jal ra, NEXT
	jalr zero,0(ra)	
	

LATER:
	add 	s7, t1, zero
	blt  	t4,s4,MULTLATER
	 
	
	jal 	ra, OPERATE
	jalr 	zero, 0(ra)
	

MULTLATER:
	 
	li 	t6, 10
	mul 	s10,s10,t6
	add 	s10,s10,s7
	jal 	ra, NEXT	
	jalr 	zero, 0(ra)
	

MULTFORMER:
	li 	t6, 10
	mul 	s11, s11, t6
	add 	s11, s11, t1
	jal 	ra, NEXT
	jalr 	zero, 0(ra)
	

EXIT:
