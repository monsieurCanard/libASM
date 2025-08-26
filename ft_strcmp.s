global ft_strcmp

section .text

; int strcmp(const char *s1, const char *s2);
ft_strcmp:
	xor eax, eax
	mov eax, 0

.loop: 
	mov al, [rsi]
	mov dl, [rdi]
	cmp al, dl
	jne .diff

	test al, dl
	je .equal

	inc rsi
	inc rdi
	jmp .loop

.diff: 
	movzx eax, byte [rsi]
	movzx edx, byte [rdi]
	sub eax, edx
	ret


.equal:
	xor eax, eax
	ret