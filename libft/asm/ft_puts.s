global	_ft_puts
extern	_ft_strlen

section .data

message:	db	"",10


section	.text

_ft_puts:
	mov		r15,rdi
	call	_ft_strlen
	mov		rdi,1
	mov		rsi,r15
	mov		rdx,rax
	mov		rax,0x02000004
	syscall

true:
	mov		rdi,1
	lea		rsi,[rel message]
	mov		rdx,1
	mov		rax,0x02000004
	syscall

done:
	ret
