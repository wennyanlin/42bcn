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

t_stack	*move_reverse_rotate(t_stack *list)
{
	t_stack	*head;
	t_stack	*tmp;

	head = list;
	while (list->next->next != NULL)
		list = list->next;
	tmp = list->next;
	list->next = NULL;
	list = head;
	tmp->next = head;
	return (tmp);
}
