#include "wkw.h"

#include <stdlib.h>
#include <time.h>

# include <unistd.h>

int	is_power_of_two(int n)
{
	return (n > 1 && (n & (n - 1)) == 0);
}

int	main(void)
{
	WINDOW *win = NULL;

	if (!is_power_of_two(WIN_VALUE))
	{
		return (1);
	}

	if (init_ncurses(win))
	{
		return (1);
	}

	game_loop();

	delwin(win);
	endwin();
	return (0);
}
