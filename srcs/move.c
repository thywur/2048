#include "wkw.h"

static int	merge_right(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
						{
							board[i][j] = board[i][j] * 2;
							board[i][k] = 0;
							(*filled)--;
							moves++;
						}
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

int	move_right(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	int moves = merge_right(board, filled);
	while (i < 4)
	{
		j = 3;
		while (j >= 0)
		{
			if (board[i][j] != 0)
			{
				k = j + 1;
				while (k < 4 && board[i][k] == 0)
					k++;
				board[i][k - 1] = board[i][j];
				if (k - 1 != j)
				{
					board[i][j] = 0;
					moves++;
				}
			}
			j--;
		}
		i++;
	}
	return (moves);
}

static int	merge_left(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
						{
							board[i][j] = board[i][j] * 2;
							board[i][k] = 0;
							(*filled)--;
							moves++;
						}
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

int	move_left(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	int moves = merge_left(board, filled);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (board[i][j] != 0)
			{
				k = j - 1;
				while (k >= 0 && board[i][k] == 0)
					k--;
				board[i][k + 1] = board[i][j];
				if (k + 1 != j)
				{
					board[i][j] = 0;
					moves++;
				}
			}
			j++;
		}
		i++;
	}
	return (moves);
}

static int	merge_up(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
						{
							board[i][j] = board[i][j] * 2;
							board[k][j] = 0;
							(*filled)--;
							moves++;
						}
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

int	move_up(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	int moves = merge_up(board, filled);
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (board[i][j] != 0)
			{
				k = i - 1;
				while (k >= 0 && board[k][j] == 0)
					k--;
				board[k + 1][j] = board[i][j];
				if (k + 1 != i)
				{
					board[i][j] = 0;
					moves++;
				}
			}
			i++;
		}
		j++;
	}
	return (moves);
}

static int	merge_down(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;
	int	moves = 0;

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
						{
							board[i][j] = board[i][j] * 2;
							board[k][j] = 0;
							(*filled)--;
							moves++;
						}
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

int	move_down(int board[4][4], int *filled)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	int moves = merge_down(board, filled);
	while (j < 4)
	{
		i = 3;
		while (i >= 0)
		{
			if (board[i][j] != 0)
			{
				k = i + 1;
				while (k < 4 && board[k][j] == 0)
					k++;
				board[k - 1][j] = board[i][j];
				if (k - 1 != i)
				{
					board[i][j] = 0;
					moves++;
				}
			}
			i--;
		}
		j++;
	}
	return (moves);
}
