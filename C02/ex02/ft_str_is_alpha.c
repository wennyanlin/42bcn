/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:17:00 by wlin              #+#    #+#             */
/*   Updated: 2023/07/24 19:11:20 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z' && str[i] >= 'A' 
					&& str[i] <= 'Z'))
		{
			return (0);
		}
		else if
		{
			if ((str[i] >= 'a' && str[i] <= 'z' && str[i] >= 'A' 
					&& str[i] <= 'Z'))
			{
				i++;
			}
			return (1);
		}
	}
}
/*
 *
 */
