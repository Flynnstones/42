#include <stdio.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
    unsigned char	*dest;
    unsigned char	*src;

    dest = (unsigned char *)s1;
    src = (unsigned char *)s2;
    if (dest < src)
    {
        while (n--)
            *dest++ = *src++;
    }
    else
    {
        dest += n;
        src += n;
        while (n--)
            *--dest = *--src;
    }
    return (s1);
}

int main(void)
{
    char src[] = "Hello, World!";
    char    *s1 = ft_memmove(src + 2, src, 11);
    printf("Copied string: %s\n", s1);
    return (0);
}