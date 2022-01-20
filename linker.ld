OUTPUT_FORMAT(binary)
INPUT(
	build/imed/kentry.o
	build/imed/kmain.o
	build/imed/dvga.o
)

SECTIONS {
	. = 0x1000;
	
	.text BLOCK(4K) : ALIGN(4K) {
		*(.text)
	}

	.rodata BLOCK(4K) : ALIGN(4K) {
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K) {
		*(.data)
	}

	.bss BLOCK(4K) : ALIGN(4K) {
		*(COMMON)
		*(.bss)
	}
}