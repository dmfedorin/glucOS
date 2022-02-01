#include "termio.h"

static inline __attribute__ ((always_inline)) uint8_t col_to_attr(
        enum term_color fg,
        enum term_color bg)
{
        return bg << 4 | fg;
}

static uint32_t print_pos = 0;

void term_clear(enum term_color fg, enum term_color bg)
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

const char hex_print_map[16] = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
};

static inline __attribute__ ((always_inline)) void put_hex(uint8_t h)
{
        put_char(hex_print_map[(h & 0xf0) >> 4]);
        put_char(hex_print_map[h & 0xf]);
}

void term_print_hex(uint64_t n)
{
        term_print("0x");

        for (int i = sizeof(uint64_t) - 1; i >= 0; i--) {
                uint8_t *p = (uint8_t *)&n + i;
                put_hex(*p);
        }
}