/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:23:51 by eliagarc          #+#    #+#             */
/*   Updated: 2023/07/09 19:30:57 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>//code's entry point to various constant, type and function declaration

//static-have property of preserving their value even out of scope
static int	g_row = 0;
static int	g_col = 0;

extern void	ft_putchar(char c, int aux);

void	o(int x, int y)
{
	if ((g_col == (x - 1)) && ((y == 1) || (g_row == 0))) //o-(0,0);
	{
		ft_putchar('o', 1);
	}
	else
	{
		if (((g_col == 0) && (g_row == 0)) 
			|| ((g_col == 0) && (g_row == (y - 1))) 
			|| ((g_col == (x - 1)) && (g_row == (y - 1))))
		{
			if (x == 1)
			{
				ft_putchar('o', 1);
			}
			else
			{
				ft_putchar('o', 0);
			}
		}
	}
}

void	dash_char(int x, int y)
{
	if (((g_row == 0) || (g_row == (y - 1))) 
		&& ((g_col > 0) && (g_col < (x - 1))))
	{
		ft_putchar('-', 0);
	}
}

void	pipe_char(int x, int y)
{
	if (((g_row > 0) && (g_row < (y - 1))) && (x == 1))
	{
		ft_putchar('|', 1);
	}
	else
	{
		if ((g_col == 0) && ((g_row > 0) && (g_row < (y - 1))))
		{
			ft_putchar('|', 0);
		}
		if ((g_col == (x - 1)) && (((g_row > 0) && (g_row < (y - 1)))))
		{
			ft_putchar('|', 1);
		}
	}
}

void	space(int x, int y)
{
	if (((g_row != 0) && (g_row != (y - 1))) 
		&& ((g_col != 0) && (g_col != (x - 1))))
	{
		ft_putchar(' ', 0);
	}
}

void	rush(int x, int y)//it's called firstly in the main.c, gradually calling ather function one by one
{
	while (g_row < y)//while the row is less than y (giving argument)
	{
		while (g_col < x)//while the column is less than x (giving argument)
		{
			o(x, y);
			dash_char(x, y);
			pipe_char(x, y);
			space(x, y);
			g_col++;
		}
		g_col = 0;//when all the function called once, come back to the top position
		g_row++;//row increase 1
	}
}
