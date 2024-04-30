#include <stdio.h>  
#include <string.h> 

typedef union Data {
    int i;
    float f;
    char str[20];
} data;

typedef struct{
    union Data *data;
    int type;
} Data;

int main() {
    data data;
    Data data2;
    int type = 1;

    data2.data = &data;
    data2.type = type;

    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %.2f\n", data.f);

    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);

    printf("union_value : %s\n", data2.data->str);
    printf("type : %d\n", data2.type);
    return 0;
}