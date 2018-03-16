#include "../filler.h"

void	assign_tilde(s_board *start)
{
	// fprintf(stderr, "start->board_x	%d\n", start->board_x);
	fprintf(stderr, "THIS IS ASSIGN_TILDE\n");

	fprintf(stderr, "start->i: %d\n", start->i);


	// fprintf(stderr, "start->board[start->i]: %s\n", start->board[start->i]);
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
	//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "THIS IS THE BOARD[%d]: %s\n", start->i, start->board[start->i]);
	// 	fprintf(stderr, "THIS IS THE END OF ASSIGN_TILDE\nboard_x: %d\n", start->board_x);

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
	fprintf(stderr, "THIS IS FIND_X\n");
	// fprintf(stderr, "start->board_x: %d\n", start->board_x);
	start->i = 0;

// 	while (start->board[start->i])
// 	{
// 		start->j = 0;
// 		while (start->board[start->i][start->j])
// 		{
// 			if (start->board[start->i][start->j] == 'X')
// 			{
// 				assign_minus(start);
// 				assign_plus(start);
// 			}			
// 			start->j++;
// 		}
// 		start->i++;
// 	}
// 	start->i = 0;
// 	start->clear_board = (char **)ft_memalloc(sizeof(char *) * (start->board_x + 1));
// 	while ((start->i < start->board_x))
// 	{
// 		start->clear_board[start->i] = ft_strdup(start->board[start->i]);
// 		start->i++;
// 	}
// //PRINT THE BOARD
// 	start->i = -1;

// 	while (++start->i < start->board_x)
// 		fprintf(stderr, "THIS IS THE BOARD[%d]: %s\n", start->i, start->clear_board[start->i]);
}


void	parse_filler(s_board *start)
{
	fprintf(stderr, "THIS IS PARSE\n");
	// fprintf(stderr, "start->board_x: %d\n", start->board_x);
	// assign_sides(start);
	// get_piece_height(start);
	// get_piece_width(start);
	assign_tilde(start);

	// find_x(start);
	// fprintf(stderr, "THIS IS RIGHT BEFORE ROW COUNT\n");
	// row_count(start);
	// col_count(start);
	// col_count2(start);
	// row_sum(start);
	// col_sum(start);
	// find_offset(start);
	// which_can_place(start);
	// start->coord_1 = start->piece_coord_x;
	// start->coord_2 = start->piece_coord_y;
	// fprintf(stderr, "%d %d\n", start->coord_1, start->coord_2);
	// printf("%d %d\n", start->coord_1, start->coord_2);
 //   	ft_putnbr(start->coord_1);
	// ft_putchar(' ');
	// ft_putnbr(start->coord_2);
	// ft_putchar('\n');


	// write(2, &start->coord_1, 2);
	// write(2, " ", 1);
	// write(2, &start->coord_2, 2);
	// write(2, "hello", 5);



}
