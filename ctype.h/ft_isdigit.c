#include <stdio.h>

int main (int argc, char *argv[])
{
    char carattere = argv[1][0];

    if(carattere >= 0 && carattere <= 9)
        printf("il carattere inserito è un numero");
    else
        printf("il carattere inserito non è un numero");
    
    return 0;
}

int ft_isdigit(int c)
{
    if (c >= 0 && c <= 9)
        return 1;
    return 0;
}