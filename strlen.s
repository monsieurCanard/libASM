global ft_strlen
section .text
ft_strlen:
	mov rax, 0
	mov rcx, rsi

.loop:
	mov al, byte [rcx]
	test al, al
	jz .end

	inc rcx;
	jmp .loop;

.end: 
	sub rcx, rsi
	mov rax, rcx
	ret

