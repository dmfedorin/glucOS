#include "terminal/termio.h"

void krnl_main(void)
{
	term_clear(TERM_COLOR_LIGHT_GRAY, TERM_COLOR_BLACK);
	term_print("[glucOS]");
}