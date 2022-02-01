#ifndef TERMIO_H_INCLUDED
#define TERMIO_H_INCLUDED

#include <stdint.h>

#define TERM_VGA_PTR    ((char *)0xb8000)
#define TERM_VGA_WIDTH  80
#define TERM_VGA_HEIGHT 25

enum term_color {
        TERM_COLOR_BLACK                = 0x0,
        TERM_COLOR_BLUE                 = 0x1,
        TERM_COLOR_GREEN                = 0x2,
        TERM_COLOR_CYAN                 = 0x3,
        TERM_COLOR_RED                  = 0x4,
        TERM_COLOR_MAGENTA              = 0x5,
        TERM_COLOR_BROWN                = 0x6,
        TERM_COLOR_LIGHT_GRAY           = 0x7,
        TERM_COLOR_GRAY	                = 0x8,
        TERM_COLOR_LIGHT_BLUE           = 0x9,
        TERM_COLOR_LIGHT_GREEN          = 0xa,
        TERM_COLOR_LIGHT_CYAN           = 0xb,
        TERM_COLOR_LIGHT_RED            = 0xc,
        TERM_COLOR_LIGHT_MAGENTA        = 0xd,
        TERM_COLOR_LIGHT_BROWN          = 0xe,
        TERM_COLOR_WHITE                = 0xf,
};

void term_clear(enum term_color fg, enum term_color bg);
void term_print(const char *s);
void term_print_hex(uint64_t n);

#endif