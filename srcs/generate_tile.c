#include "wkw.h"

void	generate_tile(int board[], int size)
{
	int	x;
	int	y;

	x = rand() % size;
	y = rand() % size;
	while (board[x * size + y] != 0)
	{
		x = rand() % size;
		y = rand() % size;
	}
	if (rand() % 10 < 9)
		board[x * size + y] = 2;
	else
		board[x * size + y] = 4;
}
