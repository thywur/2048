#include <stddef.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t    i;

    i = 0;
    while ((dest || src) && i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return (dest);
}
