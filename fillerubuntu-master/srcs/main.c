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

static void init_struct(s_board **start)
{
	*start = (s_board *)ft_memalloc(sizeof(s_board));
}
int main()
{
	int ret;
	char *line;
	s_board	 *start;

	
	// start->opponent_number = 0;
	// start->my_number = 0;
	// start->my_piece = ' ';
	// start->opponent_piece = ' ';
	


	init_struct(&start);
	// while (1)
	// {
	while ((ret = get_next_line(0, &line)))
	{
		if (ret > 0)
		{
			get_meta_data(start, line);
			// if (ft_strstr(line, "$$$"))
			// 	get_players(start, line);
			// if (ft_strstr(line, "Plateau"))
			// 	get_board_size(start, line);
			// if (ft_strstr(line, "    0"))
			// 	build_board(start, line);
			// if (ft_strstr(line, "Piece "))
		 //   		get_piece(start, line);

			parse_filler(start);
			ft_strdel(&line);
		}
   	}
   		// parse_filler(start);
   	// }




	return (0);
}


