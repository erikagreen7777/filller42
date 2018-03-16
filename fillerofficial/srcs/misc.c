/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:13:02 by egreen            #+#    #+#             */
/*   Updated: 2018/01/18 09:22:47 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int			add_row(t_board *start)
{
	int		e;
	int		f;

	start->carry_row = 0;
	e = start->i;
	f = start->j;
	start->row_min = 0;
	while (e < (start->i + 1))
	{
		f = 0;
		while (f < start->board_y)
		{
			start->row_min += start->board[start->i][start->j];
			start->carry_row = start->i - start->row_offset;
			f++;
		}
		e++;
	}
	return (0);
}

void		find_offset(t_board *start)
{
	start->offset = 0;
	start->row_offset = 0;
	start->i = -1;
	while (start->piece[++start->i])
	{
		start->j = -1;
		while (start->piece[start->i][++start->j])
		{
			if (start->piece[start->i][start->j] == '*')
			{
				start->offset = start->j;
				start->row_offset = start->i;
				break ;
			}
		}
		if (start->piece[start->i][start->j] == '*')
			break ;
	}
}

int			add_col(t_board *start)
{
	int		e;
	int		f;

	e = 0;
	f = start->j;
	start->carry_col = 0;
	start->col_min = 0;
	while (f < (start->j + 1))
	{
		while (e < start->board_x)
		{
			start->col_min += start->board[start->i][start->j];
			start->carry_col = start->j - start->offset;
			e++;
		}
		f++;
	}
	return (0);
}
