/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarol-g <dcarol-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:56:55 by dcarol-g          #+#    #+#             */
/*   Updated: 2023/07/23 19:14:55 by dcarol-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024

extern int	ft_strlen(char *s);
extern int	ft_atoi(char *str, unsigned int *input);
extern int	parse_input2(char *str, unsigned int *input);
extern int	runopen(char *str, unsigned int *input);

int	main(int argc, char **argv)
{
	char			*str;
	unsigned int	nam;
	unsigned int	*input;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		str = argv[1];
		nam = 0;
		input = &nam;
		if (!parse_input2(str, input))
		{
			write (1, "Invalid num\n", 12);
			return (0);
		}
		if (!runopen(str, input))
			return (0);
	}
	return (0);
}
