[org 0x7c00]
[bits 16]

	section .text

			jmp boot_entry

%include "src/boot/string.asm"
%include "src/boot/gdt.asm"

boot_hang_msg:
	db "[...] hanging", 0xd, 0xa, 0

boot_hang:		mov bx, boot_hang_msg
			call string_print
			
			cli
			jmp $

boot_boot_msg:
	db "[...] booting glucOS", 0xd, 0xa, 0

boot_entry:		mov bp, 0x7bff
			mov sp, bp

			mov bx, boot_boot_msg
			call string_print

			jmp boot_hang

	; bootsector padding
	times 510 - ($ - $$) db 0
	dw 0xaa55