/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:37:21 by wlin              #+#    #+#             */
/*   Updated: 2023/07/27 17:45:42 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "a\n", 2);
		return (1);
	}
	if (argc == 2)
	{
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == 'a')
		{
			write(1, "a\n", 2);
			return (0);
		}
		else if (argv[1][i] != 'a')
		{
			write(1, "\n", 1);
			return (1);
		}
		i++;
	}
	}
	return (0);
}
