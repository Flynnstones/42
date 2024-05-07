#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ft_calloc(size_t count, size_t size) 
{
    void    *ptr;

    ptr = NULL;
    if (count == 0 || size == 0)
    {
        count = 1;
        size = 1;
    }
    if (size != 0 && (count * size) / size != count)
        return (NULL);
    ptr = malloc(count * size);
    if (ptr != NULL) {
        memset(ptr, 0, count * size);
    }
    return ptr;
}