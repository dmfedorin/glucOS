#include "dvga.h"

void dvga_set_char(uint16_t pos, char c, uint8_t attr)
{
	pos *= 2;
	*(DVGA_VGA_PTR + pos) = c;
	*(DVGA_VGA_PTR + pos + 1) = attr;
}

void dvga_write_str(uint16_t pos, const char *s, uint8_t attr)
{
	for (uint16_t i = 0; s[i] != '\0'; i++)
		dvga_set_char(pos + i, s[i], attr);
}

uint8_t dvga_col_to_attr(dvga_color fg, dvga_color bg)
{
	return fg | bg << 4;
}

uint16_t dvga_row_col_to_pos(uint8_t row, uint8_t col)
{
	return DVGA_VGA_WIDTH * row + col;
}

void dvga_clear(char c, uint8_t attr)
{
	for (uint16_t i = 0; i < DVGA_VGA_WIDTH * DVGA_VGA_HEIGHT; i++)
		dvga_set_char(i, c, attr);
}