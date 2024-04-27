#include "wkw.h"

# include <unistd.h>

int	main(void)
{
	WINDOW *win = NULL;

	if (init_ncurses(win))
	{
		return (1);
	}
	usleep(5000000);
	endwin();
	return (0);
}
