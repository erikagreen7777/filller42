/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:22:23 by egreen            #+#    #+#             */
/*   Updated: 2017/12/07 10:05:14 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	free_remains(s_board *start)
{
	free_board_piece(start);
	ft_memdel((void*)&start->board);
	ft_memdel((void*)&start->piece);
	ft_memdel((void*)&start);

}

void	free_board_piece(s_board *start)
{
	start->i = -1;
	while (start->board[++start->i])
	{
		ft_strdel(&start->board[start->i]);
	}
	start->j = -1;
	while (start->piece[++start->j])
	{
		ft_strdel(&start->piece[start->j]);
	}
}

int		get_game_info(s_board *start)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "$$$"))
			get_players(start, line); // THIS WORKS
		if (ft_strstr(line, "Plateau"))
			get_board_size(start, line); //THIS WORKS
		if (ft_strstr(line, "    0"))
			build_board(start, line); //THIS WORKS
		if (ft_strstr(line, "Piece ")) {
   			get_piece(start, line); //THIS WORKS
   			return (1);
		}

		ft_strdel(&line);

	}
	return (0);
}

int		analyze(s_board *start)
{
	int i;

	i = -1;
	parse_filler(start);
	find_safe_spot(start);
	if (start->mode == 1)
	{
		while (start->piece[++i])
			fprintf(stderr, "piece:[%d] %s\n", i, start->piece[i]);
		i = -1;
		while (start->board[++i])
			fprintf(stderr, "[%d]%s\n", i, start->board[i]);
	}
	if (start->flag == 1)
		return (1);
	return (0);
}

void	init_structs(s_board **start)
{
	*start = (s_board *)ft_memalloc(sizeof(s_board));
	(*start)->my_piece = '-';
	(*start)->board = NULL;
	(*start)->i = -1;
	(*start)->j = -1;
	(*start)->piece = NULL;
	(*start)->piece_coord_x = -1;
	(*start)->piece_coord_y = -1;
	(*start)->flag = 0;
	(*start)->mode = 1;

}

int		main(void)
{
	s_board *start;

	init_structs(&start);
	while (get_game_info(start))
	{
		if (analyze(start) == 0)
		{
			ft_putnbr(start->coord_1);
			ft_putchar(' ');
			ft_putnbr(start->coord_2);
			ft_putchar('\n');
			free_board_piece(start);
		}
		else
			ft_putstr("0 0\n");
	}
	free_remains(start);
	return (0);
}


