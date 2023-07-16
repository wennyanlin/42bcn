/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:43:41 by cpujades          #+#    #+#             */
/*   Updated: 2023/07/17 00:41:53 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		correct_length(char str[]);
int		structure_verification(char str[]);
int		find_solution(int grid[4][4], int restriction[16], int cell);
void	fill_array(int arr[16], const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

// Paints an array with double dimensions with sizes 4 and 4, it just accepts arrays[4][4]
void	print_grid_4(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar(grid[row][col] + '0');
			if (col < 3)
				ft_putchar(' ');
			++col;
		}
		ft_putchar('\n');
		++row;
	}
}


int	verify_input(int argc, char *argv[]) // step 1 validate the input
{
	if (argc != 2) // check then number of arguments must be 2, the name of the executable plus the parameter that we send "1 2 2 3 2 3....."
	{
		return (0);
	}
	if (!correct_length(argv[1])) // step 2  validate the length this [1] means position 1, not the first argument. so means that is in position 2
	{
		return (0);
	}
	if (structure_verification (argv[1]) == 0)
	{
		return (0);
	}
	return (1);
}

//entry point - 0 step
int	main(int argc, char *argv[]) 
{
	int	restrictions[16];
	int	grid[4][4];

	if (verify_input(argc, argv) == 0) //first - step
	{
		ft_putstr("Error\n");
		return (0);
	}
	fill_array(restrictions, argv[1]);
	if (find_solution(grid, restrictions, 0))
	{
		print_grid_4(grid);
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (0);
}
