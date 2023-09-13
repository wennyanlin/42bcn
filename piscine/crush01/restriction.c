/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restriction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:49:29 by cpujades          #+#    #+#             */
/*   Updated: 2023/07/16 21:37:37 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_left_view(int grid[4][4], int restriction[16], int cell )
{
	int	col;
	int	max_high;
	int	view_count;

	col = -1;
	max_high = 0;
	view_count = 0;
	if (cell % 4 != 3)
		return (1);
	while (++col < 4) 
	{
		if (grid[cell / 4][col] > max_high)
		{
			max_high = grid[cell / 4][col];
			++view_count;
		}
	}
	if (restriction[8 + cell / 4] == view_count)
		return (1);
	return (0);
}

int	validate_right_view(int grid[4][4], int restriction[16], int cell)
{
	int	col;
	int	max_high;
	int	view_count;

	col = 4;
	max_high = 0;
	view_count = 0;
	if (cell % 4 != 3)
		return (1);
	while (--col >= 0)
	{
		if (grid[cell / 4][col] > max_high)
		{
			max_high = grid[cell / 4][col];
			++view_count;
		}
	}
	if (restriction[12 + cell / 4] == view_count)
		return (1);
	return (0);
}

int	validate_top_view(int grid[4][4], int restriction[16], int cell)
{
	int	row;
	int	max_high;
	int	view_count;

	row = -1;
	max_high = 0;
	view_count = 0;
	if (cell / 4 != 3)
		return (1);
	while (++row < 4)
	{
		if (grid[row][cell % 4] > max_high)
		{
			max_high = grid[row][cell % 4];
			++view_count;
		}
	}
	if (restriction[0 + cell % 4] == view_count)
		return (1);
	return (0);
}

int	validate_bottom_view(int grid[4][4], int restriction[16], int cell)
{
	int	row;
	int	max_high;
	int	view_count;

	row = 4;
	max_high = 0;
	view_count = 0;
	if (cell / 4 != 3)
		return (1);
	while (--row >= 0)
	{
		if (grid[row][cell % 4] > max_high)
		{
			max_high = grid[row][cell % 4];
			++view_count;
		}
	}
	if (restriction[4 + cell % 4] == view_count)
		return (1);
	return (0);
}

int	validate_restriction(int grid[4][4], int restriction[16], int cell)
{
	if (!validate_left_view(grid, restriction, cell))
		return (0);
	if (!validate_right_view(grid, restriction, cell))
		return (0);
	if (!validate_top_view(grid, restriction, cell))
		return (0);
	if (!validate_bottom_view(grid, restriction, cell))
		return (0);
	return (1);
}
