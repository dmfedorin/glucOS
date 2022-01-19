%ifndef ENTER32_ASM_INCLUDED
%define ENTER32_ASM_INCLUDED

[bits 16]

	section .text

%include "src/boot/string.asm"

ENTER32_KERNEL_LOAD_ADDR equ 0x7c00

enter32_error_msg:
	db "[..X] disk error", 0xd, 0xa, 0

enter32_disk_error:	mov bx, enter32_error_msg
			call string_print
			cli
			jmp $

; dh should be the number of sectors to read
; dl should be the drive to read from
enter32_read_disk:	ret

enter32_enter_32:	ret

%endif