section .text
global	_ft_atoi_base

_ft_atoi_base:

_base_check:
	mov	r8, 1	;r8: save negative
	mov	rcx, rsi
	dec	rcx

.basecheck_mainloop:
	inc	rcx
	mov	dl,	BYTE[rcx]
	cmp	dl, 0
	je	.basecheck_length
	cmp	dl, 9
	jb	.basetmpok
	cmp	dl, 32
	je	.baseerr
	cmp	dl, 43
	je	.baseerr
	cmp	dl, 45
	je	.baseerr
	cmp	dl, 14
	jb	.baseerr
	
.basetmpok:
	mov	rax, rcx
	inc	rax

.basecheck_tmploop:
	mov	dl, BYTE[rax]
	cmp	dl, 0
	je	.basecheck_mainloop
	cmp	dl, BYTE[rcx]
	je	.baseerr
	inc	rax
	jmp	.basecheck_tmploop

.baseerr:
	xor	rax, rax
	mov	rax, -1
	ret

.basecheck_length:
	cmp	rcx, 2
	jb	.baseerr
	mov	r11, rcx	;r11:	b

;skip	space

	mov	rcx, rsi
	dec	rcx
.skipspace_loop:
	inc	rcx
	mov	dl, [rcx]
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
	jmp	.return
	cmp	dl, BYTE[rdi + r9]
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
