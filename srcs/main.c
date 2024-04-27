#include "wkw.h"

#include <stdlib.h>
#include <time.h>

# include <unistd.h>

int	main(void)
{
	WINDOW *win = NULL;

	if (SIZE < 4 || SIZE > 5)
		return (1);

	if (init_ncurses(win))
	{
		return (1);
	}

	game_loop();

	endwin();
	return (0);
}
