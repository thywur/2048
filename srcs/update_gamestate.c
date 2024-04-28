#include "wkw.h"

int	update_gamestate(size_t board[], int size, int filled)
{
	int	i;
	int	j;

	i = 0;
	if (biggest(board, size) >= 8589934592)
		return (1);
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
	if (filled == size * size && !can_merge(board, size))
			return (2);
	return (0);
}
