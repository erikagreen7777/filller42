/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 08:37:47 by egreen            #+#    #+#             */
/*   Updated: 2018/01/18 08:39:54 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	get_players(t_board *start, char *line)
{
	if (ft_strstr(line, "$$$ exec p1 : [./egreen.filler]"))
	{
		start->my_piece = 'O';
		start->opp_piece = 'X';
	}
	else if (ft_strstr(line, "$$$ exec p2 : [./egreen.filler]"))
	{
		start->my_piece = 'X';
		start->opp_piece = 'O';
	}
}

void	get_board_size(t_board *start, char *line)
{
	if (ft_strstr(line, "Plateau 15 17:"))
	{
		start->map = 0;
		start->board_x = 15;
		start->board_y = 17;
	}
	else if (ft_strstr(line, "Plateau 24 40:"))
	{
		start->map = 1;
		start->board_x = 24;
		start->board_y = 40;
	}
	else if (ft_strstr(line, "Plateau 100 99:"))
	{
		start->map = 2;
		start->board_x = 100;
		start->board_y = 99;
	}
}

void	build_board(t_board *start, char *line)
{
	start->i = 0;
	start->board = (char **)ft_memalloc(sizeof(char *) * (start->board_x + 1));
	while ((start->i < start->board_x))
	{
		get_next_line(0, &line);
		start->board[start->i] = ft_strdup(line + 4);
		start->i++;
	}
}

void	get_piece(t_board *start, char *line)
{
	start->piece_x = get_x(line);
	start->piece_y = get_y(line);
	start->j = 0;
	start->piece = (char **)ft_memalloc(sizeof(char *) * (start->piece_x + 1));
	while ((start->j < start->piece_x))
	{
		get_next_line(0, &line);
		start->piece[start->j] = ft_strdup(line);
		start->j++;
	}
}
