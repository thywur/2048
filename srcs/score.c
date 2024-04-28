#include "../includes/wkw.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

# define SIZE 4

// int	count_score(int board[SIZE][SIZE])
// {
// 	int	i;
// 	int	j;
// 	int	score;

// 	i = 0;
// 	score = 0;
// 	while (i < SIZE)
// 	{
// 		j = 0;
// 		while (j < SIZE)
// 		{
// 			score += board[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (score);
// }

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

// void	sort_tab(char **tab, size_t size)
// {
// 	size_t	i;
// 	int		tmp;

// 	i = 0;
// 	while (i < size && i + 1 < size)
// 	{
// 		if (tab[i] < tab[i + 1])
// 		{
// 			tmp = tab[i];
// 			tab[i] = tab[i + 1];
// 			tab[i + 1] = tmp;
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// }

// void	sort_scores(void)
// {
// 	int		fd;
// 	int		*tab;
// 	size_t	i;
// 	int		tmp;
// 	size_t	size;

// 	fd = open("highscores.txt", O_RDWR | O_CREAT, 0644);
// 	if (fd == -1)
// 		return ;
// 	size = 0;
// 	while (read(fd, &tmp, sizeof(int)))
// 		size++;
// 	tab = malloc(sizeof(int) * size);
// 	if (!tab)
// 		return ;
// 	lseek(fd, 0, SEEK_SET);
// 	i = 0;
// 	while (read(fd, &tab[i], sizeof(int)))
// 		i++;
// 	close(fd);
// 	sort_tab(tab, size);
// 	fd = open("highscores.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		return ;
// 	i = 0;
// 	while (i < size)
// 		dprintf(fd, "%d\n", tab[i++]);
// 	close(fd);
// 	free(tab);
// }

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

// int	sort_scores(void)
// {
// 	FILE	*fd;
// 	char	**tab;
// 	size_t	i;
// 	size_t	size;
// 	char	line[100];
// 	int		ret;

// 	fd = fopen("highscores.txt", "r");
// 	if (!fd)
// 		return (1);
// 	size = 0;
// 	while (fgets(line, 100, fd))
// 		size++;
// 	if (fseek(fd, 0, SEEK_SET) == -1)
// 		return (1);
// 	tab = malloc(sizeof(char *) * (size + 1));
// 	if (!tab)
// 		return (1);
// 	memset(tab, 0, sizeof(char *) * (size + 1));
// 	i = 0;
// 	while (fgets(line, 100, fd))
// 	{
// 		tab[i] = strdup(line);
// 		if (!tab[i])
// 		{
// 			free_tab(tab);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	tab[i] = NULL;
// 	fclose(fd);
// 	qsort(tab, size, sizeof(char *), ft_compare);
// 	fd = fopen("highscores.txt", "w+");
// 	if (!fd)
// 	{
// 		free_tab(tab);
// 		return (1);
// 	}
// 	ret = 0;
// 	i = 0;
// 	while (i < size && ret != -1)
// 		ret = fprintf(fd, "%s", tab[i++]);
// 	fclose(fd);
// 	free_tab(tab);
// 	return (ret == -1);
// }

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
