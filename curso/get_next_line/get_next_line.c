/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:06:14 by wlin              #+#    #+#             */
/*   Updated: 2023/10/26 15:14:28 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_storage(char *storage)
{
	char	*updated_storage;
	size_t	i;
	size_t	j;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free (storage);
		return (NULL);
	}
	i++;
	updated_storage = malloc((ft_strlen(storage) - i + 1) * sizeof(char));
	if (!updated_storage)
	{
		free(storage);
		return (NULL);
	}
	j = 0;
	while (storage[i])
		updated_storage[j++] = storage[i++];
	updated_storage[j] = '\0';
	free(storage);
	return (updated_storage);
}

char	*ft_read_fd(int fd, char *storage)
{
	char	*buffer;
	int		actual_bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(storage);
		return (NULL);
	}
	buffer[0] = '\0';
	actual_bytes_read = 1;
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
	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*storage = NULL;

	if ((fd < 0 || BUFFER_SIZE <= 0))
		return (NULL);
	storage = ft_read_fd(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_write_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_update_storage(storage);
	return (line);
}
/*
int main()
{
    int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	printf("###Main Result###\n");
	str = "test";
	while (str != NULL)
	{
		printf("\nDel while de main: %s\n", str);
		//free(str);
	  	str = get_next_line(fd);
	}
	close(fd);
}
*/
