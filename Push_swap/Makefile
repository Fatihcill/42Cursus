# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 22:58:51 by fcil              #+#    #+#              #
#    Updated: 2022/04/22 10:33:50 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CC		:= gcc
INCLUDE	:= ./include
CFLAGS	:= -Wall -Wextra -ggdb -I $(INCLUDE)
LIBFT	= ft_printf

#TODO: -GGDB WILL BE DELETED -Werror

SRCDIR	:= src
SRC		:= $(shell find $(SRCDIR) -name '*.c')

BNSDIR	:= bns
BNS		:= $(shell find $(BNSDIR) -name '*.c')

OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJBNS	:= $(BNS:$(BNSDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

bonus:	$(OBJ) $(OBJBNS)
	make -C $(LIBFT)
	cp ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) $(OBJ) libftprintf.a -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) $(OBJ) libftprintf.a -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf libftprintf.a
	@rm -rf $(OBJDIR)

fclean:
	make fclean -C $(LIBFT)
	rm -rf libftprintf.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re