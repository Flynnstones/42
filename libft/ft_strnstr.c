#include <stdio.h>
#include <string.h>

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;

    if (*needle == '\0')
        return (char *)haystack;
    if (*haystack == '\0')
        return NULL;
    size_t needle_len = strlen(needle);
    if (needle_len > len)
        return NULL;
    i = 0;
    while (i <= len - needle_len)
    {
        if (strncmp(haystack + i, needle, needle_len) == 0)
            return (char *)(haystack + i);
        i++;
    }
    return NULL;
}