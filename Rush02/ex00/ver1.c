/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarol-g <dcarol-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:58:08 by dcarol-g          #+#    #+#             */
/*   Updated: 2023/07/23 19:07:46 by dcarol-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024

int	ft_strlen(char *s);
int	ft_atoi(char *str, unsigned int *input);

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, unsigned int *input)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	*input = result;
	return (1);
}
