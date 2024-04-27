#ifndef WKW_H
# define WKW_H

#include <ncurses.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

#define EMPTY 0
#define ERROR -1

# ifndef SIZE
#  define SIZE 4
# endif

enum e_const
{
	WIN_VALUE = 64,
};

int		init_ncurses(WINDOW *stdscr);

int	move_right(int board[4][4], int *filled);
int	move_left(int board[4][4], int *filled);
int	move_up(int board[4][4], int *filled);
int	move_down(int board[4][4], int *filled);
int	can_merge(int board[4][4]);
void	generate_tile(int board[4][4]);

int		is_win(int board[SIZE][SIZE]);

void	game_loop(void);

int		welcome_screen();

// utils
int		ft_strlen(const char *s);

#endif
