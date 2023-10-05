/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:48:39 by wlin              #+#    #+#             */
/*   Updated: 2023/10/05 18:07:32 by wlin             ###   ########.fr       */
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
		put_c('%');
	else if (c == 'c')
		put_c(va_arg(args, int));
	else if (c == 's')
		put_s(va_arg(args, char *));
	else if (c == 'p')
		//put_s(va-arg(args, char *));
	else if (c == 'd')
		put_i(va_arg(args, int));
	else if (c == 'i')
		put_i(va_arg(args, int));
	else if (c == 'u')
		put_i(va_arg(args, int));
	else if (c == 'x')
		//put_x(va_arg(args, ));
	else if (c == 'X')
		//put_x(va_arg(args, ));
}

void	putchar(int c)
{
	write(1, &c, 1);
}
