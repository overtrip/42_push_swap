segment .text
    global      _ft_strcat
    extern      _ft_strlen

_ft_strcat:

	mov         r13, rdi
	mov         r14, rsi
	mov         rdi, rsi
	call        _ft_strlen
	mov         r15, rax
	mov         rdi, r13
	call        _ft_strlen
	mov         rdi, r13
	add         rdi, rax
	mov         rcx, r15
	mov         rsi, r14
	rep         movsb
	mov byte    [rdi], 0
	mov         rax, r13
	ret
