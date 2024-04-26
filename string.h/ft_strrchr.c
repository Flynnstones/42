#include <stdio.h>

char *ft_strrchr(const char *str, int c)
{
    char *last_occurrence = NULL; 

    while (*str != '\0')
    {
        if (*str == c)
            last_occurrence = (char *)str;
        str++; 
    }

    if (c == '\0') 
        last_occurrence = (char *)str; 
    return last_occurrence; 
}

int main()
{
    char str[] = "Hello, World!";
    char *ptr = ft_strrchr(str, 'o');
    printf("String after 'o': %s\n", ptr);
    return 0;
}