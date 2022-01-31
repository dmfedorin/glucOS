#include "layout.h"

void mem_get_layout(struct mem_layout_entry *entries, uint32_t entry_cnt)
{
        for (uint32_t i = 0; i < entry_cnt; i++) {
                struct mem_layout_entry *p
                        = (struct mem_layout_entry *)MEM_LAYOUT_LIST_PTR + i;
                entries[i] = *p;
        }
}