global imprimo
extern printf
section .data
	msg db "hola mundo!!", eah,
section .text
	tmprimo:
	push dword msg
	call printf
	add esp,4
	ret
