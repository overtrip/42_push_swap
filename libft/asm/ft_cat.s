segment	.data

putmsg:

	msg1	db	"error",10

segment	.bss

buf: resb	256

segment	.text
	global	_ft_cat
	extern	_ft_puts

_ft_cat:

	mov		r8,rdi

true:

	mov		rdi,r8
	lea		rsi,[rel buf]
	mov		rdx,256
	mov		rax,0x02000003
	syscall
	cmp		rdx,256
	je		false
	cmp		rax,0
	je		done
	mov		rdi,1
	lea		rsi,[rel buf]
	mov		rdx,rax
	mov		rax,0x02000004
	syscall
	jmp		true

false:

	lea		rsi,[rel msg1]
	mov		rdi,1
	mov		rdx,7
	mov		rax,0x02000004
	syscall

done:

	ret
