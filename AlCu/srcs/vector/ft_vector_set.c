#include "ft_vector.h"

void ft_vector_set(t_vector *v, size_t index, int value)
{
    if (!v || index >= v->count)
        return;
    v->ptr[index] = value;
}
