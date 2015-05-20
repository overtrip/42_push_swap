segment	.text
	global	_ft_isascii

_ft_isascii:
	cmp		edi,0
	jl		false
	cmp		edi,127
	jg		false

true:
	mov		eax,1
	jmp		done

false:
	mov		eax,0
	jmp		done

done:
	ret
