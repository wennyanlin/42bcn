#include <unistd.h>

char    *get_next_line(int fd)
{
    char    *buffer;
    int     actual_bytes_read;

    if (fd < 0)
    {
        perror('Error');
        return (-1);
    }
    buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL)
        return (NULL);
    actual_bytes_read = read(fd, buffer, 10);
    return (0);
}

int main()
{
    //open a file
    //read the file
    //print out the first 10 bytes
    //close the file
}