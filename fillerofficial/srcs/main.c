/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:22:23 by egreen            #+#    #+#             */
/*   Updated: 2018/01/18 08:44:06 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void	free_stuff(t_board *start)
{
	ft_memdel((void*)&start->board);
	ft_memdel((void*)&start->piece);
	ft_memdel((void*)&start);
}

int			get_game_info(t_board *start)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "$$$"))
			get_players(start, line);
		if (ft_strstr(line, "Plateau"))
			get_board_size(start, line);
		if (ft_strstr(line, "    0"))
			build_board(start, line);
		if (ft_strstr(line, "Piece "))
		{
			get_piece(start, line);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}

int			analyze(t_board *start)
{
	parse_filler(start);
	if (start->flag == 1)
		return (1);
	return (0);
}

void		init_structs(t_board **start)
{
	*start = (t_board *)ft_memalloc(sizeof(t_board));
	(*start)->my_piece = '-';
	(*start)->board = NULL;
	(*start)->i = -1;
	(*start)->j = -1;
	(*start)->piece = NULL;
	(*start)->piece_coord_x = -1;
	(*start)->piece_coord_y = -1;
	(*start)->flag = 0;
}

int			main(void)
{
	t_board *start;

	init_structs(&start);
	while (get_game_info(start))
	{
		if (analyze(start) == 0)
		{
			ft_putnbr(start->coord_1);
			ft_putchar(' ');
			ft_putnbr(start->coord_2);
			start->coord_1 = 0;
			start->coord_2 = 0;
			ft_putchar('\n');
		}
		else
			ft_putstr("0 0\n");
	}
	free_stuff(start);
	return (0);
}
