#include <stdio.h>

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t n;

    i = 0;
    j = 0;
    n = 0;
    while (dst[i] != '\0' && i < size)
        i++;
    while (src[n] != '\0')
        n++;
    if (i == size)
        return (size + n);
    while (src[j] != '\0' && i + j < size - 1)
    {
        dst[i + j] = src[j];
        j++;
    }
    dst[i + j] = '\0';
    return (i + n);
}

int main()
{
    char src[] = "Hello, World!";
    char dst[20] = "Hello";
    size_t n = ft_strlcat(dst, src, 19);
    printf("dst: %s\n", dst);
    printf("n: %zu\n", n);
    return 0;
}