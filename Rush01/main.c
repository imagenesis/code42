/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:22:53 by apavlovs          #+#    #+#             */
/*   Updated: 2018/11/04 11:35:11 by apavlovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int g_successful = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		valid_arg(char *arg)
{
	int i;

	i = 0;
	while ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '.')
		i++;
	if (i != 9)
		return (0);
	else
		return (1);
}

int		args_valid(int argc, char *args[])
{
	if (argc - 1 != 9)
		return (ft_error());
	while (argc > 1)
	{
		if (!valid_arg(args[argc - 1]))
			return (ft_error());
		argc--;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	static int			box[9][9];
	static int			i[2];

	if (args_valid(argc, argv))
	{
		while (i[0] < 9)
		{
			i[1] = -1;
			while (++i[1] < 9)
			{
				if (argv[i[0] + 1][i[1]] == '.')
					box[i[0]][i[1]] = 0;
				else
					box[i[0]][i[1]] = argv[i[0] + 1][i[1]] - '0';
			}
			i[0]++;
		}
		main_solution(box);
	}
	else
		return (0);
	if (g_successful == 1)
		sudoku_grid(box);
	else
		return (ft_error());
	return (0);
}
