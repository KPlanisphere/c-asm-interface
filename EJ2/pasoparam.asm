global suma;

suma:
	push dword ebp
	mov ebp, esp;
	mov eax, [ebp + 8]
	mov edx, [ebp+12]
	add eax, edx
	pop dword ebp
	ret
