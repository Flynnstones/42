#include <stdio.h>

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1 = (unsigned char *)s1;
    unsigned char *str2 = (unsigned char *)s2;
    while (n--)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return (0);
}
/*
int     main(void)
{
    char s[] = {-128, 0, 127, 0};
    char s2[] = {0, 0, 127, 0};
    char s3[] = {0, 0, 42, 0};
    printf("%d\n", ft_memcmp(s, s2, 0));
    printf("%d\n", ft_memcmp(s2, s3, 4));
    return (0);
}
*/