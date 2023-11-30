#include "push_swap.h"
/*
void    ps_stack_sort(t_stack **list_a, t_stack **list_b)
{
    (void)*list_b;
    //move_swap(list_a);
    //move_reverse_rotate(list_a);
    //move_push(list_a, list_b);



}*/

//void    check_cost(t_list list_a, t_list list_b)
/*
typedef struct s_move
{
	int	ra;
	int	rb;
    int	rr;
	int	rra;
	int	rrb;
	int	rrr;
    int total;
}	t_move;

int main()
{
    t_move move;

    move.ra = 123;
    move.rb = 2123;
    move.rr = 145623;
    move.rra = -13;
    move.rrb = 423;
    move.rrr = -234123;
    move.total =  move.ra + move.rb + move.rr +  move.rra + move.rrb + move.rrr;
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
	/*
	1 2 3
	1 3 2  rra 2 1 3 sa 1 2 3
	2 3 1  rra 1 2 3
	2 1 3  sa  1 2 3
	3 1 2  ra  1 2 3
	3 2 1  ra  2 1 3 sa 1 2 3
	*/
}


/*
int	main(int argc, char **argv)
{
	t_stack	*list = NULL;
	ps_stack_init(list, argv, argc);
	printf("%d", find_max_nbr(list));

}*/





















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
