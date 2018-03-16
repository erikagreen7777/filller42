# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egreen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 09:46:14 by egreen            #+#    #+#              #
#    Updated: 2017/12/07 10:06:11 by egreen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = egreen.filler

SRC = srcs/main.c \
		srcs/get_meta_data.c \
		srcs/get_coords.c \
		srcs/parse.c \
		srcs/place.c \
		srcs/misc.c
		
LIBS = -L./libft -lft 

FLAGS = -Wall -Werror -Wextra $(LIBS)

HEADERS = filler.h

all : $(NAME)

$(NAME) :
	make -C ./libft/
	gcc -o $(NAME) $(SRC) $(FLAGS) -g
	@echo "\033[32;1mReady"

clean:
	make clean -C ./libft/
	@echo "\033[36mCleaned..."

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)
	@echo "\033[31;1mFcleaned..."

re: fclean all
	make re -C ./libft/
