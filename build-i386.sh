nasm -o build/imed/boot.bin -f bin src/boot/boot.asm
nasm -o build/imed/kpadding.bin -f bin src/kernel/kpadding.asm
nasm -o build/imed/kentry.o -f elf32 src/kernel/kentry.asm

# build kernel
# {
	i386-elf-gcc -o build/imed/kmain.o -c src/kernel/kmain.c -std=gnu99 -ffreestanding

	# build drivers
	# {
		i386-elf-gcc -o build/imed/dvga.o -c src/kernel/drivers/dvga.c -std=gnu99 -ffreestanding
	# }
# }

i386-elf-gcc -T linker.ld -o build/imed/kernel.bin -ffreestanding -nostdlib -lgcc

cat build/imed/boot.bin build/imed/kernel.bin build/imed/kpadding.bin > build/final/glucOS.bin

qemu-system-x86_64 --drive format=raw,file=build/final/glucOS.bin