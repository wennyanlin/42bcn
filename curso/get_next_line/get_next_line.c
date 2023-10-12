/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:06:14 by wlin              #+#    #+#             */
/*   Updated: 2023/10/12 13:16:32 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*ft_update_storage()
{
	char	*new_storage;
	//copie from storage to new_storage till BUFFER_SIZE starting from \n
	//erase till 1st \n
	return (new_storage);
}

char	*ft_read_fd(int fd, char *storage)
{
	char	*buffer;
	//read till BUFFER_SIZE into buffer
	//copie from buffer to 
	//appends what ve been read to updated_storage 
	return (storage);
}

char    *get_next_line(int fd)
{
	char			*line;
    static char    *storage = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
 	//a function that going to read and stores every bytes read in storage
	storage = ft_read_fd(fd, storage);
	//a function to extract each line after read from fd and return the line
	line = ft_write_line(storage);
	//a function to update storage;
	storage = ft_update_storage(storage);
	return(line);
}

int main()
{
    //char	*path = "/Users/wlin/Desktop/test1.txt";
	int		f;
	char	*str;

	int i = 0;
	fd = open("/Users/wlin/Desktop/test1.txt", O_RDONLY);
	while (i < 3)
	{
		//printf("%s", str);
			str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	free(str);
	close(fd);

	//read the file
    //print out the first 10 bytes
    //close the file
}
