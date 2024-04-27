#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <stddef.h>

#define VECTOR_INIT_CAPACITY 16

#define FAILURE -1
#define SUCCESS 0

typedef struct s_vector
{
	int *ptr;
	size_t capacity;
	size_t count;
} t_vector;

typedef int (*t_vfunc)(void *);

void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);

int ft_vector_add(t_vector *v, int item);
int ft_vector_free(t_vector *v);
int ft_vector_init(t_vector *v, size_t capacity);
int ft_vector_resize(t_vector *v, size_t capacity);
int ft_vector_get(t_vector *v, size_t index);
void ft_vector_set(t_vector *v, size_t index, int value);

#endif
