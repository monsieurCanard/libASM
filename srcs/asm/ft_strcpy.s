global ft_strcpy
section .text

ft_strcpy:
push rbx
	mov rbx, rdi
	
.loop:
	mov al, [rsi]
	mov [rdi], al

	inc rdi
	inc rsi
	
	test al, al
	jnz .loop
	
	mov rax, rbx
	pop rbx
	ret