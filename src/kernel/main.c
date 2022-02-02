#include "terminal/termio.h"
#include "memory/layout.h"

void krnl_main(void)
{
        term_clear(TERM_COLOR_LIGHT_GRAY, TERM_COLOR_BLACK);
        term_print("[glucOS]\r\n\n");
        
        struct mem_layout_entry entries[16];
        mem_get_layout_entries(entries, 16);

        term_print_hex(mem_get_memory_bytes(entries, MEM_LAYOUT_ENTRY_TYPE_FREE));
        term_print("\r\n\n");

        for (uint32_t i = 0; i < 16; i++) {
                term_print_hex(entries[i].base);
                term_print(" | ");
                term_print_hex(entries[i].size);
                term_print(" | ");
                term_print_hex(entries[i].type);
                term_print("\r\n");
        }
}