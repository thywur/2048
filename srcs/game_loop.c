#include "wkw.h"

void	print_board(int board[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			printf("%d ", board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	draw_map(int board[SIZE][SIZE], int filled)
{
	int	i;
	int	j;
	int	k;
	int tmp;
    int center_x = COLS / 2 - (SIZE * 8) / 2;
	int	center_y = LINES / 2 - (SIZE * 4) / 2;

	(void)board;
	clear();
	print_board(board);
	k = 0;
	i = 0;
	while (i <= SIZE * SIZE)
	{
		j = 0;
		while (j <= SIZE * 8)
		{
			if (i % 4 == 0)
			{
				if (j % 8 == 0)
				{
					if (i == 0)
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╔");
						else if (j == SIZE * 8)
							mvprintw(i + center_y, j + center_x, "╗");
						else
							mvprintw(i + center_y, j + center_x, "╦");
					}
					else if (i == SIZE * SIZE)
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╚");
						else if (j == SIZE * 8)
							mvprintw(i + center_y, j + center_x, "╝");
						else
							mvprintw(i + center_y, j + center_x, "╩");
					}
					else
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╠");
						else if (j == SIZE * 8)
							mvprintw(i + center_y, j + center_x, "╣");
						else
							mvprintw(i + center_y, j + center_x, "╬");
					}
				}
				else
					mvprintw(i + center_y, j + center_x, "═");
			}
			else
				if (j % 8 == 0)
					mvprintw(i + center_y, j + center_x, "║");
			if ((i + 2) % 4 == 0 && (j + 6) % 8 == 0)
			{
				tmp = board[k / SIZE][k % SIZE];
				if (tmp != 0)
					mvprintw(i + center_y, j + center_x, "%5d", tmp);
				k++;
			}
			j++;
		}
		i++;
	}
	mvprintw(0, center_x, "%d", filled);
	refresh();
}

void	game_loop(void)
{
	int		board[SIZE][SIZE] = {0};
	int		x;
	int		y;
	int		filled;
	int		player_input;

	(void)player_input;
	if (welcome_screen())
		return ;
	srand(time(NULL));
	filled = 0;
	while (filled < 2)
	{
		x = rand() % SIZE;
		y = rand() % SIZE;
		if (board[x][y] == 0)
		{
			if (rand() % 10 < 9)
				board[x][y] = 2;
			else
				board[x][y] = 4;
			filled++;
		}
	}
	draw_map(board, filled);
	while (1)
	{
		int ch = getch();
		if (ch == 27 || ch == 'q' || ch == 'Q')
			break ;
		else if (ch == KEY_UP)
			move_up(board, &filled);
		else if (ch == KEY_DOWN)
			move_down(board, &filled);
		else if (ch == KEY_LEFT)
			move_left(board, &filled);
		else if (ch == KEY_RIGHT)
			move_right(board, &filled);
		else
			continue ;
		if (filled == SIZE * SIZE)
			return ;
		generate_tile(board);
		filled++;
		if (is_win(board))
			return ;
		draw_map(board, filled);
	}
}

// ╔═══════╦═══════╦═══════╦═══════╗
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ╠═══════╬═══════╬═══════╬═══════╣
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ╠═══════╬═══════╬═══════╬═══════╣
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ╠═══════╬═══════╬═══════╬═══════╣
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ║       ║       ║	   ║       ║
// ╚═══════╩═══════╩═══════╩═══════╝

