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

void	print_stack(t_stack *list)
{
	while (list)
	{
		printf("\nnode: %d - %d", list->data, list->index);
		list = (list)->next;
	}
}



int	main(int argc, char **argv)
{
	t_stack *list_a;
	t_stack *list_b;
	char	**input = argv;

	if (argc > 1)
	{
		if (argc == 2)
			input = ps_split(argv[1], ' ');
		ps_input_validate(argc, input);
		list_a = NULL;
		list_a = malloc(sizeof(t_stack));
		ps_stack_init(list_a, input, argc);
		list_b = NULL;
		if (is_stack_sorted(&list_a) == true)
			return (0);
		else
		{
			if (stack_size(list_a) == 2)
			{
				move_swap(&list_a);
				return (0);
			}
			else if (stack_size(list_a) == 3)
			{
				sort_3(&list_a);
				return (0);
			}
			else
				sort(&list_a, &list_b);
		}
		printf("\n\n------- STACK A -------\n\n");
		print_stack(list_a);
		printf("\n\n------- STACK B -------\n\n");
		print_stack(list_b);
	}
	return (0);
}

