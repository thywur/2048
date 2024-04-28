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

int	menu_screen(int *size)
{
	const char *controls = {"       [↑/↓] to navigate, [→] or [⏎] to confirm, [ESC] to quit"};
	const char *play[2] = {"PLAY", "   ► PLAY ◄"};
	const char *size_selector[2] = {"GRID SIZE", "    ► GRID SIZE ◄"};
	const char *scores[2] = {"SCORES", "   ► SCORES ◄"};
	int	selected = 0;

	while (1)
	{
		int center_x = COLS / 2;
		int center_y = LINES / 2;

		clear();
		print_title();
		mvprintw(center_y + 1, center_x - ft_strlen(controls) / 2, "%s", controls);
		attron(A_BOLD);
		mvprintw(center_y + 3, center_x - ft_strlen(play[selected == 0]) / 2, "%s", play[selected == 0]);
		mvprintw(center_y + 4, center_x - ft_strlen(size_selector[selected == 1]) / 2, "%s", size_selector[selected == 1]);
		mvprintw(center_y + 5, center_x - ft_strlen(scores[selected == 2]) / 2, "%s", scores[selected == 2]);
		attroff(A_BOLD);
		refresh();

		int ch = getch();
		if (ch == 27)
		{
			return 1;
		}
		else if (ch == KEY_UP)
		{
			selected = max(selected - 1, 0);
		}
		else if (ch == KEY_DOWN)
		{
			selected = min(selected + 1, 2);
		}
		else if (ch == KEY_ENTER || ch == KEY_RIGHT || ch == 10)
		{
			if (selected == 0)
			{
				return 0;
			}
			else if (selected == 1)
			{
				if (size_screen(size))
					return 1;
			}
			else if (selected == 2)
			{
				if (scores_screen())
					return 1;
			}
		}
	}
	return 0;
}
