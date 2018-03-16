#include "../filler.h"

void	row_count(s_board *start)
{
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
	// fprintf(stderr, "start->top: %d\n", start->top);
//counting how many row i have (assuming there can't be any gaps)
	start->i = 0;
	while ((start->i < start->board_x))
	{
		if (ft_strrchr(start->board[start->i], start->my_piece))
			count++;
		start->i++;
	}
	start->bottom = start->top + (count - 1);
	// fprintf(stderr, "start->bottom: %d\n", start->bottom);

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
	// fprintf(stderr, "start->left: %d\n", start->left);
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
	// fprintf(stderr, "start->right: %d\n", start->right);
}

void	change_my_piece(s_board *start)
{
	start->i = -1;
	while (start->board[++start->i])
	{
		start->j = -1;
		while (start->board[start->i][++start->j])
		{
			if (start->board[start->i][start->j] == start->my_piece)
				start->board[start->i][start->j] = '|';
		}
	}
//PRINT THE BOARD
	 // start->i = -1;

	 // while (++start->i < start->board_x)
	 // 	fprintf(stderr, "THIS IS THE BOARD[%d]: %s\n", start->i, start->board[start->i]);

}

// void	change_my_piece_back(s_board *start)
// {
// 	start->i = -1;
// 	while (start->board[++start->i])
// 	{
// 		start->j = -1;
// 		while (start->board[start->i][++start->j])
// 		{
// 			if (start->board[start->i][start->j] == start->my_piece || start->board[start->i][start->j] == '*')
// 				start->board[start->i][start->j] = '|';
// 		}
// 	}	
// }
int	row_sum(s_board *start)
{
	int sum;
	int max; 
	int row_min;

/****find the smallest sum row (heat map) - assign to start->piece_coord_x****/
	start->i = start->top;
	max = 2147483647;
	row_min = 0;
	while (start->i <= start->bottom)
	{
		start->j = -1;
		sum = 0;
		while (++start->j < start->board_y){
			sum += start->board[start->i][start->j];
			// fprintf(stderr, "sum: %dstart->i: %d\tstart->j: %d\n", sum, 
			// 	start->i, start->j);
		}
		if ((sum < max))
		{
			// fprintf(stderr, "max: %d\tstart->i: %d\n", max, start->i);
				max = sum;
				row_min = sum;
				start->piece_coord_x = start->i;
				// fprintf(stderr, "max: %d\trow_min: %d\tstart->piece_coord_x: %d\n", max,
				// 	row_min, start->piece_coord_x);
		}
		start->i++;
	}
	return (start->piece_coord_x);
	// fprintf(stderr, "start->piece_coord_x: %d\n", start->piece_coord_x);

}


/*SEE IF YOU CAN ADD "CAN PLACE" TO THE SUM CONDITIONAL FOR EITHER ROW_SUM OR COL_SUM */



int	col_sum(s_board *start)
{
	int sum;
	int max; 
	int col_min;

/****FIND THE SMALLEST SUM_COL AND ASSIGN TO START->PIECE_COORD_Y****/
	start->j = start->left;
	max = 2147483647;
	col_min = 0;
	while (start->j <= start->right)
	{
		start->i = -1;
		sum = 0;
		while (++start->i < start->board_x){
			sum += start->board[start->j][start->i];
			// fprintf(stderr, "sum: %dstart->i: %d\tstart->j: %d\n", sum, 
				// start->i, start->j);
		}
		if (sum < max)
		{
				max = sum;
				col_min = sum;
				start->piece_coord_y = start->j;

		}
		start->j++;
	}
			// fprintf(stderr, "max: %d\tcol_min: %d\tstart->piece_coord_y: %d\n", max,
			// 		col_min, start->piece_coord_y);
	return (start->piece_coord_y);
	// fprintf(stderr, "start->piece_coord_y: %d\n", start->piece_coord_y);
}

	//PRINT THE BOARD
	// start->i = -1;

	// while (++start->i < start->board_x)
	// 	fprintf(stderr, "start->board[%d]: %s\n", start->i, start->board[start->i]);





// #include "../filler.h"

// void	row_count(s_board *start)
// {
// 	start->i = 0;
// 	start->top = 0;
// 	start->bottom = 0;
// 	int count = 0;

// //strchr for the first occurence of my piece
// 	while ((start->i < start->board_x))
// 	{
// 		if (ft_strrchr(start->board[start->i], start->my_piece))
// 		{
// 			start->top = start->i;
// 			break;
// 		}
// 		start->i++;
// 	}
// 	// fprintf(stderr, "start->top: %d\n", start->top);
// //counting how many row i have (assuming there can't be any gaps)
// 	start->i = 0;
// 	while ((start->i < start->board_x))
// 	{
// 		if (ft_strrchr(start->board[start->i], start->my_piece))
// 			count++;
// 		start->i++;
// 	}
// 	start->bottom = start->top + (count - 1);
// 	// fprintf(stderr, "start->bottom: %d\n", start->bottom);

// }

// void	col_count(s_board *start)
// {
// 	start->i = start->top;
// 	start->left = 0;

// //counting from the rows that just have my_piece in them to find the left-most occurence of my piece
// 	while (start->i <= start->bottom)
// 	{
// 		start->j = 0;
// 		while ((start->j < start->board_y))
// 		{
// 			if (start->board[start->i][start->j] == start->my_piece)
// 			{
// 				start->left = start->j;
// 				break;	
// 			}
// 			start->j++;
// 		}
// 		if (start->board[start->i][start->j] == start->my_piece)
// 			break;
// 		start->i++;
// 	}
// 	// fprintf(stderr, "start->left: %d\n", start->left);
// }

// void	col_count2(s_board	*start)
// {
// 	int count;
// 	int current_count = 0;
// /***find the right-most occurence of my piece***/
// 	start->i = start->top - 1;
// 	while (++start->i <= start->bottom)
// 	{
// 		start->j = start->left - 1;
// 		count = 0;
// 		while ((++start->j < start->board_y))
// 		{
// 			if (start->board[start->i][start->j] == start->my_piece){
// 				count++;
// 				if (count > current_count)
// 				{
// 					start->right = start->j;
// 					current_count = count;
// 				}
// 			}
// 		}
// 	}
// 	// fprintf(stderr, "start->right: %d\n", start->right);
// }

// void	change_my_piece(s_board *start)
// {
// 	start->i = -1;
// 	while (start->board[++start->i])
// 	{
// 		start->j = -1;
// 		while (start->board[start->i][++start->j])
// 		{
// 			if (start->board[start->i][start->j] == start->my_piece || start->board[start->i][start->j] == start->my_piece + 32)
// 				start->board[start->i][start->j] = '|';
// 		}
// 	}
// 	start->row_val = 2147483647;
// 	start->col_val = 2147483647;
// //PRINT THE BOARD
// 	 start->i = -1;

// 	 while (++start->i < start->board_x)
// 	 	fprintf(stderr, "change_my_piece[%d]: %s\n", start->i, start->board[start->i]);

// }

// // void	change_my_piece_back(s_board *start)
// // {
// // 	start->i = -1;
// // 	while (start->board[++start->i])
// // 	{
// // 		start->j = -1;
// // 		while (start->board[start->i][++start->j])
// // 		{
// // 			if (start->board[start->i][start->j] == start->my_piece || start->board[start->i][start->j] == '*')
// // 				start->board[start->i][start->j] = '|';
// // 		}
// // 	}	
// // }
// int	row_sum(s_board *start)
// {
// 	int sum;
// 	int max;
// 	// int temp;
// 	// int row_min;

// /****find the smallest sum row (heat map) - assign to start->piece_coord_x****/
// 	// start->i = start->top;
// 	max = 2147483647;
// 	start->row_min = 0;
// 	// while (start->i <= start->bottom)
// 	// {
// 		start->j = start->j_holder;
// 		sum = 0;
// 		while (++start->j < start->board_y)
// 		{
// 			sum += start->board[start->i][start->j];
// 			// fprintf(stderr, "sum: %dstart->i: %d\tstart->j: %d\n", sum, 
// 			// 	start->i, start->j);
// 		}
// 		if ((sum < max))
// 		{
// 			// fprintf(stderr, "max: %d\tstart->i: %d\n", max, start->i);
// 				max = sum;
// 				start->row_min = max;
// 				if (start->row_min < start->row_val)
// 					start->row_val = start->row_min;
// 				// row_min = sum;
// 				// start->piece_coord_x = start->i;
// 				// fprintf(stderr, "max: %d\trow_min: %d\tstart->piece_coord_x: %d\n", max,
// 				// 	row_min, start->piece_coord_x);
// 		}
// 	// 	start->i++;
// 	// }
// 	start->j = start->j_holder;
// 	return (start->row_min);
// 	// fprintf(stderr, "start->piece_coord_x: %d\n", start->piece_coord_x);

// }

// int	col_sum(s_board *start)
// {
// 	int sum;
// 	int max; 
// 	// int temp;
// 	// int col_min;

// /****FIND THE SMALLEST SUM_COL AND ASSIGN TO START->PIECE_COORD_Y****/
// 	// start->j = start->left;
// 	max = 2147483647;
// 	start->col_min = 0;
// 	start->j = start->j_holder;
// 	while (start->j < start->j_holder + 1)
// 	{
// 		start->i = start->i_holder;
// 		sum = 0;
// 		while (++start->i < start->board_x){
// 			sum += start->board[start->j][start->i];
// 		}
// 		if ((sum < max))
// 		{
// 				max = sum;
// 				start->col_min = max;
// 				if (start->col_min < start->col_val)
// 					start->col_val = start->col_min;
// 		// fprintf(stderr, "max: %d\tcol_min: %d\tstart->piece_coord_y: %d\n", max,
// 					// col_min, start->piece_coord_y);
// 		}
// 		start->j++;
// 	}
// 	return (start->col_min);
// 	// fprintf(stderr, "start->piece_coord_y: %d\n", start->piece_coord_y);


	
// }