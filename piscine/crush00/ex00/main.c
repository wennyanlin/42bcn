/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:50:42 by eliagarc          #+#    #+#             */
/*   Updated: 2023/07/09 18:42:49 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

extern void	rush(int x, int y);//extern:when a particular files need to access a variable from another file

int	main(void)// function that execute
{
	rush(1, 5);
	return (0);//execute successfully; (1)-error
}
