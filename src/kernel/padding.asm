; pad out some sectors to prevent disk error
; this must be added after the kernel in the OS binary

[bits 16]

	section .text

PADDING_SECTOR_COUNT equ 32

	times PADDING_SECTOR_COUNT * 512 db 0