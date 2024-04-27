#include "alcu.h"

int ft_putnbr_fd(long n, int fd)
{
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }

    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
    }

    ft_putchar_fd(n % 10 + '0', fd);
    return 1;
}

int ft_putnbr(long n)
{
    return (ft_putnbr_fd(n, 1));
}
