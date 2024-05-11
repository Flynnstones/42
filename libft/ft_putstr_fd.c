#include <unistd.h>

void	ft_putstr_fd(char *string, int fd)
{
    while (*string)
    {
        write(fd, string, 1);
        string++;
    }
}