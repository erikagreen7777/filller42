#include "../filler.h"

void	get_players(s_board *start, char *line)
{
	if (ft_strstr(line, "$$$ exec p1 : [./egreen.filler]"))
	{
		start->my_number = 1;
		start->my_piece = 'O';
		start->opponent_number = 2;
		start->opponent_piece = 'X';
	}
	else if (ft_strstr(line, "$$$ exec p2 : [./egreen.filler]"))
	{
		start->my_number = 2;
		start->my_piece = 'X';
		start->opponent_number = 1;
		start->opponent_piece = 'O';
	}
//	fprintf(stderr, "MY NUMBER: %d\n MY PIECE: %c\n", start->my_number, start->my_piece);
}

void	get_board_size(s_board *start, char *line)
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
//   	fprintf(stderr, "MAP NUMBER: %d\nBOARD.X = %d\nBOARD.Y = %d\n", start->map, start->board_x, start->board_y);
}

void	build_board(s_board *start, char *line)
{
	start->i = 0;
	start->board = (char **)ft_memalloc(sizeof(char *) * (start->board_x + 1));
	while ((start->i < start->board_x))
	{
		get_next_line(0, &line);
		start->board[start->i] = ft_strdup(line + 4);
		start->i++;
	}
//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "THIS IS THE BOARD[%d]: %s\n", start->i, start->board[start->i]);

}


void	get_piece(s_board *start, char *line)
{
	start->piece_x = get_x(line);
	start->piece_y = get_y(line);

//	fprintf(stderr, "start.piece_x: %d\nstart.piece_y: %d\n", start->piece_x, start->piece_y);

	start->j = 0;
	start->piece = (char **)ft_memalloc(sizeof(char *) * (start->piece_x + 1));
	while ((start->j < start->piece_x))
	{
		get_next_line(0, &line);
		start->piece[start->j] = ft_strdup(line);
		start->j++;
	}	
//PRINT THE PIECE
	// start->i = -1;

	// while (++start->i < start->piece_x)
	// 	fprintf(stderr, "THIS IS THE PIECE[%d]: %s\n", start->i, start->piece[start->i]);

}

void	get_piece_height(s_board *start)
{
	int start_h = -1;
	int end_h = 0;
	int i_place_holder = 0;
	start->piece_h = 0;
	start->i = 0;
	while (start->piece[start->i])
	{
		start->j = 0;
		while (start->piece[start->i][start->j])
		{
			if ((start->piece[start->i][start->j] == '*') && start_h == -1)
			{
				start_h = start->i;
				i_place_holder = start->i;
				break;
			}
			else if ((start->piece[start->i][start->j] == '*') && (start_h < start->i))
				end_h = start->i;
			start->j++;
		}
		start->i++;
	}
	start->piece_h = (end_h - start_h) + 1;
	// fprintf(stderr, "start->piece_h: %d\n", start->piece_h);
}

void	get_piece_width(s_board *start)
{
	int start_w;
	int end_w;
	int	w_place_holder;
	w_place_holder = -1;
	end_w = 0;
	start_w = -1;
	start->i = 0;
	while (start->piece[start->i])
	{
		start->j = 0;
		while (start->piece[start->i][start->j])
		{
			if (start->piece[start->i][start->j] == '*')
			{
				if (start_w == -1)
				{
					start_w = start->j;
					w_place_holder = start->j;
				
				}
				if (start->j < start_w)
					start_w = start->j;
				if (start->j > end_w)
					end_w = start->j;	
				// fprintf(stderr, "start_w: %d\tw_place_holder: %d\tend_w: %d\n", start_w, w_place_holder, end_w);
			}
			start->j++;
		}
		start->i++;
	}
	start->piece_w = (end_w - start_w) + 1;
	// fprintf(stderr, "start->piece_w: %d\n", start->piece_w);
}

