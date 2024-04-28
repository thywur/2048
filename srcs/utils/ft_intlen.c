#include "wkw.h"

int	ft_nblen(size_t n)
{
	int	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}
