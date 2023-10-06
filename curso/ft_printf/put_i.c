/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:30:30 by wlin              #+#    #+#             */
/*   Updated: 2023/10/06 16:05:25 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	put_recursive(int n)
{
	char	digit;
	int		i;

	i = 0;
	if (n > 9)
	{
		i += 1 + put_recursive(n / 10);
		digit = n % 10 + '0';
		write(1, &digit, 1);
	}
	else	
	{
		digit = n + '0';
		write(1, &digit, 1);
		i++;
	}
	return (i);
}

int	put_i(int n)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		k = 1;
	}
	i = put_recursive(n) + k;
	return (i);
}

int	main()
{
	int	n = 1556;
	int result = put_i(n);
	printf("\n%i", result);
}