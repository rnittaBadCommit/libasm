section .text
global _ft_strcmp;	int	str_cmp(const char *s1, const char *s2)

_ft_strcmp:
.loop
	movzx	rax, BYTE[rdi]
	cmp	rax, 0
	je	.exit
	movzx	r11, BYTE[rsi]
	sub	rax, r11
	jne	.exit
	inc	rdi
	inc	rsi	
	jmp	.loop

.exit
	ret
