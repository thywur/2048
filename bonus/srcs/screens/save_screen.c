#include "wkw.h"

static void	print_title(void)
{
	const char *title[] = {		"123444444432112344444444321234321123432112344444432100",
								"000000012343212343211234321234321123432123432112343210",
								"000000012343212343211234321234321123432123432112343210",
								"012344444432112343211234321234444444432112344444432100",
								"123432100000012343211234321000000123432123432112343210",
								"123432100000012343211234321000000123432123432112343210",
								"123444444443212344444444321000000123432112344444432100"};
	const char *color_map[] = {	"RRRWWWWWWWBBBRRRWWWWWWWWBBWRRWBBBRRRWBBBRRRWWWWWWBBB  ",
								"       RRRWBBWRRWBBBRRRWBBWRRWBBBRRRWBBWRRWBBBRRRWBBB ",
								"       RRRWBBWRRWBBBRRRWBBWRRWBBBRRRWBBWRRWBBBRRRWBBB ",
								" RRRWWWWWWBBBRRRWBBBRRRWBBWRRWWWWWWWWBBBRRRWWWWWWBBB  ",
								"RRRWBBB      RRRWBBBRRRWBBB      RRRWBBWRRWBBBRRRWBBB ",
								"RRRWBBB      RRRWBBBRRRWBBB      RRRWBBWRRWBBBRRRWBBB ",
								"RRRWWWWWWWWBBWRRWWWWWWWWBBB      RRRWBBBRRRWWWWWWBBB  "};
	int center = COLS / 2;
	int line = LINES / 2;
	int width = 53;
	int	height = 7;
	const char *char_selector[] = {" ", "░", "▒", "▓", "█"};


	if (LINES < 15 || COLS < 55)
	{
		attron(A_BOLD);
		mvprintw(line - 1, center - 2, "2048");
		attroff(A_BOLD);
		return ;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (color_map[i][j] == 'R')
				attron(COLOR_PAIR(2));
			else if (color_map[i][j] == 'B')
				attron(COLOR_PAIR(3));
			mvprintw(line - 3 + i - 4, center - width / 2 + j, "%s", char_selector[title[i][j] - '0']);
			if (color_map[i][j] == 'R')
				attroff(COLOR_PAIR(2));
			else if (color_map[i][j] == 'B')
				attroff(COLOR_PAIR(3));
		}
	}
}

int save_screen(size_t score, char name[5], int size)
{
	const char	*controls = {"       [↑/↓] to scroll trough letters, [←/→] to move cursor, [⏎] to confirm, [ESC] to quit"};
	const char	letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int			selected = 0;
	int			value[4] = {0};

	(void)score;
	while (1)
	{
		int center_x = COLS / 2;
		int center_y = LINES / 2;

		clear();
		print_title();
		mvprintw(center_y + 1, center_x - ft_strlen(controls) / 2, "%s", controls);
		attron(A_BOLD);
		mvprintw(center_y + 3, center_x - ft_nblen(score), "%zu", score);
		mvprintw(center_y + 5, center_x - 4 + selected * 2, "⮝");
		if (selected == 0)
			attron(A_BLINK);
		mvprintw(center_y + 6, center_x - 4, "%c", letters[value[0]]);
		if (selected == 0)
			attroff(A_BLINK);
		if (selected == 1)
			attron(A_BLINK);
		mvprintw(center_y + 6, center_x - 2, "%c", letters[value[1]]);
		if (selected == 1)
			attroff(A_BLINK);
		if (selected == 2)
			attron(A_BLINK);
		mvprintw(center_y + 6, center_x, "%c", letters[value[2]]);
		if (selected == 2)
			attroff(A_BLINK);
		if (selected == 3)
			attron(A_BLINK);
		mvprintw(center_y + 6, center_x + 2, "%c", letters[value[3]]);
		if (selected == 3)
			attroff(A_BLINK);
		attroff(A_BLINK);
		mvprintw(center_y + 7, center_x - 4 + selected * 2, "⮟");
		attroff(A_BOLD);
		refresh();

		int ch = getch();
		if (ch == 27)
		{
			return 1;
		}
		else if (ch == KEY_UP)
		{
			value[selected] = (value[selected] + 1) % 26;
		}
		else if (ch == KEY_DOWN)
		{
			value[selected] = (value[selected] - 1) == -1 ? 25 : value[selected] - 1;
		}
		else if (ch == KEY_LEFT)
		{
			selected = max(selected - 1, 0);
		}
		else if (ch == KEY_RIGHT)
		{
			selected = min(selected + 1, 3);
		}
		else if (ch == KEY_ENTER || ch == 10)
		{
			name[0] = letters[value[0]];
			name[1] = letters[value[1]];
			name[2] = letters[value[2]];
			name[3] = letters[value[3]];
			save_score(score, name, size);
			return 0;
		}
	}
	return 0;
}
