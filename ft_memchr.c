#include <stdio.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *ptr = (unsigned char *)s;
    while (n--)
    {
        if (*ptr == (unsigned char)c)
            return (ptr);
        ptr++;
    }
    return (NULL);
}