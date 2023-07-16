/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:43:41 by cpujades          #+#    #+#             */
/*   Updated: 2023/07/15 01:48:03 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_lib.h"

//void	ft_putstr(char *str);
//void	ft_putchar(int c);


int main(int argc, char *argv[])
{
	if (argc < 2){
		ft_putstr("not enough input argument\n");
		return (0);
	}

	//char *str;
	//str = argv[1];
	//
	int col_up[4];
	int col_down[4];
	int row_left[4];
	int row_right[4];
	while (*argv[1])
	{
		ft_putchar(*argv[1]);	
		++argv[1];
	}
		ft_putchar('\n');	

	ft_putstr("end of main\n");

	

	return (0);	
}
