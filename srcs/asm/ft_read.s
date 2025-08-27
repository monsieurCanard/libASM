global ft_read
extern __errno_location

section .text
ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jge .ret
	
	neg rax
	mov edi, eax
	call __errno_location wrt ..plt
	mov [rax], edi
	mov rax, -1
	ret

.ret:
	ret
