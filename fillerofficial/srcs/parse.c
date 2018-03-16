/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:33:53 by egreen            #+#    #+#             */
/*   Updated: 2018/01/18 09:06:04 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	check_board_to_piece(t_board *start)
{
	int		x;
	int		y;

	start->touch = 0;
	start->value = 0;
	x = start->o - 1;
	y = start->p - 1;
	while (start->piece[++x])
	{
		y = -1;
		while (start->piece[x][++y])
		{
			if (start->piece[x][y] == '*')
				if (!check_data(start, x, y))
					return (0);
		}
	}
	if (start->touch == 1)
	{
		if (start->value < start->low_value &&
			place_piece(start))
			return (1);
	}
	return (0);
}

static void	compare_backwards(t_board *start)
{
	start->i = start->board_x;
	while (--start->i)
	{
		start->j = start->board_y;
		while (--start->j)
		{
			if (check_board_to_piece(start))
				;
		}
	}
}

static void	compare_board(t_board *start)
{
	start->i = -1;
	while (start->board[++start->i])
	{
		start->j = -1;
		while (start->board[start->i][++start->j])
		{
			if (check_board_to_piece(start))
				;
		}
	}
}

void		find_safe_spot(t_board *start)
{
	start->o = -1;
	while (start->piece[++start->o])
	{
		start->p = -1;
		while (start->piece[start->o][++start->p])
		{
			if (start->piece[start->o][start->p] == '*')
			{
				if (((start->my_piece == 'O' && start->map == 0) || start->map
					== 1) || (start->my_piece == 'X' && start->map == 2))
					compare_backwards(start);
				if (((start->my_piece == 'X' && start->map == 0) || start->map
					== 1) || (start->my_piece == 'O' && start->map == 2))
					compare_board(start);
				return ;
			}
		}
	}
}

void		parse_filler(t_board *start)
{
	find_x(start);
	find_offset(start);
	start->low_value = 2147483647;
	start->row_min_val = 2147483647;
	start->col_min_val = 2147483647;
	find_safe_spot(start);
}
