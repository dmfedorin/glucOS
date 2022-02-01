#ifndef LAYOUT_H_INCLUDED
#define LAYOUT_H_INCLUDED

#include <stdint.h>

#define MEM_LAYOUT_LIST_PTR ((void *)0x7e00)

struct mem_layout_entry {
        uint64_t base, size;
        uint32_t type, apci_ext_attr;
} __attribute__ ((packed));

void mem_get_layout(struct mem_layout_entry *entries, uint32_t entry_cnt);

#endif