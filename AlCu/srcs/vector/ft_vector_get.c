#include "ft_vector.h"

int ft_vector_get(t_vector *v, size_t index)
{
    if (!v || index >= v->count)
        return -1;
    return (v->ptr[index]);
}
