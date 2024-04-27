#include "alcu.h"

#ifdef NCURSES

static void	print_player_win(void)
{
	const char *player[5] = {"██████  ██       █████  ██    ██ ███████ ██████      ██     ██ ██ ███    ██ ███████ ██ ██ ██", 
							"██   ██ ██      ██   ██  ██  ██  ██      ██   ██     ██     ██ ██ ████   ██ ██      ██ ██ ██", 
							"██████  ██      ███████   ████   █████   ██████      ██  █  ██ ██ ██ ██  ██ ███████ ██ ██ ██", 
							"██      ██      ██   ██    ██    ██      ██   ██     ██ ███ ██ ██ ██  ██ ██      ██         ", 
							"██      ███████ ██   ██    ██    ███████ ██   ██      ███ ███  ██ ██   ████ ███████ ██ ██ ██"};
	int center = COLS / 2;
	int line = LINES / 2;
	int width = 92;
	int	height = 5;

	if (LINES < 10 || COLS < 94)
		mvprintw(line, center - 7, "PLAYER WINS!!!");
	else
		for (int i = 0; i < height; i++)
			mvprintw(line - 3 + i, center - width / 2, "%-*s", width, player[i]);
}

static void	print_bot_win(void)
{
	const char *bot[5] = {	"██████   ██████  ████████     ██     ██ ██ ███    ██ ███████ ██ ██ ██", 
							"██   ██ ██    ██    ██        ██     ██ ██ ████   ██ ██      ██ ██ ██", 
							"██████  ██    ██    ██        ██  █  ██ ██ ██ ██  ██ ███████ ██ ██ ██", 
							"██   ██ ██    ██    ██        ██ ███ ██ ██ ██  ██ ██      ██         ", 
							"██████   ██████     ██         ███ ███  ██ ██   ████ ███████ ██ ██ ██"};
	int center = COLS / 2;
	int line = LINES / 2;
	int width = 69;
	int	height = 5;

	if (LINES < 10 || COLS < 71)
		mvprintw(line, center - 5, "BOT WINS!!!");
	else
		for (int i = 0; i < height; i++)
			mvprintw(line - 3 + i, center - width / 2, "%-*s", width, bot[i]);
}

void end_screen_ncurses(int winner)
{
	int center = COLS / 2;
	const char *anykey = "Press any key to exit...";

	clear();
	attron(COLOR_PAIR(5 + winner) | A_BOLD);
	if (winner)
		print_player_win();
	else
		print_bot_win();
	attroff(COLOR_PAIR(5 + winner) | A_BOLD);
	mvprintw(LINES - 2, center - ft_strlen(anykey) / 2, anykey);
	refresh();
	timeout(-1);
	getch();
}
#else
	void end_screen_term(int winner)
	{
		if (winner)
			ft_putendl("Player wins");
		else
			ft_putendl("AI wins");
	}
#endif

void end_screen(int winner)
{
	#ifdef NCURSES
		end_screen_ncurses(winner);
	#else
		end_screen_term(winner);
	#endif
}
