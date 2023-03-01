global half

half: push ecx
	mov ecx, [esp+8]
	mov eax, 0
agn: inc eax
	sub ecx, 2
	jg agn
	jz dun
	mov eax, 0
dun: pop ecx
	ret
