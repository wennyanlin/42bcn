/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:06:14 by wlin              #+#    #+#             */
/*   Updated: 2023/10/11 17:07:27 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    int     actual_bytes_read;

    if (fd < 0)
    {
        return (NULL);
    }
    buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL)
        return (NULL);
    actual_bytes_read = read(fd, buffer, 10);
	return (buffer);
    //return (0);
	//a function that going to read and stores every bytes read in storage
	//a function to extract each line after read from fd and return the line
	//a function to update storage;
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
