/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:43:23 by wlin              #+#    #+#             */
/*   Updated: 2023/11/23 11:57:13 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_push(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;
	if (list_a)
	{
		if (list_b)
		{
			*list_b = *list_a;
			*list_a = (*list_a)->next;
			(*list_b)->next = NULL;
		}
		else
		{
			tmp = *list_b;
			list_b = list_a;
			*list_a = (*list_a)->next;
			(*list_b)->next = tmp;
		}
	}
}