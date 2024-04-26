#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    **ft_split(char const *s, char c)
{
    size_t  i;
    size_t  j;
    size_t  k;
    char    **arr;

    arr = (char **)malloc(sizeof(char *) * (strlen(s) + 1));
    if (!arr)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (!s[i])
            break ;
        k = 0;
        while (s[i + k] && s[i + k] != c)
            k++;
        arr[j] = (char *)malloc(k + 1);
        if (!arr[j])
            return (NULL);
        memcpy(arr[j], s + i, k);
        arr[j][k] = '\0';
        j++;
        i += k;
    }
    arr[j] = NULL;
    return (arr);
}

int main()
{
    char *s = "Hello, World!";
    char **arr = ft_split(s, ' ');
    for (size_t i = 0; arr[i]; i++)
        printf("'%s'\n", arr[i]);
    return 0;
}