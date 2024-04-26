#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*str;
    size_t	i;
    size_t	j;

    if (!s1 || !s2)
        return (NULL);
    str = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

int main()
{
    char str1[] = "Hello, ";
    char str2[] = "World!";
    char *ptr = ft_strjoin(str1, str2);
    printf("Joined string: %s\n", ptr);
    free(ptr);
    return 0;
}