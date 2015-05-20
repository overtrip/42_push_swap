segment	.text
	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit

_ft_isalnum:
	call	_ft_isalpha
	cmp		eax,1
	je		true
	call	_ft_isdigit
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
