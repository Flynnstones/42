#include <stdio.h>  
#include <string.h>
#include <stdlib.h>

typedef union Data {
    int i; // 4 bytes
    float f; // 4 bytes
    char str[20]; // 20 bytes
} data; // 20 bytes

typedef struct{
    union Data *data; // 20 bytes
    int type; // 4 bytes
} Data; // 24 bytes

int main() {
    data data;
    Data data2; // Data *data2;
    int type;


    // data2 = (Data *)malloc(sizeof(Data)); // 24 bytes
    type = 1;
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
    // free(data2);
    return 0;
}