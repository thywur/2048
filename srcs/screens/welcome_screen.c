#include "wkw.h"

/*
░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  
       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
 ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░░▒▓██████▓▒░  
░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓████████▓▒░▒▓████████▓▒░      ░▒▓█▓▒░░▒▓██████▓▒░  
*/

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


	if (LINES < 10 || COLS < 55)
	{
		attron(A_BOLD);
		mvprintw(line, center - 2, "2048");
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
			mvprintw(line - 3 + i, center - width / 2 + j, "%s", char_selector[title[i][j] - '0']);
			if (color_map[i][j] == 'R')
				attroff(COLOR_PAIR(2));
			else if (color_map[i][j] == 'B')
				attroff(COLOR_PAIR(3));
		}
	}
}

int welcome_screen()
{
	const char	*anykey = "Press any key to start...";
    int			center_x = COLS / 2;

	clear();
	print_title();
	mvprintw(LINES - 2, center_x - ft_strlen(anykey) / 2, "%s", anykey);
	timeout(-1);
	int ch = getch();
	if (ch == 27)
	{
		return ERROR;
	}
	timeout(1000);
	refresh();
	return EMPTY;
}
