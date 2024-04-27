#include "wkw.h"
#include "ascii_numbers.h"

int	ft_square_root(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		i++;
		num >>= 1;
	}
	return (i);
}

void	asc_print_num(int y, int x, int num)
{
	int	i;
	int	len;
	int	tmp;

	tmp = ft_square_root(num);
	len = ft_strlen(asc_numbers[tmp][0]);
	i = 0;
	while (i < 5)
	{
		mvprintw(y + i - 1, x - len / 4, "%s", asc_numbers[tmp][i]);
		i++;
	}
}
