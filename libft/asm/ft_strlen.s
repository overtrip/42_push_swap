segment .text
	global  _ft_strlen

_ft_strlen:

	cmp			rdi,0
	je			fail
	mov         al,0
	xor         ecx,ecx ; initialise 0
	not         ecx
	mov         r10d,ecx
	repnz       scasb
	sub         ecx,r10d
	not         ecx
	mov         eax,ecx
	ret

fail:

	mov			eax,0
	ret
