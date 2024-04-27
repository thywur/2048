#include "wkw.h"

static int	merge_check_right(int board[4][4])
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	i = 0;
	while (i < 4)
	{
		j = 3;
		while (j > 0)
		{
			if (board[i][j] != 0)
			{
				k = j - 1;
				while (k >= 0)
				{
					if (board[i][k] != 0)
					{
						if (board[i][j] == board[i][k])
							can_merge++;
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

static int	merge_check_left(int board[4][4])
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (board[i][j] != 0)
			{
				k = j + 1;
				while (k < 4)
				{
					if (board[i][k] != 0)
					{
						if (board[i][j] == board[i][k])
							can_merge++;
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


static int	merge_check_up(int board[4][4])
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			if (board[i][j] != 0)
			{
				k = i + 1;
				while (k < 4)
				{
					if (board[k][j] != 0)
					{
						if (board[i][j] == board[k][j])
							can_merge++;
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

static int	merge_check_down(int board[4][4])
{
	int	i;
	int	j;
	int	k;
	int	can_merge = 0;

	j = 0;
	while (j < 4)
	{
		i = 3;
		while (i > 0)
		{
			if (board[i][j] != 0)
			{
				k = i - 1;
				while (k >= 0)
				{
					if (board[k][j] != 0)
					{
						if (board[i][j] == board[k][j])
							can_merge++;
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

int	can_merge(int board[4][4])
{
	if (merge_check_up(board))
		return (1);
	if (merge_check_down(board))
		return (1);
	if (merge_check_left(board))
		return (1);
	if (merge_check_right(board))
		return (1);
	return (0);
}
