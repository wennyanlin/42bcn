/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:19:13 by wlin              #+#    #+#             */
/*   Updated: 2023/11/22 21:36:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *list)
{
	while (list)
	{
		printf("\n%d->index:%d\n ", list->data, list->index);
		list = (list)->next;
	}
}

void	move_reverse_rotate(t_stack **list)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *list;
	while ((*list)->next->next != NULL)
		*list = (*list)->next;
	tmp = (*list)->next;
	(*list)->next = NULL;
	tmp->next = head;
	*list = tmp;
}
