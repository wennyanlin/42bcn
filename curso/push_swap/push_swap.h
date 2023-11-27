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
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

int		is_duplicate(int argc, char **str_b);
int		is_digit(int argc, char **argv);
int		is_integer(int argc, char **argv);
t_stack	*move_swap(t_stack *list);
t_stack	*move_rotate(t_stack *list);
t_stack	*move_reverse_rotate(t_stack *list);
void	move_push(t_stack **list_a, t_stack **list_b);
void    stack_init(t_stack *list, char **nbrs, int n);

#endif
