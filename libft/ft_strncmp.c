#include <stdio.h>

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *ptr1;
    unsigned char *ptr2;

    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;

    while (n)
    {
        if (*ptr1 != *ptr2 || !*ptr1 || !*ptr2)
            return (*ptr1 - *ptr2);
        ptr1++;
        ptr2++;
        n--;
    }
    return (0);
}