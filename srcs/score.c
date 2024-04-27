#include "../includes/wkw.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

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

int ft_compare (const void *a, const void *b)
{
	return strcmp((char*)a, (char*)b);
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

void	sort_scores(void)
{
	FILE	*fd;
	char	**tab;
	size_t	i;
	int		tmp;
	size_t	size;
	char	line[100];

	fd = fopen("highscores.txt", "r");
	if (!fd)
		return ;
	size = 0;
	while (fgets(line, 100, fd))
		size++;
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return ;
	fseek(fd, 0, SEEK_SET);
	i = 0;
	while (fgets(line, 100, fd))
	{
		tab[i] = strdup(line);
		i++;
	}
	tab[i] = 0;
	fclose(fd);
	// sort_tab(tab, size);
	qsort(tab, size, sizeof(char *), ft_compare);
	fd = fopen("highscores.txt", "w+");
	if (!fd)
		return ;
	i = 0;
	while (i < size)
		fprintf(fd, "%s", tab[i++]);
	fclose(fd);
	free_tab(tab);
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
