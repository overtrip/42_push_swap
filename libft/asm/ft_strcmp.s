segment	.text
	global	_ft_strcmp

_ft_strcmp:

	mov			dil,byte [rdi]
	mov			sil,byte [rsi]
	cmp			dil,sil
	jne			compare
	cmp 		dil,0
	je			compare
	cmp 		sil,0
	je			compare
	inc			rdi
	inc			rsi
	jmp			_ft_strcmp

compare:

	sub			dil,sil
	movsx		rax,dil

done:

	ret
