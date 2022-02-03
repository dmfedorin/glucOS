#ifndef LAYOUT_H_INCLUDED
#define LAYOUT_H_INCLUDED

#include <stdint.h>

#define MEM_LAYOUT_LIST_PTR ((void *)0x7e00)

enum mem_layout_entry_type {
        MEM_LAYOUT_ENTRY_TYPE_NULL              = 0,
        MEM_LAYOUT_ENTRY_TYPE_FREE              = 1,
        MEM_LAYOUT_ENTRY_TYPE_RESERVED          = 2,
        MEM_LAYOUT_ENTRY_TYPE_ACPI_RECLAIMABLE  = 3,
        MEM_LAYOUT_ENTRY_TYPE_ACPI_NON_VOLATILE = 4,
        MEM_LAYOUT_ENTRY_TYPE_BAD               = 5,
};

struct mem_layout_entry {
        uint64_t base, size;
        uint32_t type, acpi_ext_attr;
} __attribute__ ((packed));

uint32_t mem_get_layout_entry_cnt(void);

void mem_get_layout_entries(struct mem_layout_entry *entries,
                            uint32_t entry_cnt);

// total amount of a certain type of memory in bytes
uint64_t mem_get_memory_bytes(const struct mem_layout_entry *entries,
                              enum mem_layout_entry_type type);

// combines adjacent memory layout entries into a single entry
void mem_combine_layout_entries(struct mem_layout_entry *entries);

#endif