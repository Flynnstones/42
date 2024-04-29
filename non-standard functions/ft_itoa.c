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
    int	length = ft_length(n);
    int	is_negative = (n < 0);

    if (n < 0)
        n = -n;
    string = (char *)malloc(sizeof(char) * (length + 1));
    if (!string)
        return (NULL);
    if (n == 0)
        string[0] = '0';
    string[length] = '\0';
    while (n != 0)
    {
        string[--length] = (n % 10) + '0';
        n = n / 10;
        printf("temp_length: %d\n", length);
    }
    if (is_negative)
        string[--length] = '-';
    return (string);
}

int	main()
{
	int	n = -12;
    int l = ft_length(n);
	char	*string = ft_itoa(n);
    if (string == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }
	printf("From int to char: %s\n", string);
    printf("Length: %d\n", l);
	free(string);
	return (0);
}