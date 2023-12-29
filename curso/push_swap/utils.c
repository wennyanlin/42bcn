#include "push_swap.h"
/*
int	find_min_nbr(t_stack *list)
{
	int	min_nbr;

	min_nbr = list->data;
	while (list)
	{
		if (list->data < min_nbr)
			min_nbr = list->data;
		list = list->next;
	}
	return (min_nbr);
}*/

int	find_max_nbr(t_stack *list)
{
	int max_nbr;

	max_nbr = list->data;
	while (list)
	{
		if (list->data > max_nbr)
			max_nbr = list-> data;
		list = list->next;
	}
	return (max_nbr);
}

int	stack_size(t_stack *list_a)
{
	int	i;

	i = 0;
	while (list_a)
	{
		i++;
		list_a = (list_a)->next;
	}
	return (i);
}

void	initialize_indexes(t_stack *list)
{
	int	index;

	index = 0;
	while (list)
	{
		list->index = index;
		index++;
		list = list->next;
	}
}
