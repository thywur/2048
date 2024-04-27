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

int		init_ncurses(WINDOW *stdscr);

void	move_right(int board[4][4], int *filled);
void	move_left(int board[4][4], int *filled);
void	move_up(int board[4][4], int *filled);
void	move_down(int board[4][4], int *filled);

void	generate_tile(int board[4][4]);

int		is_win(int board[SIZE][SIZE]);

void	game_loop(void);

int		welcome_screen();

// utils
int		ft_strlen(const char *s);

#endif
