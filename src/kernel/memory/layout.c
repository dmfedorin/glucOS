#include "layout.h"

static inline __attribute__ ((always_inline))
const struct mem_layout_entry *get_entry(uint32_t ind)
{
        return (struct mem_layout_entry *)MEM_LAYOUT_LIST_PTR + ind;
}

uint32_t mem_get_layout_entry_cnt(void)
{
        uint32_t entry_cnt = 0;

        while (get_entry(entry_cnt)->type != MEM_LAYOUT_ENTRY_TYPE_NULL)
                entry_cnt++;

        return entry_cnt;
}

void mem_get_layout_entries(struct mem_layout_entry *entries,
                            uint32_t entry_cnt)
{
        for (uint32_t i = 0; i < entry_cnt; i++)
                entries[i] = *get_entry(i);
}

// total amount of a certain type of memory in bytes
uint64_t mem_get_memory_bytes(const struct mem_layout_entry *entries,
                              enum mem_layout_entry_type type)
{
        uint64_t total_bytes = 0;
        uint32_t entry_cnt = mem_get_layout_entry_cnt();

        for (uint32_t i = 0; i < entry_cnt; i++) {
                if (entries[i].type & type)
                        total_bytes += entries[i].size;
        }

        return total_bytes;
}

// combines adjacent memory layout entries into a single entry
void mem_combine_layout_entries(struct mem_layout_entry *entries)
{
}