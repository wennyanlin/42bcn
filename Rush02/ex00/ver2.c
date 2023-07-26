/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarol-g <dcarol-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:30:52 by dcarol-g          #+#    #+#             */
/*   Updated: 2023/07/23 19:09:29 by dcarol-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024

extern int	ft_strlen(char *s);
extern int	ft_atoi(char *str, unsigned int *input);
extern int	is_direct(unsigned int *input, int len);
extern int	se(char *buf, ssize_t bytr, unsigned int *input, int *start);
int			f_write(int len, unsigned int *input, char *buf, ssize_t bytr);

int	parse_input2(char *str, unsigned int *input)
{
	int				len;

	len = ft_strlen(str);
	if (!ft_atoi(str, input))
	{
		write (1, "Input Mistake\n", 14);
		return (0);
	}
	return (1);
}

int	runopen(char *str, unsigned int *input)
{
	int				fd;
	int				i;
	int				len;
	char			buf[BUF_SIZE];
	ssize_t			bytr;

	len = ft_strlen(str);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error open.\n", 12);
		return (1);
	}
	bytr = read(fd, buf, BUF_SIZE);
	i = 0;
	if (!f_write(len, input, buf, bytr))
	{
		write (1, "Write error\n", 12);
		return (0);
	}
	return (1);
}

int	f_write(int len, unsigned int *input, char *buf, ssize_t bytr)
{
	int	s;
	int	*start;

	s = 0;
	start = &s;
	if (!(is_direct(input, len)))
	{
		write(1, "Is not direct\n", 14);
		return (0);
	}
	if (!se(buf, bytr, input, start))
	{
		write(1, "Search error\n", 13);
		return (0);
	}
	s = s + 2;
	while (buf[s] != '\n')
	{
		write(1, &buf[s], 1);
		s++;
	}
	return (1);
}
