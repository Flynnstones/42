#include <stdio.h>

int main(int argc, char *argv[])
{
    char carattere = argv[1][0];

    if(carattere >= 'a' && carattere <= 'z')
        carattere -= 32;
    printf("%c\n", carattere);

    return 0;
}