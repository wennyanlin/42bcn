/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:15:32 by wlin              #+#    #+#             */
/*   Updated: 2023/11/23 11:31:51 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *list;
	t_stack *list_a;
	t_stack *list_b;

	if (argc > 1)
	{
		ps_input_validate(argc, argv);
		list = NULL;
		list = malloc(sizeof(t_stack));
		ps_stack_init(list, argv, argc);

		//list = move_swap(list);
		//list = move_rotate(list);
		//list = move_reverse_rotate(list);

		list_a = list;
		list_b = NULL;
		list = move_push(&list_a, &list_b);
		printf("------- STACK A -------\n\n");
		while (list_a)
		{
			printf("%d\n", list_a->data);
			list_a = list_a->next;
		}
		printf("------- STACK B -------\n\n");
		while (list_b)
		{
	
			printf("%d\n", list_b->data);
			list_b = list_b->next;
		}
	}
	return (0);
}
