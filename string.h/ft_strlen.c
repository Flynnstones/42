#include <stdio.h>

int	ft_strlen(const char *str)
{
	int i;

	i = 0; 
	while(str[i])
		i++;
	return(i);
}

int	main(void)
{
	char *str = "Hello World!";
	printf("Length of string is: %d\n", ft_strlen(str));
	return(0);
}