global ft_write
extern __errno_location

section .text

ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jge .ret
	
	neg rax
	mov edi, eax
	call __errno_location
	mov [rax], edi
	mov rax, -1
	ret

.ret:
	ret
