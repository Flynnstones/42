#include <unistd.h>

void	ft_putendl_fd(char *string, int fd)
{
    while (*string)
    {
        write(fd, string, 1);
        string++;
    }
    write(fd, "\n", 1);
}

int    main()
{
    ft_putendl_fd("Hello, World!", 1);
    return (0);
}