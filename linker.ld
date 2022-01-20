OUTPUT_FORMAT(binary)

SECTIONS {
	. = 0x7e00;
	
	.text BLOCK(8K) : ALIGN(8K) {
		*(.text)
	}

	.rodata BLOCK(8K) : ALIGN(8K) {
		*(.rodata)
	}

	.data BLOCK(8K) : ALIGN(8K) {
		*(.data)
	}

	.bss BLOCK(8K) : ALIGN(8K) {
		*(.bss)
	}
}