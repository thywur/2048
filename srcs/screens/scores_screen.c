#include "wkw.h"

static void	print_scores_of_size(char **scores, int size, int x)
{
	int center_x = COLS / 2;
	int i = 0;
	int	offset = 0;

	while (scores[i] && i < 20)
	{
		if (atoi(scores[i] + 14) == size)
		{
			mvprintw(3 + offset, center_x + x - ft_nblen(atoi(scores[i])) / 2, "%d", atoi(scores[i]));
			offset++;
		}
		i++;
	}
}

int	scores_screen(void)
{
	const char *controls = {"[R] to return to menu, [ESC] to quit"};
	char	**scores;

	scores = get_scores();
	if (!scores)
		return 0;
	sort_scores(scores);
	while (1)
	{
		int center_x = COLS / 2;

		clear();
		attron(A_BOLD);
		mvprintw(1, center_x - (COLS / 4), "4");
		mvprintw(1, center_x, "5");
		mvprintw(1, center_x + (COLS / 4), "6");
		attroff(A_BOLD);

		print_scores_of_size(scores, 4, - (COLS / 4));
		print_scores_of_size(scores, 5, 0);
		print_scores_of_size(scores, 6, (COLS / 4));

		mvprintw(LINES - 2, center_x - ft_strlen(controls) / 2, "%s", controls);

		refresh();

		int ch = getch();
		if (ch == 27)
		{
			free_tab(scores);
			return 1;
		}
		else if (ch == 'r' || ch == 'R')
		{
			free_tab(scores);
			return 0;
		}
	}
	free_tab(scores);
	return 0;
}
