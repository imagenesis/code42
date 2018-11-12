/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:54:43 by apavlovs          #+#    #+#             */
/*   Updated: 2018/11/04 12:54:44 by apavlovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>

int		box_3x3(int nbr, int box[9][9], int row, int column)
{
	int cols;
	int rows;
	int i;
	int b;

	cols = 0;
	rows = 0;
	cols = (column / 3) * 3;
	rows = (row / 3) * 3;
	i = 0;
	while (i < 3)
	{
		b = 0;
		while (b < 3)
		{
			if (box[rows + i][cols + b] == nbr)
				return (0);//gere we are checking for empty boxes in the gird
			b++;
		}
		i++;
	}
	return (1);
}

int		vh_check(int nbr, int box[9][9], int row, int column)
{
	int i;

	i = 0;
	while (i <= 8)
	{
		if (box[row][i] == nbr && i != column)
			return (0);
		i++;
	}
	i = 0;
	while (i <= 8)
	{
		if (box[i][column] == nbr && i != row)
			return (0);
		i++;
	}
	return (1);
}
