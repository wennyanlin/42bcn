/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:17:09 by wlin              #+#    #+#             */
/*   Updated: 2023/11/22 19:27:47 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*move_rotate(t_stack *list)
{
		t_stack	*tmp;
		t_stack	*head;

		tmp = list;
		head = list->next;
		while (list->next != NULL)
			list = list->next;
		tmp->next = NULL;
		list->next = tmp;
		return(head);
}
/*
t_stack *ra(t_stack *a)
{
	move_rotate();
	write(1, "ra\n", 3);
}*/
