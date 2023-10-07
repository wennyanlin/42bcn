/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:48:39 by wlin              #+#    #+#             */
/*   Updated: 2023/10/07 21:37:21 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_fmt(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len = write(1, "%", 1);
	else if (c == 'c')
		len = put_char((char)va_arg(args, int));
	else if (c == 's')
		len = put_str(va_arg(args, char *));
	else if (c == 'p')
		len = ft_put_hexa(va_arg(args, unsigned long), 'p');
	else if (c == 'd')
		len = ft_put_digit(va_arg(args, int));
	else if (c == 'i')
		len = ft_put_digit(va_arg(args, int));
	else if (c == 'u')
		len = ft_put_recursive(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_put_hexa(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		len = ft_put_hexa(va_arg(args, unsigned int), 'X');
	return (len);
}

int	ft_printf(const	char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += select_fmt(str[++i], args);
		else
			len += put_char(str[i]);
		i++;
	}
	return (len);
}

/*int	main()
{
	char *v = "sdfgh%igh";
	int r = -4568;
	int	result = ft_printf(v, r);
	printf("%i", result);
}*/
