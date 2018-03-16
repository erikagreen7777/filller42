#include "../filler.h"

void	row_count(s_board *start)
{
	fprintf(stderr, "THIS IS ROW_COUNT\n");
	start->i = 0;
	start->top = 0;
	start->bottom = 0;
	int count = 0;

//strchr for the first occurence of my piece
	while ((start->i < start->board_x))
	{
		if (ft_strrchr(start->board[start->i], start->my_piece))
		{
			start->top = start->i;
			break;
		}
		start->i++;
	}
//counting how many row i have (assuming there can't be any gaps)
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

//counting from the rows that just have my_piece in them to find the left-most occurence of my piece
	while (start->i <= start->bottom)
	{
		start->j = 0;
		while ((start->j < start->board_y))
		{
			if (start->board[start->i][start->j] == start->my_piece)
			{
				start->left = start->j;
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
	int count;
	int current_count = 0;
/***find the right-most occurence of my piece***/
	start->i = start->top - 1;
	while (++start->i <= start->bottom)
	{
		start->j = start->left - 1;
		count = 0;
		while ((++start->j < start->board_y))
		{
			if (start->board[start->i][start->j] == start->my_piece){
				count++;
				if (count > current_count)
				{
					start->right = start->j;
					current_count = count;
				}
			}
		}
	}
}

int	row_sum(s_board *start)
{
	int sum;
	int max; 
	// int row_min;

/****find the smallest sum row (heat map) - assign to start->piece_coord_x****/
	start->i = start->top;
	max = 2147483647;
	// row_min = 0;
	while (start->i <= start->bottom)
	{
		start->j = -1;
		sum = 0;
		while (++start->j < start->board_y){
			sum += start->board[start->i][start->j];
		}
		if ((sum < max))
		{
				max = sum;
				// row_min = sum;
				start->piece_coord_x = start->i;
		}
		start->i++;
	}
	return (start->piece_coord_x);
	// fprintf(stderr, "start->piece_coord_x: %d\n", start->piece_coord_x);

}

int	col_sum(s_board *start)
{
	int sum;
	int max; 
	// int col_min;

/****FIND THE SMALLEST SUM_COL AND ASSIGN TO START->PIECE_COORD_Y****/
	start->j = start->left;
	max = 2147483647;
	// col_min = 0;
	while (start->j <= start->right)
	{
		start->i = -1;
		sum = 0;
		while (++start->i < start->board_x){
			sum += start->board[start->j][start->i];
		}
		if ((sum < max))
		{
				max = sum;
				// col_min = sum;
				start->piece_coord_y = start->j;
		}
		start->j++;
	}
	return (start->piece_coord_y);
	// fprintf(stderr, "start->piece_coord_y: %d\n", start->piece_coord_y);
}

	//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);
