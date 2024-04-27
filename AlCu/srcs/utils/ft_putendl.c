#include "alcu.h"

int ft_putendl_fd(char *s, int fd)
{
    return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}

int ft_putendl(char *s)
{
    return (ft_putendl_fd(s, 1));
}
