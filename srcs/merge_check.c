#include "wkw.h"

static int	merge_check_right(size_t board[], int size)
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (j > 0)
		{
			if (board[i * size + j] != 0)
			{
				k = j - 1;
				while (k >= 0)
				{
					if (board[i * size + k] != 0)
					{
						if (board[i * size + j] == board[i * size + k])
							can_merge++;
						break;
					}
					k--;
				}
			}
			j--;
		}
		i++;
	}
	return (can_merge);
}

static int	merge_check_left(size_t board[], int size)
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (board[i * size + j] != 0)
			{
				k = j + 1;
				while (k < size)
				{
					if (board[i * size + k] != 0)
					{
						if (board[i * size + j] == board[i * size + k])
							can_merge++;
						break;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return (can_merge);
}


static int	merge_check_up(size_t board[], int size)
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (board[i * size + j] != 0)
			{
				k = i + 1;
				while (k < size)
				{
					if (board[k * size + j] != 0)
					{
						if (board[i * size + j] == board[k * size + j])
							can_merge++;
						break;
					}
					k++;
				}
			}
			i++;
		}
		j++;
	}
	return (can_merge);
}

static int	merge_check_down(size_t board[], int size)
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	j = 0;
	while (j < size)
	{
		i = size - 1;
		while (i > 0)
		{
			if (board[i * size + j] != 0)
			{
				k = i - 1;
				while (k >= 0)
				{
					if (board[k * size + j] != 0)
					{
						if (board[i * size + j] == board[k * size + j])
							can_merge++;
						break;
					}
					k--;
				}
			}
			i--;
		}
		j++;
	}
	return (can_merge);
}

int	can_merge(size_t board[], int size)
{
	if (merge_check_up(board, size))
		return (1);
	if (merge_check_down(board, size))
		return (1);
	if (merge_check_left(board, size))
		return (1);
	if (merge_check_right(board, size))
		return (1);
	return (0);
}
