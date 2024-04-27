#include "alcu.h"

int ft_strlen(const char *s)
{
    int i;

    i = -1;
    if (!s)
        return (0);
    while (s[++i])
        ;
    return (i);
}
