#include "../filler.h"

void	assign_tilde(s_board *start)
{
	char tilde;
	tilde = '~';
	start->i = 0;

	while (start->board[start->i])
	{
		start->j = 0;
		while (start->board[start->i][start->j])
		{
	// fprintf(stderr, "hi\n");
			if (start->board[start->i][start->j] == '.')
				start->board[start->i][start->j] = tilde;
			// fprintf(stderr, "[%d][%d]: %c\n", start->i, start->j, start->board[start->i][start->j]);
			start->j++;
		}
		start->i++;
	}	
}

void	assign_minus(s_board *start)
{
	int i;
	int j;

	i = 0;
	j = 0;
	start->col = '0';
	start->row = '0';
	i = start->i;
	while (i >= 0)
	{
		if (start->board[i][start->j] == '~' && start->col < 79)
			start->board[i][start->j] = start->col;
		i--;
		start->col++;
	}
	j = start->j;
	while (j >= 0)
	{
		if (start->board[start->i][j] == '~' && start->row < 79)
			start->board[start->i][j] = start->row;
		j--;
		start->row++;
	}
}

void	assign_plus(s_board	*start)
{
	int i;
	int j;

	i = 0;
	j = 0;
	start->col = '0';
	start->row = '0';
	i = start->i;
	while (i < start->board_x)
	{
		if (start->board[i][start->j] == '~' && start->col < 79)
			start->board[i][start->j] = start->col;
		i++;
		start->col++;
	}
	j = start->j;
	while (j < start->board_y)
	{
		if (start->board[start->i][j] == '~' && start->row < 79)
			start->board[start->i][j] = start->row;
		j++;
		start->row++;
	}
}


void	find_x(s_board *start)
{
	assign_tilde(start);
	start->i = 0;

	while (start->board[start->i])
	{
		start->j = 0;
		while (start->board[start->i][start->j])
		{
			if (start->board[start->i][start->j] == 'X')
			{
				assign_minus(start);
				assign_plus(start);
			}			
			start->j++;
		}
		start->i++;
	}

// //PRINT THE BOARD
// 	start->i = -1;

// 	while (++start->i < start->board_x)
// 		fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
}


void	parse_filler(s_board *start)
{
	assign_sides(start);
	find_x(start);
	row_count(start);
	col_count(start);
	col_count2(start);
	row_sum(start);
	col_sum(start);
	find_offset(start);
	if (start->row_offset > 0 && start->offset > 0)
		can_place_both_offsets(start);
	else if (start->row_offset > 0)
		can_place_row_offset(start);
	else if (start->offset > 0)
		can_place_offset(start);
	else 
		can_place(start);
}