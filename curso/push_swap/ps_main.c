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
	t_stack *list_a;
	t_stack *list_b;

	if (argc > 1)
	{
		ps_input_validate(argc, argv);
		list_a = NULL;
		list_a = malloc(sizeof(t_stack));
		ps_stack_init(list_a, argv, argc);
		list_b = NULL;
		sort(&list_a, &list_b);


		printf("\n\n------- SIZE  A -------\n\n");
		printf("%i", stack_size(list_a));
		printf("\n\n------- STACK A -------\n\n");
		print_stack(list_a);
		printf("\n\n------- STACK B -------\n\n");
		print_stack(list_b);
	}
	else
		write_error();
	return (0);
}

