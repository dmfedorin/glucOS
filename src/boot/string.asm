[bits 16]

	section .text

; pointer to string should be in bx
; length of string should be in cx
string.print:		push ax
			push bx
			push cx

			mov ah, 0xe

_string.print.loop:	mov al, byte [bx]

			int 0xa
			inc bx

			cmp bx, cx
			jl _string.print.loop

			pop cx
			pop bx
			pop ax

			ret