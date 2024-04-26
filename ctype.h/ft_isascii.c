#include <stdio.h>

int main(int argc, char *argv[])
{
    char carattere = argv[1][0];

    if(!(carattere >= 0 && carattere <= 127))
        printf("Il carattere inserito non è ascii");
    else
        printf("Il carattere inserito è ascii");
    
    return 0;
}