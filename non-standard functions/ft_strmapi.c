#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *new_string;
    size_t  length;
    size_t  i;

    if (!s || !f)
        return (NULL);
    length = strlen(s);
    new_string = (char *)malloc(sizeof(char) * (length + 1));
    if (!new_string)
        return (NULL);
    i = 0;
    while (i < length)
    {
        new_string[i] = f(i, s[i]);
        i++;
    }
    new_string[i] = '\0';
    return (new_string);
}

char    to_upper(unsigned int i, char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main()
{
    char    *string = "Hello, World!";
    char    *new_string = ft_strmapi(string, to_upper);
    printf("%s\n", new_string);
    free(new_string);
    return (0);
}