#include "alcu.h"

#ifdef NCURSES
/*
 ░▒▓██████▓▒░░▒▓█▓▒░      ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓████████▓▒░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓██████▓▒░ ░▒▓██████▓▒░  
*/
static void	print_title(void)
{
	const char *title[] = {		"01234444443211234321000000123444444321123432112343210",
								"12343211234321234321000001234321123432123432112343210", 
								"12343211234321234321000001234321000000123432112343210",
								"12344444444321234321000001234321000000123432112343210",
								"12343211234321234321000001234321000000123432112343210", 
								"12343211234321234321000001234321123432123432112343210",
								"12343211234321234444444432123444444321012344444432100"};
	const char *color_map[] = {	"RRRRWWWWWWBBBRRRWBBB      RRRWWWWWWBBBWRRWBBBRRRWBBB ",
								"RRRWBBBRRRWBBWRRWBBB     RRRWBBBRRRWBBWRRWBBBRRRWBBB ", 
								"RRRWBBBRRRWBBWRRWBBB     RRRWBBB      RRRWBBBRRRWBBB ",
								"RRRWWWWWWWWBBWRRWBBB     RRRWBBB      RRRWBBBRRRWBBB ",
								"RRRWBBBRRRWBBWRRWBBB     RRRWBBB      RRRWBBBRRRWBBB ", 
								"RRRWBBBRRRWBBWRRWBBB     RRRWBBBRRRWBBWRRWBBBRRRWBBB ",
								"RRRWBBBRRRWBBWRRWWWWWWWWBBWRRWWWWWWBBB RRRWWWWWWBBB  "};
	int center = COLS / 2;
	int line = LINES / 2;
	int width = 53;
	int	height = 7;
	const char *char_selector[] = {" ", "░", "▒", "▓", "█"};


	if (LINES < 10 || COLS < 55)
	{
		attron(COLOR_PAIR(5) | A_BOLD);
		mvprintw(line, center - 2, "Al");
		attroff(COLOR_PAIR(5) | A_BOLD);
		attron(COLOR_PAIR(8) | A_BOLD);
		mvprintw(line, center, "Cu");
		attroff(COLOR_PAIR(8) | A_BOLD);
		return ;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (color_map[i][j] == 'R')
				attron(COLOR_PAIR(5));
			else if (color_map[i][j] == 'B')
				attron(COLOR_PAIR(8));
			mvprintw(line - 3 + i, center - width / 2 + j, "%s", char_selector[title[i][j] - '0']);
			if (color_map[i][j] == 'R')
				attroff(COLOR_PAIR(5));
			else if (color_map[i][j] == 'B')
				attroff(COLOR_PAIR(8));
		}
	}
}

static int welcome_screen_ncurses()
{
	const char *anykey = "Press any key to start...";
    int center_x = COLS / 2;
	print_title();
	mvprintw(LINES - 2, center_x - ft_strlen(anykey) / 2, anykey);
	timeout(-1);
	int ch = getch();
	if (ch == 27 || ch == 'q' || ch == 'Q')
	{
		return END_OF_FILE;
	}
	timeout(1000);
	return EMPTY;
}
#endif

int welcome_screen(t_vector *v)
{
	#ifdef NCURSES
		(void)v;
        return (welcome_screen_ncurses());
    #else
        ft_putstr("The game starts\n\n");
        draw_map(v, 0, 0);
		return (EMPTY);
    #endif
}
