/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:01:53 by wlin              #+#    #+#             */
/*   Updated: 2023/09/06 17:44:32 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_isalpha(int c)
{
	int	isalpha;

	isalpha = 0;
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
	{
		isalpha = 1;
	}
	return (isalpha);
}
/* int main()
{
    int c;

    c = '5';
    printf("%i",ft_isalpha(c));
} */
