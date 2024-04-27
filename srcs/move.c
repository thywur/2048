#include "wkw.h"

static int	merge_right(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
						{
							board[i * size + j] = board[i * size + j] * 2;
							board[i * size + k] = 0;
							(*filled)--;
							moves++;
						}
						break;
					}
					k--;
				}
			}
			j--;
		}
		i++;
	}
	return (moves);
}

int	move_right(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	int moves = merge_right(board, size, filled);
	while (i < size)
	{
		j = size - 1;
		while (j >= 0)
		{
			if (board[i * size + j] != 0)
			{
				k = j + 1;
				while (k < size && board[i * size + k] == 0)
					k++;
				board[i * size + k - 1] = board[i * size + j];
				if (k - 1 != j)
				{
					board[i * size + j] = 0;
					moves++;
				}
			}
			j--;
		}
		i++;
	}
	return (moves);
}

static int	merge_left(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
						{
							board[i * size + j] = board[i * size + j] * 2;
							board[i * size + k] = 0;
							(*filled)--;
							moves++;
						}
						break;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return (moves);
}

int	move_left(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	int moves = merge_left(board, size, filled);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i * size + j] != 0)
			{
				k = j - 1;
				while (k >= 0 && board[i * size + k] == 0)
					k--;
				board[i * size + k + 1] = board[i * size + j];
				if (k + 1 != j)
				{
					board[i * size + j] = 0;
					moves++;
				}
			}
			j++;
		}
		i++;
	}
	return (moves);
}

static int	merge_up(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
					if (board[k* size + j] != 0)
					{
						if (board[i * size + j] == board[k * size + j])
						{
							board[i * size + j] = board[i * size + j] * 2;
							board[k * size + j] = 0;
							(*filled)--;
							moves++;
						}
						break;
					}
					k++;
				}
			}
			i++;
		}
		j++;
	}
	return (moves);
}

int	move_up(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	int moves = merge_up(board, size, filled);
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (board[i * size + j] != 0)
			{
				k = i - 1;
				while (k >= 0 && board[k * size + j] == 0)
					k--;
				board[(k + 1) * size + j] = board[i * size + j];
				if (k + 1 != i)
				{
					board[i * size + j] = 0;
					moves++;
				}
			}
			i++;
		}
		j++;
	}
	return (moves);
}

static int	merge_down(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
						{
							board[i * size + j] = board[i * size + j] * 2;
							board[k * size + j] = 0;
							(*filled)--;
							moves++;
						}
						break;
					}
					k--;
				}
			}
			i--;
		}
		j++;
	}
	return (moves);
}

int	move_down(int board[], int size, int *filled)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	int moves = merge_down(board, size, filled);
	while (j < size)
	{
		i = size - 1;
		while (i >= 0)
		{
			if (board[i * size + j] != 0)
			{
				k = i + 1;
				while (k < size && board[k * size + j] == 0)
					k++;
				board[(k - 1) * size + j] = board[i * size + j];
				if (k - 1 != i)
				{
					board[i * size + j] = 0;
					moves++;
				}
			}
			i--;
		}
		j++;
	}
	return (moves);
}
