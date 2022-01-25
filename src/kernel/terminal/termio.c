#include "termio.h"

static inline __attribute__ ((always_inline)) uint8_t col_to_attr(
	term_color fg,
	term_color bg)
{
	return bg << 4 | fg;
}

static uint32_t print_pos = 0;

void term_clear(term_color fg, term_color bg)
{
	uint32_t vga_size = TERM_VGA_WIDTH * TERM_VGA_HEIGHT * 2;

	for (uint32_t i = 0; i < vga_size; i += 2) {
		*(TERM_VGA_PTR + i) = '\0';
		*(TERM_VGA_PTR + i + 1) = col_to_attr(fg, bg);
	}

	print_pos = 0;
}

static inline __attribute__ ((always_inline)) void put_char(char c)
{
	*(TERM_VGA_PTR + print_pos * 2) = c;
	print_pos++;
}

static inline void handle_escape(char c)
{
	switch (c) {
	case '\r':
		print_pos -= print_pos % TERM_VGA_WIDTH;
		break;

	case '\n':
		print_pos += TERM_VGA_WIDTH;
		break;
	}
}

void term_print(const char *s)
{
	for (uint32_t i = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\r':
		case '\n':
			handle_escape(s[i]);
			break;
		
		default:
			put_char(s[i]);
			break;
		}
	}
}

void term_print_hex(uint32_t n)
{
}