#include "push_swap.h"

int	push_a_to_b(int list_a_size, int list_b_size, t_stack **list_a, t_stack **list_b)
{
	while (list_a_size > 3)
	{
		move_push(list_a, list_b);
		list_a_size--;
		list_b_size++;
		initialize_indexes(*list_a);
		initialize_indexes(*list_b);

		printf("\n------ stack b --");
		print_stack(*list_b);
		printf("\n-----------------\n");
		//find_lowercost_node(*list_a, *list_b, list_a_size, list_b_size);
		print_moves(find_lowercost_node(*list_a, *list_b, list_a_size, list_b_size));
		//find_target_node((*list_a)->data, *list_b);
		//calculate_moving_cost(list_a_size, list_b_size, 2, 3);
	}
	return (list_b_size);
}

t_move	find_lowercost_node(t_stack *list_a, t_stack *list_b, int list_a_size, int list_b_size)
{
	t_move	lowercosts;
	t_move	costs;
	int		target_node_index;

	lowercosts.total = -1;
	while (list_a)
	{
		initialize_indexes(list_a);
		initialize_indexes(list_b);
		target_node_index = find_target_node(list_a->data, list_b);
		costs = calculate_moving_cost(list_a_size, list_b_size, list_a->index, target_node_index);
		if (lowercosts.total != -1 && costs.total < lowercosts.total)
			lowercosts = costs;
		print_moves(costs);
		list_a = list_a->next;
	}
	return (lowercosts);
}
//loop through the list until we get all the node's cost
//initialize index
//find target node and calculate the cost
//compare and find the cheapest cost node
//


void	print_moves(t_move test_move)
{
	printf("Total move: %d, ra: %d, rra: %d, rb: %d, rrb: %d\n", test_move.total, test_move.ra, test_move.rra, test_move.rb, test_move.rrb);
}

int	find_target_node(int a_node, t_stack *list_b)
{
	t_stack	*target_node;
	t_stack	*curr_node;

	target_node = list_b;
	while (list_b)
	{
		curr_node = list_b;
		if (curr_node->data < a_node)
		{
			//1)if we have a biggest node and we find a small node
			//2) if we have a small and find even bigger small node.
			if (target_node->data > a_node || curr_node->data > target_node->data)
				target_node = curr_node;
		}
		else
		{
			//if we find the the node is biggest than target and a_node, which is the biggest node.
			if (target_node->data > a_node && curr_node->data > target_node->data)
				target_node = curr_node;
		}
		list_b = list_b->next;
	}
	printf("\n==> a_node : %d -> target node: %d - %d\n\n", a_node, target_node->data, target_node->index);
	return (target_node->index);
}


t_move	calculate_moving_cost(int list_a_size, int list_b_size, int a_index, int b_index)
{
	int 	middle_line_a;
	int 	middle_line_b;
	t_move	move;

	move.ra = 0;
	move.rb = 0;
	move.rr = 0;
	move.rra = 0;
	move.rrb = 0;
	move.rrr = 0;

	middle_line_a = list_a_size / 2;
	middle_line_b = list_b_size / 2;
	if (a_index <= middle_line_a)
		move.ra = a_index;
	else
		move.rra = list_a_size - a_index;
	if (b_index <= middle_line_b)
		move.rb = b_index;
	else
		move.rrb = list_b_size - b_index;
	move.total = move.ra + move.rb + move.rr + move.rra + move.rrb + move.rrr;
	return (move);
}

void	sort_3(t_stack **list)
{
	int	max_nbr;
//check size
		max_nbr = find_max_nbr(*list);
		if ((*list)->data == max_nbr)
			move_rotate(list);
		else if ((*list)->next->data == max_nbr)
			move_reverse_rotate(list);
		if ((*list)->data > (*list)->next->data)
			move_swap(list);
}

void	sort(t_stack **list_a, t_stack **list_b)
{
	int	list_a_size;
	int	list_b_size;

	list_a_size = stack_size(*list_a);
	list_b_size = stack_size(*list_b);
	list_b_size = push_a_to_b(list_a_size, list_b_size, list_a, list_b);
	//printf("after 1r loop\n\n");
	sort_3(list_a);
	initialize_indexes(*list_a);
	initialize_indexes(*list_b);
	while (list_b_size > 0)
	{
		//printf("enter 2n loop\n\n");
		move_push(list_b, list_a);
		list_a_size++;
		list_b_size--;
		initialize_indexes(*list_a);
		initialize_indexes(*list_b);

	}
}






















//create a function to find the optimized node to move

/*
We want to push elements from A to B whilst
maintaining B sorted from highest to lowest.
Once all elements are in B, we push them back to A (pa until B is empty)
The result will be all elements sorted from smallest to biggest in A.

When head A is bigger than head B
    We can compare the top two elements of A and B.
    If head of A is > head B then
        head of A should be pushed on top of B (pb)

When head A is smaller than Min B
    We can also keep track of the smallest element in B, Min B
    If head of A is < last B then
        head of A should be at the bottom of B (pb & rb)
        and we update the Min B value to be the new Min

What if it isn't the smallest or biggest? i.e. what if it is in the middle?

When head A is in the middle
    When the top of A is in the middle, we need to find its spot in B and push it
    We can find the spot with the following:
    1. compare head of A to head of B
    2. if head A > head B then push to B and go to 4.
    3. else repeat from 1.
    4. undo all the rotations from the steps above

    for example:
    1. is 6 > 9? No, rotate B
    2. is 6 > 7? No, rotate B
    3. is 6 > 3? Yes, push B
    4. undo all rotations (there were 2 rotations)

    Total, it took 5 operations (2 rb, 1 pb, 2 rrb)

        1           2           3         4          5
        rb          rb         pb         rrb        rrb
    A  B   ->   A  B   ->   A  B  ->   A  B  ->   A  B  ->   A  B
    ----   ->   ----   ->   ----  ->   ----  ->   ----  ->   ----
    6  9   ->   6  7   ->   6  3  ->   2  6  ->   2  7  ->   2  9
    2  7   ->   2  3   ->   2  2  ->   3  3  ->   3  6  ->   3  7
    3  3   ->   3  2   ->   3  9  ->      2  ->      3  ->      6
       2   ->      9   ->      7  ->      9  ->      2  ->      4
                                          7          9          3


*/
