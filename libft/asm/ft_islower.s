segment .text
	global	_ft_islower

_ft_islower:
	cmp		edi,97
	jl		false
	cmp		edi,122
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
