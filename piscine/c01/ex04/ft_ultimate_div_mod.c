/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:02:10 by wlin              #+#    #+#             */
/*   Updated: 2023/07/18 12:35:19 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	i;
	int	j;

	i = *a;
	j = *b;
	*a = i / j;
	*b = i % j;
}

/*
int	main()
{
	int l;
	int m;
	int *a;
	int *b;
	l = 15;
	m = 2;
	a = &l;
	b = &m;
	ft_ultimate_div_mod(a, b);
	return (0);
}
*/
