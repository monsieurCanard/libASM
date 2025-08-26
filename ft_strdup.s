global ft_strdup
extern __errno_location

section .text

ft_strdup:
	mov rbx, rsi
	.count_word





.count_word:
	mov al, rbx
	test al, al
	jnz .loop 