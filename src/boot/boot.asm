%ifndef BOOT_ASM_INCLUDED
%define BOOT_ASM_INCLUDED

[org 0x7c00]
[bits 16]

	section .text

boot_setup:		xor ax, ax
			mov ds, ax
			mov es, ax
			
			mov ss, ax
			mov sp, 0x7c00

			jmp boot_entry

%include "src/boot/string.asm"
%include "src/boot/gdt.asm"
%include "src/boot/enter32.asm"

boot_hello_msg:
	db "[...] booting glucOS", 0xd, 0xa, 0

boot_drive:
	db 0

boot_entry:		mov [boot_drive], dl

			mov bx, boot_hello_msg
			call string_print

			cli
			jmp $

	; bootsector padding
	times 510 - ($ - $$) db 0
	dw 0xaa55

%endif