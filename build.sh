nasm -o build/imed/boot.bin -f bin src/boot/boot.asm

# build kernel
# {
        nasm -o build/imed/entry.o -f elf32 src/kernel/entry.asm
        i686-elf-gcc -o build/imed/main.o -c src/kernel/main.c -std=gnu99 -ffreestanding
        nasm -o build/imed/padding.bin -f bin src/kernel/padding.asm

        # build terminal
        # {
                i686-elf-gcc -o build/imed/termio.o -c src/kernel/terminal/termio.c -std=gnu99 -ffreestanding
        # }

        # build memory
        # {
                i686-elf-gcc -o build/imed/layout.o -c src/kernel/memory/layout.c -std=gnu99 -ffreestanding
        # }
# }

i686-elf-gcc -T linker.ld -o build/imed/kernel.bin -ffreestanding -nostdlib -lgcc

cat build/imed/boot.bin build/imed/kernel.bin build/imed/padding.bin > build/final/glucOS.bin

qemu-system-x86_64 --drive format=raw,file=build/final/glucOS.bin -m 1G