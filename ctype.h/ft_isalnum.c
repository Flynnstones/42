#include <stdio.h>

int main(int argc, char *argv[])
{
    char carattere = argv[1][0];

    if (!(carattere >= 'a' && carattere <= 'z') && (carattere >= 'A' && carattere <= 'Z') && (carattere >= '0' && carattere <= '9'))
        printf("Il carattere inserito non è alfanumerico");
    else
        printf("Il carattere inserito è alfanumerico");

    return 0;
}