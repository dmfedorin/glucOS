#include "dvga.h"

void dvga_set(uint16_t pos, char c, uint8_t attr)
{
	pos *= 2;
	*(VGA_PTR + pos) = c;
	*(VGA_PTR + pos + 1) = attr;
}

void dvga_write(uint16_t pos, char *s, uint8_t attr)
{
	for (uint16_t i = 0; s[i] != '\0'; i++)
		dvga_set(pos + i, s[i], attr);
}

uint8_t dvga_ctoa(dvga_color fg, dvga_color bg)
{
	return fg | bg << 4;
}

uint16_t dvga_rctop(uint8_t row, uint8_t col)
{
	return VGA_WIDTH * row + col;
}

void dvga_clear(char c, uint8_t attr)
{
	for (uint16_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++)
		dvga_set(i, c, attr);
}