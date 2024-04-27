#ifndef ALCU_H
#define ALCU_H

#include <unistd.h>
#include <fcntl.h>
#include "ft_vector.h"

#ifdef NCURSES
#include <ncurses.h>
#include <wchar.h>
#include <locale.h>
#endif

#define CURRENT_STATE_MASK 0x00003FFF
#define INITIAL_STATE_MASK 0x0FFFC000
#define LAST_PLAYER_TAKE 0x30000000
#define LAST_PLAYER 0x40000000
#define SHOULD_LOOSE_FLAG 0x80000000

#define SET_LAST_PLAYER_FLAG(num, condition) num = ((num & ~LAST_PLAYER) | (LAST_PLAYER * condition))
#define SET_SHOULD_LOOSE_FLAG(num, condition) num |= (condition) << 31
#define SET_LAST_TAKE_COUNT(num, count) num = ((num & ~LAST_PLAYER_TAKE) | (count << 28))
#define SET_INI(num, ini) num |= N(ini) << 14
#define SHOULD_LOOSE(num) ((num) & SHOULD_LOOSE_FLAG)
#define N(num) ((num) & CURRENT_STATE_MASK)
#define INI(num) ((num) & INITIAL_STATE_MASK) >> 14
#define GET_LAST_TAKE(num) ((num) & LAST_PLAYER_TAKE) >> 28
#define GET_LAST_PLAYER(num) ((num) & LAST_PLAYER) >> 30

#define EMPTY 0
#define ERROR -1
#define END_OF_FILE -2

int ft_strlen(const char *s);
int ft_putstr_fd(char *s, int fd);
int ft_putstr(char *s);
int ft_putnbr_fd(long n, int fd);
int ft_putnbr(long n);
int ft_putendl_fd(char *s, int fd);
int ft_putendl(char *s);
int ft_putchar_fd(char c, int fd);
int ft_putchar(char c);
int min(int a, int b);
int max(int a, int b);

int atoi_from_read(int fd, int max);

int find_strategy(t_vector *v);
int bot_turn(t_vector *v, int count_on_line);
int player_turn(t_vector *v, int count_on_line);

#ifdef NCURSES
int init_ncurses(WINDOW *stdscr);
#endif
int game_loop(t_vector *v);

void draw_map(t_vector *v, int to_take, int to_take_color);
void end_screen(int winner);
int welcome_screen(t_vector *v);

#endif