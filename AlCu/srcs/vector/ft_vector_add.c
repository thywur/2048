#include "ft_vector.h"

int ft_vector_add(t_vector *v, int item)
{
    if (!v)
        return (FAILURE);
    if (v->count == v->capacity)
        if (ft_vector_resize(v, v->capacity << 1))
            return (FAILURE);
    v->ptr[v->count] = item;
    v->count++;
    return (SUCCESS);
}
