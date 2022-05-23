# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:29:09 by fcil              #+#    #+#              #
#    Updated: 2022/05/23 12:39:51 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		  = gcc
OS		= $(shell uname)

# mlx library
ifeq ($(OS), Linux)
	MLX		= ./minilibx-linux/
	MINILIBX	= minilibx-linux/libmlx.a
	LFLAGS	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= ./minilibx/
	MINILIBX	= minilibx/libmlx.a
	LFLAGS	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

NAME		= fract-ol
SRC_DIR	 = src
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(SRCS:.c=.o)
FT		= ./ft_printf/
FT_LIB	= ./ft_printf/libftprintf.a
CFLAGS	  = -I./include -I $(MLX) -I $(FT)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(FT_LIB) $(MINILIBX) $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(FT_LIB) -o $(NAME)

$(MINILIBX):
	@make -C $(MLX)

$(FT_LIB):
	@make -C $(FT)

re: fclean all

clean:
	rm -rf $(OBJS)
	@-make -C $(MLX) clean
	@-make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	@-make -C $(MLX) clean
	@-make -C $(FT) fclean

.PHONY: clean run fclean re all