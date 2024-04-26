#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strdup(const char *s1)
{
    size_t len = strlen(s1) + 1; 
    void *dup = malloc(len);

    if (dup != NULL) {
            memcpy(dup, s1, len);
    }

    return dup;
}

int main()
{
    char *str = "Hello, World!";
    char *dup = ft_strdup(str);
    printf("Duplicate string: %s\n", dup);
    free(dup);
    return 0;
}