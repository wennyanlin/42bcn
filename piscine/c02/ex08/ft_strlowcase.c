/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:29:38 by wlin              #+#    #+#             */
/*   Updated: 2023/07/25 23:22:45 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*
 int	main(void)
{
	char str[50] = "HOLA, CIAO";
	printf("%s", ft_strlowcase(str));
	return(0);
}*/
