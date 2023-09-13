/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:53:59 by cpujades          #+#    #+#             */
/*   Updated: 2023/07/16 21:41:20 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	correct_length(char str[])
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		++length;
		++i;
	}
	if (length != 31)
	{
		return (0); 
	}
	return (1);
}

int	is_number(char c)
{
	if ('1' <= c && c <= '4')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c != ' ')
		return (0);
	return (1);
}

int	structure_verification(char str[])
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i % 2) != 0)
		{
			if (is_space(str[i]) == 0)
				return (0);
		}
		else
		{
			if (is_number(str[i]) == 0)
				return (0);
		}
		++i;
	}
	return (1);
}
