#include "library.h"

int main() {
    char str[20];

    ft_memset(str, 'a', 20);
    printf("Before ft_bzero: %s\n", str);

    ft_bzero(str + 10, 1);
    printf("After ft_bzero: %s\n", str);

    return 0;
}