#include <stdio.h>  
#include <string.h>
#include <stdlib.h>

typedef union Data {
    int i;               // 4 bytes
    float f;            //  4 bytes
    char str[20];      //  20 bytes
} data;               //   20 bytes

typedef struct{
    union Data *data;   // 8 bytes
    int bytes;         //  4 bytes 
} Data;               //  12 bytes + 4 padding bytes = 16

int main() {
    data data;
    Data data2;

    data2.data = &data;

    data.i = 10;
    data2.data->i = 20;
    printf("data.i : %d\n", data.i);
    data2.bytes = sizeof(data2.data->i);

    data.f = 220.5;
    data2.data->f = 420.5;
    printf("data.f : %.2f\n", data.f);
    data2.bytes = sizeof(data2.data->f);

    strcpy(data.str, "C Programming");
    strcpy(data2.data->str, "C Programming Language");
    printf("data.str : %s\n", data.str);
    data2.bytes = sizeof(data2.data->str);

    printf("union_value : %s\n", data2.data->str);
    printf("bytes : %d\n", data2.bytes);
    printf("size of data2: %lu\n", sizeof(Data));
    return 0;
}