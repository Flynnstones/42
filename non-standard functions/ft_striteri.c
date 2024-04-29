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
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main()
{
    char    string[] = "Hello, World!";
    printf("Original: %s\n", string);
    ft_striteri(string, to_upper);
    printf("Modified: %s\n", string);
    return (0);
}