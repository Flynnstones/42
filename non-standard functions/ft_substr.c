#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*substr;
    size_t	i;

    if (!s)
        return (NULL);
    if (start >= strlen(s))
        return (strdup(""));
    if (strlen(s) - start < len)
        len = strlen(s) - start;
    substr = (char *)malloc(len + 1);
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    return (substr);
}

int main()
{
    char str[] = "Hello, World!!!!!!";
    char *ptr = ft_substr(str, 11, 5);
    printf("Substring: %s\n", ptr);
    free(ptr);
    return 0;
}