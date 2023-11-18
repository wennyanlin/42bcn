/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:17 by wlin              #+#    #+#             */
/*   Updated: 2023/11/18 01:07:58 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else
		return (is_duplicate(argc, argv));
		
}
