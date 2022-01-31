#include "terminal/termio.h"
#include "memory/layout.h"

void krnl_main(void)
{
        term_clear(TERM_COLOR_LIGHT_GRAY, TERM_COLOR_BLACK);
        term_print("[glucOS]\r\n\n");

        term_print_hex(0xdeadbeef);
        term_print("\r\n");

        struct mem_layout_entry entries[16];
        mem_get_layout(entries, 16);

        for (uint32_t i = 0; i < 16; i++) {
                term_print("base: ");
                term_print_hex(entries[i].base);
                term_print(" | size: ");
                term_print_hex(entries[i].size);
                term_print("\r\n");
        }
}