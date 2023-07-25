/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:37:04 by wlin              #+#    #+#             */
/*   Updated: 2023/07/25 18:49:32 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	is_printable;

	i = 0;
	is_printable = 1;
	while (str[i] != '\0' && is_printable)
	{
		is_printable = (' ' <= str[i] && str[i] <= '~');
		i++;
	}
	return (is_printable);
}
/*
int	main(void)
{
	ft_str_is_printable("abssd");
}*/
