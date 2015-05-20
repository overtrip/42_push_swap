segment .text
	global	_ft_isdigit

_ft_isdigit:

	cmp		edi,48
	jl		false
	cmp		edi,57
	jg		false
	jmp		true

true:

	mov		eax,1
	jmp		done

false:

	mov		eax,0
	jmp		done

done:

	ret
