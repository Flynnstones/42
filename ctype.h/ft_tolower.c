#include <stdio.h>

int main(int argc, char *argv[])
{
    char carattere = argv[1][0];

    if(carattere >= 'A' && carattere <= 'Z')
        carattere += 32;
    printf("%c\n", carattere);
    
    return 0;
}

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}