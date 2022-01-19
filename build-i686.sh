nasm -o build/imed/boot.bin -f bin src/boot/boot.asm

i686-elf-gcc -o build/imed/kmain.o -c src/kernel/kmain.c -ffreestanding

i686-elf-gcc -T linker.ld -o build/imed/kernel.bin build/imed/*.o -ffreestanding -nostdlib -lgcc

cat build/imed/boot.bin build/imed/kernel.bin > build/final/glucOS.bin

qemu-system-x86_64 --drive format=raw,file=build/final/glucOS.bin