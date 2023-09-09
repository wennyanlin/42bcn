/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:07:14 by wlin              #+#    #+#             */
/*   Updated: 2023/09/09 14:07:18 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_isascii(int c)
{
	int	isascii;

	isascii = 0;
	if (' ' <= c && c <= '~')
	{
		isascii = 1;
	}
	return (isascii);
}
/*
int	main(void)
{
	int	c;

	c = 32;
	printf("%i", ft_isascii(c));
} */
