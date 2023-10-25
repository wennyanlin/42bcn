/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:06:14 by wlin              #+#    #+#             */
/*   Updated: 2023/10/24 17:01:27 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_storage(char *storage)
{
	char	*updated_storage;
	size_t	i;
	size_t	j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	updated_storage = malloc((ft_strlen(storage) - i + 1) * sizeof(char));
	if (!updated_storage)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
	{
		updated_storage[j++] = storage[i++];
	}
	free(storage);
	printf("updated_storage--->%s\n", updated_storage);
	return (updated_storage);
}

char	*ft_read_fd(int fd, char *storage)
{
	char	*buffer;
	int		actual_bytes_read;

	actual_bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (actual_bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		actual_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (actual_bytes_read == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[actual_bytes_read] = '\0';
		storage = ft_strjoin (storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*ft_write_line(char *storage)
{
	char	*line;
	size_t	i;

	i = 0;
	while (storage[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] != '\n')// || storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n' || storage[i] == '\0')
			line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//a function that going to read and stores every bytes read in storage
	storage = ft_read_fd(fd, storage);
	//a function to extract each line after read from fd and return the line
	line = ft_write_line(storage);
	printf("line -> %s\n", line);
	//a function to update storage;
	storage = ft_update_storage(storage);
	return (line);
}

int main()
{
    //char	*path = "/Users/wlin/Desktop/test1.txt";
	int		fd;
	char	*str;

	int i = 0;
	fd = open("test.txt", O_RDONLY);
	//str = get_next_line(fd);
	while (i <= 5)
	{
		//printf("%s", str);
		str = get_next_line(fd);
		printf("%s", str);
	  	i++;
	}
	free(str);
	close(fd);
}
