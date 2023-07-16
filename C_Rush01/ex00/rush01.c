/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:11:25 by cpujades          #+#    #+#             */
/*   Updated: 2023/07/16 21:37:32 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	found_duplicate_values(int grid[4][4], int current_cell, int val);
int	validate_restriction(int grid[4][4], int restriction[16], int cell);

int	found_duplicate_values(int grid[4][4], int current_cell, int val)
{
	int	compare_pos;

	compare_pos = -1;
	while (++compare_pos < current_cell % 4)
	{
		if (grid[current_cell / 4][compare_pos] == val)
			return (1);
	}
	compare_pos = -1;
	while (++compare_pos < current_cell / 4)
	{
		if (grid[compare_pos][current_cell % 4] == val)
			return (1);
	}
	return (0);
}

int	find_solution(int grid[4][4], int restriction[16], int cell)
{
	int	high;

	if (cell == 16)
		return (1);
	high = 0;
	while (++high < 5)
	{
		if (!found_duplicate_values(grid, cell, high))
		{
			grid[cell / 4][cell % 4] = high;
			if (validate_restriction(grid, restriction, cell))
			{
				if (find_solution(grid, restriction, cell + 1))
					return (1);
			}
			else
			{
				grid[cell / 4][cell % 4] = high;
			}
		}
	}
	return (0);
}
