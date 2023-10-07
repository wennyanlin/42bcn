/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:09:21 by wlin              #+#    #+#             */
/*   Updated: 2023/10/07 18:57:42 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a,b;
	char c = 'c';

	a = ft_printf("hala %c\n", c);
	b = printf("hala %c\n", c);
	printf("ft: %d | og: %d\n", a, b);
	printf("%s\n | %d", (char *) NULL, a);
	return 0;
}

