section .text
global _ft_strcpy	;char *strcpy(char *s1, const chhar *s2)

_ft_strcpy:
	mov	rax, rdi

.loop:
	mov	dl, BYTE[rsi]
	mov	BYTE[rdi], dl
	cmp	BYTE[rsi], 0
	je	.exit
	inc	rsi
	inc rdi
	jmp .loop

.exit:
	ret
