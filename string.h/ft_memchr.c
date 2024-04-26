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

int main()
{
    char str[] = "Hello, World!";
    char *ptr = ft_memchr(str, 'W', 13);
    printf("String after 'W': %s\n", ptr);
    return 0;
}