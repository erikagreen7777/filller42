#include "../filler.h"

void	assign_tilde(s_board *start)
{
	start->i = 0;

	while (start->board[start->i])
	{
		start->j = 0;
		while (start->board[start->i][start->j])
		{
			if (start->board[start->i][start->j] == '.')
				start->board[start->i][start->j] = '~';
			start->j++;
		}
		start->i++;
	}
	fprintf(stderr, "MY PIECE: %c\n", start->my_piece);
//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "THIS IS THE BOARD[%d]: %s\n", start->i, start->board[start->i]);

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
			if (start->board[start->i][start->j] == start->opponent_piece)
			{
				assign_minus(start);
				assign_plus(start);
			}			
			start->j++;
		}
		start->i++;
	}
	start->i = 0;
	start->clear_board = (char **)ft_memalloc(sizeof(char *) * (start->board_x + 1));
	while ((start->i < start->board_x))
	{
		start->clear_board[start->i] = ft_strdup(start->board[start->i]);
		start->i++;
	}
//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "THIS IS THE BOARD[%d]: %s\n", start->i, start->board[start->i]);
}

static int add_row(s_board *start)
{
	int e;
 int f;

	start->carry_row = 0;
	e = start->i;
	f = start->j;
	// int max = 2147483647;
	start->row_min = 0;

	while (e< (start->i + 1))
	{
		f = 0;
		while (f < start->board_y)
		{
			start->row_min += start->board[start->i][start->j];
			start->carry_row = start->i - start->row_offset;
			// fprintf(stderr, "row_min: %d\n", start->row_min);
			f++;
		}
		e++;
	}
	return (0);
}

static int	add_col(s_board *start)
{
	int e;
	int f;
	e = 0;
	f = start->j;
	start->carry_col = 0;
	start->col_min = 0;

	while (f < (start->j + 1))
	{
		
		while (e < start->board_x)
		{
			start->col_min += start->board[start->i][start->j];
			start->carry_col = start->j - start->offset;
			// fprintf(stderr, "col_min: %d\n", start->col_min);
			e++;
		}
		f++;
	}
	return (0);
}





static int		transfer_to_high_value(s_board *start)
{
	start->high_value = start->value;
	start->coord_1 = start->carry_row;
	start->coord_2 = start->carry_col;
	fprintf(stderr, "coord1: %d\tcoord2: %d\n", start->coord_1, start->coord_2);
	return (1);
}

static int		check_data(s_board *start, int x, int y)
{
	int	i_hold;
	int	j_hold;
	if ((start->i - start->o) + x >= start->board_x || (start->j - start->p) + y >= start->board_y || (start->i - start->o) + x < 0 || (start->j - start->p) + y < 0){
		// fprintf(stderr, "start->i: %d\t start->o: %d\tx: %d\t start->j: %d\tstart->p: %d\ty: %d\n", start->i, start->o, x, start->j, start->p, y);
		// fprintf(stderr, "(start->i - start->o) + x: %d\t(start->j - start->p) + y: %d\n", (start->i - start->o) + x, (start->j - start->p) + y);
		return (0);
	}
	else if (start->board[(start->i - start->o) + x][(start->j - start->p) + y] == start->my_piece || start->board[(start->i - start->o) + x][(start->j - start->p) + y] == start->my_piece + 32){
		start->touch++;
		// fprintf(stderr, "start->touch: %d\n", start->touch);
	}
	else if (start->board[(start->i - start->o) + x][(start->j - start->p) + y] == start->opponent_piece || start->board[(start->i - start->o) + x][(start->j - start->p) + y] == start->opponent_piece + 32){
		// fprintf(stderr, "IT EQUALS A PIECE AND IT SHOULDN'T\n");
		return (0);
	}
	else if ((start->board[(start->i - start->o) + x][(start->j - start->p) + y] > 47 && start->board[(start->i - start->o) + x][(start->j - start->p) + y] < 79) || (start->board[(start->i - start->o) + x][(start->j - start->p) + y] == '~')){
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
		// fprintf(stderr, "start->row_min: %d\tstart->row_carry: %d\tstart->col_min: %d\tstart->col_carry: %d\n", start->row_min, start->carry_row, start->col_min, start->carry_col);
		start->value = start->row_min_val + start->col_min_val;
		// fprintf(stderr, "start->value: %d\n", start->value);
	}
	return (1);
}

static int		check_board_to_piece(s_board *start)
{
	int x;
	int y;

	start->touch = 0;
	start->value = 0;
	x = start->o - 1;
	y = start->p - 1;
	while (start->piece[++x])
	{
		while (start->piece[x][++y])
		{
			if (start->piece[x][y] == '*')
				if (!check_data(start, x, y)){
					// fprintf(stderr, "CHECK_BOARD_TO_PIECE RETURNS 0\n");
					return (0);
				}
		}
		y = -1;
	}
	if (start->touch == 1)
	{

		// fprintf(stderr, "TOUCH = 1\tCHECK_BOARD RETURNS 1\n");
        // start->piece_coord_x = (start->i - start->o);
        // start->piece_coord_y = (start->j - start->p);
        // fprintf(stderr, "start->piece_coord_x: %d\tstart->piece_coord_y: %d\n", start->piece_coord_x, start->piece_coord_y);
//		which_can_place(start);

		if (start->value < start->high_value &&
			transfer_to_high_value(start))
			return (1);
	}
	return (0);
}

static void	compare_board(s_board *start)
{
	start->i = -1;
	while (start->board[++start->i])
	{
		start->j = -1;
		while (start->board[start->i][++start->j])
		{
			if (check_board_to_piece(start))
				;
		}
	}
}

void	find_safe_spot(s_board *start)
{
	start->o = -1;
	while (start->piece[++start->o])
	{
		start->p = -1;
		while (start->piece[start->o][++start->p])
		{
			if (start->piece[start->o][start->p] == '*')
			{
				compare_board(start);
				return ;
			}
		}
	}
}


void	parse_filler(s_board *start)
{
	find_x(start);
	row_count(start);
	col_count(start);
	col_count2(start);
	find_offset(start);
	start->high_value = 2147483647;
	start->row_min_val = 2147483647;
	start->col_min_val = 2147483647;
 	find_safe_spot(start);
//find safe_spot needs to come before I do the math**************************
	// change_my_piece(start);

}

// void	find_safe_spot(s_board *start)
// {
// 	row_sum(start);
// 	col_sum(start);

// 	which_can_place(start);
// 	start->coord_1 = start->piece_coord_x;
// 	start->coord_2 = start->piece_coord_y;
// 	fprintf(stderr, "WE WILL PLACE IT: %d %d\n", start->coord_1, start->coord_2);

// }
