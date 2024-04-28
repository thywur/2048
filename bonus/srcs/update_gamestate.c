#include "wkw.h"

int	update_gamestate(size_t board[], int size, int filled)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	if (biggest(board, size) >= 8589934592)
		tmp |= 3;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i * size + j] >= WIN_VALUE)
				tmp |= 1;
			j++;
		}
		i++;
	}
	if (filled == size * size && !can_merge(board, size))
			tmp |= 2;
	return (tmp);
}
