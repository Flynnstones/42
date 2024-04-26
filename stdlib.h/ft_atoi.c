#include <stdio.h>

int ft_atoi(const char *nptr)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    // Skip leading whitespace
    while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' ||
           nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == '\v')
    {
        i++;
    }

    // Check for optional sign
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    // Convert digits to integer
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }

    return sign * result;
}

int main()
{
    char str[] = "12345";
    int n = ft_atoi(str);
    printf("n: %d\n", n);
    return 0;
}