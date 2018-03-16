/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:31:48 by egreen            #+#    #+#             */
/*   Updated: 2018/01/18 08:58:50 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int			get_x(char *line)
{
	int		x;
	int		ret;

	ret = 0;
	x = 0;
	while (line[x] != ' ')
		x++;
	x++;
	ret = ft_atoi(line + x);
	return (ret);
}

int			get_y(char *line)
{
	int		y;
	int		ret;
	int		spaces;

	y = 0;
	ret = 0;
	spaces = 0;
	while (line[y])
	{
		if (spaces == 2)
			break ;
		if (line[y] == ' ')
			spaces++;
		y++;
	}
	ret = ft_atoi(line + y);
	return (ret);
}

void		change_my_piece(t_board *start)
{
	start->i = -1;
	while (start->board[++start->i])
	{
		start->j = -1;
		while (start->board[start->i][++start->j])
		{
			if (start->board[start->i][start->j] == start->my_piece)
				start->board[start->i][start->j] = '|';
		}
	}
}

static void	algorithm(t_board *start)
{
	int		i_hold;
	int		j_hold;

	i_hold = start->i;
	j_hold = start->j;
	add_row(start);
	start->i = i_hold;
	start->j = j_hold;
	add_col(start);
	if (start->row_min < start->row_min_val)
		start->row_min_val = start->row_min;
	if (start->col_min < start->col_min_val)
		start->col_min_val = start->col_min;
	start->value = start->row_min_val + start->col_min_val;
}

int			check_data(t_board *start, int x, int y)
{
	if ((start->i - start->o) + x >= start->board_x || (start->j - start->p)
			+ y >= start->board_y || (start->i - start->o) + x
			< 0 || (start->j - start->p) + y < 0)
		return (0);
	else if (start->board[(start->i - start->o) + x][(start->j - start->p) +
			y] == start->my_piece || start->board[(start->i - start->o) + x]
			[(start->j - start->p) + y] == start->my_piece + 32)
		start->touch++;
	else if (start->board[(start->i - start->o) + x][(start->j - start->p)
			+ y] == start->opp_piece || start->board[(start->i - start->o)
			+ x][(start->j - start->p) + y] == start->opp_piece + 32)
		return (0);
	else if ((start->board[(start->i - start->o) + x][(start->j - start->p)
				+ y] > -1 && start->board[(start->i - start->o) + x][(start->j
				- start->p) + y] < 79) || (start->board[(start->i - start->o)
				+ x][(start->j - start->p) + y] == '~'))
		algorithm(start);
	return (1);
}
