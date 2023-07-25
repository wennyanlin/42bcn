/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:18:08 by wlin              #+#    #+#             */
/*   Updated: 2023/07/25 18:31:36 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	is_uppercase;

	i = 0;
	is_uppercase = 1;
	while (str[i] != '\0' && is_uppercase)
	{
		is_uppercase = ('A' <= str[i] && str[i] <= 'Z');
		i++;
	}
	return (is_uppercase);
}
/*
int	main()
{
	ft_str_is_uppercase("HOLAChICA");
	return (0);
}
*/
