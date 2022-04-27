section .text
global _ft_read
extern ___error

_ft_read:
	mov	rax, 0x2000003
	syscall
	jc	.err
	ret

.err:
	push	rax
	call	___error
	pop	r8
	mov	[rax], r8
	mov	rax, -1
	ret
