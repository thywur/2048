#include "wkw.h"

void	generate_tile(int board[4][4])
{
	int	x;
	int	y;

	x = rand() % 4;
	y = rand() % 4;
	while (board[x][y] != 0)
	{
		x = rand() % 4;
		y = rand() % 4;
	}
	if (rand() % 10 < 9)
		board[x][y] = 2;
	else
		board[x][y] = 4;
}
