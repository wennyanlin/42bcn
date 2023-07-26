/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarol-g <dcarol-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:26:24 by dcarol-g          #+#    #+#             */
/*   Updated: 2023/07/23 19:19:56 by dcarol-g         ###   ########.fr       */
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

int	is_direct(unsigned int *input, int len)
{
	if (len == 1)
		return (1);
	else if (len == 2 && *input >= 10 && *input <= 19)
		return (1);
	else if (len == 2 && (*input % 10 == 0))
		return (1);
	else if (*input == 100 || *input == 1000)
		return (1);
	else if (*input == 1000000 || *input == 1000000000)
		return (1);
	else
		return (0);
}

extern int	se(	char *buf, ssize_t bytr, unsigned int *input, int *start)
{
	char				*poss;
	int					i;
	unsigned int		k;
	int					cond;
	unsigned int		*pk;

	i = 0;
	k = 0;
	cond = 1;
	pk = &k;
	poss = malloc(9);
	while (bytr > 0)
	{
		while (buf[i] != '\0')
		{
			while (buf[i] != '\n')
			{
				while ((buf[i] != ' ' && buf[i] != ':') && cond == 1)
				{
					poss[k] = buf[i];
					k++;
					i++;
				}
				k = 0;
				cond = 0;
				if (!ft_atoi(poss, pk))
				{
					printf("Key not int");
					free(poss);
					return (0);
				}
				if (k == *input)
				{
					*start = i;
					free(poss);
					return (1);
				}
				k = 0;
				i++;
			}
			cond = 1;
			i++;
		}
		printf("Run Error 1\n");
		free(poss);
		return (0);
	}
	free(poss);
	return (0);
}
