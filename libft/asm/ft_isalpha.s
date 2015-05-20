segment	.text
	global	_ft_isalpha
	extern	_ft_islower
	extern	_ft_isupper

_ft_isalpha:
	call	_ft_isupper
	cmp		eax,1
	je		true
	call	_ft_islower
	cmp		eax,1
	je		true

false:
	mov		eax,0
	jmp		done

true:
	mov		eax,1
	jmp		done

done:
	ret
