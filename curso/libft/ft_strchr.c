/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:59:12 by wlin              #+#    #+#             */
/*   Updated: 2023/09/11 20:59:15 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	findchar;

	findchar = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)findchar)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)findchar)
		return ((char *)&s[i]);
	return (0);
}
