[org 0x7c00]
[bits 16]

	section .text

			jmp boot.entry

%include "src/boot/string.asm"

boot.hang_msg db "hanging...", 0xa

boot.hang:		mov bx, boot.hang_msg
			mov cx, 11
			call string.print

			jmp $

boot.setup:		mov bp, 0x7bff
			mov sp, bp
			ret

boot.hello_world db "hello world", 0xa

boot.entry:		call boot.setup

			mov bx, boot.hello_world
			mov cx, 12
			call string.print

			jmp boot.hang

; bootsector padding
times 510 - ($ - $$) db 0
dw 0xaa55