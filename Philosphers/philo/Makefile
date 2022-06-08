# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 22:58:51 by fcil              #+#    #+#              #
#    Updated: 2022/06/05 22:18:15 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo

CC		:= gcc
INCLUDE	:= ./include
#CFLAGS	:= -Wall -Wextra -Werror -ggdb -I $(INCLUDE)
CFLAGS	:= -ggdb -I $(INCLUDE)

#TODO: -GGDB WILL BE DELETED -Werror

SRCDIR	:= src
SRC		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re