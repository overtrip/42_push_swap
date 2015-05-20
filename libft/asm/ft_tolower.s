segment	.text
	global	_ft_tolower
	extern	_ft_isupper

_ft_tolower:

	mov		r10d,edi
	call	_ft_isupper
	cmp		eax,1
	jne		false
	add		r10d,32
	mov		eax,r10d

false:
	mov		eax,r10d

done:

	ret
