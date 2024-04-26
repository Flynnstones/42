#include <stdio.h>

int     ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int main()
{
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    int n = ft_strcmp(str1, str2);
    printf("n: %d\n", n);
    return 0;
}