#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (!*s)
            return (NULL);
        s++;
    }
    return ((char *)s);
}

int main()
{
    char str[] = "Hello, World!";
    char *ptr = ft_strchr(str, 'W');
    printf("String after 'W': %s\n", ptr);
    return 0;
}