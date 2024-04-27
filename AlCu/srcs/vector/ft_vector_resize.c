#include <stdlib.h>
#include "ft_vector.h"

int ft_vector_resize(t_vector *v, size_t capacity)
{
    void    *new;

    if (!v || capacity < v->count || !capacity)
        return (FAILURE);
    new = malloc(sizeof(int) * capacity);
    if (!new)
        return (FAILURE);
    ft_memcpy(new, v->ptr, sizeof(int) * v->count);
    free(v->ptr);
    v->ptr = new;
    v->capacity = capacity;
    return (SUCCESS);
}
