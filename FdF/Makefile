# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 13:58:22 by fcil              #+#    #+#              #
#    Updated: 2022/03/03 14:16:20 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC=src/*.c
INCLUDES=include/ft_printf/libftprintf.a include/minilibx_macos/libmlx.a
#GET_NEXT_LINE = include/get_next_line/get_next_line.c include/get_next_line/get_next_line_utils.c

all:
	@make -C include/ft_printf/ all
	@make -C include/minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	make -C include/ft_printf/ clean
	make -C include/minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ft_printf/ fclean

re: fclean all