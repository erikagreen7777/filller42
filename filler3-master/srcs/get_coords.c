#include "../filler.h"

int		get_x(char *line)
{
	int x;
	int ret;

	ret = 0;
	x = 0;
	while (line[x] != ' ')
		x++;
	x++;
	ret = ft_atoi(line + x);
	return (ret);
}

int		get_y(char *line)
{
	int y;
	int ret;
	int spaces;

	y = 0;
	ret = 0;
	spaces = 0;
	while (line[y])
	{
		if (spaces == 2)
			break ;
		if (line[y] == ' ')
			spaces++;
		y++;
	}
	ret = ft_atoi(line + y);
	return (ret);
}

void	assign_sides(s_board *start)
{
	if (start->my_piece == 'O' && start->map == 0)
	{
		start->my_coord[0] = 8;
		start->my_coord[1] = 2;
		start->op_coord[0] = 12;
		start->op_coord[1] = 14;
		//fprintf(stderr, "map %d\npiece: %c\nmy_coord[%d, %d]\n", start->map, start->my_piece, start->my_coord[0], start->my_coord[1]);
	}
	else if (start->my_piece == 'O' && start->map == 1)
	{
		start->my_coord[0] = 3;
		start->my_coord[1] = 3;
		start->op_coord[0] = 19;
		start->op_coord[1] = 32;
		//fprintf(stderr, "map %d\npiece: %c\nmy_coord[%d, %d]\n", start->map, start->my_piece, start->my_coord[0], start->my_coord[1]);
	}
	else if (start->my_piece == 'O' && start->map == 2)
	{
		start->my_coord[0] = 69;
		start->my_coord[1] = 70;
		start->op_coord[0] = 29;
		start->op_coord[1] = 30;
		//fprintf(stderr, "map %d\npiece: %c\nmy_coord[%d, %d]\n", start->map, start->my_piece, start->my_coord[0], start->my_coord[1]);
	}
	else 
		assign_sides2(start);
}

void	assign_sides2(s_board *start)
{
	if (start->my_piece == 'X' && start->map == 0)
	{
		start->op_coord[0] = 8;
		start->op_coord[1] = 2;
		start->my_coord[0] = 12;
		start->my_coord[1] = 14;
	}
	else if (start->my_piece == 'X' && start->map == 1)
	{
		start->op_coord[0] = 3;
		start->op_coord[1] = 3;
		start->my_coord[0] = 19;
		start->my_coord[1] = 32;
	}
	else if (start->my_piece == 'X' && start->map == 2)
	{
		start->op_coord[0] = 69;
		start->op_coord[1] = 70;
		start->my_coord[0] = 29;
		start->my_coord[1] = 30;
	}
	//fprintf(stderr, "map %d\npiece: %c\nmy_coord[%d, %d]\n", start->map, start->my_piece, start->my_coord[0], start->my_coord[1]);
}
