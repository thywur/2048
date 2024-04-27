#include "alcu.h"

int ft_putstr_fd(char *s, int fd)
{
    if (s)
        return (write(fd, s, ft_strlen(s)));
    return (0);
}

int ft_putstr(char *s)
{
    return (ft_putstr_fd(s, 1));
}
