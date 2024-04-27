#include "../includes/wkw.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

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

void	sort_tab(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

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
	FILE	*fd;
	int		*tab;
	size_t	i;
	size_t	size;
	char	line[50];

	fd = fopen("highscores.txt", "r");
	if (!fd)
		return ;
	size = 0;
	while (fgets(line, 50, fd))
		size++;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	fseek(fd, 0, SEEK_SET);
	i = 0;
	while (fgets(line, 50, fd))
		tab[i++] = atoi(line);
	fclose(fd);
	sort_tab(tab, size);
	fd = fopen("highscores.txt", "w+");
	if (!fd)
		return ;
	i = 0;
	while (i < size)
		fprintf(fd, "%d\n", tab[i++]);
	fclose(fd);
	free(tab);
}
