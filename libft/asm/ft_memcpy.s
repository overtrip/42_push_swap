segment	.text
	global	_ft_memcpy

_ft_memcpy:

	push	rdi
	mov		rcx,rdx
	mov		rax,rsi
	rep		movsb

done:

	pop		rdi
	mov		rax,rdi
	ret
