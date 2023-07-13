/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:42:21 by wlin              #+#    #+#             */
/*   Updated: 2023/07/13 19:06:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int main()
{
   int x;
   int y;
   int *a;
   int *b;
   
   y = 2;
   x = 4;
   a = &x;
   b = &y;
  ft_swap(a, b);
  return (0);
}*/
