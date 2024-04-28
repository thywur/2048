#include "wkw.h"

int	is_win(size_t board[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i * size + j] >= WIN_VALUE)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
