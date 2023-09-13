/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:07:38 by wlin              #+#    #+#             */
/*   Updated: 2023/09/06 17:07:38 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_isalnum(int c)
{
	int	isalnum;

	isalnum = 0;
	if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z'))
	{
		isalnum = 1;
	}
	return (isalnum);
}
/* int main()
{
	char c;
	c = ':';
	printf("%i",ft_isalnum(c));
} */