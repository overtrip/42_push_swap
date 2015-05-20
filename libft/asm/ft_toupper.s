segment	.text
	global	_ft_toupper
	extern	_ft_islower

_ft_toupper:

	mov		r11d,edi
	call	_ft_islower
	cmp		eax,1
	jne		false
	sub		r11d,32
	mov		eax,r11d

false:
	mov		eax,r11d

done:

	ret
