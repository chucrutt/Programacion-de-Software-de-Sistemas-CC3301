	.file	"sort-c-nbits.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	sort
	.type	sort, @function
sort:
	slli	t1,a1,2
	addi	t1,t1,-4
	add	t1,a0,t1
	bgeu	a0,t1,.L1
	mv	a1,a0
	j	.L9
.L12:
	li	a3,0
	j	.L5
.L16:
	ret
.L3:
	li	a4,0
	bne	a7,zero,.L10
.L11:
	addi	a1,a1,4
	bleu	t1,a1,.L16
.L9:
	lw	a6,0(a1)
	lw	a7,4(a1)
	beq	a6,zero,.L3
	mv	a5,a6
	li	a4,0
.L4:
	andi	a3,a5,1
	add	a4,a3,a4
	srli	a5,a5,1
	bne	a5,zero,.L4
	beq	a7,zero,.L12
.L10:
	mv	a5,a7
	li	a3,0
.L6:
	andi	a2,a5,1
	add	a3,a2,a3
	srli	a5,a5,1
	bne	a5,zero,.L6
.L5:
	bge	a4,a3,.L11
	sw	a7,0(a1)
	sw	a6,4(a1)
	mv	a1,a0
	j	.L9
.L1:
	ret
	.size	sort, .-sort
	.ident	"GCC: (GNU) 11.1.0"
