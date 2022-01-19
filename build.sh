nasm -o build/imed/boot.bin -f bin src/boot/boot.asm

#i386-elf-gcc -T linker.ld -o build/final/glucOS.bin build/imed/*.o -ffreestanding -nostdlib -lgcc

cat build/imed/boot.bin > build/final/glucOS.bin

qemu-system-x86_64 --drive format=raw,file=build/final/glucOS.bin