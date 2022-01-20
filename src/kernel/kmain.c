#include "drivers/dvga.h"

void kmain(void)
{
	dvga_clear('\0', dvga_ctoa(DVGA_COLOR_WHITE, DVGA_COLOR_BLACK));

	dvga_write(
		dvga_rctop(0, 36),
		"[glucOS]",
		dvga_ctoa(DVGA_COLOR_WHITE, DVGA_COLOR_GREEN));
}