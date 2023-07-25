/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:41:52 by wlin              #+#    #+#             */
/*   Updated: 2023/07/25 18:11:36 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	is_lowercase;

	i = 0;
	is_lowercase = 1;
	while (str[i] != '\0' && is_lowercase)
	{
		is_lowercase = ('a' <= str[i] && str[i] <= 'z');
		i++;
	}
	return (is_lowercase);
}
/*int main()
{
	ft_str_is_lowercase("hoLa");
	return (0);
}*/
