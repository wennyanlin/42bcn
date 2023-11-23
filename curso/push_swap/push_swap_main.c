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

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				write_error();
			j++;
		}
	}
	return (0);
}

int	is_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j + 1] >= '0' \
				&& argv[i][j + 1] <= '9')
			j++;
		else if (argv[i][j] == '\0')
			write_error();
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				write_error();
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_integer(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			write_error();
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack *list;
	t_stack	*list_a;
	t_stack	*list_b = NULL;
	int		i;

	i = 1;
	if (argc > 1)
	{
		is_duplicate(argc, argv);
		is_digit(argc, argv);
		is_integer(argc, argv);

		list = NULL;
		list = malloc(sizeof(t_stack));
		tmp = list;
		while (argc > 1)
		{
			//tmp = ft_calloc(sizeof(t_stack));
			//tmp->data = ft_atoi(argv[i]);
			//ft_stackadd_back(&list, tmp);
			list->data = ft_atoi(argv[i]);
			if (argc - 1 > 1)
			{
				list->next = malloc(sizeof(t_stack));
				list = list->next;
			}
			i++;
			argc--;
		}
		list->next = NULL;
		list = tmp;
		//tmp = list;
		/*while (list)
		{
			printf("%d\n", list->data);
			list = list->next;
		}*/

		//list = tmp;
		//list = move_swap(list);
		//list = move_rotate(list);
		//list = move_reverse_rotate(list);
		list_a = list;

		move_push(&list_a, &list_b);
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
