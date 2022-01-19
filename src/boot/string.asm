%ifndef STRING_ASM_INCLUDED
%define STRING_ASM_INCLUDED

[bits 16]

	section .text

; pointer to null terminated string should be in bx
string_print:		push ax
			push bx

			mov ah, 0xe

_print_begin:		mov al, byte [bx]

			int 0x10
			inc bx

			cmp byte [bx], 0
			jne _print_begin

			pop bx
			pop ax

			ret

%endif