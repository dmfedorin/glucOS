OUTPUT_FORMAT(binary)
INPUT(
	build/imed/entry.o
	build/imed/main.o

	/* terminal */
	build/imed/termio.o

	/* memman */
	build/imed/heap.o
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