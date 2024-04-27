#include "wkw.h"

#include <stdlib.h>
#include <time.h>

# include <unistd.h>

void	print_board(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d ", board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(void)
{
	// WINDOW *win = NULL;

	// if (init_ncurses(win))
	// {
	// 	return (1);
	// }
	// usleep(5000000);
	// endwin();
	int	x;
	int	y;
	int filled;

	int	board[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	srand(time(NULL));

	filled = 0;
	while (filled < 2)
	{
		x = rand() % 4;
		y = rand() % 4;
		if (board[x][y] == 0)
		{
			if (rand() % 10 < 9)
				board[x][y] = 2;
			else
				board[x][y] = 4;
			filled++;
		}
	}

	print_board(board);
	return (0);
}
