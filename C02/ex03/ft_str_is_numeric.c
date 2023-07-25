/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:28:07 by wlin              #+#    #+#             */
/*   Updated: 2023/07/25 13:35:07 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_numeric(char *str)
{
	int	i;
	int	is_numeric;

	i = 0;
	is_numeric = 1;
	while (str[i] != '\0' && is_numeric)
	{
		is_numeric = ('0' <= str[i] && str[i] <= '9');
		i++;
	}
	return (is_numeric);
}
/*
int	main()
{
	printf("%i\n",ft_str_is_numeric("123"));
}*/
