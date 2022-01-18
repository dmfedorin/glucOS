[org 0x7c00]

	section .text

		jmp boot.entry

boot.hang:	jmp $

db boot.hello_world "hello world", 0xa, 0

boot.entry:	mov ah, 0x0e
		mov al, 'h'
		int 0x10

		jmp boot.hang

; bootsector padding
times 510 - ($ - $$) db 0