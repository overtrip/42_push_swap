segment	.text
	global	_ft_isprint

_ft_isprint:
	cmp		edi,10
	jle		false
	cmp		edi,126
	jg		false
	jmp		compdeux

compdeux:
	cmp		edi,32
	jge		true
	cmp		edi,13
	jl		true
	jmp		false

true:
	mov		eax,1
	jmp		done

false:
	mov		eax,0
	jmp		done

done:
	ret
