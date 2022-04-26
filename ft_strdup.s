section .text
global	_ft_strdup
extern	_malloc

_ft_strdup:
	push	rdi
	xor		rcx, rcx
.countloop:
	cmp		BYTE[rdi + rcx], 0
	je		.malloc
	inc		rcx
	jne		.countloop

.malloc:
	inc		rcx
	mov		rdi, rcx
	call	_malloc	
	pop		rdi
	cmp		rax, 0
	je		.return
	xor		rcx, rcx

.cpyloop:
	mov		dl, BYTE[rdi + rcx]
	mov		BYTE[rax + rcx], dl
	inc		rcx
	cmp		dl, 0
	jne		.cpyloop
	jmp		.return

.return:
	ret
