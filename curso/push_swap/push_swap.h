/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:33:13 by wlin              #+#    #+#             */
/*   Updated: 2023/11/18 22:00:57 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
/*
typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;*/

int		is_duplicate(int argc, char **argv);
int		is_digit(int argc, char **argv);
void	write_error(void);

#endif
