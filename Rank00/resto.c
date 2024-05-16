#include <stdio.h>

float ft_fmod(float a, float b)
{
    return (a - b * ((int)(a / b)));
}

int ft_resto(void)
{
    int count;

    count = 1;
    float totale = 1.60;
    while (1)
    {
        totale += 4.70;
        if (ft_fmod(totale, 5) <= 0.01)
        {
            printf("Il totale %.1f è divisibile per 5 con 0.01 di tolleranza\n", totale);
            break;
        }
        count++;
    }
    return count;
}

int main()
{
    printf("Il numero di volte che è stato incrementato il totale è %d\n", ft_resto());
    return 0;
}
