/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:47 by wlin              #+#    #+#             */
/*   Updated: 2023/07/12 19:01:14 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print(int num1, int num2, int num3)
{
	write(1, &num1, 1);
	write(1, &num2, 1);
	write(1, &num3, 1);
	if (num1 != '7')
	{
		write(1, ", ", 2);
	}
}

int	ft_print_comb(void)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = '0';
	while (num1 <= '7')
	{
		num2 = num1 + 1;
		while (num2 <= '8') 
		{
			num3 = num2 + 1;
			while (num3 <= '9')
			{
				ft_print(num1, num2, num3);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}
