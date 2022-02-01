%ifndef MEMORY_ASM_INCLUDED
%define MEMORY_ASM_INCLUDED

[bits 16]

        section .text

%include "src/boot/string.asm"

memory_detect_msg:
        db "[...] detecting memory", 0xd, 0xa, 0

memory_detect_error_msg:
        db "[..X] memory detection error", 0xd, 0xa, 0

MEMORY_LIST_DEST_SEGMENT_ADDR equ 0x7e0
MEMORY_LIST_ENTRY_SIZE equ 24

memory_detect_error:    mov bx, memory_detect_error_msg
                        call string_print

                        jmp $

memory_detect:          push eax
                        push ebx
                        push ecx
                        push edx
                        push di

                        mov bx, memory_detect_msg
                        call string_print

                        mov ax, MEMORY_LIST_DEST_SEGMENT_ADDR
                        mov es, ax
                        
                        xor ebx, ebx
                        mov edx, 0x534d4150
                        mov di, 0

.detect_begin:          mov eax, 0xe820
                        mov ecx, 24
                        int 0x15

                        jc memory_detect_error

                        ; list entry layout
                        ; [ uint64 uint64 uint32 uint32 ]

                        ; first uint64 of list entry is base address
                        ; second uint64 of list entry is region size
                        ; first uint32 of list entry is region type
                        ; last uint32 of list entry is apci extended attrs
                        add di, MEMORY_LIST_ENTRY_SIZE

                        cmp ebx, 0
                        jne .detect_begin

                        xor ax, ax
                        mov es, ax

                        pop di
                        pop edx
                        pop ecx
                        pop ebx
                        pop eax

                        ret

%endif