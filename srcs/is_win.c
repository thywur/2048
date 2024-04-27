#include "wkw.h"

int	is_win(int board[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (board[i][j] >= WIN_VALUE)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
