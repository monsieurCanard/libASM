global ft_strcmp

section .text

ft_strcmp:
	mov eax, 0

.loop: 
	mov al, [rdi]
	mov dl, [rsi]
	cmp al, dl
	jne .diff

	test al, al
	je .equal

	inc rsi
	inc rdi
	jmp .loop

.diff: 
	movzx eax, byte [rdi]
	movzx edx, byte [rsi]
	sub eax, edx
	test eax, eax

	//Jump if sign bit is set (negative)
	js .negative
	mov eax, 1
	ret

.negative:
	mov eax, -1
	ret

.equal:
	xor eax, eax
	ret