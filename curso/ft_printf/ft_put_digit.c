/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:30:30 by wlin              #+#    #+#             */
/*   Updated: 2023/10/07 22:19:51 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_recursive(long long n)
{
	char	digit;
	int		i;

	i = 0;
	if (n > 9)
	{
		i += 1 + ft_put_recursive(n / 10);
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

int	ft_put_digit(long long n)
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
	i = ft_put_recursive(n) + k;
	return (i);
}

int	ft_put_recursive_hexa(unsigned long n, char *hexa_base)
{
	int		digit;
	int		i;

	i = 0;
	if (n > 15)
	{
		digit = n % 16;
		i += 1 + ft_put_recursive_hexa(n / 16, hexa_base);
		write(1, &hexa_base[digit], 1);
	}
	else
	{
		digit = n % 16;
		write(1, &hexa_base[digit], 1);
		i++;
	}
	return (i);
}

int	ft_put_hexa(unsigned long n, char mode)
{
	int	len;

	len = 0;
	if (mode == 'x')
		len = ft_put_recursive_hexa(n, "0123456789abcdef");
	else if (mode == 'X')
		len = ft_put_recursive_hexa(n, "0123456789ABCDEF");
	else if (mode == 'p')
	{
		len = write(1, "0x", 2);
		len += ft_put_recursive_hexa(n, "0123456789abcdef");
	}
	return (len);
}
/*
int	main()
{
	int	n = -1;
	int result = ft_put_hexa(n, 'p');
	int org_result = printf("%d", result);
	printf("\n%i|%i", result, org_result);
	return (0);
}*/
