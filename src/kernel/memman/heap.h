#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <stdint.h>

#define MM_HEAP_START_PTR	((void *)0x7e00)
#define MM_HEAP_SIZE		0x1000

typedef struct {
	void *data;
	uint32_t size;
} mm_heap_entry;

void *mm_alloc(uint32_t size);
void mm_free(void *data);

#endif