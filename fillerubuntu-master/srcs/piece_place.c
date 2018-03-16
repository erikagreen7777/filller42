#include "../filler.h"

void	find_offset(s_board *start)
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
				break;
			}
		}
		if (start->piece[start->i][start->j] == '*')
			break;
	}
	start->original_x = start->piece_coord_x;
	start->original_y = start->piece_coord_y;
	
//PRINT THE PIECE
	// start->i = -1;

	// while (++start->i < start->piece_x)
	// 	fprintf(stderr, "start->piece[%d]: %s\n", start->i, start->piece[start->i]);

// //PRINT THE BOARD
// 	start->i = -1;

// 	while (++start->i < start->board_x)
// 		fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
// //***********************
}

int can_place_both_offsets(s_board *start)
{
	start->o = -1;
	start->flag = 0;
	start->piece_coord_y -= start->offset;
	start->piece_coord_x -= start->row_offset;
	start->i = start->piece_coord_x - 1;

 	while (start->piece[++start->o] && start->board[++start->i])
	{
		start->p = -1;
		start->j = start->piece_coord_y - 1;
		while (start->piece[start->o][++start->p] && start->board[++start->j])
		{
			if (start->piece[start->o][start->p] == '*')
			{
				if (((start->i == start->original_x) && (start->j == start->original_y)) || ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece)))
					start->board[start->i][start->j] = '*';
				else 
					start->flag += 1;
			}
		}
	}
//PRINT THE BOARD
	start->i = -1;

	while (++start->i < start->board_x)
		fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
	if (start->flag > 0)
		return (1);
	return (0);
}

int can_place_row_offset(s_board *start)
{
	start->o = -1;
	start->flag = 0;
	start->piece_coord_x -= start->row_offset;
	start->i = start->piece_coord_x - 1;

	while (start->piece[++start->o] && start->board[++start->i])
	{
		start->p = -1;
		start->j = start->piece_coord_y - 1;
		while (start->piece[start->o][++start->p] && start->board[++start->j])
		{
			if (start->piece[start->o][start->p] == '*')
			{
				if ((start->i == start->piece_coord_x + start->row_offset && start->j && start->j == start->piece_coord_y) || ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece)))
					start->board[start->i][start->j] = '*';
				else 
					start->flag += 1;
			}
		}
	}
//PRINT THE BOARD
	start->i = -1;

	while (++start->i < start->board_x)
		fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
	if (start->flag > 0)
		return (1);
	return (0);
}

int can_place_offset(s_board *start)
{
	start->o = -1;
	start->flag = 0;
	start->i = start->piece_coord_x - 1;
	start->piece_coord_y -= start->offset;

	while (start->piece[++start->o] && start->board[++start->i])
	{
		start->p = -1;
		start->j = start->piece_coord_y - 1;
		while (start->piece[start->o][++start->p] && start->board[++start->j])
		{
			if (start->piece[start->o][start->p] == '*')
			{
				if (((start->j == start->original_y) && (start->i == start->original_x)) || ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece)))
					start->board[start->i][start->j] = '*';
				else
					start->flag += 1;
			}
		}
	}
//PRINT THE BOARD
	start->i = -1;

	while (++start->i < start->board_x)
		fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
	if (start->flag > 0)
		return (1);
	return (0);

}

int	can_place(s_board *start)
{
	start->o = -1;
	start->flag = 0;
	start->i = start->piece_coord_x - 1;

	while (start->piece[++start->o] && start->board[++start->i])
	{
		start->p = -1;
		start->j = start->piece_coord_y - 1;
		while (start->piece[start->o][++start->p] && start->board[++start->j])
		{
			if (start->piece[start->o][start->p] == '*')
			{
				if (((start->i == start->piece_coord_x) && (start->j == start->piece_coord_y)) || ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece)))
					start->board[start->i][start->j] = '*';
				else 
					start->flag += 1;
			}
		}
	}
//PRINT THE BOARD
	start->i = -1;

	while (++start->i < start->board_x)
		fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
	if (start->flag > 0)
		return (1);
	return (0);

}
