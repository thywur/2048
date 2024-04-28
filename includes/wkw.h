#ifndef WKW_H
# define WKW_H

# include <ncurses.h>
# include <wchar.h>
# include <locale.h>
# include <stdlib.h>
# include <time.h>
# include <sys/types.h>

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

int		move_right(size_t board[], int size, int *filled, size_t *score);
int		move_left(size_t board[], int size, int *filled, size_t *score);
int		move_up(size_t board[], int size, int *filled, size_t *score);
int		move_down(size_t board[], int size, int *filled, size_t *score);
int		can_merge(size_t board[], int size);
void	generate_tile(size_t board[], int size);

int		update_gamestate(size_t board[], int size, int filled);
size_t	biggest(size_t board[], int size);

void	game_loop(void);

void	error_screen(char *str);
int		welcome_screen();
int		menu_screen(int *size);
int		save_screen(size_t score, char name[5], int size);
int		size_screen(int *size);
int		scores_screen();

void	draw_board(size_t board[], int size, int gamestate, int score, int high);

void	asc_print_num(int y, int x, int num);
int		save_score(size_t score, char *name, int size);
int		get_highscore(int size);
// int		sort_scores();
void	sort_scores(char **scores);
char	**get_scores(void);
void	free_tab(char **tab);

int		ft_compare(const void *a, const void *b);

// utils
int		ft_strlen(const char *s);
int		ft_nblen(size_t n);
int		max(int a, int b);
int		min(int a, int b);

#endif
