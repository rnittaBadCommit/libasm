section .text
global	_ft_atoi_base

_ft_atoi_base:

_base_check:
	mov	r8, 1	;r8: save negative
	mov	rcx, -1

.basecheck_mainloop:
	inc	rcx
	mov	dl,	BYTE[rsi + rcx]
	cmp	dl, 0
	je	.basecheck_length
	cmp	dl, 9
	jb	.basetmpok
	cmp	dl, 32
	je	.return_zero
	cmp	dl, 43
	je	.return_zero
	cmp	dl, 45
	je	.return_zero
	cmp	dl, 14
	jb	.return_zero
	
.basetmpok:
	mov	rax, rcx
	add	rax, rsi
	inc	rax

.basecheck_tmploop:
	mov	dl, BYTE[rax]
	cmp	dl, 0
	je	.basecheck_mainloop
	cmp	dl, BYTE[rsi + rcx]
	je	.return_zero
	inc	rax
	jmp	.basecheck_tmploop

.return_zero:
	xor	rax, rax
	ret

.basecheck_length:
	cmp	rcx, 2
	jb	.return_zero

	mov	r11, rcx	;r11:	b

;skip	space

	mov	rcx, rdi
	dec	rcx
.skipspace_loop:
	inc	rcx
	mov	dl, [rcx]
	cmp	dl, 0
	je	.return_zero
	cmp	dl, 9
	jb	.sign
	cmp	dl, 14
	jb .skipspace_loop
	cmp dl, 32
	je .skipspace_loop

	dec	rcx
.sign:
	inc	rcx
	mov	dl, BYTE[rcx]
	cmp	dl, 0
	je	.return_zero
	cmp	dl, 43
	je	.sign
	cmp	dl, 45
	je	.negative
	xor	rax, rax
	xor	r9, r9

.main:
	cmp dl, 0
	je	.return

	xor	r9, r9
.main_loop2:
	cmp	r9, r11
	je	.return
	cmp	dl, BYTE[rsi + r9]
	je	.main_tmp
	inc	r9
	jmp	.main_loop2

.main_tmp:
	mul	r11
	add	rax, r9
	inc	rcx
	mov	dl, BYTE[rcx]
	jmp	.main


.return:
	imul	r8
	ret

.negative:
	neg	r8
	jmp	.sign	

.loop:
	jmp	.loop
