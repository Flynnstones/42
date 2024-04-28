#include "libft.h"

int main(void)
{
    char str[50] = "Hello World!";
    ft_memset(str, 'a', 5);
    ft_bzero(str + 5, 5);
    printf("%s\n", str);
    return (0);
}