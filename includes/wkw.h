#ifndef WKW_H
# define WKW_H

# include <ncurses.h>
# include <wchar.h>
# include <locale.h>
# include <stdlib.h>
# include <time.h>

# define WIDTH 800
# define HEIGHT 600

# define EMPTY 0
# define ERROR -1

# define MAX_SIZE 10
# define MIN_SIZE 4

enum e_const
{
	WIN_VALUE = 64,
};

int		init_ncurses(WINDOW *stdscr);

int		move_right(int board[], int size, int *filled);
int		move_left(int board[], int size, int *filled);
int		move_up(int board[], int size, int *filled);
int		move_down(int board[], int size, int *filled);
int		can_merge(int board[], int size);
void	generate_tile(int board[], int size);

int		is_win(int board[], int size);

void	game_loop(void);

void	error_screen(char *str);
int		welcome_screen();
int		menu_screen(int *size);
int		save_screen(int	score, char name[5]);
int		size_screen(int *size);
void	draw_board(int board[], int size, int gamestate);

void	asc_print_num(int y, int x, int num);

// utils
int		ft_strlen(const char *s);
int		ft_intlen(int n);
int		max(int a, int b);
int		min(int a, int b);

#endif
