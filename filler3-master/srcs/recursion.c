#include "../filler.h"

static void	clear_board(s_board	*start)
{
	start->i = 0;
	while ((start->i < start->board_x))
	{
		ft_strcpy(start->board[start->i], start->clear_board[start->i]);
		start->i++;
	}
/*PRINT THE CLEAR_BOARD*/
	// start->i = -1;
	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "HERE IT IS[%d]: %s\n", start->i, start->clear_board[start->i]);
/***************************/
}

static int which_can_both(s_board *start)
{
	int ret;
	ret = can_place_both_offsets(start);
	fprintf(stderr, "ret = %d\n", ret);
	if (ret == 1)
	{
		if (start->math_x != 0 && start->math_y != 0)
		{
			start->piece_coord_x = start->piece_coord_x - start->math_x + start->row_offset;
			start->piece_coord_y = start->piece_coord_y - start->math_y + start->offset;
			start->original_x = start->piece_coord_x;
			start->original_y = start->piece_coord_y;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_both(start);
		}
		else if (start->math_x != 0 && start->math_y == 0)
		{
			start->piece_coord_x = start->piece_coord_x - start->math_x + start->row_offset;
			start->piece_coord_y = start->piece_coord_y + start->offset;
			start->original_x = start->piece_coord_x;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_both(start);

		}
		else if (start->math_y != 0 && start->math_x == 0)
		{
			start->piece_coord_x = start->piece_coord_x + start->row_offset;
			start->piece_coord_y = start->piece_coord_y - start->math_y + start->offset;
			start->original_y = start->piece_coord_y;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_both(start);
		}
	}
	else if (start->math_x < 0 || start->math_y < 0)
	{
		//example: it can't fit with just math_x, so now try with math_y
		fprintf(stderr, "no way double-offset-way");
		return (1);
	}
	return (0);
}
	

static int	which_can_row(s_board *start)
{
	int ret;
	ret = can_place_row_offset(start);
	fprintf(stderr, "ret = %d\n", ret);
	if (ret == 1)
	{
		if (start->math_x != 0 && start->math_y != 0)
		{
			// fprintf(stderr, "something1");
			start->piece_coord_x = start->piece_coord_x - start->math_x + start->row_offset;
			start->piece_coord_y = start->piece_coord_y - start->math_y;
			start->original_x = start->piece_coord_x;
			start->original_y = start->piece_coord_y;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_row(start);
		}	
		else if (start->math_x != 0 && start->math_y == 0)
		{
			// fprintf(stderr, "something2");
			start->piece_coord_x = start->piece_coord_x - start->math_x + start->row_offset;
			start->piece_coord_y = start->piece_coord_y;
			start->original_x = start->piece_coord_x;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_row(start);
		}
		else if (start->math_y != 0 && start->math_x == 0)
		{
			// fprintf(stderr, "something3");
			start->piece_coord_x = start->piece_coord_x + start->row_offset;
			start->piece_coord_y = start->piece_coord_y + start->math_y;
			start->original_y = start->piece_coord_y;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_row(start);
		}
	}
	else if (start->math_x < 0 || start->math_y < 0){
		fprintf(stderr, "no way offset-way");
		return (1);
	}
	return (0);
}

static int	which_can_offset(s_board *start)
{
	int ret;
	ret = can_place_offset(start);
		fprintf(stderr, "ret = %d\n", ret);

	if (ret == 1)
	{
		if (start->math_x != 0 && start->math_y != 0)
		{
			start->piece_coord_x = start->piece_coord_x;
			start->piece_coord_y = start->piece_coord_y + start->offset;
			start->original_x = start->piece_coord_x;
			start->original_y = start->piece_coord_y;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_offset(start);
		}
		else if (start->math_x != 0 && start->math_y == 0)
		{
			start->piece_coord_x = start->piece_coord_x + start->math_x;
			//make original_x the new piece_coord_x?
			start->original_x = start->piece_coord_x;
			start->piece_coord_y = start->piece_coord_y + start->offset;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_offset(start);
		}
		else if (start->math_y != 0 && start->math_x == 0)
		{
			start->piece_coord_x = start->piece_coord_x;
			start->piece_coord_y = start->piece_coord_y + start->math_y + start->offset;
			start->original_y = start->piece_coord_y;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_offset(start);
		}
	}
	else if (start->math_x < 0 || start->math_y < 0){
		fprintf(stderr, "no way offset-way");
		return (1);
	}
	return (0);

}

static int	which_can_plain(s_board *start)
{
	int ret;
	ret = can_place(start);
		fprintf(stderr, "ret = %d\n", ret);

	if (ret == 1)
	{
		if (start->math_x != 0 && start->math_y != 0)
		{
			start->piece_coord_x = start->piece_coord_x + start->math_x;
			start->piece_coord_y = start->piece_coord_y + start->math_y;
			start->original_x = start->piece_coord_x;
			start->original_y = start->piece_coord_y;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_plain(start);
		}
		else if (start->math_x != 0 && start->math_y == 0)
		{
			start->piece_coord_x = start->piece_coord_x + start->math_x;
			start->original_x = start->piece_coord_x;
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_plain(start);
		}
		else if (start->math_y != 0 && start->math_x == 0)
		{
			start->piece_coord_y = start->piece_coord_y + start->math_y;
			start->original_y = start->piece_coord_y;
			// start->piece_coord_y = start->piece_coord_y - start->math_y; // add math_y t- coord_y?
			start->math_x = 0;
			start->math_y = 0;
			clear_board(start);
			which_can_plain(start);
		}
	}
	else if (start->math_x < 0 || start->math_y < 0){
		fprintf(stderr, "no way");
		return (1);
	}
	return (0);
}

int		which_can_place(s_board *start)
{
	if (start->row_offset > 0 && start->offset > 0)
	{
		if (which_can_both(start) == 1)
		{
			fprintf(stderr, "BOTH SKITTLES");
			return (1);
		}
		
	}
	else if (start->row_offset > 0)
	{
		if (which_can_row(start) == 1)
		{
			fprintf(stderr, "ROW SKITTLES");
			return (1);
		}
	}
	else if (start->offset > 0)
	{
		if (which_can_offset(start) == 1)
		{
			fprintf(stderr, "OFFSET SKITTLES");
			return (1);
		}
	}
	else if (start->offset == 0 && start->row_offset == 0)
	{
		if (which_can_plain(start) == 1)
		{
			fprintf(stderr, "SKITTLES");
			return (1);
		}
	}
	return (0);
}

