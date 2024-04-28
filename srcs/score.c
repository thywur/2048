#include "wkw.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int	save_score(int score, char *name, int size)
{
	int	fd;

	fd = open("highscores.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (1);
	if (dprintf(fd, "%10d%4s%2d\n", score, name, size))
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

	fd = fopen("highscores.txt", "r");
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
	int		highscore;
	int		tmp;
	int		tmp_size;

	fd = fopen("highscores.txt", "r");
	if (!fd)
		return (0);
	scores = get_scores();
	if (!scores)
		return (0);
	highscore = 0;
	i = 0;
	while (scores[i])
	{
		if (sscanf(scores[i], "%d%*s%d", &tmp, &tmp_size) == 2 && tmp_size == size && tmp > highscore)
			highscore = tmp;
		i++;
	}
	free_tab(scores);
	return (highscore);
}

// int	main()
// {
// 	int i;

// 	i = 0;
// 	srand(time(NULL));
// 	while (i < 10)
// 	{
// 		write_score(rand() % 10000000);
// 		i++;
// 	}
// 	// FILE *fd = fopen("highscores.txt", "r");
// 	// char line[50];
// 	// fgets(line, 50, fd);
// 	// printf("%s\n", line);
// 	// printf("%s\n", fgets(line, 50, fd));
// 	// fclose(fd);
// 	sort_scores();
// }
