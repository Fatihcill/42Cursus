# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 14:36:41 by fcil              #+#    #+#              #
#    Updated: 2022/06/13 14:45:00 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo_bonus

CC		:= gcc
INCLUDE	:= ./include
CFLAGS	:= -Wall -Wextra -Werror -I $(INCLUDE)

SRCDIR	:= src
SRC		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -o $(@D)
	$(CC) $(CFLAGS) -c $< -O $@

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
