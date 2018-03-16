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
	// start->original_x = start->piece_coord_x;
	// start->original_y = start->piece_coord_y;
	// start->math_x = 0;
	// start->math_y = 0;


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
static void vanilla(s_board *start)
{
				if ((start->j == start->original_y) && (start->i == start->original_x))
					start->board[start->i][start->j] = '*';
				else if ((start->board[start->i][start->j] == start->my_piece) || (start->board[start->i][start->j] == start->opponent_piece))
				{
					start->piece_offset_x = start->i;
					start->piece_offset_y = start->j;
					// fprintf(stderr, "piece_offset_x: %d\tpiece_offset_y: %d\n", start->piece_offset_x, start->piece_offset_y);
					start->math_x = start->piece_offset_x - start->original_x;
					start->math_y = start->piece_offset_y - start->original_y;
					// fprintf(stderr, "math_x: %d\tmath_y: %d\n", start->math_x, start->math_y);
				}
				if ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece))
					start->board[start->i][start->j] = '*';
				if (start->board[start->original_x][start->original_y] != '*')
					start->flag += 1;
				else
					start->flag += 1;
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
				vanilla(start);
			}
		}
	}
//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
	if ((start->math_x > 0 || start->math_y > 0) || (start->board[start->original_x][start->original_y] != '*'))
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
				vanilla(start);
			}
		}
	}

//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
	if ((start->math_x > 0 || start->math_y > 0) || (start->board[start->original_x][start->original_y] != '*'))
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
				vanilla(start);
			}
		}
	}

//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
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
	start->my_piece_flag = 0;


	while (start->piece[++start->o] && start->board[++start->i])
	{
		start->p = -1;
		start->j = start->piece_coord_y - 1;
		while (start->piece[start->o][++start->p] && start->board[++start->j])
		{
			if (start->piece[start->o][start->p] == '*')
			{
				vanilla(start);
			}
		}
	}

// //PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
	if ((start->math_x > 0 || start->math_y > 0) || (start->board[start->original_x][start->original_y] != '*'))
		return (1);
	else 
		return (0);

}






