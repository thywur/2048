#include "alcu.h"

int ft_putchar_fd(char c, int fd)
{
    if (c)
        return (write(fd, &c, 1));
    return (0);
}

int ft_putchar(char c)
{
    return (ft_putchar_fd(c, 1));
}
