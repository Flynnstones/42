#include <stdio.h>

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1 = (unsigned char *)s1;
    unsigned char *str2 = (unsigned char *)s2;
    while (n-- && *str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int main()
{
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    int n = ft_memcmp(str1, str2, 5);
    printf("n: %d\n", n);
    return 0;
}