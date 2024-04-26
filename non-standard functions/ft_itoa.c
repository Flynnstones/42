#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int	ft_length(int number)
{
	unsigned int	length;
	
	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
    char	*string;
    long	number = n;  // Tratta n come un long
    int	length = ft_length(n);
    int	is_negative = (n < 0);

    if (number < 0)
        number = -number;  // Questo non causerà un overflow perché number è un long
    string = (char *)malloc(sizeof(char) * (length + 1));
    if (!string)
        return (NULL);
    if (number == 0)
        string[0] = '0';
    string[length] = '\0';
    while (number != 0)
    {
        string[length - 1] = (number % 10) + '0';
        number = number / 10;
        length--;
    }
    if (is_negative)
        string[0] = '-';
    return (string);
}

int	main()
{
	int	n = -123456;
	char	*string = ft_itoa(n);
	printf("%s\n", string);
	free(string);
	return (0);
}