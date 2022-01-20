#ifndef DVGA_H_INCLUDED
#define DVGA_H_INCLUDED

#include <stdint.h>

#define VGA_PTR ((char *)0xb8000)
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

typedef enum {
	DVGA_COLOR_BLACK = 0x00,
	DVGA_COLOR_BLUE = 0x01,
	DVGA_COLOR_GREEN = 0x02,
	DVGA_COLOR_CYAN = 0x03,
	DVGA_COLOR_RED = 0x04,
	DVGA_COLOR_MAGENTA = 0x05,
	DVGA_COLOR_BROWN = 0x06,
	DVGA_COLOR_LIGHT_GRAY = 0x07,

	DVGA_COLOR_GRAY = 0x08,
	DVGA_COLOR_LIGHT_BLUE = 0x09,
	DVGA_COLOR_LIGHT_GREEN = 0x0a,
	DVGA_COLOR_LIGHT_CYAN = 0x0b,
	DVGA_COLOR_LIGHT_RED = 0x0c,
	DVGA_COLOR_LIGHT_MAGENTA = 0x0d,
	DVGA_COLOR_LIGHT_BROWN = 0x0e,
	DVGA_COLOR_WHITE = 0x0f,
} dvga_color;

void dvga_set(uint16_t pos, char c, uint8_t attr);
void dvga_write(uint16_t pos, char *s, uint8_t attr);
uint8_t dvga_ctoa(dvga_color fg, dvga_color bg);
uint16_t dvga_rctop(uint8_t row, uint8_t col);
void dvga_clear(char c, uint8_t attr);

#endif