#include <stdio.h>

int main(int argc, char *argv[])
{
    char carattere = argv[1][0];

    if(carattere >= 'a' && carattere <= 'z')
        carattere -= 32;
    printf("%c\n", carattere);

    return 0;
}

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return c;
}