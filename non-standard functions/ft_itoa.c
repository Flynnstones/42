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
    int	number = n; 
    int	length = ft_length(number);
    int	is_negative = (number < 0);

    if (number < 0)
        number = -number;
    string = (char *)malloc(sizeof(char) * (length + 1));
    if (!string)
        return (NULL);
    if (number == 0)
        string[0] = '0';
    string[length] = '\0';
    while (number != 0)
    {
        string[--length] = (number % 10) + '0';
        number = number / 10;
    }
    if (is_negative)
        string[0] = '-';
    return (string);
}

int	main()
{
	int	n = -1234567890;
    int length = ft_length(n);
	char	*string = ft_itoa(n);
    if (string == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }
	printf("%s\n", string);
    printf("Length: %d\n", length);
	free(string);
	return (0);
}