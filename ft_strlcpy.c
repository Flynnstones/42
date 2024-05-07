#include <stdio.h>
#include <string.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t src_len = strlen(src);

    if (size == 0) {
        return src_len;
    }
    i = 0;
    while (i < size - 1 && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';
    return src_len;
}