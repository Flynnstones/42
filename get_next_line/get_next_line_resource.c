#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int print_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    close(fd);
    return 0;
}

int print_ffile(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    char c;
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c);
    }

    fclose(file);
    return 0;
}

int main()
{
    printf("\n\nprint_file\n\n");
    print_file("/Users/filocasoni/Downloads/Avventuriero.txt");
    printf("\n\nprint_ffile\n\n");
    print_ffile("/Users/filocasoni/Downloads/Avventuriero.txt");
    return 0;
}