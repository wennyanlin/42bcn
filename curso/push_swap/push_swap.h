/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:33:13 by wlin              #+#    #+#             */
/*   Updated: 2023/11/23 11:16:46 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

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

typedef struct s_stack
{
	int				data;
	int				index;

	struct s_stack	*next;
	struct s_move	curr_move;
}	t_stack;

int		is_duplicate(int argc, char **str_b);
int		is_digit(int argc, char **argv);
int		is_integer(int argc, char **argv);
void	write_error(void);
void	move_swap(t_stack **list);
void	move_rotate(t_stack **list);
void	move_reverse_rotate(t_stack **list);
void	move_push(t_stack **list_a, t_stack **list_b);
void    ps_input_validate(int  n, char **nbrs);
//void    ps_stack_sort(t_stack **list_a, t_stack **list_b);
void    ps_stack_init(t_stack *list, char **nbrs, int n);
int		find_max_nbr(t_stack *list);
void	sort_3(t_stack **list);
void	print_stack(t_stack *list);
int		stack_size(t_stack *list_a);
void	sort(t_stack **list_a, t_stack **list_b);
void	initialize_indexes(t_stack *list);
t_move	calculate_moving_cost(int list_a_size, int list_b_size, int a_index, int b_index);

#endif
