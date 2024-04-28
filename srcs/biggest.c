#include "wkw.h"

size_t	biggest(size_t board[], int size)
{
	int	i;
	int	j;
	size_t	biggest;

	biggest = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i * size + j] > biggest)
				biggest = board[i * size + j];
			j++;
		}
		i++;
	}
	return (biggest);
}
