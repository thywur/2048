#include "../includes/wkw.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	count_score(int board[SIZE][SIZE])
{
	int	i;
	int	j;
	int	score;

	i = 0;
	score = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			score += board[i][j];
			j++;
		}
		i++;
	}
	return (score);
}

void	write_score(int score)
{
	int	fd;

	fd = open("highscores.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return ;
	dprintf(fd, "%d\n", score);
	close(fd);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size && i + 1 < size)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_scores(void)
{
	int		fd;
	int		*tab;
	int		i;
	int		j;
	int		tmp;
	int		size;

	fd = open("highscores.txt", O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return ;
	size = 0;
	while (read(fd, &tmp, sizeof(int)))
		size++;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	lseek(fd, 0, SEEK_SET);
	i = 0;
	while (read(fd, &tab[i], sizeof(int)))
		i++;
	close(fd);
	sort_tab(tab, size);
	fd = open("highscores.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	i = 0;
	while (i < size)
		dprintf(fd, "%d\n", tab[i++]);
	close(fd);
	free(tab);
}
