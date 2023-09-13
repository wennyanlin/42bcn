/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:00:42 by wlin              #+#    #+#             */
/*   Updated: 2023/07/20 17:54:01 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = temp;
		i++;
		size--;
	}
}
/*
int main()
{
	
	int i = 0;
	int arr[] = {1, 2, 3, 4, 5};

	ft_rev_int_tab(arr, 5);
	
	while (i < 5)
	{
	
		printf("%d", arr[i]);

		i++;
	}
}
*/
