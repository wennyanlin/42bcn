/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:25:31 by eliagarc          #+#    #+#             */
/*   Updated: 2023/07/09 18:20:31 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

//char c is character to be printed, int aux is a helper, type number
void	ft_putchar(char c, int aux) 
{
	if (aux == 0)
	{
		write(1, &c, 1); //print character *write(1-output;0-input;2-error, num. bytes)
	}
	else
	{
		write(1, &c, 1);
		write(1, " \n", 2);//also starting below a newline
	}
}
