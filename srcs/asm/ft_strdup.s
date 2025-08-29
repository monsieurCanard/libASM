global ft_strdup
extern __errno_location
extern malloc

section .text

ft_strdup:
	push rbx
	mov rbx, rdi 

	call ft_strlen
	inc rax
	
	mov rdi, rax
	call malloc wrt ..plt
	test rax, rax
	jz .error
	
	mov rsi, rbx
	mov rdi, rax
	call ft_strcpy
	
	pop rbx
	ret

.error:
	xor rax, rax
	pop rbx
	
	mov edi, 12
	call __errno_location wrt ..plt
	mov [rax], edi
	xor rax, rax
	ret

ft_strlen:
	mov rcx, rdi

.loop:
	mov dl, byte [rcx]
	test dl, dl
	jz .end

	inc rcx;
	jmp .loop;

.end: 
	sub rcx, rdi
	mov rax, rcx
	ret

ft_strcpy:
	mov rax, rdi

.loop:
	mov dl, [rsi]
	mov [rdi], dl
	inc rdi
	inc rsi
	test dl, dl
	jnz .loop
	ret