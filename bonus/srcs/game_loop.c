#include "wkw.h"

static void	init_board(size_t board[], int size)
{
	int		i;
	int		j;
	int		filled = 0;

	i = 0;
	while (i < size * size)
	{
		board[i] = 0;
		i++;
	}
	while (filled < 2)
	{
		i = rand() % size;
		j = rand() % size;
		if (board[i * size + j] == 0)
		{
			if (rand() % 10 < 9)
				board[i * size + j] = 2;
			else
				board[i * size + j] = 4;
			filled++;
		}
	}
}

int	party_loop(int size, size_t *score, int highscore)
{
	int		filled = 0;
	int		has_moved = 0;
	size_t	board[size * size];
	int		gamestate = 0;

	for (int i = 0; i < size * size; i++)
			board[i] = 0;

	srand(time(NULL));
	filled = 2;
	init_board(&(board[0]), size);
	if (LINES > size * 2 + 6 && COLS > size * 15 + 2)
		draw_board(&(board[0]), size, 0, *score, highscore);
	else
		error_screen("Terminal too small");
	while (gamestate < 2)
	{
		int ch = getch();
		if (ch == 27)
			return (1) ;
		else if (ch == ' ' && gamestate & 1)
			return (2);
		else if (ch == 'r' || ch == 'R')
			return (0);
		else if (ch == KEY_UP)
			has_moved = move_up(board, size, &filled, score);
		else if (ch == KEY_DOWN)
			has_moved =move_down(board, size, &filled, score);
		else if (ch == KEY_LEFT)
			has_moved = move_left(board, size, &filled, score);
		else if (ch == KEY_RIGHT)
			has_moved = move_right(board, size, &filled, score);
		else
		{
			if (LINES > size * 6 + 6 && COLS > size * 15 + 2)
				draw_board(&(board[0]), size, gamestate, *score, highscore);
			else
				error_screen("Terminal too small");
			continue ;
		}
		if (has_moved && filled < size * size)
		{
			generate_tile(board, size);
			filled++;
		}
		gamestate |= update_gamestate(board, size, filled);
		if (LINES > size * 6 + 6 && COLS > size * 15 + 2)
			draw_board(&(board[0]), size, gamestate, *score, highscore);
		else
			error_screen("Terminal too small");
	}
	while (1)
	{
		if (LINES > size * 6 + 6 && COLS > size * 15 + 2)
			draw_board(&(board[0]), size, gamestate, *score, highscore);
		else
			error_screen("Terminal too small");
		int ch = getch();
		if (ch == 27)
			return (1) ;
		else if (ch == 'r' || ch == 'R')
			return (0);
		else if (ch == ' ' && gamestate & 1)
			return (2);
	}
	return (0);
}

void	game_loop(void)
{
	int		size = MIN_SIZE;
	int		ret;
	size_t	score = 0;
	size_t	highscore = 0;
	char	name[5] = "AAAA";

	if (welcome_screen())
		return ;
	while (1)
	{
		if (menu_screen(&size))
			return ;
		name[0] = 'A';
		name[1] = 'A';
		name[2] = 'A';
		name[3] = 'A';
		score = 0;
		highscore = get_highscore(size);
		ret = party_loop(size, &score, highscore);
		if (ret == 1)
			return ;
		else if (ret == 2)
		{
			if (save_screen(score, name, size))
				return ;
		}
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

