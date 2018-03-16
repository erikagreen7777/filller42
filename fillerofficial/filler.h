/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:27:40 by egreen            #+#    #+#             */
/*   Updated: 2018/01/18 09:34:36 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/printf.h"

# define BUFF_SIZE 1

typedef struct	s_board
{
	int			map;
	char		opp_piece;
	char		my_piece;
	int			board_x;
	int			board_y;
	char		**board;
	int			piece_x;
	int			piece_y;
	char		**piece;
	int			piece_coord_x;
	int			piece_coord_y;
	int			flag;
	int			i;
	int			j;
	int			o;
	int			p;
	int			touch;
	int			value;
	int			low_value;
	int			carry_row;
	int			coord_1;
	int			row_offset;
	char		row;
	int			row_min;
	int			row_val;
	int			row_value;
	int			row_min_val;
	int			coord_2;
	int			offset;
	int			carry_col;
	char		col;
	int			col_val;
	int			col_min_val;
	int			col_min;
	int			col_value;
}				t_board;

void			get_players(t_board *start, char *line);
void			get_board_size(t_board *start, char *line);
int				get_y(char *line);
int				get_x(char *line);
void			get_piece(t_board *start, char *line);
void			get_meta_data(t_board *start, char *line);
void			parse_filler(t_board *start);
void			find_x(t_board *start);
void			assign_minus(t_board *start);
void			assign_plus(t_board	*start);
void			assign_diag(t_board *start);
void			assign_tilde(t_board *start);
void			find_offset(t_board *start);
void			find_safe_spot(t_board *start);
void			build_board(t_board *start, char *line);
int				analyze(t_board *start);
int				get_game_info(t_board *start);
void			change_my_piece(t_board *start);
int				place_piece(t_board *start);
int				check_data(t_board *start, int x, int y);
int				add_col(t_board *start);
int				add_row(t_board *start);

#endif
