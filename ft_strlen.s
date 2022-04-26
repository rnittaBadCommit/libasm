section .text

global _ft_strlen;	size_t strlen(const char *s)

_ft_strlen:
	xor	rax, rax
.loop:
	cmp	BYTE[rdi + rax], 0
	je	.exit
	inc	rax
	jmp	.loop
.exit:
	ret

						
