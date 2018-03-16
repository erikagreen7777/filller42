/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:06:35 by egreen            #+#    #+#             */
/*   Updated: 2018/01/18 09:11:31 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	assign_tilde(t_board *start)
{
	start->i = 0;
	while (start->board[start->i])
	{
		start->j = 0;
		while (start->board[start->i][start->j])
		{
			if (start->board[start->i][start->j] == '.')
				start->board[start->i][start->j] = '~';
			start->j++;
		}
		start->i++;
	}
}

void	assign_minus(t_board *start)
{
	int i;
	int j;

	i = 0;
	j = 0;
	start->col = 0;
	start->row = 0;
	i = start->i;
	while (i >= 0)
	{
		if (start->board[i][start->j] == '~' && start->col < 79)
			start->board[i][start->j] = start->col;
		i--;
		start->col++;
	}
	j = start->j;
	while (j >= 0)
	{
		if (start->board[start->i][j] == '~' && start->row < 79)
			start->board[start->i][j] = start->row;
		j--;
		start->row++;
	}
}

void	assign_plus(t_board *start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	start->col = 0;
	start->row = 0;
	i = start->i;
	while (i < start->board_x)
	{
		if (start->board[i][start->j] == '~' && start->col < 79)
			start->board[i][start->j] = start->col;
		i++;
		start->col++;
	}
	j = start->j;
	while (j < start->board_y)
	{
		if (start->board[start->i][j] == '~' && start->row < 79)
			start->board[start->i][j] = start->row;
		j++;
		start->row++;
	}
}

void	find_x(t_board *start)
{
	assign_tilde(start);
	start->i = 0;
	while (start->board[start->i])
	{
		start->j = 0;
		while (start->board[start->i][start->j])
		{
			if (start->board[start->i][start->j] == start->opp_piece || start->
					board[start->i][start->j] == start->opp_piece + 32)
			{
				assign_minus(start);
				assign_plus(start);
			}
			start->j++;
		}
		start->i++;
	}
}

int		place_piece(t_board *start)
{
	start->low_value = start->value;
	start->coord_1 = start->carry_row;
	start->coord_2 = start->carry_col;
	return (1);
}
