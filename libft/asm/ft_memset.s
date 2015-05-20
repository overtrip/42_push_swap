segment .text
	global _ft_memset

_ft_memset:

	mov		r11,rdi
	mov		rcx,rdx
	rep		stosb

done:

	mov			rax,r11
	ret
