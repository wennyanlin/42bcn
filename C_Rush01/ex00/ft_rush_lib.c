/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:00:43 by cpujades          #+#    #+#             */
/*   Updated: 2023/07/16 21:39:41 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		++str;
	}
}

int	ft_char_to_int(char c)
{
	return (c - '0');
}

void	fill_array(int arr[16], char *str)
{
	int	i;
	int	count_str;

	i = 0;
	count_str = 0;
	while (*str != '\0')
	{
		if (count_str % 2 == 0)
		{
			arr[i] = ft_char_to_int(*str);
			++i;
		}
		++count_str;
		++str;
	}
}
