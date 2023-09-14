/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:51:27 by wlin              #+#    #+#             */
/*   Updated: 2023/09/14 13:51:30 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = 0;
	srclen = 0;
	while (dest[destlen])
	{
		destlen++;
	}
	while (src[srclen])
	{
		dest[destlen] = src[srclen];
		srclen++;
	}
	printf("%s", dest);
	return (dest);
}


/* int	main()
{
printf("c", )
} */
