#include <stdio.h>
#include <string.h>
char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    if (*needle == '\0')
        return (char *)haystack;

    size_t needle_len = strlen(needle);
    for (size_t i = 0; i <= len - needle_len; i++)
    {
        if (strncmp(haystack + i, needle, needle_len) == 0)
            return (char *)(haystack + i);
    }

    return NULL;
}

int main()
{
    char str[] = "Hello, World!";
    char *ptr = ft_strnstr(str, "World", 13);
    printf("String after 'World': %s\n", ptr);
    return 0;
}