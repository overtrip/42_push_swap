segment	.text
	global	_ft_bzero

_ft_bzero:

while:
	cmp			rsi,0
	jle			done
	mov byte	[rdi],0
	inc			rdi
	dec			rsi
	jmp			while

done:
	ret
