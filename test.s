global _start

section .data
	messsage: db "Hello, World!";


section .text
_start:
	mov rax, 1					;
	mov rdi, 1					;
	mov rsi, messsage	;
	mov rdx, 13+1			;
	syscall						;
	jmp exit

exit:	
	mov     rax, 60       ; syscall: sys_exit
  xor     rdi, rdi      ; status = 0
  syscall