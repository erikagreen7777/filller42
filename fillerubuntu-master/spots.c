#include "../filler.h"

void	row_count(s_board *start)
{
	start->i = 0;
	start->top = 0;
	start->bottom = 0;
	int count = 0;

	while ((start->i < start->board_x))
	{
		if (ft_strrchr(start->board[start->i], start->my_piece))
		{
			start->top = start->i;
			break;
		}
		start->i++;
	}

	start->i = 0;
	while ((start->i < start->board_x))
	{
		if (ft_strrchr(start->board[start->i], start->my_piece))
			count++;
		start->i++;
	}
	start->bottom = start->top + (count - 1);
}

void	col_count(s_board *start)
{
	start->i = start->top;
	start->left = 0;

	while (start->i <= start->bottom)
	{
		start->j = 0;
		while ((start->j < start->board_y))
		{
			if (start->board[start->i][start->j] == start->my_piece)
			{
				start->left = start->j;
				// fprintf(stderr, "start->left %d\n", start->left);
				break;	
			}
			start->j++;
		}
		if (start->board[start->i][start->j] == start->my_piece)
			break;
		start->i++;
	}

}

void	col_count2(s_board	*start)
{
	int count = 0;
	start->right = 0;

	start->i = start->top;
	while (start->i <= start->bottom)
	{
		start->j = 0;
		while ((start->j < start->board_y))
		{
			if (start->board[start->i][start->j] == start->my_piece){
				count++;
				break ;
			}
			start->j++;
		}
		start->i++;
	}
	start->right = start->j;
	// fprintf(stderr, "start->right: %d\n", start->right);
}

void	row_sum(s_board *start)
{
	int sum;
	int max; 
	int row_min;

	start->i = start->top;
	max = 2147483647;
	row_min = 0;
	// fprintf(stderr, "start->i: %d start->top: %d\n", start->i, start->top);
	while (start->i <= start->bottom)
	{
		start->j = -1;
		sum = 0;
		while (++start->j < start->board_y){
			sum += start->board[start->i][start->j];
			// fprintf(stderr, "row_sum: char: %c start->i: %d sum: %d start->j: %d\n", start->board[start->i][start->j], start->i, sum, start->j);
		}
		if ((sum < max))
		{
				max = sum;
				row_min = sum;
				start->piece_coord_x = start->i;
		}
		start->i++;
	}
	// fprintf(stderr, "row_min: %d start->piece_coord_x: %d\n", row_min, start->piece_coord_x);


}

void	col_sum(s_board *start)
{
	int sum;
	int max; 
	int col_min;

	start->j = start->left;
	max = 2147483647;
	col_min = 0;
	while (start->j <= start->right)
	{
		start->i = -1;
		sum = 0;
		while (++start->i < start->board_x){
			sum += start->board[start->j][start->i];
			// fprintf(stderr, "col_sum: char: %c start->j: %d sum: %d start->i: %d\n", start->board[start->i][start->j], start->j, sum, start->i);
		}
		if ((sum < max))
		{
				max = sum;
				col_min = sum;
				start->piece_coord_y = start->j;
		}
		start->j++;
	}
	// fprintf(stderr, "col_min: %d start->piece_coord_y: %d\n", col_min, start->piece_coord_y);
}

	//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
