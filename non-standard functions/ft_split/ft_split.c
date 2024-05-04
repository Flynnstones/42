#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int     word_count(const char *s, char c);
void    ft_initiate(size_t *i, size_t *j, size_t *k);
void    *ft_free(char **strs, int count);


char    **ft_split(char const *s, char c)
{
    size_t  i;
    size_t  j;
    size_t  k;
    char    **arr;

    ft_initiate(&i, &j, &k);
    arr = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
    while (s[i])
    {
        while (s[i] == c)
            i++;
        while (s[i + k] && s[i + k] != c)
            k++;
        arr[j] = (char *)malloc(k + 1);
        if (!arr[j])
            return (ft_free(arr, j));
        memcpy(arr[j], s + i, k);
        arr[j][k] = '\0';
        j++;
        i += k;
    }
    arr[j] = NULL;
    return (arr);
}

void    ft_initiate(size_t *i, size_t *j, size_t *k)
{
    *i = 0;
    *j = 0;
    *k = 0;
}

int word_count(const char *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (!s[i])
            break ;
        count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

void    *ft_free(char **strs, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
    return (NULL);
}

int main()
{
    char    **arr;
    int     i;

    arr = ft_split("Hello, World!", ' ');
    i = 0;
    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
    return 0;
}