# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 11:41:37 by fcil              #+#    #+#              #
#    Updated: 2022/08/11 17:36:34 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CC = clang++ -std=c++98
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./
SRC	= 	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o	: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< 

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
