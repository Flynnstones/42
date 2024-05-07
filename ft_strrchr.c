#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
    char *last_occurrence = NULL;
    c = (unsigned char)c;

    while (*s)
    {
        if ((unsigned char)*s == c)
            last_occurrence = (char *)s;
        s++;
    }

    if (c == '\0')
        last_occurrence = (char *)s;

    return last_occurrence;
}