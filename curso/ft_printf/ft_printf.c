/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:48:39 by wlin              #+#    #+#             */
/*   Updated: 2023/10/06 18:35:53 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	select_fmt(char c, va_list args)
{
	if (c == '%')
		write(1, "%", 1);
	else if (c == 'c')
		return (0);
	else if (c == 's')
		return (0);
	else if (c == 'p')
		return (0);
	else if (c == 'd')
		put_i(va_arg(args, int));
	else if (c == 'i')
		put_i(va_arg(args, int));
	else if (c == 'u')
		return (0);
	else if (c == 'x')
		return (0);
	else if (c == 'X')
		return (0);
	return (0);
}

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
			select_fmt(str[i + 1], args);
		else
			return (0);
		i++;
	}
	return (i);
}

int	main()
{
	char *v = "sdfgh%igh";
	int r = -4568;
	int	result = ft_printf(v, r);
	printf("%i", result);
}
