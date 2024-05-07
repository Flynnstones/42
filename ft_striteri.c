#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    ft_striteri(char *string, void (*f)(unsigned int, char *))
{
    unsigned int    i;

    if (!string || !f)
        return ;
    i = 0;
    while (string[i])
    {
        f(i, &string[i]);
        i++;
    }
}

void    to_upper(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c -= 32;
}