#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    *ft_calloc(size_t count, size_t size)
{
    void *ptr = malloc(count * size);
    if (ptr)
    {
        memset(ptr, 0, count * size);
        return ptr;
    }
    return NULL;
}

int main()
{
    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}