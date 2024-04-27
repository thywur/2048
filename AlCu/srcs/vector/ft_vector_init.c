#include <stdlib.h>
#include "ft_vector.h"

int ft_vector_init(t_vector *v, size_t capacity)
{
    if (!v)
        return (FAILURE);
    if (capacity < 1)
        v->capacity = VECTOR_INIT_CAPACITY;
    else
        v->capacity = capacity;
    v->count = 0;
    v->ptr = malloc(v->capacity * sizeof(int));
    if (!v->ptr)
    {
        ft_memset(v, '\0', sizeof(t_vector));
        return (FAILURE);
    }
    return (SUCCESS);
}
