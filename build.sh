nasm -o build/imed/boot.bin -f bin src/boot/boot.asm

qemu-system-x86_64 --drive format=raw,file=build/imed/boot.bin