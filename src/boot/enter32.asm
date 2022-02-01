%ifndef ENTER32_ASM_INCLUDED
%define ENTER32_ASM_INCLUDED

[bits 16]

        section .text

%include "src/boot/gdt.asm"
%include "src/boot/string.asm"

enter32_read_msg:
        db "[...] reading kernel from disk", 0xd, 0xa, 0

enter32_error_msg:
        db "[..X] disk error", 0xd, 0xa, 0

enter32_disk_error:     mov bx, enter32_error_msg
                        call string_print

                        jmp $

ENTER32_KERNEL_LOAD_ADDR equ 0x1000
ENTER32_SECTORS_TO_READ equ 32

; dl should be the drive to read from
enter32_read_disk:      push ax
                        push bx
                        push cx
                        
                        mov bx, enter32_read_msg
                        call string_print

                        xor ax, ax
                        mov es, ax

                        mov bx, ENTER32_KERNEL_LOAD_ADDR

                        mov ah, 2
                        mov al, ENTER32_SECTORS_TO_READ
                        mov ch, 0
                        mov cl, 2
                        xor dh, dh
                        ; dl should already be set, no need to do it here

                        int 0x13

                        jc enter32_disk_error
                        
                        pop cx
                        pop bx
                        pop ax

                        ret

; assumes correct conditions for disk read
enter32_enter_32:       call enter32_read_disk

                        cli
                        lgdt [gdt_desc]

                        mov eax, cr0
                        or eax, 0x1
                        mov cr0, eax

                        jmp GDT_CODE_SEG:enter32_entry

[bits 32]

enter32_entry:          mov ax, GDT_DATA_SEG
                        mov ds, ax
                        mov es, ax
                        mov fs, ax
                        mov gs, ax

                        mov ss, ax
                        mov esp, 0x7c00
                        mov ebp, esp

                        jmp ENTER32_KERNEL_LOAD_ADDR

%endif