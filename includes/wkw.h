#ifndef WKW_H
# define WKW_H

#include <ncurses.h>
#include <wchar.h>
#include <locale.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct env_4
{
	int filled;
	int board[4][4];
	int size;
}	t_env_4;

typedef struct env_5
{
	int filled;
	int board[5][5];
	int size;
}	t_env_5;



int init_ncurses(WINDOW *stdscr);

#endif
