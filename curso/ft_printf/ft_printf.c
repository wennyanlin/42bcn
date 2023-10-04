/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:48:39 by wlin              #+#    #+#             */
/*   Updated: 2023/10/04 18:11:53 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const	char *str, ...)
{
	va_list	args;
	int		i;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			select_fmt(str[i + 1], args)//call function and start checking which format.
		else
			putchar(str[i]);//call funcition and print.
		i++;
	}
	return (i);
}

int	select_fmt(char c, va_list args)
{
	if (c == '%')
		putchar('%');
	else if (c == 'c')
		putchar(va_arg(args, int));
}

void	putchar(char c)
{
	write(1, &c, 1);
}
