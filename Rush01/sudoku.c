/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:32:36 by apavlovs          #+#    #+#             */
/*   Updated: 2018/11/04 11:32:39 by apavlovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>

void	sudoku_grid(int box[9][9])
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (i < 9)
	{
		while (b < 9)
		{
			ft_putchar(box[i][b] + '0');
			if (b < 8)
				ft_putchar(' ');
			b++;
		}
		ft_putchar('\n');
		b = 0;
		i++;
	}
}

void	main_solution(int box[9][9])
{
	int row;
	int column;
	int i;

	row = 0;
	column = 0;
	i = 1;
	while (box[row][column] != 0)
	{
		if (row == 8)
		{
			row = 0;
			column++;
			if (column == 9)
			{
				g_successful = 1;
				return ;
			}
		}
		else
			row++;
	}
	while (i < 10)
	{
		if (box_3x3(i, box, row, column) && vh_check(i, box, row, column))
		{
			box[row][column] = i;
			main_solution(box);
			if (g_successful)
				return ;
		}
		i++;
	}
	box[row][column] = 0;
	return ;
}
