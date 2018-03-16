# ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/printf.h"

typedef struct 		t_board
{
	int		map;
	int		opponent_number;
	char	opponent_piece;
	int		my_number;
	char	my_piece;
	int 	my_piece_flag;
	int		board_x;
	int		board_y;
	char 	row;
	char	col;
	char	**board;
	char	**clear_board;
	int		my_coord[2];
	int		op_coord[2];
	int		piece_x;
	int		piece_y;
	char	**piece;
	int		piece_h;
	int		piece_w;
	int		i;
	int 	j;
	int		top;
	int		bottom;
	int		left;
	int		right;
	int		piece_coord_x;
	int		piece_coord_y;
	int		piece_offset_x;
	int		piece_offset_y;
	int		math_x;
	int		math_y;
	int 	offset;
	int 	row_offset;
	int 	flag;
	int		o;
	int		p;
	int		original_x;
	int		original_y;
	int		coord_1;
	int		coord_2;
}					s_board;


void		get_players(s_board *start, char *line);
void		get_board_size(s_board *start, char *line);
int			get_y(char *line);
int			get_x(char *line);
void		get_piece(s_board *start, char *line);
void 		get_meta_data(s_board *start, char *line);
void		assign_sides(s_board *start);
void		parse_filler(s_board *start);
void		assign_sides2(s_board *start);
void		find_x(s_board *start);
void		assign_minus(s_board *start);
void		assign_plus(s_board	*start);
void		assign_diag(s_board *start);
void		assign_tilde(s_board *start);
int			row_sum(s_board *start);
int			col_sum(s_board *start);
void		row_count(s_board *start);
void		col_count(s_board *start);
void		col_count2(s_board	*start);
void		find_offset(s_board *start);
int 		can_place_both_offsets(s_board *start);
int 		can_place_row_offset(s_board *start);
int 		can_place_offset(s_board *start);
int			can_place(s_board *start);
int			which_can_place(s_board *start);
void		get_piece_height(s_board *start);
void		get_piece_width(s_board *start);
void		build_board(s_board *start, char *line);

# endif
