/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:55:37 by apavlovs          #+#    #+#             */
/*   Updated: 2018/11/04 15:09:28 by apavlovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H

extern int	g_successful;
int			box_3x3(int nbr, int box[9][9], int row, int column);//this is a 3x3 box that moves that creates an index at the same time
int			vh_check(int nbr, int box[9][9], int row, int column);//this checks like across and line down
void		ft_putchar(char c);
void		sudoku_grid(int box[9][9]);//this is the grid we print for the 9x9
void		main_solution(int box[9][9]);//this is the main function

#endif
