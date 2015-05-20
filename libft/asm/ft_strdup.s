extern _ft_strlen
extern _malloc

section .text
	global _ft_strdup

_ft_strdup:

	push	rdi
	call	_ft_strlen
	mov		rcx, rax
	push	rcx
	mov		rdi, rax
	inc		rdi
	push	rdi
	call	_malloc
	pop		rdi
	cmp		rax, 0
	je		exit
	pop		rcx
	pop		rsi
	mov		rdi, rax
	cld
	rep		movsb

exit:

	ret
