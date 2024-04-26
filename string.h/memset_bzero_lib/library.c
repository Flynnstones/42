#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

void    ft_bzero(void *s, size_t n) 
{
    ft_memset(s, 0, n);
}