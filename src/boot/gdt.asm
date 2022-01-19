[bits 16]

	section .text

gdt_start:

gdt_null_entry:
	dq 0

;gdt_dummy_entry:
;	dw [segment length, bits 0 - 15]
;	dw [segment base, bits 0 - 15]
;	db [segment base, bits 16 - 23]
;	db [flags]
;	db [flags (first 4 bits) - segment length, bits 16 - 19 (last 4 bits)]
;	db [segment base, bits 24 - 31]

gdt_code_entry:
	dw 0xffff
	dw 0
	db 0
	db 0b10011010
	db 0b11001111
	db 0

gdt_data_entry:
	dw 0xffff
	dw 0
	db 0
	db 0b10010010
	db 0b11001111
	db 0

gdt_end:

gdt_desc:
	dw gdt_end - gdt_start - 1
	dd gdt_start

GDT_CODE_SEG equ gdt_code_entry - gdt_start
GDT_DATA_SEG equ gdt_data_entry - gdt_start