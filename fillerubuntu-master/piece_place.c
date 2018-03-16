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
				// fprintf(stderr, "offset: %d\nrow_offset: %d\n", offset, row_offset);
				break;
			}
		}
		if (start->piece[start->i][start->j] == '*')
			break;
	}
	
//PRINT THE PIECE
	// start->i = -1;

	// while (++start->i < start->piece_x)
	// 	fprintf(stderr, "start->piece[%d]: %s\n", start->i, start->piece[start->i]);

// //PRINT THE BOARD
	start->i = -1;

	while (++start->i < start->board_x)
		fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
//***********************
}

int can_place_both_offsets(s_board *start)
{
	start->o = -1;
	start->flag = 0;
	start->original_y = start->piece_coord_y;
	start->original_x = start->piece_coord_x;
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
					;
				else 
					start->flag += 1;
			}
		}
	}
	if (start->flag > 0)
		return (1);
	return (0);
}


// int can_place_both_offsets(s_board *start)
// {
// 	int o;
// 	int p;
// 	int	original_y;
// 	int original_x;

// 	o = -1;
// 	start->flag = 0;
// 	original_y = start->piece_coord_y;
// 	original_x = start->piece_coord_x;
// 	start->piece_coord_y -= start->offset;
// 	start->piece_coord_x -= start->row_offset;
// 	start->i = start->piece_coord_x - 1;

//  	while (start->piece[++o] && start->board[++start->i])
// 	{
// 		p = -1;
// 		start->j = start->piece_coord_y - 1;
// 		while (start->piece[o][++p] && start->board[++start->j])
// 		{
// 			if (start->piece[o][p] == '*')
// 			{
// 				if ((start->i == original_x) && (start->j == original_y))
// 					fprintf(stderr, "IT'S THE FIRST ONE WITH ROW_AND_OFFSET start->i: %d start->j: %d\n", start->i, start->j);
// 				else if ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece))
// 					fprintf(stderr, "IT'S COOL in function row_and_offset: start->i: %d start->j: %d\n", start->i, start->j);
// 				else 
// 				{
// 					start->flag += 1;
// 					fprintf(stderr, "NO in function with row_and_offset: start->i: %d start->j: %d piece_coord_x: %d piece_coord_y: %d\n", start->i, start->j, start->piece_coord_x, start->piece_coord_y);
// 				}
// 			}
// 		}
// 	}
// 	if (start->flag > 0)
// 	{
// 		fprintf(stderr, "FLAG: %d\n", start->flag);
// 		return (0);
// 	}
// 	fprintf(stderr, "ALL GOOD ON THE FLAG: %d\n", start->flag);
// 	return (1);
// }

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
					;
				else 
					start->flag += 1;
			}
		}
	}
	if (start->flag > 0)
		return (1);
	return (0);
}

// int can_place_row_offset(s_board *start)
// {
// 	int o;
// 	int p;
// 	int original_x;
// 	int	original_y;

// 	o = -1;
// 	start->flag = 0;
// 	original_y = start->piece_coord_y;
// 	original_x = start->piece_coord_x;
// 	start->piece_coord_x -= start->row_offset;
// 	start->i = start->piece_coord_x - 1;

// 	while (start->piece[++o] && start->board[++start->i])
// 	{
// 		p = -1;
// 		start->j = start->piece_coord_y - 1;
// 		while (start->piece[o][++p] && start->board[++start->j])
// 		{
// 			if (start->piece[o][p] == '*')
// 			{
// 				if (start->i == start->piece_coord_x + start->row_offset && start->j && start->j == start->piece_coord_y)
// 					fprintf(stderr, "IT'S THE FIRST ONE WITH ROW_OFFSET start->i: %d start->j: %d\n", start->i, start->j);
// 				else if ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece))
// 					fprintf(stderr, "IT'S COOL in function row_offset: start->i: %d start->j: %d\n", start->i, start->j);
// 				else 
// 				{
// 					start->flag += 1;
// 					fprintf(stderr, "NO in function with row_offset: start->i: %d start->j: %d piece_coord_x: %d piece_coord_y: %d\n", start->i, start->j, start->piece_coord_x, start->piece_coord_y);
// 				}
// 			}
// 		}
// 	}
// 	if (start->flag > 0)
// 	{
// 		fprintf(stderr, "FLAG: %d\n", start->flag);
// 		return (1);
// 	}
// 	fprintf(stderr, "ALL GOOD ON THE FLAG: %d\n", start->flag);
// 	return (0);
// }

int can_place_offset(s_board *start)
{
	int o;
	int p;
	int original_x;
	int	original_y;

	o = -1;
	start->flag = 0;
	original_y = start->piece_coord_y;
	original_x = start->piece_coord_x;
	start->i = start->piece_coord_x - 1;
	start->piece_coord_y -= start->offset;

	while (start->piece[++o] && start->board[++start->i])
	{
		p = -1;
		start->j = start->piece_coord_y - 1;
		while (start->piece[o][++p] && start->board[++start->j])
		{
			if (start->piece[o][p] == '*')
			{
				if ((start->j == original_y) && (start->i == original_x))
					fprintf(stderr, "IT'S THE FIRST ONE WITH OFFSET start->i: %d start->j %d\n", start->i, start->j);
					else if ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece))
					fprintf(stderr, "IT'S COOL in function offset: start->i: %d start->j: %d\n", start->i, start->j);
				else
				{
					start->flag += 1;
					fprintf(stderr, "NO in function with offset: start->i: %d start->j: %d piece_coord_x: %d piece_coord_y: %d\n", start->i, start->j, start->piece_coord_x, start->piece_coord_y);
				}
			}
		}
	}
	if (start->flag > 0)
	{
		fprintf(stderr, "FLAG: %d\n", start->flag);
		return (1);
	}
	fprintf(stderr, "ALL GOOD ON THE FLAG: %d\n", start->flag);
	return (0);
}

int	can_place(s_board *start)
{
	int o;
	int p;
	int original_x;
	int	original_y;

	o = -1;
	start->flag = 0;
	original_y = start->piece_coord_y;
	original_x = start->piece_coord_x;
	start->i = start->piece_coord_x - 1;

	while (start->piece[++o] && start->board[++start->i])
	{
		p = -1;
		start->j = start->piece_coord_y - 1;
		while (start->piece[o][++p] && start->board[++start->j])
		{
			if (start->piece[o][p] == '*')
			{
				if ((start->i == start->piece_coord_x) && (start->j == start->piece_coord_y))
					fprintf(stderr, "IT'S THE FIRST ONE start->i: %d start->j: %d start->piece_coord_x: %d start->piece_coord_y: %d\n", start->i, start->j, start->piece_coord_x, start->piece_coord_y);
				else if ((start->board[start->i][start->j] != start->my_piece) && (start->board[start->i][start->j] != start->opponent_piece))
					fprintf(stderr, "IT'S COOL in function: start->i: %d start->j: %d\n", start->i, start->j);
				else 
				{
					start->flag += 1;
					fprintf(stderr, "NO in function: start->i: %d start->j: %d piece_coord_x: %d piece_coord_y: %d\n", start->i, start->j, start->piece_coord_x, start->piece_coord_y);
				}
			}
		}
	}
	if (start->flag > 0){
		fprintf(stderr, "FLAG: %d\n", start->flag);
		return (1);
	}
	fprintf(stderr, "ALL GOOD ON THE FLAG: %d\n", start->flag);
	return (0);

}