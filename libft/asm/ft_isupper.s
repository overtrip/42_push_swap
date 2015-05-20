segment .text
	global	_ft_isupper

_ft_isupper:

	cmp		edi,65
	jl		false
	cmp		edi,90
	jg		false

true:
	mov		eax,1
	jmp		done

false:
	mov		eax,0
	jmp		done

done:
	ret
