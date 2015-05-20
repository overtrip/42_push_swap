segment	.text
	global	_ft_memchr

_ft_memchr:

	mov 	al,sil
	mov		rcx,rdx
	repnz	scasb
	cmp		ecx,0
	je		false

find:

	mov		rax,rdi
	ret

false:

	mov		rax,0
	ret


