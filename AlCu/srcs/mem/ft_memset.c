#include <stddef.h>

void    *ft_memset(void *s, int c, size_t n)
{
    void    *ret;
    size_t    i;

    ret = s;
    i = 0;
    while (i < n)
    {
        ((char *)s)[i] = (char)c;
        i++;
    }
    return (ret);
}
