/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:47:55 by cpujades          #+#    #+#             */
/*   Updated: 2023/07/16 18:40:25 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_LIB_H
# define FT_RUSH_LIB_H

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		validate_restriction(int grid[4][4], int restriction[16], int cell);
int		found_duplicate_values(int grid[4][4], int current_cell, int val);
int		find_solution(int grid[4][4], int restriction[16], int cell);

#endif 
