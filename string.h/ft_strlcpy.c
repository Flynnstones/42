#include <stdio.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    for (i = 0; i < size - 1 && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return i;
}

int main()
{
    char src[] = "Hello, World!";
    char dst[6];
    size_t n = ft_strlcpy(dst, src, 6);
    printf("dst: %s\n", dst);
    printf("n: %zu\n", n);
    return 0;
}