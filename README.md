# libASM
Library of Assembler Functions

• You must write 64-bit assembly. Beware of the "calling convention".
• You can’t do inline ASM, you must do ’.s’ files.
• You must compile your assembly code with nasm.
• You must use the Intel syntax, not the AT&T syntax.

he library must be called libasm.a.
• You must submit a main function that will test your functions and compile with
your library to demonstrate that it is functional.
• You must rewrite the following functions in assembly:
◦ ft_strlen (man 3 strlen)
◦ ft_strcpy (man 3 strcpy)
◦ ft_strcmp (man 3 strcmp)
◦ ft_write (man 2 write)
◦ ft_read (man 2 read)
◦ ft_strdup (man 3 strdup, you can call to malloc)
• You must check for errors during syscalls and handle them properly when needed.
• Your code must set the variable errno properly.
• For that, you are allowed to call the extern ___error or errno_location.



rax → registre principal (souvent pour les retours de fonction, calculs).

rbx, rcx, rdx → registres de travail.

rsi, rdi → souvent pour passer des arguments (ex: pointeurs).

rsp → stack pointer (pointe vers le sommet de la pile).

rbp → base pointer (repère pour les variables locales).

r8 → r15 → registres supplémentaires (x86-64 en a plus que x86-32).

👉 Chaque registre a aussi des versions plus petites :

rax (64 bits), eax (32 bits), ax (16 bits), al (8 bits).


cmp A, B → fait A - B en interne sans stocker le résultat, mais met à jour les flags du processeur :

Flag	Signification
ZF	Zero Flag → 1 si résultat = 0
SF	Sign Flag → 1 si résultat < 0 (signe négatif)
CF	Carry Flag → 1 si dépassement non signé
OF	Overflow Flag → 1 si dépassement signé


je LABEL → jump if equal → saute si ZF = 1 (résultat = 0)

jne LABEL → jump if not equal → saute si ZF = 0 (résultat ≠ 0)

jl LABEL → jump if less → saute si résultat signé < 0 (SF ≠ OF)

jg LABEL → jump if greater → saute si résultat signé > 0 (ZF=0 et SF=OF)

jz LABEL → jump if zero → idem que je

jnz LABEL → jump if not zero → idem que jne


lea rsi, [rsi]  ; rsi = l'adresse actuelle de rsi

lea = Load Effective Address

Il ne lit pas le contenu mémoire, il calcule l’adresse et la met dans le registre

Ici lea rsi, [rsi] ne sert à rien, car ça ne change pas rsi.

En 64 bits, les registres généraux sont :

64-bit	32-bit	16-bit	8-bit bas	8-bit haut
rax			eax			ax			al					ah
rbx			ebx			bx			bl					bh
rcx			ecx			cx			cl					ch
rdx			edx			dx			dl					dh
rdi			edi			di			—					—
rsi			esi			si			—					—
rbp			ebp			bp			—					—
rsp			esp			sp			—					—
r8–r15	r8d–r15d	r8w–r15w	r8b–r15b	—