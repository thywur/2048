#include "wkw.h"

static void	ft_start_color(int num)
{
	if (num == 0)
		attron(COLOR_PAIR(1));
	else if (num == 2 || num == 4)
		attron(COLOR_PAIR(7));
	else if (num == 8 || num == 16)
		attron(COLOR_PAIR(4));
	else if (num == 32 || num == 64)
		attron(COLOR_PAIR(6));
	else if (num == 128 || num == 256)
		attron(COLOR_PAIR(8));
	else if (num == 512 || num == 1024)
		attron(COLOR_PAIR(5));
	else if (num == 2048 || num == 4096)
		attron(COLOR_PAIR(9));
	else
		attron(COLOR_PAIR(10));
}

static void	ft_end_color(int num)
{
	if (num == 0)
		attroff(COLOR_PAIR(1));
	else if (num == 2 || num == 4)
		attroff(COLOR_PAIR(7));
	else if (num == 8 || num == 16)
		attroff(COLOR_PAIR(4));
	else if (num == 32 || num == 64)
		attroff(COLOR_PAIR(6));
	else if (num == 128 || num == 256)
		attroff(COLOR_PAIR(8));
	else if (num == 512 || num == 1024)
		attroff(COLOR_PAIR(5));
	else if (num == 2048 || num == 4096)
		attroff(COLOR_PAIR(9));
	else
		attroff(COLOR_PAIR(10));
}

static void	draw_ascii(size_t board[], int size)
{
	int	i;
	int	j;
	int	k;
	int tmp;
	int	case_width = 42;
	int	case_height = 8;
    int center_x = COLS / 2 - (size * case_width) / 2;
	int	center_y = LINES / 2 - (size * case_height) / 2;

	k = 0;
	i = 0;
	(void)tmp;
	while (i <= size * case_height)
	{
		j = 0;
		while (j <= size * case_width)
		{

			if (i % case_height == 0)
			{
				if (j % case_width == 0)
				{
					if (i == 0)
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╔");
						else if (j == size * case_width)
							mvprintw(i + center_y, j + center_x, "╗");
						else
							mvprintw(i + center_y, j + center_x, "╦");
					}
					else if (i == size * case_height)
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╚");
						else if (j == size * case_width)
							mvprintw(i + center_y, j + center_x, "╝");
						else
							mvprintw(i + center_y, j + center_x, "╩");
					}
					else
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╠");
						else if (j == size * case_width)
							mvprintw(i + center_y, j + center_x, "╣");
						else
							mvprintw(i + center_y, j + center_x, "╬");
					}
				}
				else
					mvprintw(i + center_y, j + center_x, "═");
			}
			else
			{
				if (j % case_width == 0)
					mvprintw(i + center_y, j + center_x, "║");
				else
				{
					ft_start_color(board[i / case_height * size + (j - 7 + 6) / case_width]);
					mvprintw(i + center_y, j + center_x, " ");
					ft_end_color(board[i / case_height * size + (j - 7 + 6) / case_width]);
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i * size + j] != 0)
			{
				ft_start_color(board[i * size + j]);
				asc_print_num(i * case_height + 3 + center_y, (j + 1) * case_width + center_x - 18, board[i * size + j]);
				ft_end_color(board[i * size + j]);
			}
			j++;
		}
		i++;
	}
}

static void	draw_simple(size_t board[], int size)
{
	int	i;
	int	j;
	int	k;
	int tmp;
	int	case_width = 13;
	int	case_height = 6;
    int center_x = COLS / 2 - (size * case_width) / 2;
	int	center_y = LINES / 2 - (size * case_height) / 2;

	k = 0;
	i = 0;
	(void)tmp;
	while (i <= size * case_height)
	{
		j = 0;
		while (j <= size * case_width)
		{

			if (i % case_height == 0)
			{
				if (j % case_width == 0)
				{
					if (i == 0)
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╔");
						else if (j == size * case_width)
							mvprintw(i + center_y, j + center_x, "╗");
						else
							mvprintw(i + center_y, j + center_x, "╦");
					}
					else if (i == size * case_height)
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╚");
						else if (j == size * case_width)
							mvprintw(i + center_y, j + center_x, "╝");
						else
							mvprintw(i + center_y, j + center_x, "╩");
					}
					else
					{
						if (j == 0)
							mvprintw(i + center_y, j + center_x, "╠");
						else if (j == size * case_width)
							mvprintw(i + center_y, j + center_x, "╣");
						else
							mvprintw(i + center_y, j + center_x, "╬");
					}
				}
				else
					mvprintw(i + center_y, j + center_x, "═");
			}
			else
			{
				if (j % case_width == 0)
					mvprintw(i + center_y, j + center_x, "║");
				else
				{
					ft_start_color(board[i / case_height * size + (j - 7 + 6) / case_width]);
					mvprintw(i + center_y, j + center_x, " ");
					ft_end_color(board[i / case_height * size + (j - 7 + 6) / case_width]);
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i * size + j] != 0)
			{
				ft_start_color(board[i * size + j]);
				mvprintw(i * case_height + 3 + center_y, (j + 1) * case_width - 6 + center_x - ft_nblen(board[i * size + j]) / 2, "%zu", board[i * size + j]);
				ft_end_color(board[i * size + j]);
			}
			j++;
		}
		i++;
	}
}

void	draw_board(size_t board[], int size, int gamestate, int score, int high)
{
	const char *win = "YOU WON!";
	const char *loose = "YOU LOSE!";
	const char *controls[] = {"        [↑/↓/←/→] to move, [R] to return to menu, [ESC] to quit",
								"        [↑/↓/←/→] to move, [R] to return to menu, [Space] to save your score, [ESC] to quit",
								"        [R] to return to menu, [ESC] to quit",
								"        [R] to return to menu, [Space] to save your score, [ESC] to quit"};
	const char *highscore = "HIGHSCORE: ";
	const char *yourscore = "YOUR SCORE: ";
	int		center_x = COLS / 2;

	clear();
	if (LINES > size * 8 + 10 && COLS > size * 42 + 2 && biggest(board, size) <= 65536)
	{
		mvprintw(1, center_x - size * 42 / 2, "%s%d", highscore, high);
		mvprintw(1, center_x + size * 42 / 2 - ft_strlen(yourscore) - ft_nblen(score), "%s%d", yourscore, score);
		draw_ascii(board, size);
	}
	else
	{
		mvprintw(1, center_x - size * 13 / 2, "%s%d", highscore, high);
		mvprintw(1, center_x + size * 13 / 2 - ft_strlen(yourscore) - ft_nblen(score), "%s%d", yourscore, score);
		draw_simple(board, size);
	}

	if (gamestate == 2)
		mvprintw(1, center_x - ft_strlen(loose) / 2, "%s", loose);
	if (gamestate & 1)
		mvprintw(1, center_x - ft_strlen (win) / 2, "%s", win);
	if (gamestate == 0)
		mvprintw(LINES - 2, center_x - ft_strlen(controls[0]) / 2, "%s", controls[0]);
	else if (gamestate == 1)
		mvprintw(LINES - 2, center_x - ft_strlen(controls[1]) / 2, "%s", controls[1]);
	else if (gamestate == 2)
		mvprintw(LINES - 2, center_x - ft_strlen(controls[2]) / 2, "%s", controls[2]);
	else if (gamestate == 3)
		mvprintw(LINES - 2, center_x - ft_strlen(controls[3]) / 2, "%s", controls[3]);
	refresh();
}
