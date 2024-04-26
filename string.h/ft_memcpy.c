#include <stdio.h>

void    *ft_memcpy( void *dest, const void *src, size_t n)
{
    char *d;
    char *s;

    d = (char *)dest;
    s = (char *)src;
    while (n--)
        *d++ = *s++;
    return (dest);
}

int        main(void)
{
    char src[] = "Hello, World!";
    char dest[50];
    ft_memcpy(dest, src, 11);
    printf("Copied string: %s\n", dest);
    return (0);
}