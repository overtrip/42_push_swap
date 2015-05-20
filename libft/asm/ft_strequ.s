segment	.text
	global	_ft_strequ
	extern	_ft_strlen

_ft_strequ:

	mov			r12,rsi
	mov			r13,rdi
	cmp			rsi,0
	je			false
	cmp			rdi,0
	je			false
	call		_ft_strlen
	mov			r8,rax
	mov			rdi,rsi
	call		_ft_strlen
	mov			r10,rax
	cmp			r8,r10
	jne			false

loop:
cld
	mov			rsi,r12
	mov			rdi,r13
	mov			rcx,r8
	repe cmpsb
	cmp			ecx,0
	jne			false

true:

	mov			rax,1
	ret

false:

	mov			rax,0
	ret
