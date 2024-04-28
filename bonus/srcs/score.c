#include "wkw.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int	save_score(size_t score, char *name, int size)
{
	int	fd;

	fd = open(SCORE_PATH, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (1);
	if (dprintf(fd, "%12zu%4s%2d\n", score, name, size))
		return (1);
	close(fd);
	return (0);
}

int	ft_compare(const void *a, const void *b)
{
	return (strcmp(*(char**)a, *(char**)b) * -1);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	sort_scores(char **scores)
{
	size_t	size;

	size = 0;
	while (scores[size])
		size++;
	qsort(scores, size, sizeof(char *), ft_compare);
}

char	**get_scores(void)
{
	FILE	*fd;
	char	**scores;
	size_t	i;
	size_t	size;
	char	line[100];

	fd = fopen(SCORE_PATH, "r");
	if (!fd)
		return (NULL);
	size = 0;
	while (fgets(line, 100, fd))
		size++;
	if (fseek(fd, 0, SEEK_SET) == -1)
		return (NULL);
	scores = malloc(sizeof(char *) * (size + 1));
	if (!scores)
		return (NULL);
	memset(scores, 0, sizeof(char *) * (size + 1));
	i = 0;
	while (fgets(line, 100, fd))
	{
		scores[i] = strdup(line);
		if (!scores[i++])
		{
			free_tab(scores);
			return (NULL);
		}
	}
	scores[i] = NULL;
	fclose(fd);
	return (scores);
}

int	get_highscore(int size)
{
	FILE	*fd;
	char	**scores;
	size_t	i;
	size_t		highscore;
	size_t	tmp;
	int		tmp_size;

	fd = fopen(SCORE_PATH, "r");
	if (!fd)
		return (0);
	scores = get_scores();
	if (!scores)
		return (0);
	highscore = 0;
	i = 0;
	while (scores[i])
	{
		if (sscanf(scores[i], "%zu%*s%d", &tmp, &tmp_size) == 2 && tmp_size == size && tmp > highscore)
			highscore = tmp;
		i++;
	}
	free_tab(scores);
	return (highscore);
}
