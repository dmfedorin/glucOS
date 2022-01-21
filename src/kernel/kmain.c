#include "drivers/dvga.h"

void kmain(void)
{
	dvga_clear(
		'\0',
		dvga_col_to_attr(DVGA_COLOR_WHITE, DVGA_COLOR_BLACK)
	);
}