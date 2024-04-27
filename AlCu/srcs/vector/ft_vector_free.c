#include <stdlib.h>
#include "ft_vector.h"

int ft_vector_free(t_vector *v)
{
    if (!v)
        return (FAILURE);
    free(v->ptr);
    ft_memset(v, '\0', sizeof(t_vector));
    return (SUCCESS);
}
