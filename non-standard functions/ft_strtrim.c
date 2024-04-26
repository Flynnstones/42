#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    size_t  i;

    start = 0;
    while (s1[start] && strchr(set, s1[start]))
        start++;
    end = strlen(s1);
    while (end > start && strchr(set, s1[end - 1]))
        end--;
    char *str = (char *)malloc(end - start + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (start < end)
    {
        str[i] = s1[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return str;
}

int main()
{
    char *s1 = "abababbhello worldabbbabab";
    char *set = "ab";
    char *trimmed = ft_strtrim(s1, set);
    printf("Trimmed string: '%s'\n", trimmed);
    free(trimmed);
    return 0;
}