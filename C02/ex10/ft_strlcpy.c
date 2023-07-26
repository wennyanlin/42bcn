/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:11:54 by wlin              #+#    #+#             */
/*   Updated: 2023/07/26 21:34:58 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;

	j = 0;
	if (size > 0)
	{
		while (src[j] && j < (size - 1))
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "HolaWen";
	char dest[] = "Adios";
	unsigned int a;
	unsigned int size = 5;
	a = ft_strlcpy(dest, src, size);
	//ft_strlcpy(dest, src, size);
	printf("%d %s %s", a, src, dest);
}*/
