global ft_strlen
section .text
ft_strlen:

	push rbp
	mov rbp, rsp
	mov rcx, rdi

.loop:
	mov al, byte [rdi]
	test al, al
	jz .end

	inc rdi;
	; inc rcx;
	jmp .loop;

.end: 
	mov rax, rdi;
	sub rax, rcx
	pop rbp
	ret

