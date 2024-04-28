#include "wkw.h"

void	error_screen(char *str)
{
	clear();
	mvprintw(LINES / 2, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	refresh();
}
